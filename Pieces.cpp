#include "Pieces.h"
#include"Board.h"
void Pieces::Move(Position Ep)
{
	B->Move(P, Ep);
	P = Ep;
}
Color Pieces::GetColor()
{
	return C;
}
bool Pieces::IsLegal(Position Ep)
{
	return IsLegal(Ep);
}
bool Pieces::isHorizontalMove(Position S, Position E)
{
	return S.ri == E.ri;
}
bool Pieces::isVerticalMove(Position S, Position E)
{
	return S.ci == E.ci;
}
bool Pieces::isDiagonalMove(Position S, Position E)
{
	int dr = E.ri - S.ri;
	int dc = E.ci - S.ci;
	return abs(dr) == abs(dc);
}
bool Pieces::isHorizontalPathClear(Position S, Position E, Board* B)
{
	if (S.ci < E.ci)
	{
		for (int i = S.ci + 1; i < E.ci; i++)
			if (B->B[S.ri][i] != nullptr)
				return false;
	}
	else
	{
		for (int i = E.ci + 1; i < S.ci; i++)
			if (B->B[S.ri][i] != nullptr)
				return false;
	}
}
bool Pieces::isVerticalPathClear(Position S, Position E, Board* B)
{
	if (S.ri < E.ri)
	{
		for (int i = S.ri + 1; i < E.ri; i++)
			if (B->B[i][S.ci] != nullptr)
				return false;
	}
	else
	{
		for (int i = E.ri + 1; i < S.ri; i++)
			if (B->B[i][S.ci] != nullptr)
				return false;
	}
}
bool Pieces::isDiagonalPathClear(Position S, Position E, Board* B)
{
	int temp = S.ci;
	if (S.ri > E.ri && E.ci < S.ci)
	{
		for (int i = S.ri - 1; i > E.ri; i--)
		{
			temp--;
			if (B->B[i][temp] != nullptr)
				return false;
		}
		return true;

	}
	if (S.ri > E.ri && E.ci > S.ci)
	{
		for (int i = S.ri - 1; i > E.ri; i--)
		{
			temp++;
			if (B->B[i][temp] != nullptr)
				return false;
		}
		return true;
	}
	if (S.ri < E.ri && E.ci < S.ci)
	{
		for (int i = S.ri + 1; i < E.ri; i++)
		{
			temp--;
			if (B->B[i][temp] != nullptr)
				return false;
		}
		return true;

	}
	if (S.ri < E.ri && E.ci > S.ci)
	{
		for (int i = S.ri + 1; i < E.ri; i++)
		{
			temp++;
			if (B->B[i][temp] != nullptr)
				return false;
		}
		return true;
	}
	return false;
}