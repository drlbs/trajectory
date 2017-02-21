
//
// Projectile Calculations Using Fourth-Order Runge-Kutta Method
//   Includes frictional drag and gravity, but no crosswind calculation
//   
//   Andrew J. Pounds, Ph.D.
//   Department of Computer Science
//   Mercer University
//   Spring 2006
//

#include "preamble.h"
#include "prototypes.h"
#include "State.h"
#include "Motion.h"
#include "WindowState.h"
#include "Gun.h"
#include "Target.h"


void physicsWindowInit(void) 
{

   glClearColor (1.0, 1.0, 1.0, 0.0);
   glLoadIdentity();
   glClear (GL_COLOR_BUFFER_BIT );
}

void physicsWindowReshape (int w, int h)
{
   extern WindowState physicsWindow;

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
//   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 10000.0);
//   glOrtho(-200.0, 200.0, -20.0, 400.0, -1.0, 10000.0);
//   glFrustum(-10.0, 10.0, 0.0, 30.0, 10.0, 1000.0);

// Note on string comparisons.  The "compare" from the STL returns 0 if strings are equal

   if ( (physicsWindow.get_projection()).compare("FRUSTUM") == 0 ) { 
      glFrustum(physicsWindow.get_projection_left(),
                physicsWindow.get_projection_right(),
                physicsWindow.get_projection_bottom(),
                physicsWindow.get_projection_top(),
                physicsWindow.get_projection_near(),
                physicsWindow.get_projection_far());
     }
   else if ( (physicsWindow.get_projection()).compare("PERSPECTIVE") == 0 ) {
      gluPerspective(physicsWindow.get_projection_fovy(),
                     physicsWindow.get_projection_aspect(),
                     physicsWindow.get_projection_near(),
                     physicsWindow.get_projection_far());
    }
   else if ( (physicsWindow.get_projection()).compare("ORTHOGRAPHIC") == 0 ) {
      glOrtho(physicsWindow.get_projection_left(),
              physicsWindow.get_projection_right(),
              physicsWindow.get_projection_bottom(),
              physicsWindow.get_projection_top(),
              physicsWindow.get_projection_near(),
              physicsWindow.get_projection_far());
    }
   else if ( (physicsWindow.get_projection()).compare("ORTHO2D") == 0 ) {
     gluOrtho2D(physicsWindow.get_projection_left(),
               physicsWindow.get_projection_right(),
               physicsWindow.get_projection_bottom(),
               physicsWindow.get_projection_top());
    }

 
   glMatrixMode(GL_MODELVIEW);
}


void physicsWindowDisplay (){
   extern vector<Motion> projectile;
   extern WindowState physicsWindow;
   extern Target target[];
   extern Gun cannon;

   glClear ( GL_DEPTH_BUFFER_BIT );
   glEnable(GL_DEPTH_TEST);
   glLoadIdentity();   // Call this before setting the viewing position 
   gluLookAt(physicsWindow.get_lookat_eye_x(),
             physicsWindow.get_lookat_eye_y(),
             physicsWindow.get_lookat_eye_z(),
             physicsWindow.get_lookat_center_x(),
             physicsWindow.get_lookat_center_y(),
             physicsWindow.get_lookat_center_z(),
             physicsWindow.get_lookat_up_x(),
             physicsWindow.get_lookat_up_y(),
             physicsWindow.get_lookat_up_z());

 //  cout << physicWindow.get_lookat_center_x()*sin(cannon.get_azimuth()*M_PI/180.0) << endl; 
              
   drawScene2();

   glutSwapBuffers();
   glFlush();
}
