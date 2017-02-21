#include "preamble.h"
#include "Gun.h"


Gun :: Gun() {

/* Default Constructor */

         angle = 30.0;   
         azimuth = 0.0;
         charge = 1000.0;
         binoculars_short = 800.0;
         binoculars_long  = 1000.0;
         loaded = true;
}

void Gun :: set_angle ( double angle ){
         if (angle > 90.0 )
            this->angle = 90.0;
         else if (angle < 0.0)
            this->angle = 0.0;
         else
            this-> angle = angle;
} 

void Gun :: set_azimuth ( double azimuth ){
         if (azimuth > 90.0) 
            this->azimuth = 90.0;
         else if (azimuth < -90.0)
            this->azimuth = -90.0;
         else
            this-> azimuth = azimuth;
} 

void Gun :: set_charge ( double charge ){
         if (charge > 10000.0) 
            this->charge = 10000;
         else if (charge < 10.0)
            this->charge = 10.0;
         else
            this-> azimuth = azimuth;
} 


void Gun :: add_angle (){
         angle = angle + 0.1;
         if (angle > 90.0) angle = 90.0; 
} 

void Gun :: add_azimuth (){
         azimuth = azimuth + 0.1;
         if (azimuth > 90.0) azimuth = 90.0; 
} 

void Gun :: add_charge (){
         charge = charge + 1.0;
         if (charge > 10000.0) charge = 10000.0; 
} 


void Gun :: minus_angle (){
         angle = angle - 0.1;
         if (angle < 0.0) angle = 0.0; 
} 

void Gun :: minus_azimuth (){
         azimuth = azimuth - 0.1;
         if (azimuth < -90.0) azimuth = -90.0; 
} 

void Gun :: minus_charge (){
         charge = charge - 1.0;
         if (charge < 10.0) charge = 10.0; 
} 

void Gun :: add_binoculars (){
         binoculars_short = binoculars_short + 1.0;
         binoculars_long = binoculars_long + 1.0;
} 

void Gun :: minus_binoculars (){
         binoculars_short = binoculars_short - 1.0;
         binoculars_long = binoculars_long - 1.0;
} 

Gun cannon;
