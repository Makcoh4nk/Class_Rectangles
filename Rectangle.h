#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <time.h>

const int N = 4;

using namespace std;

class Rectangle
{
	int RectCrd[N];

public:
	Rectangle();
	~Rectangle();

	void MoveRectX(int);				//����������� �� X
	void MoveRectY(int);				//����������� �� Y
	void ChangeSize();					//��������� �������
	Rectangle BuildRect(Rectangle);		//���������� ����������� �������������� �� �������� ����
	Rectangle CommonPart(Rectangle);	//���������� ����������� (����� �����)

	void Set(int,int);
	int Get(int);

	void Test1(int, int, int, int);					// ���� ������������ �������� ������
	void Test5(Rectangle, Rectangle);	// ���� ������������ ���������� ����� �����
};


