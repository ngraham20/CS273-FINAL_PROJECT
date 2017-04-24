#ifndef _VECTOR_BASED_HEAP_C
#define _VECTOR_BASED_HEAP_C

#include <algorithm>
#include <vector>

template <class T>
class Heap {
private:
	std::vector<T> elements;
public:
	/*
		Adds an element to the end of the heap,
		then bubbles the element up to its appropriate location.
		Returns the final index of newItem.
	*/
	int push(const T& newItem) {
		//Stick newItem at the back of the heap
		elements.push_back(newItem);
		//Find the parent of newItem
		int indexOfChild = elements.size() - 1;
		int indexOfParent = (indexOfChild - 1) / 2;
		T parent = elements[indexOfParent];
		T child;
		//While the newItem is greater than its parent, swap
		while (newItem > parent && indexOfParent >= 0) {
			elements[indexOfParent] = newItem;
			elements[indexOfChild] = parent;
			indexOfChild = indexOfParent;
			indexOfParent = (indexOfChild - 1) / 2;
			parent = elements[indexOfParent];
			child = elements[indexOfChild];
		}
		return indexOfChild;
	}

	T pop() {
		//Capture top item
		T firstElement = elements[0];
		T parent, leftChild, rightChild;
		//Replace the first item with the last item;
		elements[0] = elements[elements.size() - 1];
		//Destroy the last item
		elements.pop_back();
		if (elements.size() < 1) {
			return firstElement;
		}
		//Find the parent node and its children
		//TODO: check to make sure there are two children
		int indexOfParent = 0;
		int indexOfLeftChild = 1;
		int indexOfRightChild = 2;
		parent = elements[indexOfParent];
		//if the parent has no left child
		if (indexOfLeftChild >= elements.size()) {
			leftChild = parent;
		}
		else { //Otherwise get the leftChild
			leftChild = elements[indexOfLeftChild];
		}
		//If the parent has no right child 
		if (indexOfRightChild >= elements.size()) {
			rightChild = parent;
		}
		else { //Otherwise get the rightChild
			rightChild = elements[indexOfRightChild];
		}
		//While the parent node is smaller than its largest child
		//Swap the parent node with its largest child
		while ((parent < leftChild || parent < rightChild) && indexOfParent >= 0) {
			//If the rightChild is the fat kid, swap with the parent.
			if (rightChild > leftChild) {
				elements[indexOfParent] = rightChild;
				elements[indexOfRightChild] = parent;
			}
			//otherwise, swap leftChild with parent
			else {
				elements[indexOfParent] = leftChild;
				elements[indexOfLeftChild] = parent;
			}
			//Calculate the new parent and children;
			indexOfParent = (indexOfParent - 1) / 2;
			indexOfLeftChild = indexOfParent * 2 + 1;
			indexOfRightChild = indexOfLeftChild + 1;
			parent = elements[indexOfParent];
			//if the parent has no left child
			if (indexOfLeftChild >= elements.size()) {
				leftChild = parent;
			}
			else { //Otherwise get the leftChild
				leftChild = elements[indexOfLeftChild];
			}
			//If the parent has no right child 
			if (indexOfRightChild > elements.size()) {
				rightChild = parent;
			}
			else { //Otherwise get the rightChild
				rightChild = elements[indexOfRightChild];
			}
		}
		return firstElement;
	}
};

#endif // !_VECTOR_BASED_HEAP_C
