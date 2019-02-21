#include "Customer.hpp"

// Object used to represent a customer with a defective apple product
// States include name, defective device and wait time
// Behaviors include getters for his/her name, device, wait time and a function to update customer's wait time

//default constructor
Customer::Customer() {

}

//parameterized constructor
Customer::Customer(string name, string device, int wait_time) {
  name_ = name;
  defective_device_ = device;
  wait_time_ = wait_time;
}

//return: name_
string Customer::getName() {
  return name_;
}

//return: defective_device_
string Customer::getDevice() {
  return defective_device_;
}

//return: wait_time_
int Customer::getWaitTime() {
  return wait_time_;
}

//post: wait_time_ = new_wait_time
void Customer::updateWaitTime(int new_wait_time) {
  wait_time_ = new_wait_time;
}
