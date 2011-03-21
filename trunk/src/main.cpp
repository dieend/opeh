#include "game/game.h"
using namespace std;
int main(){
    system("cls");
    Game* game = new Game();
    game->Run();
    delete game;
    return 0;
}
