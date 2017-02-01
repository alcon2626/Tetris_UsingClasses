#include "stdafx.h"
#include "TetrisShape.h"


TetrisShape::TetrisShape()
{
}

void TetrisShape::populateShapeArray(int shapeType)
{
	switch (shapeType) {
	case 1:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = 'X'; shapeArray[3][0] = ' ';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = 'X'; shapeArray[3][1] = ' ';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = 'X'; shapeArray[3][2] = 'X';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	case 2:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = 'X';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = ' '; shapeArray[3][1] = 'X';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = ' '; shapeArray[3][2] = 'X';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = 'X';
		break;
	case 3:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = 'X'; shapeArray[3][0] = 'X';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = 'X'; shapeArray[3][1] = 'X';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = ' '; shapeArray[3][2] = ' ';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	case 4:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = 'X'; shapeArray[3][0] = 'X';
		shapeArray[0][1] = ' '; shapeArray[1][1] = 'X'; shapeArray[2][1] = 'X'; shapeArray[3][1] = ' ';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = ' '; shapeArray[3][2] = ' ';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	case 5:
		shapeArray[0][0] = ' '; shapeArray[1][0] = 'X'; shapeArray[2][0] = 'X'; shapeArray[3][0] = ' ';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = 'X'; shapeArray[3][1] = 'X';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = ' '; shapeArray[3][2] = ' ';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	case 6:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = 'X';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = ' '; shapeArray[3][1] = 'X';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = 'X'; shapeArray[3][2] = 'X';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	case 7:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = 'X'; shapeArray[3][0] = ' ';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = 'X'; shapeArray[3][1] = 'X';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = 'X'; shapeArray[3][2] = ' ';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	}
}

void TetrisShape::populateCopyShapeArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Copy_of_ShapeArray[i][j] = shapeArray[i][j];
		}

	}
}

void TetrisShape::populateShapeArrayReverse(int shapeType)
{
	switch (shapeType) {
	case 11:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = 'x';
		shapeArray[0][1] = ' '; shapeArray[1][1] = 'X'; shapeArray[2][1] = 'X'; shapeArray[3][1] = 'X';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = ' '; shapeArray[3][2] = ' ';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	case 12:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = 'X'; shapeArray[3][0] = 'X';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = ' '; shapeArray[3][1] = 'X';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = ' '; shapeArray[3][2] = 'X';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	case 21:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = ' ';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = ' '; shapeArray[3][1] = ' ';
		shapeArray[0][2] = 'X'; shapeArray[1][2] = 'X'; shapeArray[2][2] = 'X'; shapeArray[3][2] = 'X';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	case 41:
		shapeArray[0][0] = ' '; shapeArray[1][0] = 'X'; shapeArray[2][0] = ' '; shapeArray[3][0] = ' ';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = 'X'; shapeArray[3][1] = ' ';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = 'X'; shapeArray[3][2] = ' ';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = 'X';
		break;
	case 42:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = ' '; shapeArray[3][0] = 'X';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = 'X'; shapeArray[3][1] = ' ';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = 'X'; shapeArray[3][2] = ' ';
		shapeArray[0][3] = ' '; shapeArray[1][3] = 'X'; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	case 71:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = 'X'; shapeArray[3][0] = ' ';
		shapeArray[0][1] = ' '; shapeArray[1][1] = 'X'; shapeArray[2][1] = 'X'; shapeArray[3][1] = 'X';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = ' '; shapeArray[3][2] = ' ';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' '; shapeArray[3][3] = ' ';
		break;
	case 72:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = ' ', shapeArray[3][0] = 'X';
		shapeArray[0][1] = ' '; shapeArray[1][1] = ' '; shapeArray[2][1] = 'X', shapeArray[3][1] = 'X';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = ' ', shapeArray[3][2] = 'X';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' ', shapeArray[3][3] = ' ';
		break;
	case 73:
		shapeArray[0][0] = ' '; shapeArray[1][0] = ' '; shapeArray[2][0] = ' ', shapeArray[3][0] = ' ';
		shapeArray[0][1] = ' '; shapeArray[1][1] = 'X'; shapeArray[2][1] = 'X', shapeArray[3][1] = 'X';
		shapeArray[0][2] = ' '; shapeArray[1][2] = ' '; shapeArray[2][2] = 'X', shapeArray[3][2] = ' ';
		shapeArray[0][3] = ' '; shapeArray[1][3] = ' '; shapeArray[2][3] = ' ', shapeArray[3][3] = ' ';
		break;

	}
}

TetrisShape::~TetrisShape()
{
}
