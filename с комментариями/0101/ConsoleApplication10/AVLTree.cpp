#include "AVLTree.h"
//Определим три вспомогательные функции, связанные с высотой. Первая является оберткой для поля height, она может работать и с нулевыми указателями (с пустыми деревьями):
unsigned char AVLTree::height(node* p)
{
	
		return p ? p->height : 0; //вычисление высоты
	
}
//Вторая вычисляет balance factor заданного узла(и работает только с ненулевыми указателями) :
int AVLTree::bfactor(node* p)
{
	return height(p->right) - height(p->left);
}

void AVLTree::fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}
//Третья функция восстанавливает корректное значение поля height заданного узла(при условии, что значения этого поля в правом и левом дочерних узлах являются корректными) :
Tree::node* AVLTree::rotateright(node* p)//Код, реализующий правый поворот, выглядит следующим образом (как обычно, каждая функция, изменяющая дерево, возвращает новый корень полученного дерева)
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

Tree::node* AVLTree::rotateleft(node* q)//Левый поворот является симметричной копией правого:
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

Tree::node* AVLTree::balance(node* p)//Код, выполняющий балансировку, сводится к проверке условий и выполнению поворотов:

{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

void AVLTree::_print(node* n)//вставка ключей
{
	if (n)
	{
		std::cout << n->key << " ";
		if (n->left)
		{
			std::cout << " down ";
			_print(n->left);
			std::cout << " up ";
		}

		if (n->right)
		{
			std::cout << " down ";
			_print(n->right);
			std::cout << " up ";
		}

	}
}

void AVLTree::_aroud(node* n, int* i)
{
	if (n)
	{
		if (n->left)
		{

			_aroud(n->left, i);
		}
		arr[*i] = n->key;
		(*i)++;
		if (n->right)
		{
			_aroud(n->right, i);
		}
	}
}

int* AVLTree::getAllKeys()
{
	arr = new int[getSize()];
	int* i = new int(0);
	_aroud(root, i);
	delete i;
	return arr;
}

void AVLTree::print()
{
	_print(root);
}

int* AVLTree::getNumberCollection()
{
	return getAllKeys();
}

