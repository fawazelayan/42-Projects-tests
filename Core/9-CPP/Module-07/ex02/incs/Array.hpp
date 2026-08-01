#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

// Class Templates

template <typename T>
class Array
{
	private:
		T*				_elements;
		unsigned int	_size;

	public:
		// Constructors & Destructor
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		// Assignment Operator
		Array& operator=(const Array& other);

		// Subscript Operators
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		// Getters
		unsigned int size() const;

		// Exception Classes
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

// Template definitions are included here because compilers need to see the implementation
// to instantiate the templates for specific types at compile time (compilers cannot link them
// from a separate translation unit .cpp).
#include "Array.tpp"

#endif