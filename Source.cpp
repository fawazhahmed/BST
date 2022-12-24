#include<iostream>

//to delete a node from BST: if node is lead node- just delete and set its parent corresponding node to nullptr
//if node has 1 child node- set parent node's corresponding to its child node, then delete node.
//if node has 2 child nodes- find candidate (either max from left, or min from right) to replace node, then delete the og candidate node.

struct Node
{
	int num;
	Node* left;
	Node* right;
	Node(int num) : num{ num }, left{ nullptr }, right{ nullptr } {}
};

void inOrder(Node* node) //numbers in ascending order
{
	if(node)
	{
		inOrder(node->left);
		std::cout << node->num << " ";
		inOrder(node->right);
	}
}

void add(int num, Node*& node)
{
	if (node == nullptr)
	{
		node = new Node(num);
		return;
	}
	if (num < node->num)
	{
		add(num, node->left);
	}
	else
	{
		add(num, node->right);
	}
}

//O(n * log n)
int main()
{
	Node* root{};
	for (auto i : { 20,10,30,5,8,4,60,9,80,40,45 })
	{
		if (i == 5)
			std::cout<<std::endl;
		add(i, root);
	}
	inOrder(root);


	return 0;
}