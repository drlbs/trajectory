#include "Target.h"

Target :: Target() {

/* Default Constructor */

         this->x = 0.0;
         this->y = 0.0;
         this->z = 0.0;

         top_support_length = 10.0;
         bottom_support_length = 10.0;
         bottom_support_width = 10.0;
         top_support_thickness = 1.0;
         top_support_width = 10.0;
         bottom_support_thickness = 1.0;
         crossbar_support_length = 8.0;
         platform_width = 10.0;

         set_components();
}

void Target :: set_position( double x, double y, double z ) {
        
         this->x = x;
         this->y = y;
         this->z = z;

         set_components();
}

void Target :: set_components(){

  // This is for setting the initial value of the target components
  // based on the initial x, y, and z values.
        bottom_support_vertices_x.push_back( x - bottom_support_length / 2.0 ); 
        bottom_support_vertices_y.push_back( y - bottom_support_width / 2.0); 
        bottom_support_vertices_z.push_back( z ); 

        bottom_support_vertices_x.push_back( x + bottom_support_length / 2.0); 
        bottom_support_vertices_y.push_back( y - bottom_support_width / 2.0); 
        bottom_support_vertices_z.push_back( z ); 
        
        bottom_support_vertices_x.push_back( x + bottom_support_length / 2.0); 
        bottom_support_vertices_y.push_back( y + bottom_support_width / 2.0); 
        bottom_support_vertices_z.push_back( z ); 
        
        bottom_support_vertices_x.push_back( x - bottom_support_length / 2.0); 
        bottom_support_vertices_y.push_back( y + bottom_support_width / 2.0); 
        bottom_support_vertices_z.push_back( z ); 
        
        bottom_support_vertices_x.push_back( x - bottom_support_length / 2.0); 
        bottom_support_vertices_y.push_back( y - bottom_support_width / 2.0); 
        bottom_support_vertices_z.push_back( z + bottom_support_thickness); 

        bottom_support_vertices_x.push_back( x + bottom_support_length / 2.0); 
        bottom_support_vertices_y.push_back( y - bottom_support_width / 2.0); 
        bottom_support_vertices_z.push_back( z + bottom_support_thickness); 
        
        bottom_support_vertices_x.push_back( x + bottom_support_length / 2.0); 
        bottom_support_vertices_y.push_back( y + bottom_support_width / 2.0); 
        bottom_support_vertices_z.push_back( z + bottom_support_thickness); 
        
        bottom_support_vertices_x.push_back( x - bottom_support_length / 2.0); 
        bottom_support_vertices_y.push_back( y + bottom_support_width / 2.0); 
        bottom_support_vertices_z.push_back( z + bottom_support_thickness); 
        
        top_support_vertices_x.push_back( x - top_support_length / 2.0); 
        top_support_vertices_y.push_back( y - top_support_width / 2.0); 
        top_support_vertices_z.push_back( z ); 

        top_support_vertices_x.push_back( x + top_support_length / 2.0); 
        top_support_vertices_y.push_back( y - top_support_width / 2.0); 
        top_support_vertices_z.push_back( z ); 
        
        top_support_vertices_x.push_back( x + top_support_length / 2.0); 
        top_support_vertices_y.push_back( y + top_support_width / 2.0); 
        top_support_vertices_z.push_back( z ); 
        
        top_support_vertices_x.push_back( x - top_support_length / 2.0); 
        top_support_vertices_y.push_back( y + top_support_width / 2.0); 
        top_support_vertices_z.push_back( z ); 
        
        top_support_vertices_x.push_back( x - top_support_length / 2.0); 
        top_support_vertices_y.push_back( y - top_support_width / 2.0); 
        top_support_vertices_z.push_back( z + top_support_thickness); 

        top_support_vertices_x.push_back( x + top_support_length / 2.0); 
        top_support_vertices_y.push_back( y - top_support_width / 2.0); 
        top_support_vertices_z.push_back( z + top_support_thickness); 
        
        top_support_vertices_x.push_back( x + top_support_length / 2.0); 
        top_support_vertices_y.push_back( y + top_support_width / 2.0); 
        top_support_vertices_z.push_back( z + top_support_thickness); 
        
        top_support_vertices_x.push_back( x - top_support_length / 2.0); 
        top_support_vertices_y.push_back( y + top_support_width / 2.0); 
        top_support_vertices_z.push_back( z + top_support_thickness); 


}

Target  target[10];
