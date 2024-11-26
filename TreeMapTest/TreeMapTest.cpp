#include "pch.h"
#include "..\CA2 project\TreeMap.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeMapTest
{
	TEST_CLASS(TreeMapTest)
	{
	public:
		
		TEST_METHOD(TestNodesEqaul)
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
	};
}
