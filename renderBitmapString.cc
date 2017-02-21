#include "preamble.h"

void renderBitmapString(
		float x, 
		float y, 
		void *font, 
		string stringval) {  
  int i;
  glRasterPos2f(x, y);
  glColor3f(1.0,1.0,1.0);
  for (i=0; i < stringval.size(); i++) {
    glutBitmapCharacter(font, stringval.at(i) );
  }
}
