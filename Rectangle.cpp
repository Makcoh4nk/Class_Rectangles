#include "Rectangle.h"


Rectangle::Rectangle()
{
	for (int i = 0; i < N; i++)
		RectCrd[i] = 0;
}


Rectangle::~Rectangle()
{
	for (int i = 0; i < N; i++)
		RectCrd[i] = 0;
}

void Rectangle::MoveRectX(int X)
{
	for (int i = 0; i < N; i += 2)
		RectCrd[i] += X;
}

void Rectangle::MoveRectY(int Y)
{
	for (int i = 1; i < N; i += 2)
		RectCrd[i] += Y;
}

void Rectangle::ChangeSize()
{
	for (int i = 0; i < N; i++)
		(*this).Set(i, 0);
	while (((*this).Get(0) >= (*this).Get(2)) || ((*this).Get(1) >= (*this).Get(3)))
	{
		for (int i = 0; i < N; i++)
		{
			int temp = (int)(rand() % 100)*pow((-1), rand() % 2);
			(*this).Set(i, temp);
		}
	}
}

Rectangle Rectangle::BuildRect(Rectangle B)
{
	int i,
		minX = (*this).RectCrd[0],
		minY = (*this).RectCrd[1],
		maxX = (*this).RectCrd[0], 
		maxY = (*this).RectCrd[1];
	Rectangle C;

	for (i = 0; i < N; i += 2)
	{
		if (((*this).RectCrd[i] <= B.RectCrd[i]) && ((*this).RectCrd[i] <= minX)) minX = (*this).RectCrd[i];
		else
			if ((B.RectCrd[i] <= (*this).RectCrd[i]) && (B.RectCrd[i] <= minX)) minX = B.RectCrd[i];

		if (((*this).RectCrd[i] >= B.RectCrd[i]) && ((*this).RectCrd[i]>=maxX)) maxX = (*this).RectCrd[i];
		else
			if ((B.RectCrd[i] >= (*this).RectCrd[i]) && (B.RectCrd[i]>=maxX)) maxX = B.RectCrd[i];
	}

	for (i = 1; i < N; i += 2)
	{
		if (((*this).RectCrd[i]<=B.RectCrd[i]) && ((*this).RectCrd[i]<=minY)) minY = (*this).RectCrd[i];
		else 
			if ((B.RectCrd[i]<=(*this).RectCrd[i]) && (B.RectCrd[i]<=minY)) minY = B.RectCrd[i];

		if (((*this).RectCrd[i] >= B.RectCrd[i]) && ((*this).RectCrd[i]>=maxY)) maxY = (*this).RectCrd[i];
		else 
			if ((B.RectCrd[i]>=(*this).RectCrd[i]) && (B.RectCrd[i]>=maxY)) maxY = B.RectCrd[i];
	}
	C.RectCrd[0] = minX;
	C.RectCrd[1] = minY;
	C.RectCrd[2] = maxX;
	C.RectCrd[3] = maxY;

	return C;
}

