#include "specialbox.h"

SpecialBox::SpecialBox(int ID) : id(ID){
}
SpecialBox::~SpecialBox(){
	//Dtor SpecialBox
}
int SpecialBox::getId(){
	return id;
}