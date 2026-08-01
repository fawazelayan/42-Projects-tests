#ifndef ARRAY_HPP
# error "Do not include Array.tpp directly"
#endif

template <typename T>
Array<T>::Array()
	: _elements(NULL),
		_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
	: _elements(NULL),
		_size(n)
{
	if (n > 0)
		this -> _elements = new T[n]();
}

template <typename T>
Array<T>::Array(const Array<T>& other)
	: _elements(NULL),
		_size(other._size)
{
	if (this -> _size > 0)
	{
		this -> _elements = new T[this -> _size]();
		for (unsigned int i = 0; i < this -> _size; i++)
			this -> _elements[i] = other._elements[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		T* newElements = NULL;
		if (other._size > 0)
		{
			newElements = new T[other._size]();
			for (unsigned int i = 0; i < other._size; i++)
				newElements[i] = other._elements[i];
		}
		delete[] this -> _elements;
		this -> _elements = newElements;
		this -> _size = other._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this -> _elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this -> _size)
		throw Array<T>::OutOfBoundsException();
	return this -> _elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this -> _size)
		throw Array<T>::OutOfBoundsException();
	return this -> _elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this -> _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index is out of bounds";
}