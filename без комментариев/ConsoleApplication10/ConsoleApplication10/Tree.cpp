#include "Tree.h"

Tree::node* Tree::removemin(node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

Tree::node* Tree::findmin(node* p)
{
	return p->left ? findmin(p->left) : p;
}

Tree::node* Tree::insert(node* p, int k)
{
	if (!p)  return new node(k);
	if (k < p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

Tree::node* Tree::find(node* p, int k)
{
	if (p->key == k) return p;
	else
	{
		if (k < p->key) find(p->left, k);
		else
			find(p->right, k);
	}
	return NULL;
}

Tree::node* Tree::remove(node* p, int k)
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

void Tree::_count(node* n)
{
	{
		if (n)
		{
			if (n->left)
			{
				_count(n->left);
			}
			size++;
			if (n->right)
			{
				_count(n->right);
			}
		}
	}
}

void Tree::destr(node* n)
{
	if (n)
	{
		if (n->left)
		{
			destr(n->left);
		}
		if (n->right)
		{
			destr(n->right);
		}
		delete n;
	}
}

int Tree::getSize()
{
	size = 0;
	_count(root);
	return size;
}

void Tree::Insert(int k)
{
	root = insert(root, k);
}

bool Tree::Search(int k)
{
	if (find(root, k)) return true;
	else return false;
}

void Tree::Remove(int k)
{
	root = remove(root, k);
}

Tree::~Tree()
{
	destr(root);
	if (arr)
	{
		delete []arr;
	}
}
