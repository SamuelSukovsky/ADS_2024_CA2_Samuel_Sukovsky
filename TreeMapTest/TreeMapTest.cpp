#include "pch.h"
#include "..\CA2 project\TreeMap.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeMapTest
{
	TEST_CLASS(TreeMapTest)
	{
	public:
		
		TEST_METHOD(Aaaaaaaaaaaaa)
		{
			TreemapNode<int, int> node1(1, 1);
			TreemapNode<int, int> node2(2, 1);
			Assert::IsTrue((node1 == node2));
		}
		
		TEST_METHOD(TestPutEmpty)
		{
			TreeMap<int, int> map;
			map.put(1, 1);

			int expected = 1;
			int actual = map.get(expected);
			Assert::AreEqual(1, map.size());
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(aAAAAaaaaaa)
		{
			BinaryTree<int> tree;
			int x = 1;
			tree.add(x);
			Assert::AreEqual(1, tree.get(x));
		}
	};
}
