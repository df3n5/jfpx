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
#ifndef JFFORCEREGISTRY_H
#define JFFORCEREGISTRY_H

#include <jfpx/jfForceGenerator.h>
#include <jfpx/jfRigidBody.h>

#include <vector>
using namespace std;

/*-----------------------------------------------------------------------------
 *  Struct to hold body and forceGen duo
 *-----------------------------------------------------------------------------*/
typedef struct jfBodyForceGen {
    jfRigidBody* body;
    jfForceGenerator* forceGen;
} jfBodyForceGen;

class jfForceRegistry {
public:
    jfForceRegistry();
    virtual ~jfForceRegistry();

    /*-----------------------------------------------------------------------------
		*  Interface
		*-----------------------------------------------------------------------------*/
    virtual void add(jfRigidBody* body, jfForceGenerator* forceGen) = 0;
    virtual void remove(jfRigidBody* body, jfForceGenerator* forceGen) = 0;
    virtual void clear() = 0;
    virtual void updateForces(jfReal timeStep) = 0;

    /*-----------------------------------------------------------------------------
		 *  Getters and Setters
		 *-----------------------------------------------------------------------------*/
    vector<jfBodyForceGen> getForceGens() { return m_BodyForceGens; }

protected:
    vector<jfBodyForceGen> m_BodyForceGens;

private:
};

#endif // JFFORCEREGISTRY_H
