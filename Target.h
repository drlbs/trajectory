#include "preamble.h"

class Target {
     // Variables specific to the targets 
     public:
         Target();
        
         void set_x(double x ){ this->x = x; };  
         void set_y(double y ){ this->y = y; };
         void set_z(double z ){ this->z = z; };
         void set_position(double, double, double);

         double get_x(){ return x; };  
         double get_y(){ return y; };
         double get_z(){ return z; };
         
         vector<double> top_support_vertices_x;
         vector<double> top_support_vertices_y;
         vector<double> top_support_vertices_z;
         vector<double> bottom_support_vertices_x;
         vector<double> bottom_support_vertices_y;
         vector<double> bottom_support_vertices_z;
         vector<double> left_front_crossbar_support_vertices_x;
         vector<double> left_front_crossbar_support_vertices_y;
         vector<double> left_front_crossbar_support_vertices_z;
         vector<double> left_rear_crossbar_support_vertices_x;
         vector<double> left_rear_crossbar_support_vertices_y;
         vector<double> left_rear_crossbar_support_vertices_z;
         vector<double> right_front_crossbar_support_vertices_x;
         vector<double> right_front_crossbar_support_vertices_y;
         vector<double> right_front_crossbar_support_vertices_z;
         vector<double> right_rear_crossbar_support_vertices_x;
         vector<double> right_rear_crossbar_support_vertices_y;
         vector<double> right_rear_crossbar_support_vertices_z;
         
     private:
         double x;
         double y;
         double z;
         double top_support_length;
         double bottom_support_length;
         double bottom_support_width;
         double top_support_thickness;
         double top_support_width;
         double bottom_support_thickness;
         double crossbar_support_length;
         double platform_width;
         
       
         void set_components();
};


