
// This sets up the initial values for the motion and windows

#include "preamble.h"
#include "State.h"
#include "Target.h"
#include "Motion.h"
#include "WindowState.h"
#include "Gun.h"


void loadProjectile(void) 
{
   extern vector<Motion> projectile;
   Motion chamber = Motion(); 
   extern Gun cannon;

/* S E T   P R O J E C T I L E   P H Y S I C A L    P A R A M E T E R S  */
   if (!cannon.cannon_loaded()) {
     projectile.push_back(chamber);
     cout << projectile.size() << endl;
     cannon.load();
   }

}

