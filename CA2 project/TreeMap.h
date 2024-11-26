#pragma once
#include "BinaryTree.h"
#include "TreemapNode.h"

template <class K, class V>
class TreeMap
{
	BinaryTree<TreemapNode<K, V>> tree;
public:
	TreeMap<K, V>::TreeMap<K, V>();
	void clear();
	bool containsKey(K key);
	V get(K key);
	BinaryTree<K> keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);
	//V& operator[K key];

	~TreeMap();
};

template <class K, class V>
TreeMap<K, V>::TreeMap<K, V>() {}

template <class K, class V>
void TreeMap<K, V>::clear()
{
	tree.clear();
}

template <class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
	TreemapNode<K, V> node(key);
	try
	{
		tree.get(node);
		return true;
	}
	catch (exception e) 
	{
		return false;
	}
}

template <class K, class V>
V TreeMap<K, V>::get(K key)
{
	TreemapNode<K, V> node(key);
	try
	{
		TreemapNode<K, V> retnode = tree.get(node);
		return retnode.getValue();
	}
	catch (exception e) {}
	return V();
}

template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
	BinaryTree<K> retTree;
	TreemapNode<K, V>* nodes = tree.toArray();
	for (int i = 0; i < size(); i++)
	{
		K key = nodes[i].getKey();
		retTree.add(key);
	}
	return retTree;
}

template <class K, class V>
void TreeMap<K, V>::put(K key, V value)
{
	TreemapNode<K, V> node(key, value);
	tree.add(node);
}

template <class K, class V>
int TreeMap<K, V>::size()
{
	return tree.count();
}

template <class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{
	return false;
}

template <class K, class V>
TreeMap<K, V>::~TreeMap()
{
}