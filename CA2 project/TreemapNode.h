#pragma once
#include <iostream>

using namespace std;
template <class K, class V>
class TreemapNode
{
	K key;
	V value;
public:
	TreemapNode<K, V>();
	TreemapNode<K, V>(K key);
	TreemapNode<K, V>(K key, V value);
	K& getKey();
	V& getValue();

	bool operator<(TreemapNode<K, V>& right);
	bool operator>(TreemapNode<K, V>& right);
	bool operator==(TreemapNode<K, V>& right);
	friend ostream& operator<<(ostream& os, TreemapNode<K, V>& node)
	{
		os << node.getKey() << ": " << node.getValue();
		return os;
	}
};

template <class K, class V>
TreemapNode<K, V>::TreemapNode<K, V>() { this->key = K(); this->value = V(); }

template <class K, class V>
TreemapNode<K, V>::TreemapNode<K, V>(K key)
{
	this->key = key;
	this->value = V();
}

template <class K, class V>
TreemapNode<K, V>::TreemapNode<K, V>(K key, V value)
{
	this->key = key;
	this->value = value;
}

template <class K, class V>
K& TreemapNode<K, V>::getKey() { return key; }

template <class K, class V>
V& TreemapNode<K, V>::getValue() { return value; }


template <class K, class V>
bool TreemapNode<K, V>::operator<(TreemapNode<K, V>& right)
{
	return getKey() < right.getKey();
}

template <class K, class V>
bool TreemapNode<K, V>::operator>(TreemapNode<K, V>& right)
{
	return getKey() > right.getKey();
}

template <class K, class V>
bool TreemapNode<K, V>::operator==(TreemapNode<K, V>& right)
{
	return getKey() == right.getKey();
}