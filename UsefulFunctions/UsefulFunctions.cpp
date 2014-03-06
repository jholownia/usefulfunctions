/*
================================
UsefulFunctions.cpp

Collection of useful functions.

Created on: 26 Dec 2013
Author: Jan Holownia

Copyright (c) Jan Holownia <jan.holownia@gmail.com> 2014.
================================
*/

#include "stdafx.h"
#include <iostream>
#include <vector>


/*
================================
 prefixSums

 Calculate prefix sums for a given array.
================================
*/
std::vector<int> prefixSums(std::vector<int> array)
{
	int n = array.size();
	std::vector<int> sums(n + 1, 0);

	for (int i = 1; i < n + 1; ++i)
	{
		sums[i] = sums[i - 1] + array[i - 1];
	}

	return sums;
}

/*
================================
 rangeSum

 Calculate sum of all the numbers in range 1 to n in O(1).
================================
*/
int rangeSum(int n)
{
	long long temp = n * ((long long)n + 1);
	return (temp + 1) / 2;
}

/*
================================
 ceilDiv

 Return ceil devision of two numbers.
 I.e. the smallest multiple of b which is greater or equal a.
================================
*/
int fastCeilDiv(int a, int b)
{
	return (a + b - 1) / b;
}

/*
================================
 findPrimeFactors

 Return all prime factors of a number.
================================
*/
std::vector<int> findPrimeFactors(int a)
{
	std::vector<int> primeFactors;
	
	int d = 2;
	while (a > 1)
	{
		while (a % d == 0)
		{
			primeFactors.push_back(d);
			a /= d;
		}
		++d;
	}

	return primeFactors;
}

/*
================================
 isPrime

 Check if the argument is a prime number.
================================
*/
bool isPrime(int a)
{
	if (a <= 1)
		return false;
	if (a == 2)
		return true;	

	for (int i = 2; i * i <= a; ++i)
	{
		if (a % i == 0)
			return false;
	}

	return true;
}

/*
================================
 isPrime2

 Fast constexpr version of isPrime.

 Call with: (number <= 1) ? false : is_prime_recursive(number, 2);
================================
*/
constexpr bool isPrime2(size_t a, size_t b)
{
	return (b * b > a) ? true : (a % b == 0) ? false : isPrime2(a, b + 1);
}


/*
================================
 gcd
 
 Greatest common divisor.
================================
*/
int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

/*
================================
 fibonacci1

 Fibonacci sequence with 2 variables and subtraction.
================================
*/
long long fibonacci1(int x)
{
	if (x <= 1)
	{
		return 1;
	}

	long long prev = 1;
	long long result = 1;

	for (int i = 1; i < x; ++i)
	{
		result += prev;
		prev = result - prev;
	}

	return result;
}

/*
================================
 fionacci2

 Fibonacci sequence with 3 variables.
================================
*/
long long fibonacci2(int x)
{
	if (x <= 1)
	{
		return 1;
	}

	long long prev = 1;
	long long result = 1;
	long long temp = 0;

	for (int i = 1; i < x; ++i)
	{
		temp = result + prev;
		prev = result;
		result = temp;
	}

	return result;
}

/*
================================
 fionacci3

 Recursive constexpr fibonacci.
================================
*/
constexpr long long fibonacci3(int x)
{
	return ( (x == 0) ? 1 : ( (x == 1) ? 1 : ( fibonacci3(x - 2) + fibonacci3(x - 1) ) ) );
}

/*
================================================================
 main
================================================================
*/
int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << fibonacci1(7) << std::endl;
	std::cout << fibonacci2(7) << std::endl;
	std::cout << fibonacci3(7) << std::endl;
	
	std::cout << std::endl;
	system("pause");
	return 0;
}

