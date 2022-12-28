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

	node* removemin(node* p); // �������� ���� � ����������� ������ �� ������ p
	node* findmin(node* p); // ����� ���� � ����������� ������ � ������ p 
	node* insert(node* p, int k); // ������� ����� k � ������ � ������ p
	node* find(node* p, int k);
	node* remove(node* p, int k); // �������� ����� k �� ������ p
	void _count(node* n); //������� ���������� ��������� � ������
	void destr(node* n);// ����������� ����������
	virtual node* balance(node* p) = 0;
public:
	int getSize();
	void Insert(int k);
	bool Search(int k);
	void Remove(int k);
	 //������ ����������� ������� ������ ������������ 
	~Tree();//����������
	
};

