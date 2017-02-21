#include "preamble.h"
#include "Motion.h"
#include "WindowState.h"

#include "prototypes.h"

void updateDisplays(){
   extern vector<Motion> projectile;
   extern WindowState mainWindow;
   extern WindowState targetWindow;
   extern WindowState projectileWindow;
   extern WindowState physicsWindow;
   extern WindowState settingsWindow;
   int i;

   for (i=0;i<projectile.size();i++) { 
      projectile.at(i).check_ground_collision();
//      cout << projectile.at(i).in_flight() << " " <<
 //             projectile.at(i).get_z() << endl;
      if (projectile.at(i).in_flight()) projectile.at(i).step();
      }
 
   glutSetWindow(mainWindow.get_window_context());
   glutPostRedisplay();
   glutSetWindow(targetWindow.get_window_context());
   glutPostRedisplay();
   glutSetWindow(projectileWindow.get_window_context());
   glutPostRedisplay();
   glutSetWindow(physicsWindow.get_window_context());
   glutPostRedisplay();
   glutSetWindow(settingsWindow.get_window_context());
   glutPostRedisplay();
}


