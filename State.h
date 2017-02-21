
class State {
     // State Variable that Control the Graphics and Program  
     private:
         double h; // Stepsize for RK4 method
     public:
         State();
         void set_h( double var ) { h = var; }; 
         double get_h() { return h; }; 
         
};


