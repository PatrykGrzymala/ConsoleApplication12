#include "Template.h"
#include "Gra.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main()
{
	srand(unsigned int(time(NULL)));
	Gra Game;

	Game.run();

	return 0;
}
