#include "Application2D.h"
#include "JRPG.h"

int main() {
	
	// allocation
	auto app = new JRPG();

	// initialise and loop
	app->run("AIE", 1920, 1080, false);

	// deallocation
	delete app;

	return 0;
}