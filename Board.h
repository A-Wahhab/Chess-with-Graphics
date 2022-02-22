#pragma once
#include<fstream>
#include<time.h>
#include"graphics.h"
#include"Pieces.h"
#include"Position.h"
#include"Pawn.h"
#include"Rook.h"
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Queen.h"
class Board
{
	char HL[8][8];
	Pieces* B[8][8];
	Pieces* Undo[8][8];
	Position S, E;
	Color Turn;
	friend class Pieces;
	friend class Pawn;
public:
	Board();
	void Init(const char *FN);
	void SelectPiece();
	void SelectDestination();
	bool IsValidSelection();
	bool IsValidDestination();
	bool check(Pieces *b[8][8]);
	bool selfcheck(Position s, Position e);
	bool checkmate();
	bool AnyMoveLeft();
	void Highlight();
	void UnHighlight();
	void Play();
	void TurnChange();
	void DisplayMessage();
	void PrintBoard();
	void Grid();
	Position kingposition(Pieces* b[8][8]);
	void Move(Position S, Position E);
	void SaveGame(Pieces* b[8][8]);
	void CopyBoard();
	void PawnPromotion();
	~Board()
	{	}
};

