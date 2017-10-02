#include <Windows.h>
#include "engine.h"

using namespace std;

int main(int argc, char* argv[])
{
	OutputDebugStringA("Initializing...\n");

	Engine game = Engine();
	game.Init();
	OutputDebugStringA("Game initialized!\n");
	while(game.getState() == 0)
	{
		game.Update();
	}
	game.Exit();

	return 0;
}