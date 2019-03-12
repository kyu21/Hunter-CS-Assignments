#include "GeniusBar.hpp"

// need to intialize private variables 
GeniusBar::GeniusBar() {
	current_wait_time_ = 0;
	number_of_available_geniuses_ = TOTAL_NUMBER_OF_GENIUSES;
	number_of_customers_ = 0;
}

bool GeniusBar::addWaitingCustomer(Customer& new_customer) {
	if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS) {
		genius_bar_[number_of_customers_] = new_customer;
		number_of_customers_++;

		current_wait_time_ += WAIT_TIME_INCREMENT;
		new_customer.updateWaitTime(current_wait_time_);

		return true;
	}
	else {
		return false;
	}
}

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

bool GeniusBar::releaseGenius() {
	if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES) {
		number_of_available_geniuses_++;

		return true;
	}
	else {
		return false;
	}
}

bool GeniusBar::updateCustomersWaitTime() {
	if (number_of_customers_ > 0) {
		for (auto i = 0; i < number_of_customers_; ++i) {
			genius_bar_[i].updateWaitTime(genius_bar_[i].getWaitTime() + WAIT_TIME_INCREMENT);
		}

		return true;
	}
	else {
		return false;
	}
}