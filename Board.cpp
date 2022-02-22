#include "Board.h"
#include"Position.h"
#include<Windows.h>

Board::Board()
{
	char FN[10];
	cout << "\n\nCHESS GAME.......\n\n";
	cout << "File to Load New.txt/SaveGame.txt: ";
	cin >> FN;
	system("cls");
	Init(FN);
}
void Board::Init(const char* FN)
{
	ifstream rdr(FN);
	char p;
	rdr >> p;
	if (p == '1')
		Turn = white;
	else
		Turn = black;
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			rdr >> p;
			if (p == 'p')
				B[ri][ci] = new Pawn(Position(ri, ci), white, this);
			else if (p == 'P')
				B[ri][ci] = new Pawn(Position(ri, ci), black, this);
			else if (p == 'k')
				B[ri][ci] = new King(Position(ri, ci), white, this);
			else if (p == 'K')
				B[ri][ci] = new King(Position(ri, ci), black, this);
			else if (p == 'q')
				B[ri][ci] = new Queen(Position(ri, ci), white, this);
			else if (p == 'Q')
				B[ri][ci] = new Queen(Position(ri, ci), black, this);
			else if (p == 'b')
				B[ri][ci] = new Bishop(Position(ri, ci), white, this);
			else if (p == 'B')
				B[ri][ci] = new Bishop(Position(ri, ci), black, this);
			else if (p == 'h')
				B[ri][ci] = new Knight(Position(ri, ci), white, this);
			else if (p == 'H')
				B[ri][ci] = new Knight(Position(ri, ci), black, this);
			else if (p == 'r')
				B[ri][ci] = new Rook(Position(ri, ci), white, this);
			else if (p == 'R')
				B[ri][ci] = new Rook(Position(ri, ci), black, this);
			else 
				B[ri][ci]=nullptr;
		}
	}
}
void Board::SelectPiece()
{
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
		delay(500);
	}
	getmouseclick(WM_LBUTTONDOWN, S.ci, S.ri);
	cout << S.ri << " " << S.ci << endl;
	S.ri = S.ri / (400 / 8);
	S.ci = S.ci / (400 / 8);
	cout << S.ri << " " << S.ci;
}
void Board::SelectDestination()
{
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
		delay(500);
	}
	getmouseclick(WM_LBUTTONDOWN, E.ci, E.ri);
	E.ri = E.ri / (400 / 8);
	E.ci = E.ci / (400 / 8);
	cout << E.ri << " " << E.ci;
}
bool Board::IsValidSelection()
{
	return (B[S.ri][S.ci] != nullptr && B[S.ri][S.ci]->GetColor() == Turn);
}
bool Board::IsValidDestination()
{
	return ((B[E.ri][E.ci] == nullptr || B[E.ri][E.ci]->GetColor() != Turn));
}
void Board::CopyBoard()
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			Undo[r][c] = B[r][c];
		}
	}
}
void Board::Play()
{
	bool WIN = false;
	bool sc = false;
	Grid();
	while (!WIN)
	{
	x:
		CopyBoard();
		PrintBoard();
		time_t st = time(0);
		do
		{
			do
			{
				DisplayMessage();
				do
				{
					cout << "\nSelect Piece\n";
					SelectPiece();
					if (S.ri == 0 && S.ci == 8)
					{
						Init("SaveGame.txt");
						TurnChange();
						goto x;
					}
				} while (IsValidSelection() == false);
				Highlight();
				cout << "Select Destination\n";
				SelectDestination();
				if (!IsValidDestination())
					cout << "Invalid Destination\n";
				UnHighlight();
			} while ((!IsValidDestination()));
			if (selfcheck(S, E))
			{
				cout << "\007" << "SelfCheck";
				sc = true;
				delay(1000);
			}
		} while ((!B[S.ri][S.ci]->IsLegal(E)));
		time_t et = time(0);
		time_t t = et - st;
		/*if (t > 60)
		{
			cout << "GAME OVER... TIMES UP..";
			if (Turn == black)
				cout << "WINNER WHITE";
			else
				cout << "WINNER BLACK";
			exit(0);
		}*/
		if (!sc)
		{
			B[S.ri][S.ci]->Move(E);
			PawnPromotion();
			if (check(B))
			{
				cout << "\a" << "Check";
				delay(1000);
			}
			if (checkmate())
			{
				WIN = true;
				cout << "\a" << "Checkmate";
				delay(1000);
			}
			else
				TurnChange();

		}
		SaveGame(Undo);
	}
	if (WIN == true)
	{
		cout << "GAME OVER";
		delay(100000);
		exit(0);
	}
}
void Board::Highlight()
{
	int s = 50;
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			E = Position(r, c);
			if (IsValidDestination() && B[S.ri][S.ci]->IsLegal(E))
			{
				HL[E.ri][E.ci] = '*';
				setcolor(GREEN);
				int x1 = c * s, y1 = r * s, x2 = (c + 1) * s - 0, y2 = (r + 1) * s - 0;
				rectangle(x1, y1, x2, y2);
			}
			else
				HL[E.ri][E.ci] = ' ';
		}
	}
}
void Board::UnHighlight()
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if ((r + c) % 2 == 0)
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
			}
			else
			{
				setfillstyle(SOLID_FILL, DARKGRAY);
			}
			int x1 = c * 50, y1 = r * 50, x2 = (c + 1) * 50 - 0, y2 = (r + 1) * 50 - 0;
			bar(y1, x1, y2, x2);
			HL[r][c] = ' ';
		}
	}
}
void Board::TurnChange()
{
	if (Turn == white)
	{
		Turn = black;
	}
	else if (Turn == black)
	{
		Turn = white;
	}
}
void Board::DisplayMessage()
{
	if (Turn == white)
	{
		cout << "White";
	}
	else
		cout << "Black";
}
void Board::Grid()
{
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	bar(410, 10, 430, 20);
	int s = 50;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if ((x + y) % 2 == 0)
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
			}
			else
			{
				setfillstyle(SOLID_FILL, DARKGRAY);
			}
			int x1 = x * s, y1 = y * s, x2 = (x + 1) * s - 0, y2 = (y + 1) * s - 0;
			bar(y1, x1, y2, x2);
		}
	}
}
void Board::PrintBoard()
{
	system("cls");
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (B[ri][ci] == nullptr)
			{
				cout << "-";
			}
			else
			{
				B[ri][ci]->Draw();
			}
		}
		cout << endl;
	}
}
void Board::Move(Position S, Position E)
{
	B[E.ri][E.ci] = B[S.ri][S.ci];
	B[E.ri][E.ci]->Draw();
	B[S.ri][S.ci]->UnDraw();
	B[S.ri][S.ci] = nullptr;
}
Position Board::kingposition(Pieces* b[8][8])
{
	int x = 0, y = 0;
	TurnChange();
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (b[r][c] != nullptr && b[r][c]->GetColor() == Turn && b[r][c]->IsKing() == true)
			{
				x = r;
				y = c;
				Position Kp(x, y);
				TurnChange();
				return Kp;
			}
		}
	}
}
bool Board::check(Pieces *b[8][8])
{
	Position Kp = kingposition(b);
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (b[r][c] != nullptr && b[r][c]->GetColor() == Turn && b[r][c]->IsLegal(Kp))
			{
				return true;
			}
		}
	}
	return false;
}
bool Board::selfcheck(Position s,Position e)
{
	Pieces *dB[8][8];
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			dB[r][c] = B[r][c];
	dB[e.ri][e.ci] = dB[s.ri][s.ci];
	dB[s.ri][s.ci] = nullptr;
	//Move(s, e);
	TurnChange();
	if (check(dB))
	{
		TurnChange();
		return true;
	}
	TurnChange();
	return false;
}
bool Board::AnyMoveLeft()
{
	Position Kp = kingposition(B);
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			Position p(r, c);
			if (B[r][c] != nullptr && selfcheck(Kp, p) && B[Kp.ri][Kp.ci]->IsLegal(p))
				return true;
		}
	}
	return false;
}
bool Board::checkmate()
{
	Color T = Turn;
	if (AnyMoveLeft() == false && check(B))
	{
		Turn = T;
		return true;
	}
	else
	{
		Turn = T;
		return false;
	}
}
void Board::SaveGame(Pieces* b[8][8])
{
	ofstream wrt("SaveGame.txt");
	if (Turn == black)
		wrt << 0;
	else
		wrt << Turn;
	wrt << endl;
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (b[r][c] == nullptr)
				wrt << "-";
			else if (b[r][c]->IsPawn() && b[r][c]->GetColor() == white)
				wrt << "p";
			else if(b[r][c]->IsPawn() && b[r][c]->GetColor() == black)
				wrt << "P";
			else if (b[r][c]->IsKing() && b[r][c]->GetColor() == white)
				wrt << "k";
			else if(b[r][c]->IsKing() && b[r][c]->GetColor() == black)
				wrt << "K";
			else if (b[r][c]->IsQueen() && b[r][c]->GetColor() == white)
				wrt << "q";
			else if (b[r][c]->IsQueen() && b[r][c]->GetColor() == black)
				wrt << "Q";
			else if (b[r][c]->IsBishop() && b[r][c]->GetColor() == white)
				wrt << "b";
			else if (b[r][c]->IsBishop() && b[r][c]->GetColor() == black)
				wrt << "B";
			else if (b[r][c]->IsKnight() && b[r][c]->GetColor() == white)
				wrt << "h";
			else if (b[r][c]->IsKnight() && b[r][c]->GetColor() == black)
				wrt << "H";
			else if (b[r][c]->IsRook() && b[r][c]->GetColor() == white)
				wrt << "r";
			else if(b[r][c]->IsRook() && b[r][c]->GetColor() == black)
				wrt << "R";
		}
		wrt << endl;
	}
}
void Board::PawnPromotion()
{
	char choice = 0;
	if (B[E.ri][E.ci]->IsPawn() && E.ri == 7 && B[E.ri][E.ci]->GetColor() == white)
	{
		cout << "PAWN PROMOTION";
		cout << "Q-QUEEN, H-KNIGHT, R-ROOK, B-BISHOP";
		cin >> choice;
		switch (choice)
		{
		case 'Q':
			B[E.ri][E.ci] = new Queen(Position(E.ri, E.ci), white, this);
			break;
		case 'H':
			B[E.ri][E.ci] = new Knight(Position(E.ri, E.ci), white, this);
			break;
		case 'R':
			B[E.ri][E.ci] = new Rook(Position(E.ri, E.ci), white, this);
			break;
		case 'B':
			B[E.ri][E.ci] = new Bishop(Position(E.ri, E.ci), white, this);
			break;
		}
	}
	else if (B[E.ri][E.ci]->IsPawn() && E.ri == 0 && B[E.ri][E.ci]->GetColor() == black)
	{
		cout << "PAWN PROMOTION";
		cout << "Q-QUEEN, H-KNIGHT, R-ROOK, B-BISHOP";
		cin >> choice;
		switch (choice)
		{
		case 'Q':
			B[E.ri][E.ci] = new Queen(Position(E.ri, E.ci), black, this);
			break;
		case 'H':
			B[E.ri][E.ci] = new Knight(Position(E.ri, E.ci), black, this);
			break;
		case 'R':
			B[E.ri][E.ci] = new Rook(Position(E.ri, E.ci), black, this);
			break;
		case 'B':
			B[E.ri][E.ci] = new Bishop(Position(E.ri, E.ci), black, this);
			break;
		}
	}
}