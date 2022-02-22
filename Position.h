#pragma once
struct Position
{
	int ri, ci;
public:
	Position() { ri = 0, ci = 0; }
	Position(int r,int c):ri(r),ci(c)
	{	}
	~Position()
	{	}
};

