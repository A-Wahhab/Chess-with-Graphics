#pragma once
#include"Pieces.h"
class Rook :virtual public Pieces
{
	bool isMove;
public:
	Rook()
	{	}
	Rook(Position p, Color c, Board* b) :Pieces(p, c, b)
	{	}
	bool IsLegal(Position Ep)override;
	bool IsRook()override
	{
		return true;
	}
	virtual void Draw();
	virtual void UnDraw();
	~Rook()
	{	}
};
