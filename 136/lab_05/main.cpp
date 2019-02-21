#include<iostream>

#include "funcs.h"

int main() {
	std::cout << std::boolalpha << "isDivisbleBy(100, 25) == " << isDivisbleBy(100, 25) << std::endl;
	std::cout << std::boolalpha << "isDivisbleBy(37, 15) == " << isDivisbleBy(35, 17) << std::endl;
	std::cout << std::boolalpha << "isPrime(5) == " << isPrime(5) << std::endl;
	std::cout << std::boolalpha << "isPrime(4) == " << isPrime(4) << std::endl;
	std::cout << "nextPrime(14) == " << nextPrime(14) << std::endl;
	std::cout << "nextPrime(17) == " << nextPrime(17) << std::endl;
	std::cout << "countPrimes(2, 11) == " << countPrimes(2, 11) << std::endl;
	std::cout << "countPrimes(5, 20) == " << countPrimes(5, 20) << std::endl;
	std::cout << "isTwinPrime(17) == " << isTwinPrime(17) << std::endl;
	std::cout << "isTwinPrime(5) == " << isTwinPrime(5) << std::endl;
	std::cout << "nextTwinPrime(5) == " << nextTwinPrime(5) << std::endl;
	std::cout << "nextTwinPrime(19) == " << nextTwinPrime(19) << std::endl;
	std::cout << "largestTwinPrime(5, 18) == " << largestTwinPrime(5, 18) << std::endl;
	std::cout << "largestTwinPrime(1, 31) == " << largestTwinPrime(1, 31) << std::endl;
	return 0;
}