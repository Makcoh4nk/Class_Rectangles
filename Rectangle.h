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

	void MoveRectX(int);				//Перемещение по X
	void MoveRectY(int);				//Перемещение по Y
	void ChangeSize();					//Изменение размера
	Rectangle BuildRect(Rectangle);		//Построение наименьшего прямоугольника по заданным двум
	Rectangle CommonPart(Rectangle);	//Нахождение пересечения (общей части)

	void Set(int,int);
	int Get(int);

	void Test1(int, int, int, int);					// Тест корректности введённых данных
	void Test5(Rectangle, Rectangle);	// Тест корректности нахождения общей части
};


