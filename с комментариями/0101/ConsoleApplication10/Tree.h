#pragma once
#include <cstddef>//������������ ���� ����������� ���������� ����� ���������������� �, ������������ ������� NULL � offsetof, � ����� ���� ptrdiff_t, wchar t � size_t.
#include <iostream>//iostream � ������������ ���� � ��������, ��������� � ����������� ��� ����������� �����-������ � ����� ���������������� C++
class Tree//����� ������
{
//����� ������������ ���� ��� - ������ ��������� ���������� :
protected:

	struct node// ��������� ��� ������������� ����� ������
	{
		int key;//���� key ������ ���� ����
		unsigned char height;//���� height � ������ ��������� � ������ � ������ ����
		node* left = NULL;// ���� left � right � ��������� �� ����� � ������ ����������
		node* right = NULL;// ���� left � right � ��������� �� ����� � ������ ����������
		node(int k) { key = k; left = right; height = 1; }//������� ����������� ������� ����� ���� (������ 1) � �������� ������ k.
	};

	node* root;
	int* arr;
	int size = 0;

	node* removemin(node* p); // �������� ���� � ����������� ������ �� ������ p
	node* findmin(node* p); // ����� ���� � ����������� ������ � ������ p 
	node* insert(node* p, int k); // ������� ����� k � ������ � ������ p
	node* find(node* p, int k);//����� ���� � ������ � ������ p 
	{	node* remove(node* p, int k); // �������� ����� k �� ������ p
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

