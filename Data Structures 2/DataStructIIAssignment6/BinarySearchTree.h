//*****************************************************************************************************
//
//		File:					BinarySearchTree.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 6
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					10/7/24
//
//
//		This is the header for the Binary Tree class.
//	
//		Other files required: 
//			1.	Node.h
//			2.  Stock.h
//			3.  main.cpp
//			4.  Stock.txt
//			5.	Stock.cpp
//			
//*****************************************************************************************************

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

//*****************************************************************************************************

#include <new>
#include "Node.h"

//*****************************************************************************************************

template <typename TYPE>
class BinarySearchTree
{
private:
	Node<TYPE>* root;

	void destroyRec(Node<TYPE>* &r);
	void insertRec(Node<TYPE>*& r, const TYPE& item);
	void inorderRec(Node<TYPE>* r, ostream& os) const;
	void preorderRec(Node<TYPE>* r, ostream& os) const;
	void postorderRec(Node<TYPE>* r, ostream& os) const;
	TYPE* searchRec(Node<TYPE>* r, const TYPE& item) const;
	int heightRec(Node<TYPE>* r) const;
public:
	BinarySearchTree();
	~BinarySearchTree();
	void destroy();
	void insert(const TYPE& item);
	void inorder(ostream& os = cout) const;
	void preorder(ostream& os = cout) const;
	void postorder(ostream& os = cout) const;
	TYPE* search(const TYPE& item) const;
	int height() const;
};

//*****************************************************************************************************

template <typename TYPE>
BinarySearchTree<TYPE>::BinarySearchTree()
{
	root = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::destroy()
{
	destroyRec(root);
}

//*****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::destroyRec(Node<TYPE>* &r)
{
	if (r != nullptr)
	{
		destroyRec(r->left);
		destroyRec(r->right);
		delete r;
		r = nullptr;
	}
}

//*****************************************************************************************************

template <typename TYPE>
BinarySearchTree<TYPE>::~BinarySearchTree()
{
	destroy();
}

//*****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::insert(const TYPE& item)
{
	insertRec(root, item);
}

//*****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::insertRec(Node<TYPE>*& r, const TYPE& item)
{
	if (r == nullptr) 
	{
		r = new Node<TYPE>(item);
	}
	else if (item < r->data) 
	{
		insertRec(r->left, item);
	}
	else if (r->data < item) 
	{
		insertRec(r->right, item);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::inorder(ostream& os) const
{
	inorderRec(root, os);
}

//*****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::inorderRec(Node<TYPE>* r, ostream& os) const
{
	using namespace std;

	if (r != nullptr)
	{
		inorderRec(r->left, os);
		os << r->data;
		cout << endl;
		inorderRec(r->right, os);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::preorder(ostream& os) const
{
	preorderRec(root, os);
}

//*****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::preorderRec(Node<TYPE>* r, ostream& os) const
{
	using namespace std;

	if (r != nullptr)
	{
		os << r->data;
		cout << endl;
		preorderRec(r->left, os);
		preorderRec(r->right, os);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::postorder(ostream& os) const
{
	postorderRec(root, os);
}

//*****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::postorderRec(Node<TYPE>* r, ostream& os) const
{
	using namespace std;

	if (r != nullptr)
	{
		postorderRec(r->left, os);
		postorderRec(r->right, os);
		os << r->data;
		cout << endl;
	}
}

//*****************************************************************************************************

template <typename TYPE>
TYPE* BinarySearchTree<TYPE>::search(const TYPE& item) const
{
	return searchRec(root, item);
}

//*****************************************************************************************************

template <typename TYPE>
TYPE* BinarySearchTree<TYPE>::searchRec(Node<TYPE>* r, const TYPE& item) const
{
	TYPE* result;

	if (r == nullptr) 
	{
		result = nullptr;
	}
	else if (item < r->data) 
	{
		result = searchRec(r->left, item);
	}
	else if (r->data < item) 
	{
		result = searchRec(r->right, item);
	}
	else 
	{
		result = &(r->data);
	}

	return result;
}

//*****************************************************************************************************

template <typename TYPE>
int BinarySearchTree<TYPE>::height() const
{
	return heightRec(root);
}

//*****************************************************************************************************

template <typename TYPE>
int BinarySearchTree<TYPE>::heightRec(Node<TYPE>* r) const
{
	int result;

	if (r == nullptr)
		result = 0;
	else
	{
		int leftH = heightRec(r->left);
		int rightH = heightRec(r->right);

		if (leftH > rightH)
			result = leftH + 1;
		else
			result = rightH + 1;
	}

	return result;
}

//*****************************************************************************************************

#endif