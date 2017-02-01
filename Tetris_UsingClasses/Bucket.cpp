#include "stdafx.h"
#include "Bucket.h"
#include <iostream>
#include <time.h>
#include "Windows.h"
#include <conio.h>
using namespace std;

Bucket::Bucket()
{
}
void Bucket::InitBucket()
{
	for (int i = 0; i < 25; i++)  // 25 rows and 12 columns.
	{
		for (int j = 0; j < 12; j++)
		{
			//the rest
			bucket[i][j] = ' ';
			//paint the top
			if (j == 0 || j == 11)
			{
				bucket[i][j] = '#';
			}
			//paint the bottom of it
			if (i == 24)
			{
				bucket[i][j] = '#';
			}
		}

	}
}

void Bucket::Copy_Bucket()
{
	for (int i = 0; i < 25; i++)  // 25 rows and 12 columns.
	{
		for (int j = 0; j < 12; j++)
		{
			copy_bucket[i][j] = bucket[i][j];
		}

	}
}

void Bucket::displayBucket()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << copy_bucket[i][j];
		}
		cout << endl;
	}
}

void Bucket::updateBukcet(TetrisShape localTetrisShape, int & x, int & y)
{
	//limit y
	if (y == 0)
	{
		y = 1;
	}
	if (y == 9)
	{
		y = 8;
	}
	localTetrisShape.populateCopyShapeArray();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (bucket[i + x][j + y] == '#')
			{
				localTetrisShape.Copy_of_ShapeArray[i][j] = '#';
			}
			copy_bucket[i + x][j + y] = localTetrisShape.Copy_of_ShapeArray[i][j];
		}
	}
}

void Bucket::UpdateOriginalBucket()
{
	for (int i = 0; i < 25; i++)  // 25 rows and 12 columns.
	{
		for (int j = 0; j < 12; j++)
		{
			bucket[i][j] = copy_bucket[i][j];
		}

	}
}

void Bucket::Clearmistakes(int x)
{
	for (int i = 1; i < 11; i++)
	{
		if (copy_bucket[x][i] != ' ')
		{
			copy_bucket[x][i] = ' ';
		}
	}
}

void Bucket::ClearRow(int & Score)
{
	for (int i = 1; i < 24; i++)//anywhere in the bucket
	{
		//if an entire line is busy
		if (copy_bucket[i][1] == 'X' & copy_bucket[i][2] == 'X' & copy_bucket[i][3] == 'X'
			& copy_bucket[i][4] == 'X' & copy_bucket[i][5] == 'X' & copy_bucket[i][6] == 'X'
			& copy_bucket[i][7] == 'X' & copy_bucket[i][8] == 'X' & copy_bucket[i][9] == 'X'
			& copy_bucket[i][10] == 'X')
		{
			//make it look cool =P
			setCursorTo(13, 12);
			cout << "Clearing." << endl;
			sleep(200);
			setCursorTo(13, 12);
			cout << "Clearing.." << endl;
			sleep(200);
			setCursorTo(13, 12);
			cout << "Clearing..." << endl;
			sleep(200);
			setCursorTo(13, 12);
			cout << "Clearing...." << endl;
			sleep(200);
			setCursorTo(13, 12);
			cout << "            " << endl;
			Score += 100;
			setCursorTo(13, 5);
			cout << "Score: " << Score;
			for (int j = 1; j < 11; j++)//clear and copy the previous line for a bit
			{
				copy_bucket[i][j] = copy_bucket[i - 1][j];
				copy_bucket[i - 1][j] = ' ';
				copy_bucket[i - 1][j] = copy_bucket[i - 2][j];
				copy_bucket[i - 2][j] = ' ';
				copy_bucket[i - 2][j] = copy_bucket[i - 3][j];
				copy_bucket[i - 3][j] = ' ';
				copy_bucket[i - 3][j] = copy_bucket[i - 4][j];
				copy_bucket[i - 4][j] = ' ';
				copy_bucket[i - 4][j] = copy_bucket[i - 5][j];
				copy_bucket[i - 5][j] = ' ';

			}
		}
	}
}


Bucket::~Bucket()
{
}

void setCursorTo(int x, int y)//cursor
{
	HANDLE handle;
	COORD position;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(handle, position);
}

void sleep(unsigned int mseconds)//sleep
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
