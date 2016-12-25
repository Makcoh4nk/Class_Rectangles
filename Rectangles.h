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

	void MoveRectX(int);				//Перемещение по X
	void MoveRectY(int);				//Перемещение по Y
	void ChangeSize();					//Изменение размера
	Rectangle BuildRect(Rectangle);		//Построение наименьшего прямоугольника по заданным двум
	Rectangle CommonPart(Rectangle);	//Нахождение пересечения (общей части)

	void Set(int,int);
	int Get(int);

	void correct_input(int, int, int, int);		// Проверка корректности введённых данных
	void common_part();							// Чем является пересечение?
};

void Test_for_point_1(Rectangle);
void Test_for_point_2();
void Test_for_point_3();
void Test_for_point_4(Rectangle, Rectangle);
void Test_for_point_5(Rectangle, Rectangle);




