#include "dice.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
using namespace std;

Dice::Dice(){
}
Dice::~Dice(){
}
int Dice::getValue(){
	srand(time(0));
	n = (rand() % 12) + 1;
	while (n > 12) {
		srand(time(0));
		n = (rand() % 12) + 1;
	}
	cout << "El n es " << n << endl;
	return n;
}