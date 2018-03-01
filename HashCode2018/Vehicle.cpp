#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle() {}


Vehicle::~Vehicle() {}

void Vehicle::setDestination(int x, int y){
  destination=intersection(x,y);
}

bool Vehicle::isFull(){
  return isRiding;
}
