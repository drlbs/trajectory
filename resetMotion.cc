
// This sets the projectile back to its initial position

#include "preamble.h"
#include "Motion.h"


void resetMotion(){
   extern vector<Motion> projectile;
  
   projectile.back().set_x(0.0);
   projectile.back().set_y(0.0);
   projectile.back().set_z(0.0);
   projectile.back().set_t(0.0);
   projectile.back().init_motion();

}


