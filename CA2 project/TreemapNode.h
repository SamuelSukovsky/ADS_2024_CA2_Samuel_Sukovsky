#pragma once

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
	K getKey();
	V getValue();

	bool operator<(TreemapNode<K, V>& right);
	bool operator>(TreemapNode<K, V>& right);
	bool operator==(TreemapNode<K, V>& right);
};

template <class K, class V>
TreemapNode<K, V>::TreemapNode<K, V>(){}

template <class K, class V>
TreemapNode<K, V>::TreemapNode<K, V>(K key)
{
	key = key;
}

template <class K, class V>
TreemapNode<K, V>::TreemapNode<K, V>(K key, V value)
{
	key = key;
	value = value;
}

template <class K, class V>
K TreemapNode<K, V>::getKey() { return key; }

template <class K, class V>
V TreemapNode<K, V>::getValue() { return value; }

template <class K, class V>
bool TreemapNode<K, V>::operator<(TreemapNode<K, V>& right)
{
	return right.getKey();
}

template <class K, class V>
bool TreemapNode<K, V>::operator>(TreemapNode<K, V>& right)
{
	return right.getKey();
}

template <class K, class V>
bool TreemapNode<K, V>::operator==(TreemapNode<K, V>& right)
{
	return key == right.getKey();
}