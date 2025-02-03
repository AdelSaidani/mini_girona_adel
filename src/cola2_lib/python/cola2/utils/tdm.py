# Copyright (c) 2023 Iqua Robotics SL - All Rights Reserved
#
# This file is subject to the terms and conditions defined in file
# 'LICENSE.txt', which is part of this source code package.

import time


def slot(slot_ends, epoch=None):
    """
    Check which slot of the given time division multiplex input vector corresponds to the given time point.

    :param slot_ends: Sorted vector where each value corresponds to the cumulative time of each slot
        of the time division multiplex.
    :type slot_ends: list(int)
    :param epoch: Seconds since the epoch, defaults to None
    :type epoch: float
    :return: Index of the current slot.
    :raises RuntimeError: Not enough elements in the slots_ends list.
    """
    # Check input.
    if len(slot_ends) < 1:
        raise RuntimeError("TDM needs at least one element.")
    if epoch is None:
        epoch = time.time()

    # Get index.
    num = int(epoch) // slot_ends[-1]
    slot_time = epoch - float(num * slot_ends[-1])
    for i, slot_end in enumerate(slot_ends):
        if slot_time < slot_end:
            return i
    return len(slot_ends)  # not found


def is_my_slot(my_slot, slot_ends=[3, 6], epoch=None):
    """
    Check if the return of cola2:: utils: : tdm: : slot corresponds to the input slot.

    :param my_slot: Slot to check.
    :type my_slot: int
    :param slot_ends: Sorted vector where each value corresponds to the cumulative time of each slot
        of the time division multiplex, defaults to [3, 6]
    :type slot_ends: list(int), optional
    :param epoch: Seconds since the epoch, defaults to None
    :type epoch: float, optional
    :return: Funtion slot() is equal to provide my_slot.
    :rtype: bool
    :raises RuntimeError: Param slot is >= than len(slot_ends).
    :raises RuntimeError: Raises according to cola2.utils.tdm.slot.
    """
    # Check input.
    if len(slot_ends) <= my_slot:
        raise RuntimeError("TDM slot out of slots_ends vector.")

    # Check if it is my slot.
    return slot(slot_ends=slot_ends, epoch=epoch) == my_slot


def my_next_slot_epoch(my_slot, slot_ends=[3, 6], epoch=None):
    """
    Get the epoch at with the next slot starts.

    :param my_slot: Slot to check.
    :type my_slot: int
    :param slot_ends: Used to call cola2.utils.tdm.slot, defaults to [3, 6]
    :type slot_ends: list(int), optional
    :param epoch: Used to call cola2.utils.tdm.slot, defaults to None
    :type epoch: float, optional
    :return: Start epoch of the requested slot.
    :rtype: float
    :raises RuntimeError: Param slot is >= than len(slot_ends).
    :raises RuntimeError: Raises according to cola2.utils.tdm.slot.
    """
    # Check input.
    if len(slot_ends) <= my_slot:
        raise RuntimeError("TDM slot out of slots_ends vector.")
    if epoch is None:
        epoch = time.time()

    # Get current slot.
    current_slot = slot(slot_ends=slot_ends, epoch=epoch)

    # Get number of times the cycle is done for the given epoch.
    num = int(epoch) // slot_ends[-1]

    # Compute the epoch of the cycle start for the given number.
    next_epoch_0 = num * slot_ends[-1]
    if current_slot >= my_slot:
        # If my slot is passed, add another lap.
        next_epoch_0 += slot_ends[-1]

    # Compute the epoch.
    time_from_lap_start = slot_ends[my_slot - 1] if my_slot > 0 else 0
    return next_epoch_0 + time_from_lap_start


def seconds_to_my_next_slot(my_slot, slot_ends=[3, 6], epoch=None):
    """
    Get the seconds to my next slot.

    :param my_slot: Slot to check.
    :type my_slot: int
    :param slot_ends: Used to call cola2.utils.tdm.my_next_slot_epoch, defaults to [3, 6]
    :type slot_ends: list(int), optional
    :param epoch: Used to call cola2.utils.tdm.my_next_slot_epoch, defaults to None
    :type epoch: float, optional
    :return: Seconds from the given epoch until my next slots starts.
    :rtype: float
    :raises RuntimeError: Raises according to cola2.utils.tdm.seconds_to_my_next_slot.
    """
    # Check input.
    if epoch is None:
        epoch = time.time()
    return my_next_slot_epoch(my_slot, slot_ends, epoch) - epoch
