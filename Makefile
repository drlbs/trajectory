CC = g++
CFLAGS = -O3

# This checks for the existence of 64 bit librarires and uses them if available
64BITLIB := $(shell if test -e /usr/lib64; then ls -d /usr/lib64; else ls -d /usr/lib; fi)

LIBDIRS = -L $(64BITLIB)

INCDIRS = -I/usr/X11R6/include
LDLIBS =  -lGL -lGLU -lglut -lm 
CLASSOBJS = State.o Target.o Gun.o Motion.o WindowState.o 
WINDOWOBJS = mainWindow.o targetWindow.o  projectileWindow.o physicsWindow.o settingsWindow.o
OBJS = setup.o drawScene.o drawScene2.o resetMotion.o\
       updateDisplays.o loadProjectile.o fire.o \
       renderBitmapString.o

all: traj ctags

traj : preamble.h State.h  main.o $(CLASSOBJS) $(WINDOWOBJS) $(OBJS)   
	$(CC) $(CFLAGS) -o traj main.o $(CLASSOBJS) $(WINDOWOBJS) $(OBJS) $(INCDIRS) $(LIBDIRS) $(LDLIBS)  

main.o : preamble.h prototypes.h  main.cc $(CLASSOBJS) $(WINDOWOBJS) $(OBJS) 
	$(CC) $(CFLAGS) -c main.cc 

setup.o : setup.cc preamble.h  
	$(CC) $(CFLAGS) -c setup.cc     

drawScene.o : drawScene.cc preamble.h  
	$(CC) $(CFLAGS) -c drawScene.cc     

drawScene2.o : drawScene2.cc preamble.h  
	$(CC) $(CFLAGS) -c drawScene2.cc     

resetMotion.o : resetMotion.cc preamble.h   
	$(CC) $(CFLAGS) -c resetMotion.cc     

updateDisplays.o : updateDisplays.cc  preamble.h 
	$(CC) $(CFLAGS) -c updateDisplays.cc     

loadProjectile.o : loadProjectile.cc preamble.h  
	$(CC) $(CFLAGS) -c loadProjectile.cc     

fire.o : fire.cc preamble.h  
	$(CC) $(CFLAGS) -c fire.cc     

renderBitmapString.o : renderBitmapString.cc preamble.h   
	$(CC) $(CFLAGS) -c renderBitmapString.cc     


# These are the five main windows
mainWindow.o : mainWindow.cc preamble.h  $(CLASSOBJS) 
	$(CC) $(CFLAGS) -c mainWindow.cc  

targetWindow.o : targetWindow.cc preamble.h  $(CLASSOBJS) 
	$(CC) $(CFLAGS) -c targetWindow.cc 

projectileWindow.o : projectileWindow.cc  preamble.h  $(CLASSOBJS)
	$(CC) $(CFLAGS) -c projectileWindow.cc 

physicsWindow.o : physicsWindow.cc  preamble.h  $(CLASSOBJS)
	$(CC) $(CFLAGS) -c physicsWindow.cc 

settingsWindow.o : settingsWindow.cc  preamble.h  $(CLASSOBJS)
	$(CC) $(CFLAGS) -c settingsWindow.cc 

# These are all Class Files
State.o : State.cc State.h
	$(CC) $(CFLAGS) -c State.cc    

Target.o : Target.cc Target.h
	$(CC) $(CFLAGS) -c Target.cc    

Gun.o : Gun.cc Gun.h
	$(CC) $(CFLAGS) -c Gun.cc    

Motion.o  : Motion.cc Motion.h preamble.h State.o 
	$(CC) $(CFLAGS) -c Motion.cc 

WindowState.o  : WindowState.cc WindowState.h preamble.h  
	$(CC) $(CFLAGS) -c WindowState.cc  

# Default Targets for Cleaning up the Environment
clean :
	rm *.o

pristine :
	rm *.o
	touch *.cc *.h

ctags :
	ctags *.h *.cc

