#include <string>

using std::string;

class WindowState {
    public:
       WindowState() { sizex = 0; sizey = 0; };       
       void set_size_x(int x) { sizex = x; };
       void set_size_y(int y) { sizey = y; };
       void set_size(int x, int y) { sizex = x; sizey = y; };
       void set_init_x(int x) { initx = x; };
       void set_init_y(int y) { inity = y; };
       void set_init_xy(int x, int y) { initx = x; inity = y; };
       int get_size_x() { return sizex; };
       int get_size_y() { return sizey; };
       int get_init_x() { return initx; };
       int get_init_y() { return inity; };
       void set_lookat( double, double, double, 
                        double, double, double,
                        double, double, double ); 
       void set_window_name( string name ) { window_name = name; }; 
       string get_window_name() { return window_name; };
       void set_window_context( int var ) { context = var; };
       int get_window_context( ) { return context; };

// These are for the projection type
       void set_projection( string );   
       string get_projection() { return projection; };

// These are setters for the projection type
       void set_frustum (    double, double, 
                             double, double, 
                             double, double);
       void set_perspective (double, double, 
                             double, double); 
       void set_orthographic (double, double, 
                              double, double, 
                              double, double);
       void set_ortho2d ( double, double, double, double );

// These are getters for the projection variables
       double get_projection_aspect() { return aspect; };
       double get_projection_fovy()   { return fovy;   };
       double get_projection_left()   { return left;   };
       double get_projection_right()  { return right;  };
       double get_projection_bottom() { return bottom; };
       double get_projection_top()    { return top;    };
       double get_projection_near()   { return near;   };
       double get_projection_far()    { return far;    };

// These are getters for the lookat variables

       double get_lookat_eye_x() { return eye_x; };
       double get_lookat_eye_y() { return eye_y; };
       double get_lookat_eye_z() { return eye_z; };
       double get_lookat_center_x() { return center_x; };
       double get_lookat_center_y() { return center_y; };
       double get_lookat_center_z() { return center_z; };
       double get_lookat_up_x() { return up_x; };
       double get_lookat_up_y() { return up_y; };
       double get_lookat_up_z() { return up_z; };

// These are setters for the clear color 
       
    private:
       int sizex;
       int sizey;
       int initx;
       int inity;
       int context;
       double eye_x; 
       double eye_y; 
       double eye_z;
       double center_x; 
       double center_y; 
       double center_z;
       double up_x; 
       double up_y; 
       double up_z;
       double aspect;
       double fovy;
       double left;
       double right;
       double bottom;
       double top;
       double near;
       double far;
       string window_name;       
       string projection;
       double clear_color_r;
       double clear_color_g;
       double clear_color_b;
 
};

