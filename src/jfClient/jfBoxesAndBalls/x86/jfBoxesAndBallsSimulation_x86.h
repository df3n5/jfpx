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
#ifndef JFBOXESANDBALLSSIMULATION_H
#define JFBOXESANDBALLSSIMULATION_H
#include <jfSimulation/jfSimulation.h>
#include <jfEvent/jfEvent.h>
#include <jfClient/jfBoxesAndBalls/x86/jfBoxesAndBallsEventHandler_x86.h>
#include <jfClient/jfBoxesAndBalls/x86/jfBoxesAndBalls3DGraphicsHandler_x86.h>
#include <jfGraphics/jfWindowManager/jfWindowManager.h>
#include <jfGraphics/jfWindowManager/jfSDL/jfSDL.h>
#include <jfGraphics/jf3DGraphics/jf3DGraphicsHandler.h>
#include <jfGraphics/jf3DGraphics/jfSDLGL/jfSDLGL3DGraphicsHandler.h>

#include <jfTimer/jfTimer.h>

#define PERF_TIMING

#ifdef PERF_TIMING
#include <jfTimer/jfPerformanceTimer.h>

static const char* timingFilename = "CollisionDetectionTimes.csv";
#endif

#include <jfpx/jfCollisionData.h>
#include <jfpx/x86/jfContactResolver_x86.h>
#include <jfpx/x86/jfCollisionDetector_x86.h>
#include <jfpx/x86/jfCollisionPlane_x86.h>

#include <jfpx/x86/jfFactory_x86.h>
#include <jfShape/x86/jfShapeFactory_x86.h>

#include <jfpx/cuda/jfCudaConstants.h>

#include <jfLog/jfLog.h>

//#include <sys/time.h>

#include <vector>
using namespace std;

class jfBoxesAndBallsSimulation_x86 : public jfSimulation
{
	public:
		jfBoxesAndBallsSimulation_x86();
		virtual ~jfBoxesAndBallsSimulation_x86();
		virtual bool init();
		virtual void run();
        virtual void fire();
		void updateObjects(jfReal timeStep);
		void generateContacts();
		void drawDebug();
    protected:
		//Constants
        const static unsigned m_MaxBoxes = 0;
        const static unsigned m_MaxBalls = N_SPHERES;
        const static unsigned m_MaxContacts = (m_MaxBalls + m_MaxBoxes) * 8;
		const static bool m_RenderDebugInfo = false;

        jfBoxesAndBallsEventHandler_x86* m_EventHandler;
        jfWindowManager* m_WindowManager;
        jfBoxesAndBalls3DGraphicsHandler_x86* m_3DGraphicsHandler;
        jfTimer* m_Timer;
        int m_LastFrameDuration;

        //Collision Objects
        vector<jfBall*> m_Balls;
        vector<jfBox*> m_Boxes;
        jfCollisionPlane* m_Plane;

        bool m_MousePressedLast;
		//vector<jfContact*> m_Contacts;
		//Collision data
		jfCollisionData* m_CollisionData;
		jfContactResolver* m_ContactResolver;
		jfCollisionDetector* m_CollisionDetector;
		//Factories
		jfFactory* m_PhysicsFactory;
		jfShapeFactory* m_ShapeFactory;

        jfFPSCamera* m_Cam;

        //timeval t1, t2;
        double m_ElapsedTime;
#ifdef PERF_TIMING
        jfPerformanceTimer* m_PerformanceTimer;
#endif
};

#endif //JFBOXESANDBALLSSIMULATION_H

