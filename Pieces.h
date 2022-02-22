#pragma once
#include"graphics.h"
#include"Position.h"
#include<iostream>
using namespace std;
enum Color { black = -1, white = 1 };
class Board;
class Pieces
{
protected:
	Color C;
	Position P;
	Board* B;
public:
	Pieces()
	{	}
	Pieces(Position p, Color c, Board* b) :P(p), C(c), B(b)
	{	}
	virtual bool IsLegal(Position Ep);
	void Move(Position Ep);
	Color GetColor();
	virtual bool IsKing()
	{
		return false;
	}
	virtual bool IsPawn()
	{
		return false;
	}
	virtual bool IsRook()
	{
		return false;
	}
	virtual bool IsQueen()
	{
		return false;
	}
	virtual bool IsBishop()
	{
		return false;
	}
	virtual bool IsKnight()
	{
		return false;
	}
	virtual void Draw()
	{	

	}
	virtual void UnDraw()
	{
		
	}
	~Pieces()
	{	}
protected:
	static bool isHorizontalMove(Position S, Position E);
	static bool isVerticalMove(Position S, Position E);
	static bool isDiagonalMove(Position S, Position E);
	static bool isHorizontalPathClear(Position S, Position E, Board* B);
	static bool isVerticalPathClear(Position S, Position E, Board* B);
	static bool isDiagonalPathClear(Position S, Position E, Board* B);
};