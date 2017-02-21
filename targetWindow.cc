
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
#include "Target.h"
#include "Motion.h"
#include "WindowState.h"
#include "Gun.h"


void targetWindowDisplay (){
   extern WindowState targetWindow;
   extern Target target[];
   extern Gun cannon;

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   glEnable(GL_DEPTH_TEST);
   glLoadIdentity();   // Call this before setting the viewing position 
/*   gluLookAt(targetWindow.get_lookat_eye_x(),
             targetWindow.get_lookat_eye_y(),
             targetWindow.get_lookat_eye_z(),
             targetWindow.get_lookat_center_x(),
             targetWindow.get_lookat_center_y(),
             targetWindow.get_lookat_center_z(),
             targetWindow.get_lookat_up_x(),
             targetWindow.get_lookat_up_y(),
             targetWindow.get_lookat_up_z());
*/

   gluLookAt(cannon.get_binoculars_short()*sin(cannon.get_azimuth()*M_PI/180.0),
             cannon.get_binoculars_short()*cos(cannon.get_azimuth()*M_PI/180.0),
             targetWindow.get_lookat_eye_z(),
             cannon.get_binoculars_long()*sin(cannon.get_azimuth()*M_PI/180.0),
             cannon.get_binoculars_long()*cos(cannon.get_azimuth()*M_PI/180.0),
             targetWindow.get_lookat_center_z(),
             targetWindow.get_lookat_up_x(),
             targetWindow.get_lookat_up_y(),
             targetWindow.get_lookat_up_z());
 

   drawScene();
   
   glutSwapBuffers();
   glFlush();


}


void targetWindowInit(void) 
{

   glClearColor (1.0, 1.0, 1.0, 0.0);
   glLoadIdentity();
   glClear (GL_COLOR_BUFFER_BIT );
}

void targetWindowReshape (int w, int h)
{
   extern WindowState targetWindow;

   targetWindow.set_size_x(w);
   targetWindow.set_size_y(h);

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   if ( (targetWindow.get_projection()).compare("FRUSTUM") == 0 ) { 
      glFrustum(targetWindow.get_projection_left(),
                targetWindow.get_projection_right(),
                targetWindow.get_projection_bottom(),
                targetWindow.get_projection_top(),
                targetWindow.get_projection_near(),
                targetWindow.get_projection_far());
     }
   else if ( (targetWindow.get_projection()).compare("PERSPECTIVE") == 0 ) {
      gluPerspective(targetWindow.get_projection_fovy(),
                     targetWindow.get_projection_aspect(),
                     targetWindow.get_projection_near(),
                     targetWindow.get_projection_far());
    }
   else if ( (targetWindow.get_projection()).compare("ORTHOGRAPHIC") == 0 ) {
      glOrtho(targetWindow.get_projection_left(),
              targetWindow.get_projection_right(),
              targetWindow.get_projection_bottom(),
              targetWindow.get_projection_top(),
              targetWindow.get_projection_near(),
              targetWindow.get_projection_far());
    }
   else if ( (targetWindow.get_projection()).compare("ORTHO2D") == 0 ) {
     gluOrtho2D(targetWindow.get_projection_left(),
               targetWindow.get_projection_right(),
               targetWindow.get_projection_bottom(),
               targetWindow.get_projection_top());
    }

 
   glMatrixMode(GL_MODELVIEW);
}


// Keyboard handler for special keys
void targetWindowSpecialKeyboardHandler(int key, int x, int y){
   extern Gun cannon;

   if  ( key ==  GLUT_KEY_UP   ) {
     cannon.add_binoculars(); 
     }
   else if  ( key ==  GLUT_KEY_DOWN   ) {
     cannon.minus_binoculars(); 
     }
   updateDisplays();
}
