
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
#include "State.h"
#include "Target.h"
#include "Motion.h"
#include "WindowState.h"
#include "prototypes.h"

void projectileWindowInit(void) 
{

   glClearColor (1.0, 1.0, 1.0, 0.0);
   glLoadIdentity();
   glClear (GL_COLOR_BUFFER_BIT );
}



void projectileWindowDisplay (){
   extern vector<Motion> projectile;
   extern WindowState projectileWindow;

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   glEnable(GL_DEPTH_TEST);
   glLoadIdentity();   // Call this before setting the viewing position 
/*   gluLookAt(projectile.back().get_x(),
             projectile.back().get_y(),
             projectile.back().get_z(),
             projectile.back().get_x()+(projectile.back().get_x()-projectile.back().get_old_x()),
             projectile.back().get_y()+(projectile.back().get_y()-projectile.back().get_old_y()),
             projectile.back().get_z()+(projectile.back().get_z()-projectile.back().get_old_z()),
             projectileWindow.get_lookat_up_x(),
             projectileWindow.get_lookat_up_y(),
             projectileWindow.get_lookat_up_z());
*/

   gluLookAt(projectile.back().get_rotated_x(),
             projectile.back().get_rotated_y(),
             projectile.back().get_rotated_z(),
             projectile.back().get_rotated_x()+(projectile.back().get_rotated_x()-projectile.back().get_rotated_old_x()),
             projectile.back().get_rotated_y()+(projectile.back().get_rotated_y()-projectile.back().get_rotated_old_y()),
             projectile.back().get_rotated_z()+(projectile.back().get_rotated_z()-projectile.back().get_rotated_old_z()),
             projectileWindow.get_lookat_up_x(),
             projectileWindow.get_lookat_up_y(),
             projectileWindow.get_lookat_up_z());
 

   glColor3f(1.0,0.0,0.0);

   drawScene();
         
   glutSwapBuffers();
   glFlush();


}



void projectileWindowReshape (int w, int h)
{

   extern WindowState projectileWindow;
   
   projectileWindow.set_size_x(w);
   projectileWindow.set_size_y(h);

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   if ( (projectileWindow.get_projection()).compare("FRUSTUM") == 0 ) { 
      glFrustum(projectileWindow.get_projection_left(),
                projectileWindow.get_projection_right(),
                projectileWindow.get_projection_bottom(),
                projectileWindow.get_projection_top(),
                projectileWindow.get_projection_near(),
                projectileWindow.get_projection_far());
     }
   else if ( (projectileWindow.get_projection()).compare("PERSPECTIVE") == 0 ) {
      gluPerspective(projectileWindow.get_projection_fovy(),
                     projectileWindow.get_projection_aspect(),
                     projectileWindow.get_projection_near(),
                     projectileWindow.get_projection_far());
    }
   else if ( (projectileWindow.get_projection()).compare("ORTHOGRAPHIC") == 0 ) {
      glOrtho(projectileWindow.get_projection_left(),
              projectileWindow.get_projection_right(),
              projectileWindow.get_projection_bottom(),
              projectileWindow.get_projection_top(),
              projectileWindow.get_projection_near(),
              projectileWindow.get_projection_far());
    }
   else if ( (projectileWindow.get_projection()).compare("ORTHO2D") == 0 ) {
     gluOrtho2D(projectileWindow.get_projection_left(),
               projectileWindow.get_projection_right(),
               projectileWindow.get_projection_bottom(),
               projectileWindow.get_projection_top());
    }

 
   glMatrixMode(GL_MODELVIEW);

}
