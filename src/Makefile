#INC specifies our include files, such as header files, and libs.
INC= -I ../inc/

#OBJS specifies which files to compile as part of the project 
OBJS = lairspace.cpp 

#CC specifies which compiler we're using 
CC = g++ 

#COMPILER_FLAGS specifies the additional compilation options we're using 
# -w suppresses all warnings 
COMPILER_FLAGS = -w 

#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_gfx 


#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = ../bin/lairspace 

#This is the target that compiles our executable 
all : $(OBJS) 
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INC) -o $(OBJ_NAME)
