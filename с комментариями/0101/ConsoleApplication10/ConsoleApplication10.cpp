#include <iostream>
#include "Tree.h"
#include "AVLTree.h" 


int main()
{
	AVLTree tree;
	/*tree.Insert(5);
	tree.Insert(6);
	tree.Insert(8);
	tree.Insert(11);
	tree.Insert(9);
	tree.Insert(12);
	tree.Insert(10);
	tree.Insert(7);*/

	int work = 1;
	while (work != -1)//для завершения ввода нужно ввести -1
	{
		std::cin >> work;
		if (work!=-1)
		tree.Insert(work);
	}
	
	tree.print();
	for (int i = 0; i < tree.getSize(); i++)
	{
		std::cout << std::endl << tree.getNumberCollection()[i]<<" ";
	}


	system("pause");
}


