#include "game/game.h"
using namespace std;
int main(){
    Game* game = new Game();
    game->run();
    delete game;
    return 0;
}
