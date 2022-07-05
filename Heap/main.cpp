#include<iostream>
#include"Heap.h"

int main()
{
	Heap myHeap;

	auto pRoot = myHeap.CreateNode(6);
	myHeap.AddnSort(pRoot, 5);
	myHeap.AddnSort(pRoot, 3);
	myHeap.AddnSort(pRoot, 1);
	myHeap.AddnSort(pRoot, 8);
	myHeap.AddnSort(pRoot, 7);
	myHeap.AddnSort(pRoot, 2);
	myHeap.AddnSort(pRoot, 4);
	myHeap.AddnSort(pRoot, 10);
	myHeap.AddnSort(pRoot, 24);
	myHeap.AddnSort(pRoot, 44);





	myHeap.InOrder(pRoot);
}