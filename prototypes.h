
// Put ALL function prototypes for non class-based functions here


void setup(void); 
void drawScene(); 
void drawScene2(); 
void resetMotion();
void updateDisplays();
void loadProjectile();
void fire();
void renderBitmapString( float, float, void*, string );

void mainWindowInit(void); 
void mainWindowDisplay ();
void mainWindowReshape (int, int );
void mainWindowNormalKeyboardHandler (unsigned char, int, int );
void mainWindowSpecialKeyboardHandler (int, int, int );

void targetWindowInit(void); 
void targetWindowDisplay ();
void targetWindowReshape (int, int );
void targetWindowSpecialKeyboardHandler (int, int, int );

void projectileWindowInit(void);
void projectileWindowDisplay ();
void projectileWindowReshape (int, int );

void physicsWindowInit(void); 
void physicsWindowDisplay ();
void physicsWindowReshape (int, int);


void settingsWindowInit(void); 
void settingsWindowReshape (int, int );
void settingsWindowDisplay ();
