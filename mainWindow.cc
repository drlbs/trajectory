// This file contains all of the information for the Main Window

#include "preamble.h"
#include "prototypes.h"
#include "State.h"
#include "Target.h"
#include "Gun.h"
#include "Motion.h"
#include "WindowState.h"


void mainWindowInit(void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0);
   glLoadIdentity();
   glClear (GL_COLOR_BUFFER_BIT );
}


void mainWindowDisplay (){
   extern vector<Motion> projectile;
   extern WindowState mainWindow;
   extern Target target[];
   extern Gun cannon;

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   glEnable(GL_DEPTH_TEST);
   glLoadIdentity();   // Call this before setting the viewing position 
/*   gluLookAt(mainWindow.get_lookat_eye_x(),
             mainWindow.get_lookat_eye_y(),
             mainWindow.get_lookat_eye_z(),
             mainWindow.get_lookat_center_x()*sin(cannon.get_azimuth()*M_PI/180.0),
             mainWindow.get_lookat_center_y()*cos(cannon.get_azimuth()*M_PI/180.0),
             mainWindow.get_lookat_center_z(),
             mainWindow.get_lookat_up_x(),
             mainWindow.get_lookat_up_y(),
             mainWindow.get_lookat_up_z());
*/

   gluLookAt(mainWindow.get_lookat_eye_x(),
             mainWindow.get_lookat_eye_y(),
             mainWindow.get_lookat_eye_z(),
             1000.0*sin(cannon.get_azimuth()*M_PI/180.0),
             1000.0*cos(cannon.get_azimuth()*M_PI/180.0),
             mainWindow.get_lookat_center_z(),
             mainWindow.get_lookat_up_x(),
             mainWindow.get_lookat_up_y(),
             mainWindow.get_lookat_up_z());

 //  cout << mainWindow.get_lookat_center_x()*sin(cannon.get_azimuth()*M_PI/180.0) << endl; 
              
   drawScene();

   glutSwapBuffers();
   glFlush();
}

void mainWindowReshape (int w, int h)
{
   extern WindowState mainWindow;

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
//   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 10000.0);
//   glOrtho(-200.0, 200.0, -20.0, 400.0, -1.0, 10000.0);
//   glFrustum(-10.0, 10.0, 0.0, 30.0, 10.0, 1000.0);

// Note on string comparisons.  The "compare" from the STL returns 0 if strings are equal

   if ( (mainWindow.get_projection()).compare("FRUSTUM") == 0 ) { 
      glFrustum(mainWindow.get_projection_left(),
                mainWindow.get_projection_right(),
                mainWindow.get_projection_bottom(),
                mainWindow.get_projection_top(),
                mainWindow.get_projection_near(),
                mainWindow.get_projection_far());
     }
   else if ( (mainWindow.get_projection()).compare("PERSPECTIVE") == 0 ) {
      gluPerspective(mainWindow.get_projection_fovy(),
                     mainWindow.get_projection_aspect(),
                     mainWindow.get_projection_near(),
                     mainWindow.get_projection_far());
    }
   else if ( (mainWindow.get_projection()).compare("ORTHOGRAPHIC") == 0 ) {
      glOrtho(mainWindow.get_projection_left(),
              mainWindow.get_projection_right(),
              mainWindow.get_projection_bottom(),
              mainWindow.get_projection_top(),
              mainWindow.get_projection_near(),
              mainWindow.get_projection_far());
    }
   else if ( (mainWindow.get_projection()).compare("ORTHO2D") == 0 ) {
     gluOrtho2D(mainWindow.get_projection_left(),
               mainWindow.get_projection_right(),
               mainWindow.get_projection_bottom(),
               mainWindow.get_projection_top());
    }

 
   glMatrixMode(GL_MODELVIEW);
}

// Keyboard handler for special keys
void mainWindowSpecialKeyboardHandler(int key, int x, int y){
   extern Gun cannon;

   if ( key ==  GLUT_KEY_RIGHT   ) {
     cannon.add_azimuth(); 
     }
   else if  ( key ==  GLUT_KEY_LEFT   ) {
     cannon.minus_azimuth(); 
     }
   else if  ( key ==  GLUT_KEY_UP   ) {
     cannon.add_angle(); 
     }
   else if  ( key ==  GLUT_KEY_DOWN   ) {
     cannon.minus_angle(); 
     }
   else if  ( key ==  GLUT_KEY_PAGE_UP   ) {
     cannon.add_charge(); 
     }
   else if  ( key ==  GLUT_KEY_PAGE_DOWN   ) {
     cannon.minus_charge(); 
     }
   updateDisplays();
}


void mainWindowNormalKeyboardHandler(unsigned char key, int x, int y){
   if ( key == ' '   ) {
     //resetMotion(); 
     fire(); 
     }
   else if ( key == 'l' ) {
     loadProjectile();
     }
   else if ( key == 'q' ) {
     exit(0);
     }
   updateDisplays();
}
