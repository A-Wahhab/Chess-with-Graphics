#pragma once
#include"Queen.h"
class King :virtual public Queen
{
	bool isMove;
public:
	King(Position p, Color c, Board* b) :Pieces(p, c, b)
	{	}
	int Max(int A, int B);
	int MaxAbsDifference(Position Ep);
	bool IsLegal(Position Ep)override;
	bool IsKing()override
	{
		return true;
	}
	virtual void Draw();
	virtual void UnDraw();
	~King()
	{	}
};

