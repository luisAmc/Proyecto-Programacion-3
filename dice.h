#include <ctime>
#include <stdlib.h>
using namespace std;

class Dice{
	int a, b, n, doubles;
public:
	Dice();
	~Dice();
	int getValue();
};