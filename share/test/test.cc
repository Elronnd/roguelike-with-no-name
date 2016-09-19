#include "stddef.hh"
#include "stdlib.hh"
#include <iostream>

void random_test() {
	int i;

	std::cout << "Here are 100 random numbers between 0 and 100, inclusive." << std::endl;


	for (i=0;i<100;i++) {
		std::cout << int(rn1(15)) << std::endl;
	}
}
	
int main() {
	random_test();
	return 0;
}
