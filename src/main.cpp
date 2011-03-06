#include "world.h"
using namespace std;
int main(){
	World world;
	World::load("save.dat", world);
	cout << world;
	return 0;
}
