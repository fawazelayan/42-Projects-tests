#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

// Test empty array construction and size()
void testEmptyArray(void)
{
	std::cout << "--- Testing Empty Array ---" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;
	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Expected exception on empty array access: " << e.what() << std::endl;
	}
}

// Test Array with string types and const access
void testStringAndConstArray(void)
{
	std::cout << "\n--- Testing String & Const Array ---" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "42";
	strArr[2] = "Network";

	std::cout << "strArr size: " << strArr.size() << std::endl;
	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;

	const Array<std::string> constStrArr(strArr);
	std::cout << "constStrArr size: " << constStrArr.size() << std::endl;
	std::cout << "constStrArr[1] = " << constStrArr[1] << std::endl;
}

// Subject benchmark test harness
int main(int, char**)
{
	testEmptyArray();
	testStringAndConstArray();

	std::cout << "\n--- Subject Benchmark (750 elements) ---" << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete[] mirror;
			return 1;
		}
	}

	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();

	delete[] mirror;
	std::cout << "Subject benchmark completed successfully!" << std::endl;
	return 0;
}