Rectangle Rectangle::CommonPart(Rectangle B)
{
	Rectangle C;

	if ((((*this).RectCrd[0] <= B.RectCrd[0]) && (B.RectCrd[0] <= (*this).RectCrd[2])) && (((*this).RectCrd[1] <= B.RectCrd[1]) && (B.RectCrd[1] <= (*this).RectCrd[3])))
	{
		C.RectCrd[0] = B.RectCrd[0];
		C.RectCrd[1] = B.RectCrd[1];
	}

	if ((((*this).RectCrd[0] <= B.RectCrd[2]) && (B.RectCrd[2] <= (*this).RectCrd[2])) && (((*this).RectCrd[1] <= B.RectCrd[3]) && (B.RectCrd[3] <= (*this).RectCrd[3])))
	{
		C.RectCrd[2] = B.RectCrd[2];
		C.RectCrd[3] = B.RectCrd[3];
	}

	if ((((B.RectCrd[0] <= (*this).RectCrd[0]) && ((*this).RectCrd[0] <= B.RectCrd[2])) && ((B.RectCrd[1] <= (*this).RectCrd[1]) && ((*this).RectCrd[1] <= B.RectCrd[3]))))
	{
		C.RectCrd[0] = (*this).RectCrd[0];
		C.RectCrd[1] = (*this).RectCrd[1];
	}

	if ((((B.RectCrd[0] <= (*this).RectCrd[2]) && ((*this).RectCrd[2] <= B.RectCrd[2])) && ((B.RectCrd[1] <= (*this).RectCrd[3]) && ((*this).RectCrd[3] <= B.RectCrd[3]))))
	{
		C.RectCrd[2] = (*this).RectCrd[2];
		C.RectCrd[3] = (*this).RectCrd[3];
	}

	if ((((B.RectCrd[0] <= (*this).RectCrd[0]) && ((*this).RectCrd[0] <= B.RectCrd[2])) && (((*this).RectCrd[1] <= B.RectCrd[1]) && (B.RectCrd[1] <= (*this).RectCrd[3]))))
	{
		C.RectCrd[0] = (*this).RectCrd[0];
		C.RectCrd[1] = B.RectCrd[1];
	}

	if (((B.RectCrd[1] <= (*this).RectCrd[3]) && ((*this).RectCrd[3] <= B.RectCrd[3])) && (((*this).RectCrd[0] <= B.RectCrd[2]) && (B.RectCrd[2] <= (*this).RectCrd[2])))
	{
		C.RectCrd[2] = B.RectCrd[2];
		C.RectCrd[3] = (*this).RectCrd[3];
	}

	if (((((*this).RectCrd[0] <= B.RectCrd[0]) && (B.RectCrd[0] <= (*this).RectCrd[2])) && ((B.RectCrd[1] <= (*this).RectCrd[1]) && ((*this).RectCrd[1] <= B.RectCrd[3]))))
	{
		C.RectCrd[0] = B.RectCrd[0];
		C.RectCrd[1] = (*this).RectCrd[1];
	}

	if ((((*this).RectCrd[1] <= B.RectCrd[3]) && (B.RectCrd[3] <= (*this).RectCrd[3])) && ((B.RectCrd[0] <= (*this).RectCrd[2]) && ((*this).RectCrd[2] <= B.RectCrd[2])))
	{
		C.RectCrd[2] = (*this).RectCrd[2];
		C.RectCrd[3] = B.RectCrd[3];
	}

	return C;
}


int Rectangle::Get(int i)
{
	return RectCrd[i];
}

void Rectangle::Set(int i, int j)
{
	RectCrd[i] = j;
}

void Rectangle::Test1(int x1,int y1,int x2,int y2)
{
	cout << "\nВведённые координаты: (" << x1 << ',' << y1 << "); (" << x2 << ',' << y2 << ')';
	if ((x1 >= x2) || (y1 >= y2))
		cout << "\nНекорректный ввод данных.Повторите ввод" << endl;
	else
	{
		RectCrd[0] = x1;
		RectCrd[1] = y1;
		RectCrd[2] = x2;
		RectCrd[3] = y2;
		cout << "\nКоординаты прямоугольника: (" << RectCrd[0] << ',' << RectCrd[1] << ");(" << RectCrd[2] << ',' << RectCrd[3] << ')';
	}
}

void Rectangle::Test5(Rectangle A, Rectangle B)
{
	if ((Get(0) == 0) && (Get(1) == 0) && (Get(2) == 0) && (Get(3) == 0))
		cout << "Прямоугольники не пересекаются";
	else
		if ((Get(0) == Get(2)) || (Get(1) == Get(3)))
			cout << "Пересечение не является прямоугольником";
		else
			cout << "Координаты прямоугольника, являющегося общей частью заданных: (" << Get(0) << ',' << Get(1) << ");(" << Get(2) << ',' << Get(3) << ')';
}