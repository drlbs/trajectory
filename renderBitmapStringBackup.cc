#include "preamble.h"

void renderBitmapString(
		float x, 
		float y, 
		void *font, 
		char *string) {  
  char *c;
  cout << *string << endl;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}
