/*
 * Copyright (c) 2020 Iqua Robotics SL - All Rights Reserved
 *
 * This file is subject to the terms and conditions defined in file
 * 'LICENSE.txt', which is part of this source code package.
 */

#include "cola2_lib/utils/tdm.h"

#include <algorithm>
#include <stdexcept>

std::size_t cola2::utils::tdm::slot(const std::vector<int>& slots_ends, const double& epoch)
{
  // Check input
  if (slots_ends.size() < 1)
    throw std::runtime_error("TDM needs at least one element.");

  // Get index.
  int num = static_cast<int>(epoch) / slots_ends.back();
  const double slot_time = epoch - num * slots_ends.back();
  return std::upper_bound(slots_ends.begin(), slots_ends.end(), slot_time) - slots_ends.begin();
}

bool cola2::utils::tdm::isMySlot(const std::size_t my_slot, const std::vector<int>& slots_ends, const double& epoch)
{
  // Check input.
  if (slots_ends.size() <= my_slot)
    throw std::runtime_error("TDM slot out of slots_ends vector.");

  // Check if it is my slot.
  return slot(slots_ends, epoch) == my_slot;
}

double cola2::utils::tdm::myNextSlotEpoch(const std::size_t my_slot, const std::vector<int>& slots_ends,
                                          const double& epoch)
{
  // Check input.
  if (slots_ends.size() <= my_slot)
    throw std::runtime_error("TDM slot out of slots_ends vector.");

  // Get current slot.
  std::size_t current_slot = slot(slots_ends, epoch);

  // Get number of times the cycle is done for the given epoch.
  int num = static_cast<int>(epoch) / slots_ends.back();

  // Compute the epoch of the cycle start for the given number.
  double next_epoch_0 = num * slots_ends.back();
  if (current_slot >= my_slot)
  {
    // If my slot is passed, add another lap.
    next_epoch_0 += slots_ends.back();
  }

  // Compute the epoch.
  return next_epoch_0 + (my_slot > 0 ? slots_ends[my_slot - 1] : 0);
}

double cola2::utils::tdm::secondsToMyNextSlot(const std::size_t my_slot, const std::vector<int>& slots_ends,
                                              const double& epoch)
{
  return myNextSlotEpoch(my_slot, slots_ends, epoch) - epoch;
}