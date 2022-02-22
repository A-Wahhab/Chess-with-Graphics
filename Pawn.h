#pragma once
#include"Pieces.h"
class Pawn :virtual public Pieces
{
public:
	Pawn(Position p, Color c, Board* b) :Pieces(p, c, b)
	{	}
	virtual bool IsLegal(Position Ep)override;
	bool IsPawn()override
	{
		return true;
	}
	virtual void Draw();
	virtual void UnDraw();
};