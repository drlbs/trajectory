
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
#include "Target.h"
#include "Gun.h"
#include "WindowState.h"

void settingsWindowInit(void) 
{

   glClearColor (1.0, 1.0, 1.0, 0.0);
   glLoadIdentity();
   glClear (GL_COLOR_BUFFER_BIT );
}

void settingsWindowReshape (int w, int h)
{
   extern WindowState settingsWindow;

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();

// Note on string comparisons.  The "compare" from the STL returns 0 if strings are equal

   if ( (settingsWindow.get_projection()).compare("FRUSTUM") == 0 ) { 
      glFrustum(settingsWindow.get_projection_left(),
                settingsWindow.get_projection_right(),
                settingsWindow.get_projection_bottom(),
                settingsWindow.get_projection_top(),
                settingsWindow.get_projection_near(),
                settingsWindow.get_projection_far());
     }
   else if ( (settingsWindow.get_projection()).compare("PERSPECTIVE") == 0 ) {
      gluPerspective(settingsWindow.get_projection_fovy(),
                     settingsWindow.get_projection_aspect(),
                     settingsWindow.get_projection_near(),
                     settingsWindow.get_projection_far());
    }
   else if ( (settingsWindow.get_projection()).compare("ORTHOGRAPHIC") == 0 ) {
      glOrtho(settingsWindow.get_projection_left(),
              settingsWindow.get_projection_right(),
              settingsWindow.get_projection_bottom(),
              settingsWindow.get_projection_top(),
              settingsWindow.get_projection_near(),
              settingsWindow.get_projection_far());
    }
   else if ( (settingsWindow.get_projection()).compare("ORTHO2D") == 0 ) {
     gluOrtho2D(settingsWindow.get_projection_left(),
               settingsWindow.get_projection_right(),
               settingsWindow.get_projection_bottom(),
               settingsWindow.get_projection_top());
    }

 
   glMatrixMode(GL_MODELVIEW);
}

void settingsWindowDisplay (){
   extern WindowState targetWindow;
   extern Target target[];
   extern Gun cannon;
   string s;
   char c[100];
 
   void *font = GLUT_BITMAP_TIMES_ROMAN_24;

   glClear (GL_COLOR_BUFFER_BIT  );
   

   glColor3f(1.0,1.0,0.0); 
   s = "Fire Control Settings";
   renderBitmapString(-.8,0.8,font,s);

   font = GLUT_BITMAP_HELVETICA_18;
   glColor3f(0.0,1.0,1.0); 
   s = "Angle     :";
   renderBitmapString(-1.0,0.6,font,s);
   glColor3f(0.0,1.0,1.0); 
   s = "Direction :";
   renderBitmapString(-1.0,0.4,font,s);
   glColor3f(0.0,1.0,1.0); 
   s = "Charge    :";
   renderBitmapString(-1.0,0.2,font,s);
  
   sprintf ( c, " %4.1f", cannon.get_angle() );
   renderBitmapString(0.0,0.6,font,c);
   sprintf ( c, " %4.1f", cannon.get_azimuth() );
   renderBitmapString(0.0,0.4,font,c);
   sprintf ( c, " %.0f", cannon.get_charge() );
   renderBitmapString(0.0,0.2,font,c);

   s = "Cannon is :";
   renderBitmapString(-1.0,-0.2,font,s);

   if (cannon.cannon_loaded()) {
       glColor3f(1.0,0.0,0.0); 
       s = "LOADED";
       renderBitmapString(0.0,-0.2,font,s);
     }
   else {
       glColor3f(0.0,1.0,0.0); 
       s = "UNLOADED"; 
       renderBitmapString(0.0,-0.2,font,s);
     }

   glutSwapBuffers();
   glFlush();

}
