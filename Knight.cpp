#include "Knight.h"
bool Knight::IsLegal(Position Ep)
{
	int dr = abs(Ep.ri - P.ri);
	int dc = abs(Ep.ci - P.ci);
	return ((dr == 1 && dc == 2) || (dr == 2 && dc == 1));
}
void Knight::Draw()
{
	int rdim = 400 / 8, cdim = 400 / 8;
	if (C == white)
	{
		setcolor(WHITE);
		pieslice(P.ci * rdim + 20, P.ri * rdim + 30, 0, 90, 15);
		cout << 'h';
	}
	else
	{
		setcolor(BLACK);
		pieslice(P.ci * rdim + 20, P.ri * rdim + 30, 0, 90, 15);
		cout << 'H';
	}
}
void Knight::UnDraw()
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