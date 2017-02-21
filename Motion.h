#include "preamble.h"

class Motion {
     // Variables specific to the motion of the projectile
     public:
         Motion();
         
         void step();
         void set_x(double x ){ this->x = x; };  
         void set_y(double y ){ this->y = y; };
         void set_z(double z ){ this->z = z; };
         void set_t(double t ){ this->t = t; };
         void set_V(double V ){ this->V = V; };
         void set_angle(double angle){ this->angle = angle; };
         void set_G(double G){ this->G = G; };
         void set_C(double C){ this->C = C; };
         double get_x(){ return x; };
         double get_y(){ return y; };
         double get_z(){ return z; };
         double get_t(){ return t; };
         double get_angle(){ return angle; };
         double get_old_x(){ return old_x; };
         double get_old_y(){ return old_y; };
         double get_old_z(){ return old_z; };
         double get_rotated_x(){ return rotated_x; };
         double get_rotated_y(){ return rotated_y; };
         double get_rotated_z(){ return rotated_z; };
         double get_rotated_old_x(){ return rotated_old_x; };
         double get_rotated_old_y(){ return rotated_old_y; };
         double get_rotated_old_z(){ return rotated_old_z; };
         void init_motion(){
               p = V*cos(angle*M_PI/180.0);
               q = V*sin(angle*M_PI/180.0);
               onGround = false;
               inFlight = true;
               };
         void set_ground_collision( bool onGround ) { this->onGround = onGround; };
         void check_ground_collision() { 
             if ( z <= 0.0 ) {
                this->onGround = true;
                }
             else {
                this->onGround = false;
                }
             };
         bool ground_collision() { return onGround; };
         bool in_flight() { return inFlight; };
         void set_inflight( bool inFlight ) { this->inFlight = inFlight; };
         void rotate();
         double get_direction() { return direction; };
         void set_direction( double direction ) { this->direction = direction; };
         void fire( bool projectile_fired ) { this->projectile_fired = true; };
         bool fired() { return projectile_fired; };
     private:
         double f(double, double, double);  
         double g(double, double, double, double); 
         double t;
         double x;
         double y;
         double z;
         double old_x;
         double old_y;
         double old_z;
         double p;
         double q; 
         double V;       // Velocity            (ft/sec)
         double angle;   // Angle of Gun above azimuth  (degrees)
         double G;       // Acceleration due to Graviey (ft/sec^2)
         double C;       // Coefficient of friction due to air
         bool   onGround; // True if the projectile breaks the ground plane
         bool   inFlight; // True if the projectile has been fired but is not on the ground 
         double rotated_x;
         double rotated_y;
         double rotated_z;
         double rotated_old_x;
         double rotated_old_y;
         double rotated_old_z;
         void vmatm();
         double rotate_z_matrix[3][3];
         double in_vector[3];
         double out_vector[3];
         double direction;
         bool   projectile_fired;
};


