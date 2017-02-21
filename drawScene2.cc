
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


void drawScene2(){
   extern vector<Motion> projectile;
   extern WindowState targetWindow;
   extern Target target[];
   int i;

// Draw the projectile
   glColor3f(1.0,0.0,0.0);
   for (i=0;i<projectile.size();i++) {
      if ( projectile.at(i).in_flight() ) {
        glPushMatrix();
        glBegin( GL_LINES );
          glVertex3f( projectile.at(i).get_rotated_old_x(),
                      projectile.at(i).get_rotated_old_y(),
                      projectile.at(i).get_rotated_old_z());
          glVertex3f( projectile.at(i).get_rotated_x(),
                      projectile.at(i).get_rotated_y(),
                      projectile.at(i).get_rotated_z());
        glEnd();
        glPopMatrix();
      }
    }

// Draw the targets
     glColor3f(0.0,1.0,0.0);
     for (i=0; i<7; i++) {
        glPushMatrix();
        glTranslatef(target[i].get_x(), target[i].get_y(), target[i].get_z());
        gluCylinder(gluNewQuadric(), 
                    (GLdouble) 20.0,
                    (GLdouble) 20.0,
                    (GLdouble) 20.0,
                    (GLint)    20,
                    (GLint)    20 );
        glPopMatrix();
    }
      
}


