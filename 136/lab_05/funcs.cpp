#include <iostream>

//Task A
bool isDivisbleBy(int n, int d) {
	return (n % d == 0);
}

//Task B
bool isPrime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (isDivisbleBy(n, 2)) return false;
	for (int i = 3; (i*i)<=n; i+=2) {
		if (isDivisbleBy(n, i)) return false;
	}
	return true;
}

//Task C
int nextPrime(int n) {
	int p = n + 1;
	while (!isPrime(p)) {
		(isDivisbleBy(p, 2)) ? p++ : p+=2;
	}
	return p;
}

//Task D
int countPrimes(int a, int b) {
	int count = (isPrime(a)) ? 1 : 0;
	int p = (count == 0) ? a : a + 1;
	while (a <= p && p <= b) {
		if (!(isPrime(p))) {
			p += 1;
			continue;
		}
		else {
			p = nextPrime(p);
			count++;
		}
	}
	return count;
}

//Task E
bool isTwinPrime(int n) {
	return (isPrime(n) && (isPrime(n-2) || isPrime(n+2)));
}

//Task F
int nextTwinPrime(int n) {
	int p = n + 1;
	while (!isTwinPrime(p)) {
		p++;
	}
	return p;
}

//Task G
int largestTwinPrime(int a, int b) {
	int p = (isTwinPrime(a)) ? a + 1 : a;
	while (a <= p && p <= b) {
		if (nextTwinPrime(p) <= b) p = nextTwinPrime(p); 
		else break;
	}
	return (p == a) ? -1 : p;
}