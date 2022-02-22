#pragma once
#include"Bishop.h"
#include"Rook.h"
class Queen:virtual public Bishop, virtual public Rook
{
public:
	Queen()
	{	}
	Queen(Position p, Color c, Board* b);
	bool IsLegal(Position Ep)override;
	bool IsQueen()override
	{
		return true;
	}
	virtual void Draw();
	virtual void UnDraw();
	~Queen()
	{	}
};