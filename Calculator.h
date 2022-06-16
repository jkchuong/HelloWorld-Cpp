#pragma once // Also Header Guard but less portable than traditional header guard

#ifndef CALCULATOR_H // Header Guard (Include Guard)
#define CALCULATOR_H // Protects against importing header multiple times if multiple files are dependent 
int add(int x, int y); // function prototype

int subtract(int x, int y);

int multiply(int x, int y);

int getInteger();
#endif // Header Guard goes out of scope here.

/*
*  If HelloWorld.cpp also incluided this header file, we can have duplicate methods and linker will complain.
*  Put function definitions in .cpp file and not header file so only forward declarations are in header
*/
