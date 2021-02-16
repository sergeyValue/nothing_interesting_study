// �������� RTTI
//

#include <iostream>
//#include<typeinfo>
#include<crtdbg.h> // ��� ������ ������ 
#include<fstream>
#include"List.h"
#include"Circle.h"
#include"Rect.h"

#define stop __asm nop

std::ostream& operator<<(std::ostream& os, const List& list)	// ! Done     // ����������� ������ 
{
	if ( list.m_size != 0 )
	{
		os << "\n������: \n";
		Node* p = list.Head.pNext;
		//p->pNext;
		os << list.m_size << std::endl;
		for ( size_t i = 0; i < list.m_size; i++ )
		{
			/*os <<*/ p->figure->Print(os) << std::endl;
			p = p->pNext;
		}

		return os;
	}
	else
	{
		os << "\n������ ����!!";
	}

	return os;
}

std::ifstream& operator>>(std::ifstream& iff, List& list)		// ������ �� �����
{
	// TODO

	return iff;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	// ����� �������� ��������� � ������ ��������� � �� ���� ����� ����������� ��� ��������� ������������� 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	List l;
	l.AddToHead(Rect(1, 1, 4, 4, Shape::BLUE));
	l.AddToHead(Circle(2, 2, 4, Shape::GREEN));
	l.AddToEnd(Circle(4, 4, 6, Shape::YELLOW));
	l.AddToEnd(Rect(6, 6, 8, 8, Shape::YELLOW));
	//l.ClearList();

	List l2 = l;		// ����������� �����������
	std::cout << "\n********���������� �����������:************" << std::endl;
	std::cout << "\n������ l2:" << std::endl;
	std::cout << l2;			// ����������� ������

	List l3;
	l3 = l2;				// ������������
	std::cout << "\n************������������:*****************" << std::endl;
	std::cout << "\n������ l2:" << std::endl;
	std::cout << l2;
	std::cout << "\n������ l3:" << std::endl;
	std::cout << l;

	std::cout << "\n*********���������� �� �����:**************" << std::endl;
	l.Sort(Color);
	std::cout << "����� ���������������� ������:" << std::endl;
	std::cout << l;
	
	std::cout << "\n*********���������� �� �����:**************" << std::endl;
	l.Sort(Area);
	std::cout << "����� ���������������� ������:" << std::endl;
	std::cout << l;

	stop

	std::cout << "\n*********�������� � ����:****************" << std::endl;
	std::ofstream listOut("in.txt");	// ������� ����
	listOut << l;						// �������� ������ � ����	// ������������ ������������� std::ostream& operator<<(std::ostream& os, const List& list)
	listOut.close();

	stop

	std::cout << "\n******������� �� �����**********" << std::endl;
	std::ifstream fout("in.txt");
	List list1;
	fout >> list1;				// ��������� � ���������� � ������ list1
	fout.close();
	std::cout << "\n����� ������ list1 �� �����:" << std::endl;
	std::cout << list1;			// ����������� ������


	std::cout << "\n**********�������� ������ list1:************" << std::endl;
	list1.ClearList();
	std::cout << "\n����� ������ list1:" << std::endl;
	std::cout << list1;			// ����������� ������
	stop



	std::cout << "\n**********������� �������:************" << std::endl;
	l.RemoveOne(Circle(1, 1, 4, Shape::GREEN));
	std::cout << l;

	stop
	return 0;
}

