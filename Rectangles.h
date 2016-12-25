#pragma once
#include <stdio.h>
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

	void correct_input(int, int, int, int);		// �������� ������������ �������� ������
	void common_part();							// ��� �������� �����������?
};

void Test_for_point_1(Rectangle);
void Test_for_point_2();
void Test_for_point_3();
void Test_for_point_4(Rectangle, Rectangle);
void Test_for_point_5(Rectangle, Rectangle);




