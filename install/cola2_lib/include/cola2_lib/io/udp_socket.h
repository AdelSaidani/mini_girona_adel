/*
 * Copyright (c) 2021 Iqua Robotics SL - All Rights Reserved
 *
 * This file is subject to the terms and conditions defined in file
 * 'LICENSE.txt', which is part of this source code package.
 */

#pragma once

#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/udp.hpp>
#include <boost/bind/bind.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <cstdlib>
#include <iostream>

using boost::asio::deadline_timer;
using boost::asio::ip::udp;

namespace cola2
{
namespace io
{
/**
 * @addtogroup io
 * @{
 */

namespace udp_socket
{
/**
 * @brief Custom UDP client with a templated buffer size that remembers who the sender is
 *
 * @tparam BUFFER_SIZE Maximum size to read
 */
template <size_t BUFFER_SIZE>
class Client
{
  boost::asio::io_service io_service_;  //!< IO service
  udp::socket socket_;                  //!< UDP socket
  deadline_timer deadline_;             //!< Deadline
  udp::endpoint sender_endpoint_;       //!< Where we are reading from to send replies
  char buffer_[BUFFER_SIZE];            //!< Read buffer.
  unsigned int timeout_ms_;             //!< Read timeout in milliseconds

public:
  /**
   * @brief Construct a new Client object
   *
   * @param port Port to listen to
   * @param timeout_ms Read timeout in milliseconds
   */
  Client(const unsigned int& port, const unsigned int& timeout_ms)
    : socket_(io_service_, udp::endpoint(udp::v4(), port)), deadline_(io_service_), timeout_ms_(timeout_ms)
  {
    // no dealine at start
    deadline_.expires_at(boost::posix_time::pos_infin);
    check_deadline();
  }

  /**
   * @brief Read data from UDP port with a timeout.
   *
   * @return Received data as string.
   */
  std::string receiveFromUDP()
  {
    // set timeout
    deadline_.expires_from_now(boost::posix_time::millisec(timeout_ms_));

    // read async
    boost::system::error_code ec = boost::asio::error::would_block;
    std::size_t length = 0;
    socket_.async_receive_from(boost::asio::buffer(buffer_), sender_endpoint_,
                               boost::bind(&Client::handle_receive, _1, _2, &ec, &length));

    // block until async complete
    do
    {
      io_service_.run_one();
    } while (ec == boost::asio::error::would_block);

    // result
    if (ec)
    {
      std::cerr << "Client, receive error: " << ec.message() << "\n";
      return "";
    }
    return std::string(buffer_, length);
  }

  /**
   * @brief Send data to the address of the last sender (reply).
   *
   * @param msg Data to send.
   */
  void sendToLastReceived(const std::string& msg)
  {
    socket_.send_to(boost::asio::buffer(msg), sender_endpoint_);
  }

private:
  /**
   * @brief Check deadline for timeouts before completition.
   *
   */
  void check_deadline()
  {
    // deadline passed
    if (deadline_.expires_at() <= deadline_timer::traits_type::now())
    {
      // cancel job
      socket_.cancel();
      deadline_.expires_at(boost::posix_time::pos_infin);
    }
    // back to queue
    deadline_.async_wait(boost::bind(&Client::check_deadline, this));
  }

  /**
   * @brief Copy async received data.
   *
   * @param ec Received error code
   * @param length Received length
   * @param out_ec Returned error code
   * @param out_length Returned length
   */
  static void handle_receive(const boost::system::error_code& ec, std::size_t length, boost::system::error_code* out_ec,
                             std::size_t* out_length)
  {
    // copy values
    *out_ec = ec;
    *out_length = length;
  }
};

}  // namespace udp_socket
}  // namespace io
}  // namespace cola2
