#include "Application2D.h"
#include "JRPG.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() 
{
	
	srand(time(NULL));

	// allocation
	auto app = new JRPG();

	// initialise and loop
	app->run("AIE", 1920, 1080, false);

	// deallocation
	delete app;

	return 0;
}