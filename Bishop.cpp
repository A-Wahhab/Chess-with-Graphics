#include "Bishop.h"
Bishop::Bishop(Position p, Color c, Board* b) :Pieces(p, c, b)
{	}
bool Bishop::IsLegal(Position Ep)
{
	return (isDiagonalMove(P, Ep) && isDiagonalPathClear(P, Ep, B));
}
void Bishop::Draw()
{
	int rdim = 400 / 8, cdim = 400 / 8;
	if (C == white)
	{
		setcolor(WHITE);
		line(P.ci * cdim + 20, P.ri * rdim + 15, P.ci * cdim + 30, P.ri * rdim + 30);
		line(P.ci * cdim + 20, P.ri * rdim + 15, P.ci * cdim + 15, P.ri * rdim + 30);
		line(P.ci * cdim + 15, P.ri * rdim + 30, P.ci * cdim + 30, P.ri * rdim + 30);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(P.ci * cdim + 25, P.ri * rdim + 25, WHITE);
		cout << 'b';
	}
	else
	{
		setcolor(BLACK);
		line(P.ci * cdim + 20, P.ri * rdim + 15, P.ci * cdim + 30, P.ri * rdim + 30);
		line(P.ci * cdim + 20, P.ri * rdim + 15, P.ci * cdim + 15, P.ri * rdim + 30);
		line(P.ci * cdim + 15, P.ri * rdim + 30, P.ci * cdim + 30, P.ri * rdim + 30);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(P.ci * cdim + 25, P.ri * rdim + 25, BLACK);
		cout << 'B';
	}
}
void Bishop::UnDraw()
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