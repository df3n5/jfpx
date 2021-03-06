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
#include "UnitTest++.h"

#include <jfpx/x86/jfAeroControlForceGenerator_x86.h>

#include <iostream>
#include <vector>
using namespace std;

namespace
{
    TEST(CreationDeletion)
    {
        jfAeroControlForceGenerator_x86* aeroControlForceGen = new jfAeroControlForceGenerator_x86();
        delete aeroControlForceGen;
    }
}
