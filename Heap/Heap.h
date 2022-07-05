#pragma once
#include<iostream>

struct Node
{
	int mData;
	Node* mLeft;
	Node* mRight;
	
	Node(int data, Node* left, Node* right) : mData{data}, mLeft{left}, mRight{right}
	{
		
	}
};

class Heap
{
private:
	Node* mRoot{};


public:
	Heap() : mRoot{}
	{
		mRoot = CreateNode(0);
	}


	Node* GetNode()
	{
		return mRoot;
	}
	Node* CreateNode(int data)
	{
		return new Node(data, nullptr, nullptr);
	}

public:
	void Visit(Node* node) { std::cout << node->mData << "->"; }
	void InOrder(Node* node);

	Node* AddNode(Node* node, int value);
	Node* AddnSort(Node* node, int value);

	bool Search(Node* node, int value);

private:
	Node* Swap(Node* node, Node* current);
	Node* HeapSort(Node* node);

	int height(Node* node);

	bool Check(Node* node);
	
	bool Squence(Node* node);
};

