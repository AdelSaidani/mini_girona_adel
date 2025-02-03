/*
 * Copyright (c) 2020 Iqua Robotics SL - All Rights Reserved
 *
 * This file is subject to the terms and conditions defined in file
 * 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @file
 * @brief This file contains functions and classes related to time division multiplex
 */

#pragma once

#include <chrono>
#include <vector>

namespace cola2
{
namespace utils
{
/**
 * @addtogroup utils
 * @{
 */
namespace tdm
{

std::vector<int> default_slots_ends = { 3, 6 };  //!< Default slots for TDM.

/**
 * @brief Check which slot of the given time division multiplex input vector corresponds to the given time point.
 *
 * @param slots_ends Sorted vector where each value corresponds to the cumulative time of each slot of the time division
 * multiplex.
 * @param epoch Seconds since the epoch.
 * @return index of the current slot.
 * @throw std::runtime_error Runtime error if there are not enough elements in the slots_ends vector.
 */
std::size_t
slot(const std::vector<int>& slots_ends = default_slots_ends,
     const double& epoch = std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count());

/**
 * @brief Check if the return of cola2::utils::tdm::slot corresponds to the input slot.
 *
 * @param slot Slot to check
 * @param slots_ends Used to call cola2::utils::tdm::slot.
 * @param epoch Used to call cola2::utils::tdm::slot.
 * @return cola2::utils::tdm::slot return equals slot.
 * @throw std::runtime_error if slot is >= than slots_ends.size().
 * @throw std::runtime_error Throw according to cola2::utils::tdm::slot.
 */
bool isMySlot(
    const std::size_t slot, const std::vector<int>& slots_ends = default_slots_ends,
    const double& epoch = std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count());

/**
 * @breif Get the epoch at with the next slot starts.
 *
 * @param slot Slot to check
 * @param slots_ends Used to call cola2::utils::tdm::slot.
 * @param epoch Used to call cola2::utils::tdm::slot.
 * @return cola2::utils::tdm::slot return equals slot.
 * @throw std::runtime_error if slot is >= than slots_ends.size().
 * @throw std::runtime_error Throw according to cola2::utils::tdm::slot.
 */
double myNextSlotEpoch(
    const std::size_t slot, const std::vector<int>& slots_ends = default_slots_ends,
    const double& epoch = std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count());

/**
 * @breif Get the seconds to my next slot.
 *
 * @param slot Slot to check
 * @param slots_ends Used to call cola2::utils::tdm::myNextSlotEpoch.
 * @param epoch Used to call cola2::utils::tdm::myNextSlotEpoch.
 * @return Seconds from the given epoch until my next slots starts.
 * @throw std::runtime_error Throw according to cola2::utils::tdm::myNextSlotEpoch.
 */
double secondsToMyNextSlot(
    const std::size_t slot, const std::vector<int>& slots_ends = default_slots_ends,
    const double& epoch = std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count());

}  // namespace tdm
/** @} */
}  // namespace utils
}  // namespace cola2