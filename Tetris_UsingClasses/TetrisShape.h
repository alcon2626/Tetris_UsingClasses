#pragma once
class TetrisShape
{
private:
	char shapeArray[4][4];
public:
	TetrisShape();
	char Copy_of_ShapeArray[4][4];
	void populateShapeArray(int shapeType);
	void populateCopyShapeArray();
	void populateShapeArrayReverse(int shapeType);
	~TetrisShape();
};

