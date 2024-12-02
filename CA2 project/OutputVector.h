#pragma once
#include <iostream>

using namespace std;
template <class T>
class OutputVector
{
	vector<T>* vec;
	int* connections;
public:
	OutputVector<T>();
	OutputVector<T>(const OutputVector<T>& other);
	void push_back(T item);
	vector<T>* getVector();
	bool contains(T item);
	int size();
	T at(int i);
	~OutputVector();

	OutputVector<T> operator=(OutputVector<T> right);
	friend ostream& operator<<(ostream& os, OutputVector& in)
	{
		for (int i = 0; i < in.getVector()->size(); i++)
		{
			if (i > 0)
				os << ", ";
			os << in.getVector()->at(i);
		}
		return os;
	}
};

template <class T>
OutputVector<T>::OutputVector<T>()
{
	vec = new vector<T>();
	int con = 0;
	connections = &con;
}

template <class T>
OutputVector<T>::OutputVector<T>(const OutputVector<T>& other)
{
	vec = other.vec;
	connections = other.connections;
	connections++;
}

template <class T>
void OutputVector<T>::push_back(T item)
{
	vec->push_back(item);
}

template <class T>
vector<T>* OutputVector<T>::getVector()
{ 
	return vec;
}


template <class T>
bool OutputVector<T>::contains(T item)
{
	for (int i = 0; i < vec->size(); i++)
	{
		if (vec->at(i) == item)
			return true;
	}
	return false;
}

template <class T>
int OutputVector<T>::size()
{
	return vec->size();
}

template <class T>
T OutputVector<T>::at(int i)
{
	return vec->at(i);
}

template <class T>
OutputVector<T>::~OutputVector()
{
	if (*connections < 1)
		delete vec;
	connections--;
}

template <class T>
OutputVector<T> OutputVector<T>::operator=(OutputVector<T> right)
{
	vec = right.getVector();
	connections = right.connections;
	connections++;
	return *this;
}