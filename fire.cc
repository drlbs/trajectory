
// This sets up the initial values for the motion and windows

#include "preamble.h"
#include "prototypes.h"
#include "Motion.h"
#include "Gun.h"


void fire() 
{
   extern vector<Motion> projectile;
   extern Gun cannon;
   int i;

//   for (i=0;i<projectile.size();i++) {
     if (!projectile.back().in_flight()) {
       cannon.fire();
       projectile.back().fire(true);
       projectile.back().set_direction(cannon.get_azimuth());
       projectile.back().set_angle(cannon.get_angle());
       projectile.back().set_V(cannon.get_charge());
       projectile.back().init_motion();
       projectile.back().step();
       updateDisplays();
     }
 //  }

}

