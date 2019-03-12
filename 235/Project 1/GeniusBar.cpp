#include "GeniusBar.hpp"

GeniusBar::GeniusBar() {
	number_of_available_geniuses_ = TOTAL_NUMBER_OF_GENIUSES;
}

//pre: number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS
//post: add new_customer to genius_bar_ and increment current_wait_time_ by WAIT_TIME_INCREMENT
//return: true if number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS, false otherwise
bool GeniusBar::addWaitingCustomer(Customer& new_customer) {
	if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS) {
		current_wait_time_ += WAIT_TIME_INCREMENT;
		genius_bar_[number_of_customers_] = new_customer;
		new_customer.updateWaitTime(current_wait_time_);
		number_of_customers_++;
		return true;
	}
	else {
		return false;
	}
}

//pre: (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)
//post: decrement number_of_customers_ and number_of_available_geniuses_
//return: true if (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0), false otherwise
bool GeniusBar::assignGeniusToCustomer() {
	if (number_of_customers_ > 0 && number_of_available_geniuses_ > 0) {
		number_of_customers_--;
		number_of_available_geniuses_--;
		return true;
	}
	else {
		return false;
	}
}

//pre: number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES
//post: increment number_of_available_geniuses
//return: true if number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES, false otherwise
bool GeniusBar::releaseGenius() {
	if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES) {
		number_of_available_geniuses_++;
		return true;
	}
	else {
		return false;
	}
}

//pre: number_of_customers_ > 0
//post: increment the wait time of each customer on the genius_bar by WAIT_TIME_INCREMENT
//return: true if number_of_customers_ > 0, false otherwise
bool GeniusBar::updateCustomersWaitTime() {
	if (number_of_customers_ > 0) {
		for (int i = 0; i < TOTAL_NUMBER_OF_GENIUSES; i++) {
			genius_bar_[i].updateWaitTime(genius_bar_[i].getWaitTime() + WAIT_TIME_INCREMENT);
		}
		return true;
	}
	else {
		return false;
	}
}
