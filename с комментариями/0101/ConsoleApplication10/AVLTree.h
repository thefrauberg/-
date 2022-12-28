#pragma once
#include "Tree.h"
class AVLTree :
    public Tree
{
private:
	//��������� ��� ��������������� �������, ��������� � �������
	unsigned char height(node* p);//������ �������� �������� ��� ���� height, ��� ����� �������� � � �������� �����������(� ������� ���������)
	int bfactor(node* p);//������ ��������� balance factor ��������� ����(� �������� ������ � ���������� �����������)
	void fixheight(node* p);//������ ������� ��������������� ���������� �������� ���� height ��������� ���� (��� �������, ��� �������� ����� ���� � ������ � ����� �������� ����� �������� �����������):
	
	node* rotateright(node* p); // ������ ������� ������ p
	node* rotateleft(node* q); // ����� ������� ������ q
	node* balance(node* p) override; // ������������ ���� p
	
	void _print(node* n);
	void _aroud(node* n, int* i);
	int* getAllKeys();

public:

	void print();//������� ������ ������ �� �����
	int* getNumberCollection();//��������� ������������������ �����
};

