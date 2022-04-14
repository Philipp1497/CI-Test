#include "math_module.h"


int add (int a, int b){
	a = a + b;
	return a;
}
int greater_zero (int a, int b){
	if( a + b >= 0){
		return 0;
	} else {
		return 1;
	}	
}