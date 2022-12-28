#pragma once
#include <cstddef>
#include <iostream>
class Tree
{
protected:

	struct node
	{
		int key;
		unsigned char height;
		node* left = NULL;
		node* right = NULL;
		node(int k) { key = k; left = right; height = 1; }
	};

	node* root;
	int* arr;
	int size = 0;

	node* removemin(node* p); // удаление узла с минимальным ключом из дерева p
	node* findmin(node* p); // поиск узла с минимальным ключом в дереве p 
	node* insert(node* p, int k); // вставка ключа k в дерево с корнем p
	node* find(node* p, int k);
	node* remove(node* p, int k); // удаление ключа k из дерева p
	void _count(node* n); //подсчёт количества элементов в дереве
	void destr(node* n);// рекурсивный деструктор
	virtual node* balance(node* p) = 0;
public:
	int getSize();
	void Insert(int k);
	bool Search(int k);
	void Remove(int k);
	 //чистая виртуальная функция метода балансировки 
	~Tree();//деструктор
	
};

