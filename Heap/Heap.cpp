#include "Heap.h"

void Heap::InOrder(Node* node)
{
	if (node == nullptr)
		return;

	InOrder(node->mLeft);
	Visit(node);
	InOrder(node->mRight);
}

Node* Heap::AddNode(Node* node, int value)
{
	if (node == nullptr)
	{
		return CreateNode(value);
	}

	//�ڽľ���
	if (node->mLeft == nullptr && node->mRight == nullptr)
	{
		node->mLeft = AddNode(node->mLeft, value);
	}
	//�ڽ� ���� �ϳ�
	else if (node->mLeft != nullptr && node->mRight == nullptr)
	{
		node->mRight = AddNode(node->mRight, value);
	}
	//�ڽ� ��
	else
	{
		//���̰��� �������� ���� ��
		if (Squence(node) == 0 && Check(node->mRight))
			return AddNode(node->mRight, value);

		//�ڽĵ��� ���̰� ������ �����߰�
		if (Squence(node) == 0)
			return AddNode(node->mLeft, value);

		//�����ڽ��� ũ�� ������ ���� ��
		if (Squence(node) == 1 && Check(node->mLeft))
			return AddNode(node->mLeft, value);

		//�����ڽ��� Ŭ��
		if (Squence(node) == 1)
			return AddNode(node->mRight, value);
	}

	return node;
}

bool Heap::Check(Node* node)
{
	if (node == nullptr)
		return false;


	bool x = Check(node->mLeft);

	if (Squence(node))
		return true;

	bool y = Check(node->mRight);

	return x || y;
}

bool Heap::Search(Node* node, int value)
{
    return false;
}

bool Heap::Squence(Node* node)
{
	if (node == nullptr)
		return 0;

	int lHeight = height(node->mLeft) + 1;
	int rHeight = height(node->mRight) + 1;

	return (lHeight - rHeight);
}

int Heap::height(Node* node)
{
	if (node == nullptr)
		return 0;
	else
	{
		int lHeight = height(node->mLeft) + 1;
		int rHeight = height(node->mRight) + 1;

		return (lHeight > rHeight) ? lHeight : rHeight;
	}
}

Node* Heap::Swap(Node* parents, Node* current)
{
	Node* Parents = parents;
	int temp;

	
	if (current == nullptr)
	{
		return current;
	}

	if (current->mData > Parents->mData)
	{
		temp = current->mData;
		current->mData = Parents->mData;
		Parents->mData = temp;
	}

	Swap(parents, current->mLeft);
	Swap(parents, current->mRight);
}

Node* Heap::HeapSort(Node* node)
{
	for(int i = 0; i < height(node); ++i)
	{
		if (node == nullptr)
		{
			return node;
		}
		else
		{
			HeapSort(node->mLeft);
			HeapSort(node->mRight);
		}
		Swap(node, node); 
	}

	return node;
}

Node* Heap::AddnSort(Node* node, int value)
{
	AddNode(node, value);
	HeapSort(node);

	return node;
}


	
	



