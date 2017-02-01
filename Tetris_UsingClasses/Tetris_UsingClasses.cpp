// Tetris_UsingClasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <string>
#include "Bucket.h"
#include <iostream>
#include <time.h>
#include "Windows.h"
#include <conio.h>
using namespace std;
//declarations
int up_down = - 3;
int left_right = 5;
int sleep_in_mili = 400;
int Up_Pressed = 0;
int Score = 0;
//functions
void getUserInput(TetrisShape & localTetrisShape, int & up, int & end_game, int & randomNumber);//input
bool collision(Bucket current_bucket, TetrisShape localTetrisShape, int x, int y);//move down function check
//main entry point
int main()
{
	Bucket CurrentBucket;
	CurrentBucket.InitBucket();//create bucket
	CurrentBucket.Copy_Bucket();//copy from private to public
	CurrentBucket.displayBucket();//display
	TetrisShape CurrentShape;
	int random = rand() % 7 + 1;
	CurrentShape.populateShapeArray(random);//create shape
	int EndOfGame = 0;
	while (EndOfGame==0)//loop
	{
		setCursorTo(13, 5);
		cout << "Score: " << Score;
		CurrentBucket.updateBukcet(CurrentShape, up_down, left_right);//update
		setCursorTo(0, 1);//update one on top of the other
		CurrentBucket.displayBucket();//display 
		getUserInput(CurrentShape, Up_Pressed, EndOfGame, random);//input
		CurrentBucket.Clearmistakes(up_down - 1);//anoying x's that are corrupted
		CurrentBucket.ClearRow(Score);//cear row
		up_down++;
		sleep(sleep_in_mili);//sleep
		if (collision(CurrentBucket, CurrentShape, up_down + 1, left_right))
		{
			CurrentBucket.UpdateOriginalBucket();//copy from copy to original
			CurrentBucket.Copy_Bucket();//copy from private to public
			up_down = -3;
			left_right = 5;
			random = rand() % 7 + 1;//new random shape
			CurrentShape.populateShapeArray(random);//create shape
		}
	}
    return 0;
}
//get input 
void getUserInput(TetrisShape & localTetrisShape, int & up, int & end_game, int & randomNumber)
{
	TetrisShape reverse;
	setCursorTo(13, 1);
	cout << "up! " << up;
	setCursorTo(13, 2);
	cout << "End! " << end_game;
	setCursorTo(13, 3);
	cout << "Random! " << randomNumber;
	//my keyboard keys
#define	KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27
	//I need the user input
	int KB_code = 0;//store arrow struck
	while (_kbhit()) //get input without interupting
	{
		KB_code = _getch();//get the arrow
	}//input
	if (KB_code == 27)
	{
		end_game = 1;
	}
	switch (KB_code)//what to do depending on the arrow
	{
	case KB_LEFT:
		//Do something
		left_right--;
		break;

	case KB_RIGHT:
		//Do something
		left_right++;
		break;
	case KB_DOWN:
		//Do something
		sleep_in_mili = sleep_in_mili - 100;
		//processDownArrow(curentShape);
		break;
	case KB_UP:
		up++;
		setCursorTo(13, 1);
		cout << "up! " << up;
		switch (randomNumber)
		{
		case 1:
			if (up == 1)
			{
				reverse.populateShapeArray(6);
				localTetrisShape = reverse;
				break;
			}
			if (up == 2)
			{
				reverse.populateShapeArrayReverse(11);
				//change
				localTetrisShape = reverse;
				break;
			}
			if (up == 3)
			{
				reverse.populateShapeArrayReverse(12);
				//change
				localTetrisShape = reverse;
				break;
			}
			else
			{
				reverse.populateShapeArray(1);
				localTetrisShape = reverse;
				up = 0;
				break;
			}

		case 2:
			if (up == 1)
			{
				reverse.populateShapeArrayReverse(21);
				//change
				localTetrisShape = reverse;
				break;
			}
			else
			{
				reverse.populateShapeArray(2);
				localTetrisShape = reverse;
				up = 0;
				break;
			}
		case 4:
			if (up == 1)
			{
				reverse.populateShapeArray(5);
				localTetrisShape = reverse;
				break;

			}
			if (up == 2)
			{
				reverse.populateShapeArrayReverse(41);
				//change
				localTetrisShape = reverse;
				break;
			}
			if (up == 3)
			{
				reverse.populateShapeArrayReverse(42);
				//change
				localTetrisShape = reverse;
				break;
			}
			else
			{
				reverse.populateShapeArray(4);
				localTetrisShape = reverse;
				up = 0;
				break;
			}

		case 7:
			if (up == 1)
			{
				reverse.populateShapeArrayReverse(71);
				localTetrisShape = reverse;
				break;
			}
			if (up == 2)
			{
				reverse.populateShapeArrayReverse(72);
				//change
				localTetrisShape = reverse;
				break;
			}
			if (up == 3)
			{
				reverse.populateShapeArrayReverse(73);
				//change
				localTetrisShape = reverse;
				break;
			}
			else
			{
				up = 0;
				reverse.populateShapeArray(7);
				localTetrisShape = reverse;
				break;
			}
		}
	}
}
//coalition
bool collision(Bucket current_bucket, TetrisShape localTetrisShape, int x, int y)
{
	setCursorTo(13, 4);
	cout << "X: " << up_down << ' ';
	if (x == 22)
	{
		return true;
	}
	for (int i = 3; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//for some reason empty won't work
			if (current_bucket.copy_bucket[i + x - 1][j + y] != ' ' & current_bucket.copy_bucket[i + x][j + y] != '#')
			{
				if (localTetrisShape.Copy_of_ShapeArray[i][j] != ' ')
				{
					//game over
					if (x == -2 || x == -1)
					{
						setCursorTo(25, 20);
						cout << "Game Over";
						sleep(100000);
					}
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}
