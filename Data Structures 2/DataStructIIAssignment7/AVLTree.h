//*****************************************************************************************************
//
//		File:					AVLTree.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 7
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					11/4/24
//
//
//		This is the header for the AVL Tree class.
//	
//		Other files required: 
//			1.	Node.h
//			2.  Stock.h
//			3.  main.cpp
//			4.  Stock.txt
//			5.	Stock.cpp
//			
//*****************************************************************************************************

#ifndef AVLTREE_H
#define AVLTREE_H

//*****************************************************************************************************

#include <new>
#include "Node.h"

//*****************************************************************************************************

template <typename TYPE>
class AVLTree
{
private:
	Node<TYPE>* root;

	void destroyRec(Node<TYPE>*& r);
	void insertRec(Node<TYPE>*& r, const TYPE& item);
	void rotateLeft(Node<TYPE>*& k1);
	void rotateRight(Node<TYPE>*& k1);
	int getBalance(Node<TYPE>* r) const;
	void updateBFactors(Node<TYPE>* r);
	void inorderRec(Node<TYPE>* r, ostream& os) const;
	void preorderRec(Node<TYPE>* r, ostream& os) const;
	void postorderRec(Node<TYPE>* r, ostream& os) const;
	TYPE* searchRec(Node<TYPE>* r, const TYPE& item) const;
	int heightRec(Node<TYPE>* r) const;
public:
	AVLTree();
	~AVLTree();
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
AVLTree<TYPE>::AVLTree()
{
	root = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::destroy()
{
	destroyRec(root);
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::destroyRec(Node<TYPE>*& r)
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
AVLTree<TYPE>::~AVLTree()
{
	destroy();
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::insert(const TYPE& item)
{
	insertRec(root, item);
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::insertRec(Node<TYPE>*& r, const TYPE& item)
{
	if (r == nullptr) 
	{
		r = new Node<TYPE>(item);
	}
	else 
	{
		if (item < r->data)
			insertRec(r->left, item);
		else 
			insertRec(r->right, item);
	}

	r->bFactor = getBalance(r);

	if (r->bFactor > 1) 
	{
		if (r->left->bFactor > 0) 
		{
			rotateRight(r);
		}
		else 
		{
			rotateLeft(r->left);
			rotateRight(r);
		}

		updateBFactors(r);
	}
	else if (r->bFactor < -1) 
	{
		if (r->right->bFactor < 0) 
		{
			rotateLeft(r);
		}
		else 
		{
			rotateRight(r->right);
			rotateLeft(r);
		}

		updateBFactors(r);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::rotateLeft(Node<TYPE>*& k1)
{
	Node<TYPE>* k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1 = k2;
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::rotateRight(Node<TYPE>*& k1)
{
	Node<TYPE>* k2 = k1->left;
	k1->left = k2->right;
	k2->right = k1;
	k1 = k2;
}

//*****************************************************************************************************

template <typename TYPE>
int AVLTree<TYPE>::getBalance(Node<TYPE>* r) const
{
	int balance;

	if (r == nullptr)
		balance = 0;
	else
		balance = heightRec(r->left) - heightRec(r->right);

	return balance;
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::updateBFactors(Node<TYPE>* r)
{
	if (r != nullptr) 
	{
		r->bFactor = getBalance(r);
		updateBFactors(r->left);
		updateBFactors(r->right);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::inorder(ostream& os) const
{
	inorderRec(root, os);
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::inorderRec(Node<TYPE>* r, ostream& os) const
{
	using namespace std;

	if (r != nullptr)
	{
		inorderRec(r->left, os);
		os << "Value: " << r->data << "\t Balance Factor: " << r->bFactor;
		cout << endl;
		inorderRec(r->right, os);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::preorder(ostream& os) const
{
	preorderRec(root, os);
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::preorderRec(Node<TYPE>* r, ostream& os) const
{
	using namespace std;

	if (r != nullptr)
	{
		os << "Value: " << r->data << "\t Balance Factor: " << r->bFactor;
		cout << endl;
		preorderRec(r->left, os);
		preorderRec(r->right, os);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::postorder(ostream& os) const
{
	postorderRec(root, os);
}

//*****************************************************************************************************

template <typename TYPE>
void AVLTree<TYPE>::postorderRec(Node<TYPE>* r, ostream& os) const
{
	using namespace std;

	if (r != nullptr)
	{
		postorderRec(r->left, os);
		postorderRec(r->right, os);
		os << "Value: " << r->data << "\t Balance Factor: " << r->bFactor;
		cout << endl;
	}
}

//*****************************************************************************************************

template <typename TYPE>
TYPE* AVLTree<TYPE>::search(const TYPE& item) const
{
	return searchRec(root, item);
}

//*****************************************************************************************************

template <typename TYPE>
TYPE* AVLTree<TYPE>::searchRec(Node<TYPE>* r, const TYPE& item) const
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
int AVLTree<TYPE>::height() const
{
	return heightRec(root);
}

//*****************************************************************************************************

template <typename TYPE>
int AVLTree<TYPE>::heightRec(Node<TYPE>* r) const
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