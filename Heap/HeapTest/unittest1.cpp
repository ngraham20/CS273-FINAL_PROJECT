#include "stdafx.h"
#include "CppUnitTest.h"
#include "Heap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HeapTest
{		
	TEST_CLASS(HeapOfInts)
	{
	public:
		
		TEST_METHOD(Can_create_an_empy_heap_of_ints)
		{
			Heap<int>* myHeap = new Heap<int>();
			Assert::IsNotNull(myHeap);
		}

		//Tests a full tree
		TEST_METHOD(Can_push_seven_ints_to_a_heap_in_increasing_order_and_pop_the_largest_three_off_in_decreasing_order) {
			Heap<int>* myHeap = new Heap<int>();
			myHeap->push(5);
			myHeap->push(6);
			myHeap->push(7);
			myHeap->push(8);
			myHeap->push(9);
			myHeap->push(15);
			myHeap->push(73);
			Assert::AreEqual(myHeap->pop(), 73);
			Assert::AreEqual(myHeap->pop(), 15);
			Assert::AreEqual(myHeap->pop(), 9);
		}

		TEST_METHOD(Can_add_one_int_to_a_heap_and_pop_it_off) {
			Heap<int>* myHeap = new Heap<int>();
			myHeap->push(15);
			Assert::AreEqual(myHeap->pop(), 15);
		}

		TEST_METHOD(Can_add_two_ints_to_a_heap_and_pop_them_off) {
			Heap<int>* myHeap = new Heap<int>();
			myHeap->push(15);
			myHeap->push(89);
			Assert::AreEqual(myHeap->pop(), 89);
			Assert::AreEqual(myHeap->pop(), 15);
		}

		TEST_METHOD(Can_add_three_ints_to_a_heap_and_pop_them_off) {
			Heap<int>* myHeap = new Heap<int>();
			myHeap->push(15);
			myHeap->push(89);
			myHeap->push(42);
			Assert::AreEqual(myHeap->pop(), 89);
			Assert::AreEqual(myHeap->pop(), 42);
			Assert::AreEqual(myHeap->pop(), 15);
		}
	};
}