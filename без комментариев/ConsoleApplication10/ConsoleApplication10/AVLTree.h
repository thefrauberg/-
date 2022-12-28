#pragma once
#include "Tree.h"
class AVLTree :
    public Tree
{
private:

	unsigned char height(node* p);
	int bfactor(node* p);
	void fixheight(node* p);
	
	node* rotateright(node* p); // правый поворот вокруг p
	node* rotateleft(node* q); // левый поворот вокруг q
	node* balance(node* p) override; // балансировка узла p
	
	void _print(node* n);
	void _aroud(node* n, int* i);
	int* getAllKeys();

public:

	void print();//функция вывода дерева на экран
	int* getNumberCollection();//возращает последовательность чисел
};

