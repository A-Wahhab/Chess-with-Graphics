#pragma once
#include"Pieces.h"
class Bishop : virtual public Pieces
{
public:
	Bishop()
	{	}
	Bishop(Position p, Color c, Board* b);
	bool IsLegal(Position Ep)override;
	bool IsBishop()override
	{
		return true;
	}
	virtual void Draw();
	virtual void UnDraw();
	~Bishop()
	{	}
};