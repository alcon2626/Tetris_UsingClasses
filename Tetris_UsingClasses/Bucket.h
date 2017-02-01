#pragma once
#include "TetrisShape.h"
class Bucket
{
private:
	char bucket[25][12];
public:
	Bucket();
	char copy_bucket[25][12];
	void InitBucket();
	void Copy_Bucket();
	void displayBucket();
	void updateBukcet(TetrisShape localTetrisShape, int & x, int & y);
	void UpdateOriginalBucket();
	void Clearmistakes(int x);
	void ClearRow(int & Score);
	~Bucket();
	friend void setCursorTo(int x, int y);//cursor
	friend void sleep(unsigned int mseconds);//sleep
};

