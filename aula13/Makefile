CXX = g++
IFLAGS = -I. 
GLADFLAGS = -Iglad/include -DUSE_GLAD
LIBS = -lGL -lGLU -lglut
SRC = chkerr.c cleanall.c compfrag.c compvert.c mkshader.c readfile.c #coreglew.c loadcore.c
OBJ_GLEW = $(patsubst %.c,%.glew.o,$(SRC)) coreglew.glew.o loadcore.glew.o
OBJ_GLAD = $(patsubst %.c,%.glad.o,$(SRC))

all: $(OBJ_GLAD) $(OBJ_GLEW) coreglew compatglad

%.glad.o: %.c 
	$(CXX) -o $@ -c $< $(IFLAGS) $(GLADFLAGS)

compatglad.o: compatglad.c
	$(CXX) -o $@ -c $< $(IFLAGS) $(GLADFLAGS)

compatglad: $(OBJ_GLAD) compatglad.o glad/glad.o
	$(CXX) -o $@ $^ $(LIBS)

%.glew.o: %.c 
	$(CXX) -o $@ -c $< $(IFLAGS)

drawcore.o: drawcore.cpp
	$(CXX) -o $@ -c $< $(IFLAGS)

coreglew: $(OBJ_GLEW) drawcore.o loadcore.glew.o coreglew.glew.o
	$(CXX) -o $@ $^ $(LIBS) -lGLEW

clean:
	rm -f *.o coreglew compatglad
