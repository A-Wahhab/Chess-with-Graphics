#pragma once
#include"Pieces.h"
class Knight :virtual public Pieces
{
public:
	Knight(Position p, Color c, Board* b) :Pieces(p, c, b)
	{	}
	bool IsLegal(Position Ep)override;
	bool IsKnight()override
	{
		return true;
	}
	virtual void Draw();
	virtual void UnDraw();
	~Knight()
	{	}
};
