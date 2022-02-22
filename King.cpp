#include "King.h"
int King::Max(int A, int B)
{
	return ((A > B) ? A : B);
}
int King::MaxAbsDifference(Position Ep)
{
	return	(Max(abs(P.ri - Ep.ri), abs(P.ci - Ep.ci)));
}
bool King::IsLegal(Position Ep)
{
	if (Queen::IsLegal(Ep) && MaxAbsDifference(Ep) <= 1)
		return true;
	return false;
}
void King::Draw()
{
	int rdim = 400 / 8, cdim = 400 / 8;
	if (C == white)
	{
		setfillstyle(1, WHITE);
		bar(P.ci * rdim + 10, P.ri * rdim + 20, P.ci * rdim + 40, P.ri * rdim + 30);
		bar(P.ci * cdim + 20, P.ri * rdim + 10, P.ci * cdim + 30, P.ri * rdim + 40);
		cout << 'k';
	}
	else
	{
		setfillstyle(1, BLACK);
		bar(P.ci * rdim + 10, P.ri * rdim + 20, P.ci * rdim + 40, P.ri * rdim + 30);
		bar(P.ci * cdim + 20, P.ri * rdim + 10, P.ci * cdim + 30, P.ri * rdim + 40);
		cout << 'K';
	}
}
void King::UnDraw()
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