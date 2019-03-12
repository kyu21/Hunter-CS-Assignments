#include "Customer.hpp"

Customer::Customer() {

}

Customer::Customer(std::string name, std::string device, int wait_time) {
	name_ = name;
	defective_device_ = device;
	wait_time_ = wait_time;
}

std::string Customer::getName() {
	return name_;
}

std::string Customer::getDevice() {
	return defective_device_;
}

int Customer::getWaitTime() {
	return wait_time_;
}

void Customer::updateWaitTime(int new_wait_time) {
	wait_time_ = new_wait_time;
}