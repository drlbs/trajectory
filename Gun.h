#include "preamble.h"

class Gun {
     // Variables specific to the motion of the projectile
     public:
         Gun();
         
         void set_angle(double);
         void set_azimuth(double);
         void set_charge(double);

         double get_angle() { return angle; };
         double get_azimuth() { return azimuth;};
         double get_charge() { return charge; };
         double get_binoculars_short() { return binoculars_short; };
         double get_binoculars_long()  { return binoculars_long; };

         void add_angle();
         void add_azimuth();
         void add_charge();
         void minus_angle();
         void minus_azimuth();
         void minus_charge();

         void add_binoculars();
         void minus_binoculars();
         
         void load() { loaded = true; };
         void fire() { loaded = false; };
         bool cannon_loaded() { return loaded; };

     private:
         double angle;   // Up angle
         double azimuth; // Side Angle
         double charge;  // Sets the initial charge (initial velocity)
         double binoculars_short;
         double binoculars_long;
         bool   loaded;
};


