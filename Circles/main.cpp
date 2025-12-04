/*
    Start shape drawing file
*/

#include <iostream>
#include <algorithm>
#include <math.h>
#include "Framework.h"
#include "Shapes.h"

// Variables with global scope - do not rename them, feel free to change values though

// Screen dimensions
int gScreenWidth{800};
int gScreenHeight{600};

// Delay to slow things down
int gTimeDelayMS{10};

using namespace std;

#define SHAPE_COUNT 100

int main()
{
	srand(time(0));

	cout << "Hello circles" << endl;

	Rectangle shapes[SHAPE_COUNT];
	for (int i = 0; i < SHAPE_COUNT; i++)
	{
		shapes[i] = Rectangle(); shapes[i].Randomise();
	}

	while(UpdateFramework())
	{
		for (int i = 0; i < SHAPE_COUNT; i++)
		{
			shapes[i].Tick();
			shapes[i].Draw();
		}
	}

	cout << "Bye bye" << endl;

	return 0;
}