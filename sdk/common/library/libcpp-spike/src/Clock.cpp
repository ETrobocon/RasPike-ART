//
// Clock.cpp
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#include "Clock.h"
using namespace spikeapi;


//=============================================================================
// Constructor
Clock::Clock(void)
:mStartClock(getTim())
{}

//=============================================================================
// reset system tick to 0
void Clock::reset(void)
{
    mStartClock = getTim();
}

//=============================================================================
// get tick after app began
uint64_t Clock::now(void) const
{
    return (getTim() - mStartClock);
}

uint64_t Clock::getTim()
{
    SYSTIM time;
    get_tim(&time);
    // We're using a 64-bitter and can assume that we
    // don't need to do any locking here.
    return static_cast<uint64_t>(time);
}
