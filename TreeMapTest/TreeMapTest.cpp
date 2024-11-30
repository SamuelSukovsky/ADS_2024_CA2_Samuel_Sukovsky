#include "pch.h"
#include "..\CA2 project\TreeMap.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeMapTest
{
	TEST_CLASS(TreeMapTest)
	{
	public:
		
		TEST_METHOD(TestNodesEqual)
		{
			TreemapNode<int, int> node1(1, 1);
			TreemapNode<int, int> node2(1, 0);
			Assert::AreEqual(1, node1.getKey());
			Assert::AreEqual(1, node2.getKey());
			Assert::IsTrue((node1 == node2));
		}

		TEST_METHOD(TestNodesGreater)
		{
			TreemapNode<int, int> node1(2, 1);
			TreemapNode<int, int> node2(1, 0);
			Assert::AreEqual(2, node1.getKey());
			Assert::AreEqual(1, node2.getKey());
			Assert::IsTrue((node1 > node2));
		}

		TEST_METHOD(TestNodesLess)
		{
			TreemapNode<int, int> node1(1, 1);
			TreemapNode<int, int> node2(2, 0);
			Assert::AreEqual(1, node1.getKey());
			Assert::AreEqual(2, node2.getKey());
			Assert::IsTrue((node1 < node2));
		}


		TEST_METHOD(TestPutEmpty)
		{
			TreeMap<int, int> map;
			map.put(1, 5);

			int expected = 5;
			int actual = map.get(1);
			Assert::AreEqual(1, map.size());
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestPutExisting)
		{
			TreeMap<int, int> map;
			map.put(1, 5);

			int expected = 5;
			int actual = map.get(1);
			Assert::AreEqual(1, map.size());
			Assert::AreEqual(expected, actual);

			map.put(1, 4);

			expected = 4;
			actual = map.get(1);
			Assert::AreEqual(1, map.size());
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestClear)
		{
			TreeMap<int, int> map;
			map.put(1, 5);
			map.put(0, 5);
			map.put(2, 5);
			Assert::AreEqual(3, map.size());
			map.clear();
			Assert::AreEqual(0, map.size());
		}

		TEST_METHOD(TestContainsKey)
		{
			TreeMap<int, int> map;
			map.put(1, 5);

			Assert::IsTrue(map.containsKey(1));
		}

		TEST_METHOD(TestContainsKeyEmpty)
		{
			TreeMap<int, int> map;

			Assert::IsFalse(map.containsKey(1));
		}

		TEST_METHOD(TestGetEmpty)
		{
			TreeMap<int, int> map;

			int expected = 0;
			int actual = map.get(1);
			Assert::AreEqual(expected, actual);
			actual = map[1];
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestKeySet)
		{
			TreeMap<int, int> map;
			map.put(3, 5);
			map.put(1, 5);
			map.put(0, 5);
			map.put(2, 5);
			map.put(5, 5);
			map.put(4, 5);
			map.put(6, 5);

			Assert::AreEqual(7, map.size());
			Assert::IsTrue(map.containsKey(6));

			BinaryTree<int> keys = map.keySet();

			Assert::AreEqual(7, keys.count());
			int expected = 1;
			Assert::AreEqual(1, keys.get(expected));
		}

		TEST_METHOD(TestRemoveEmpty)
		{
			TreeMap<int, int> map;

			Assert::AreEqual(0, map.size());
			Assert::IsFalse(map.removeKey(1));
			Assert::AreEqual(0, map.size());
		}

		TEST_METHOD(TestRemoveLeaf)
		{
			TreeMap<int, int> map;
			map.put(2, 5);
			map.put(1, 5);
			map.put(3, 5);

			Assert::AreEqual(3, map.size());
			Assert::IsTrue(map.removeKey(1));
			Assert::AreEqual(2, map.size());
		}

		TEST_METHOD(TestRemoveRoot)
		{
			TreeMap<int, int> map;
			map.put(3, 5);
			map.put(1, 5);
			map.put(0, 5);
			map.put(2, 5);
			map.put(5, 5);
			map.put(4, 5);
			map.put(6, 5);

			Assert::AreEqual(7, map.size());
			Assert::IsTrue(map.removeKey(3));
			Assert::AreEqual(6, map.size());
		}
	};
}