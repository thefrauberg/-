#pragma once
#include <cstddef>//заголовочный файл стандартной библиотеки €зыка программировани€ —, определ€ющий макросы NULL и offsetof, а также типы ptrdiff_t, wchar t и size_t.
#include <iostream>//iostream Ч заголовочный файл с классами, функци€ми и переменными дл€ организации ввода-вывода в €зыке программировани€ C++
class Tree//класс дерева
{
//Ѕудем представл€ть узлы ј¬Ћ - дерева следующей структурой :
protected:

	struct node// структура дл€ представлени€ узлов дерева
	{
		int key;//ѕоле key хранит ключ узла
		unsigned char height;//поле height Ч высоту поддерева с корнем в данном узле
		node* left = NULL;// пол€ left и right Ч указатели на левое и правое поддеревь€
		node* right = NULL;// пол€ left и right Ч указатели на левое и правое поддеревь€
		node(int k) { key = k; left = right; height = 1; }//ѕростой конструктор создает новый узел (высоты 1) с заданным ключом k.
	};

	node* root;
	int* arr;
	int size = 0;

	node* removemin(node* p); // удаление узла с минимальным ключом из дерева p
	node* findmin(node* p); // поиск узла с минимальным ключом в дереве p 
	node* insert(node* p, int k); // вставка ключа k в дерево с корнем p
	node* find(node* p, int k);//поиск узла с ключом в дереве p 
	{	node* remove(node* p, int k); // удаление ключа k из дерева p
	void _count(node* n); //подсчЄт количества элементов в дереве
	void destr(node* n);// рекурсивный деструктор
	virtual node* balance(node* p) = 0;
public:
	int getSize();
	void Insert(int k);
	bool Search(int k);
	void Remove(int k);
	 //чиста€ виртуальна€ функци€ метода балансировки 
	~Tree();//деструктор
	
};

