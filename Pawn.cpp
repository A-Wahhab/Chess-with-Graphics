#include"Pawn.h"
#include"Board.h"
bool Pawn::IsLegal(Position Ep)
{
	int dr = Ep.ri - P.ri, dc = Ep.ci - P.ci;
	if ((C == black && dr < 0) || (C == white && dr > 0))
	{
		if (dc == 0 && abs(dr) == 1 && B->B[Ep.ri][Ep.ci] == nullptr)
			return true;
		if (dc == 0 && abs(dr) == 2 && (P.ri == 6 || P.ri == 1) && B->B[Ep.ri][Ep.ci] == nullptr)
			return true;
		if (isDiagonalMove(P, Ep) && abs(dr) == 1 && abs(dc) == 1 && B->B[Ep.ri][Ep.ci] != nullptr)
			return true;
	}
	return false;
}
void Pawn::Draw()
{
	int rdim = 400 / 8, cdim = 400 / 8;
	if (C == white)
	{
		setcolor(WHITE);
		circle(P.ci * cdim + 25, P.ri * rdim + 25, 5);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(P.ci * cdim + 25, P.ri * rdim + 25, WHITE);
		cout << 'p';
	}
	else
	{
		setcolor(BLACK);
		circle(P.ci * cdim + 25, P.ri * rdim + 25, 5);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(P.ci * cdim + 25, P.ri * rdim + 25, BLACK);
		cout << 'P';
	}
}
void Pawn::UnDraw()
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