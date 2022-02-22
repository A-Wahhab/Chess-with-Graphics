#include "Rook.h"
bool Rook::IsLegal(Position Ep)
{
	return ((isHorizontalMove(P, Ep) && isHorizontalPathClear(P, Ep, B)) ||
		(isVerticalMove(P, Ep) && isVerticalPathClear(P, Ep, B)));
}
void Rook::Draw()
{
	int rdim = 400 / 8, cdim = 400 / 8;
	if (C == white)
	{
		setfillstyle(1,WHITE);
		bar(P.ci * rdim + 20, P.ri * rdim + 20, P.ci * rdim + 30, P.ri * rdim + 30);
		cout << 'r';
	}
	else
	{
		setfillstyle(1, BLACK);
		bar(P.ci * rdim + 20, P.ri * rdim + 20, P.ci * rdim + 30, P.ri * rdim + 30);
		cout << 'R';
	}
}
void Rook::UnDraw()
{
	int s = 50;
	if ((P.ri + P.ci) % 2 == 0)
	{
		setfillstyle(SOLID_FILL, LIGHTGRAY);
	}
	else
	{
		setfillstyle(SOLID_FILL, DARKGRAY);
	}
	int x1 = P.ci * s, y1 = P.ri * s, x2 = (P.ci + 1) * s - 0, y2 = (P.ri + 1) * s - 0;
	bar(x1, y1, x2, y2);
}