#include "Queen.h"
Queen::Queen(Position p, Color c, Board* b) :Pieces(p, c, b)
{	}
bool Queen::IsLegal(Position Ep)
{
	return Bishop::IsLegal(Ep) || Rook::IsLegal(Ep);
}
void Queen::Draw()
{
	int rdim = 400 / 8, cdim = 400 / 8;
	if (C == white)
	{
		setcolor(WHITE);
		pieslice(P.ci * rdim + 25, P.ri * rdim + 25, 0, 180, 15);
		setfillstyle(1, WHITE);
		bar(P.ci * rdim + 20, P.ri * rdim + 20, P.ci * rdim + 30, P.ri * rdim + 35);
		cout << 'q';
	}
	else
	{
		setcolor(BLACK);
		pieslice(P.ci * rdim + 25, P.ri * rdim + 25, 0, 180, 15);
		setfillstyle(1, BLACK);
		bar(P.ci * rdim + 20, P.ri * rdim + 20, P.ci * rdim + 30, P.ri * rdim + 35);
		cout << 'Q';
	}
}
void Queen::UnDraw()
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