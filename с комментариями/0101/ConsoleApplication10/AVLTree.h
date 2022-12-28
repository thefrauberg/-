#pragma once
#include "Tree.h"
class AVLTree :
    public Tree
{
private:
	//Определим три вспомогательные функции, связанные с высотой
	unsigned char height(node* p);//Первая является оберткой для поля height, она может работать и с нулевыми указателями(с пустыми деревьями)
	int bfactor(node* p);//Вторая вычисляет balance factor заданного узла(и работает только с ненулевыми указателями)
	void fixheight(node* p);//Третья функция восстанавливает корректное значение поля height заданного узла (при условии, что значения этого поля в правом и левом дочерних узлах являются корректными):
	
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

