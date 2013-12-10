#include "dice.h"
#include <ctime>
#include <stdlib.h>
using namespace std;

Dice::Dice(){
}
Dice::~Dice(){

}
int Dice::getValue(){
	srand(time(0));
	a = rand() % 6 + 1;
	b = rand() % 6 + 1;
	n = a +  b;
	return n;
}