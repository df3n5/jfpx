/**
jfpx - A cross platform physics engine using CUDA    
Copyright (C) 2010 Jonathan Frawley

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
#ifndef UNITTEST_TIMEHELPERS_H
#define UNITTEST_TIMEHELPERS_H

#include <sys/time.h>

namespace UnitTest {

class Timer
{
public:
    Timer();
    void Start();
    int GetTimeInMs() const;    

private:
    struct timeval m_startTime;    
};


namespace TimeHelpers
{
void SleepMs (int ms);
}


}

#endif