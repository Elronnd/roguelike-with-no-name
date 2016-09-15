#include "stddef.hh"
#include "stdlib.hh"
#include <iostream>

void random_test() {
	int i, curr_avg, curr_stddev, curr_rand, random_max = 100;
	int random_list[random_max];
	int biggest_random[random_max];

	std::cout << "Here are 100 random numbers between 0 and 100, inclusive." << std::endl;

	curr_avg= curr:wq

	for (i=0;i<100;i++) {
		curr_rand = rn2(random_max);
		curr_avg += curr_rand;

		std::cout << int(curr_rand) << std::endl;

		random_list[i] = curr_rand;
		biggest_random[curr_rand]++;
	}

	std::cout << curr_avg << std::endl;
	curr_avg /= random_max;
	std::cout << "Average is " << curr_avg << ", ";
	for (auto i: random_list)
		curr_stddev += abs(curr_avg-i);

	std::cout << "stddev is " << curr_stddev/random_max << std::endl;
}
	
int main() {
	random_test();
	return 0;
}
