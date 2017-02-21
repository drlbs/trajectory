#include "WindowState.h"

void WindowState :: set_lookat ( double eye_x,
                              double eye_y,
                              double eye_z,
                              double center_x,
                              double center_y,
                              double center_z,
                              double up_x,
                              double up_y,
                              double up_z      ) {

         this->eye_x = eye_x;
         this->eye_y = eye_y;
         this->eye_z = eye_z;
         this->center_x = center_x;
         this->center_y = center_y;
         this->center_z = center_z;
         this->up_x = up_x;
         this->up_y = up_y;
         this->up_z = up_z;
}

void WindowState :: set_projection( string projection ) {

/* Need to use an iterator here to convert entire string to uppercase and check to 
   see if it matches one of the projection types.  If it doesn't then throw an
   exception 
*/          
        
          this->projection = projection; };
           
 
void WindowState :: set_frustum ( double left, 
                                  double right, 
                                  double bottom,
                                  double top, 
                                  double near, 
                                  double far    ) {

         this->left   = left;
         this->right  = right;
         this->bottom = bottom;
         this->top    = top;
         this->near   = near;
         this->far    = far;
}


void WindowState :: set_perspective ( double fovy, 
                                      double aspect, 
                                      double near, 
                                      double far)   {

         this->fovy   = fovy;
         this->aspect = aspect;
         this->near   = near;
         this->far    = far;
}

       
void WindowState :: set_orthographic ( double left, 
                                       double right, 
                                       double bottom,
                                       double top, 
                                       double near, 
                                       double far    ) {

         this->left   = left;
         this->right  = right;
         this->bottom = bottom;
         this->top    = top;
         this->near   = near;
         this->far    = far;

}

void WindowState :: set_ortho2d ( double left, 
                                  double right, 
                                  double bottom, 
                                  double top     ) {

         this->left   = left;
         this->right  = right;
         this->bottom = bottom;
         this->top    = top;
}


WindowState mainWindow = WindowState();
WindowState targetWindow = WindowState();
WindowState projectileWindow = WindowState();
WindowState physicsWindow = WindowState();
WindowState settingsWindow = WindowState();

