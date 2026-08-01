#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

void testMutantStack()
{
	std::cout << "--- Testing MutantStack ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Successfully copied to std::stack" << std::endl;
}

void testListComparison()
{
	std::cout << "--- Testing std::list (equivalent code) ---" << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void testExtraIterators()
{
	std::cout << "--- Testing Const & Reverse Iterators ---" << std::endl;
	MutantStack<std::string> mstack;
	mstack.push("Hello");
	mstack.push("World");
	mstack.push("42");

	std::cout << "Reverse traversal:" << std::endl;
	for (MutantStack<std::string>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
	{
		std::cout << *rit << std::endl;
	}

	std::cout << "Const traversal:" << std::endl;
	const MutantStack<std::string> const_mstack(mstack);
	for (MutantStack<std::string>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit)
	{
		std::cout << *cit << std::endl;
	}
}

int main()
{
	testMutantStack();
	testListComparison();
	testExtraIterators();
	return 0;
}