
// This sets up the initial values for the motion and windows

#include "preamble.h"
#include "State.h"
#include "Target.h"
#include "Motion.h"
#include "WindowState.h"


void setup(void) 
{
   extern vector<Motion> projectile;
   extern WindowState mainWindow;
   extern WindowState targetWindow;
   extern WindowState projectileWindow;
   extern WindowState physicsWindow;
   extern WindowState settingsWindow;

   extern Target target[];

   extern State state;

/* S E T  V A L U E   O F  "H"  F O R   R U N G E -- K U T T A  M E T H O D */

   state.set_h(0.05);

/* S E T   P R O J E C T I L E   P H Y S I C A L    P A R A M E T E R S  */

   projectile.resize(1);
   projectile.back() = Motion();
//   projectile.set_V(1750.0);
//   projectile.set_angle(55.0);
   projectile.back().set_direction(20.0);
   projectile.back().set_V(1750.0);
   projectile.back().set_angle(4.0);
//   projectile.back().init_motion();

/* S E T   T A R G E T  P A R A M E T E R S  */

// Cozart
   target[0].set_x(-1000.0);
   target[0].set_y(1000.0);
   target[0].set_z(0.0);

// Allen
   target[1].set_x(-600.0);
   target[1].set_y(1000.0);
   target[1].set_z(0.0);
  
// Pounds 
   target[2].set_x(-300.0);
   target[2].set_y(1000.0);
   target[2].set_z(0.0);
  
// White 
   target[3].set_x(0.0);
   target[3].set_y(1000.0);
   target[3].set_z(0.0);
  
// Eason 
   target[4].set_x(300.0);
   target[4].set_y(1000.0);
   target[4].set_z(0.0);
  
// Digh 
   target[5].set_x(600.0);
   target[5].set_y(1000.0);
   target[5].set_z(0.0);
  
// Zhou 
   target[6].set_x(1000.0);
   target[6].set_y(1000.0);
   target[6].set_z(0.0);


/* S E T U P   M A I N   W I N D O W  */

   mainWindow.set_window_name("Cannon View");
   mainWindow.set_size(500,500);
   mainWindow.set_init_xy(0,100);
   mainWindow.set_projection("PERSPECTIVE");
   mainWindow.set_perspective(60.0, 
                              (float) mainWindow.get_size_x() / (float) mainWindow.get_size_y(),
                              10.0,  10000.0 );
   mainWindow.set_lookat(0.0,-10.0,1.0,0.0,0.0,0.0,0.0,0.0,1.0); 

/* S E T U P   T A R G E T   W I N D O W  */

   targetWindow.set_window_name("Target View");
   targetWindow.set_size(240,240);
   targetWindow.set_init_xy(510,370);
   targetWindow.set_projection("PERSPECTIVE");
   targetWindow.set_perspective(60.0, 
                              (float) targetWindow.get_size_x() / (float) targetWindow.get_size_y(),
                              10.0,  10000.0 );
   targetWindow.set_lookat(0.0,800.0,1.0,0.0,1000.0,0.0,0.0,0.0,1.0); 

/* S E T U P   P R O J E C T I L E   W I N D O W  */

   projectileWindow.set_window_name("Projectile View");
   projectileWindow.set_size(240,240);
   projectileWindow.set_init_xy(510,100);
   projectileWindow.set_projection("PERSPECTIVE");
   projectileWindow.set_perspective(60.0, 
                              (float) projectileWindow.get_size_x() / (float) projectileWindow.get_size_y(),
                              10.0,  10000.0 );
   projectileWindow.set_lookat(projectile.back().get_x(), projectile.back().get_y(), projectile.back().get_z(),
                               0.0,
                               cos(projectile.back().get_angle()*M_PI/180.0), 
                               sin(projectile.back().get_angle()*M_PI/180.0),
                               0.0,0.0,1.0);



/* S E T U P   P H Y S I C S   W I N D O W  */

   physicsWindow.set_window_name("Coordinate Space");
   physicsWindow.set_size(240,240);
   physicsWindow.set_init_xy(760,370);
   
   physicsWindow.set_projection("PERSPECTIVE");
   physicsWindow.set_perspective(60.0, 
                              (float) physicsWindow.get_size_x() / (float) physicsWindow.get_size_y(),
                              10.0,  10000.0 );
   physicsWindow.set_lookat(1000.0,0.0,800.0,500.0,1000.0,0.0,0.0,0.0,1.0); 

/* S E T U P    S E T T I N G S    W I N D O W  */

   settingsWindow.set_window_name("Settings");
   settingsWindow.set_size(240,240);
   settingsWindow.set_init_xy(760,100);
   settingsWindow.set_projection("ORTHO2D");
   settingsWindow.set_perspective(0.0,100.0,0.0,100.0); 
   
}

