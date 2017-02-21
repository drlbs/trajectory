
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
#include "Motion.h"
#include "WindowState.h"
#include "prototypes.h"

void idle() {
   extern vector<Motion> projectile;
   int i;
  
   for (i=0;i<projectile.size();i++) { 
      projectile.at(i).check_ground_collision();
      if ( projectile.at(i).ground_collision()  ) projectile.at(i).set_z(0.0); 
   }
   updateDisplays();
}

int main(int argc, char** argv) {

   extern WindowState mainWindow;
   extern WindowState targetWindow;
   extern WindowState projectileWindow;
   extern WindowState physicsWindow;
   extern WindowState settingsWindow;

   setup();

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB  );

   mainWindowInit();
   glutInitWindowSize (mainWindow.get_size_x(), mainWindow.get_size_y()); 
   glutInitWindowPosition(mainWindow.get_init_x(), mainWindow.get_init_y());
   mainWindow.set_window_context(glutCreateWindow ((mainWindow.get_window_name()).c_str()));
   glutDisplayFunc(mainWindowDisplay); 
   glutReshapeFunc(mainWindowReshape);
   glutKeyboardFunc(mainWindowNormalKeyboardHandler);
   glutSpecialFunc(mainWindowSpecialKeyboardHandler);

   targetWindowInit();
   glutInitWindowSize (targetWindow.get_size_x(), targetWindow.get_size_y()); 
   glutInitWindowPosition(targetWindow.get_init_x(), targetWindow.get_init_y());
   targetWindow.set_window_context(glutCreateWindow ((targetWindow.get_window_name()).c_str()));
   glutDisplayFunc(targetWindowDisplay); 
   glutReshapeFunc(targetWindowReshape);
   glutSpecialFunc(targetWindowSpecialKeyboardHandler);

   projectileWindowInit();
   glutInitWindowSize (projectileWindow.get_size_x(), projectileWindow.get_size_y()); 
   glutInitWindowPosition(projectileWindow.get_init_x(), projectileWindow.get_init_y());
   projectileWindow.set_window_context(glutCreateWindow ((projectileWindow.get_window_name()).c_str()));
   glutDisplayFunc(projectileWindowDisplay); 
   glutReshapeFunc(projectileWindowReshape);
   
   physicsWindowInit();
   glutInitWindowSize (physicsWindow.get_size_x(), physicsWindow.get_size_y()); 
   glutInitWindowPosition(physicsWindow.get_init_x(), physicsWindow.get_init_y());
   physicsWindow.set_window_context(glutCreateWindow ((physicsWindow.get_window_name()).c_str()));
   glutDisplayFunc(physicsWindowDisplay); 
   glutReshapeFunc(physicsWindowReshape);
   
   settingsWindowInit();
   glutInitWindowSize (settingsWindow.get_size_x(), settingsWindow.get_size_y()); 
   glutInitWindowPosition(settingsWindow.get_init_x(), settingsWindow.get_init_y());
   settingsWindow.set_window_context(glutCreateWindow ((settingsWindow.get_window_name()).c_str()));
   glutReshapeFunc(settingsWindowReshape);
   glutDisplayFunc(settingsWindowDisplay); 
   

   glutIdleFunc(idle);


   glutMainLoop();
   return 0;
}
