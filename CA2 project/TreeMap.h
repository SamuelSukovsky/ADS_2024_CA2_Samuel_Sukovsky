#pragma once
#include "BinaryTree.h"

template <class K, class V>
class TreeMap
{
	BinaryTree<TreemapNode<K, V>> tree;
public:
	void clear();
	bool containsKey(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);
	V& operator[K key];

	~TreeMap();
};

template <class K, class V>
void TreeMap<K, V>::clear()
{
	tree.clear();
}

template <class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
	return false;
}

template <class K, class V>
V& TreeMap<K, V>::get(K key)
{
	return null;
}

template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
	return null;
}

template <class K, class V>
void TreeMap<K, V>::put(K key, V value)
{
}

template <class K, class V>
int TreeMap<K, V>::size()
{
	return 0;
}

template <class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{
	return false;
}

template <class K, class V>
TreeMap<K, V>::~TreeMap()
{
	delete tree;
}