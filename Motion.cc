#include "preamble.h"
#include "Motion.h"
#include "State.h"


Motion :: Motion() {

/* Default Constructor */

         t = 0.0;
         x = 0.0;
         y = 0.0;
         z = 0.0;
         p = 0.0;
         q = 0.0; 
         V = 1000.0;       
         angle = 30.0;   
         G = 32.0;       
         C = 0.0025;       
         onGround = true;
         inFlight = false;
         projectile_fired = false;

}

double Motion :: f ( double p, double q, double C ){
// Function for motion in horizontal direction
	return -C*p*sqrt(pow(p,2)+pow(q,2));
    }

double Motion ::  g ( double p, double q, double C, double G){
// Function for motion in vertical direction
    return -C*q*sqrt(pow(p,2)+pow(q,2))-G;
    }

void Motion :: step() {

double f1, f2, f3, f4;
double g1, g2, g3, g4;
double dp, dq;
extern State state;

  if (!onGround) {
     // Begin Runge-Kutta Method Here for Systems
   	f1 = f(p,q,C);
	g1 = g(p,q,C,G);
	f2 = f(p+state.get_h()*f1/2,q+state.get_h()*g1/2,C);
	g2 = g(p+state.get_h()*f1/2,q+state.get_h()*g1/2,C,G); 
	f3 = f(p+state.get_h()*f2/2,q+state.get_h()*g2/2,C);
	g3 = g(p+state.get_h()*f2/2,q+state.get_h()*g2/2,C,G); 
	f4 = f(p+state.get_h()*f3,q+state.get_h()*g3,C); 
	g4 = g(p+state.get_h()*f3,q+state.get_h()*g3,C,G); 
	dp = (f1 + 2*f2 + 2*f3 + f4 ) / 6.0;
	dq = (g1 + 2*g2 + 2*g3 + g4 ) / 6.0;
        old_x = x;
        old_y = y;
        old_z = z;
	y = y + p*state.get_h() + 0.5*dp*state.get_h()*state.get_h(); 
	z = z + q*state.get_h() + 0.5*dq*state.get_h()*state.get_h(); 
	p = p + dp*state.get_h();
	q = q + dq*state.get_h();
	t = t + state.get_h();
    rotate();
  }
}

void Motion :: rotate() {


// Rotation Matrix for Rotating Coordinates About Z-Axis
rotate_z_matrix[0][0] = cos(direction*M_PI/180.0);
rotate_z_matrix[0][1] = -sin(direction*M_PI/180.0);
rotate_z_matrix[0][2] = 0.0; 
rotate_z_matrix[1][0] = sin(direction*M_PI/180.0);
rotate_z_matrix[1][1] = cos(direction*M_PI/180.0);
rotate_z_matrix[1][2] = 0.0; 
rotate_z_matrix[2][0] = 0.0;
rotate_z_matrix[2][1] = 0.0;
rotate_z_matrix[2][2] = 1.0; 

in_vector[0] = x;
in_vector[1] = y;
in_vector[2] = z;

vmatm();

rotated_x = out_vector[0];
rotated_y = out_vector[1];
rotated_z = out_vector[2];

in_vector[0] = old_x;
in_vector[1] = old_y;
in_vector[2] = old_z;

vmatm();

rotated_old_x = out_vector[0];
rotated_old_y = out_vector[1];
rotated_old_z = out_vector[2];

}



void Motion :: vmatm () { 


   int SIZE = 3;
   int i, j;

   for (i=0; i<SIZE; i++)
     {
       out_vector[i] = 0.0;
     }

   for (i = 0; i < SIZE; i++) {
     for (j = 0; j < SIZE; j++)
         {
           out_vector[i] = out_vector[i] + rotate_z_matrix[j][i] * in_vector[j]; 
         }
   }
}



vector<Motion> projectile;
