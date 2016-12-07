#include <chrono>
#include <thread>

// Just for sleep functions, for now


// nanoseconds
void nsleep(int amount_of_time) {
	std::this_thread::sleep_for(std::chrono::nanoseconds(amount_of_time));
}

// microseconds
void usleep(int amount_of_time) {
	std::this_thread::sleep_for(std::chrono::microseconds(amount_of_time));
}

// milliseconds
void msleep(int amount_of_time) {
	std::this_thread::sleep_for(std::chrono::milliseconds(amount_of_time));
}

// seconds
void sleep(int amount_of_time) {
	std::this_thread::sleep_for(std::chrono::seconds(amount_of_time));
}
