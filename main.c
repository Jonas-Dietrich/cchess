#include <stdio.h>
// Zweidimensionales array an Squares
// Ein Square hat eine Figur mit farbe drauf
struct Board {

};

struct Position {
	char col; 
	char row; 
};

struct Move {
	struct Position from;
	struct Position to;
};

enum PieceType {
	PAWN,
	BISHOP,
	KNIGHT,
	ROOK,
	QUEEN,
	KING
};

enum PieceColor {
	WHITE,
	BLACK
};

struct Piece {
	enum PieceType type; 
	enum PieceColor color;
};

char signFromBoardPiece(struct Piece piece) {
	char returnChar = 'a';

	switch (piece.type)  {
		case PAWN: 
			returnChar = 'P';
			break;
		case BISHOP: 
			returnChar = 'B';
			break;
		case KNIGHT: 
			returnChar = 'N';
			break;
		case ROOK: 
			returnChar = 'R';
			break;
		case QUEEN: 
			returnChar = 'Q';
			break;
		case KING: 
			returnChar = 'K';
			break;
	}

	printf("%c: %i\n", returnChar, returnChar);

	if (piece.color == BLACK) returnChar += 34;
	
	printf("%c: %i\n", returnChar, returnChar);

	return returnChar;
}


void printMove(struct Move m) {
	printf("%c %c \n", m.from.col, m.to.row);
}

int main(int argc, char *argv[])
{	
	struct Move m = {{'a', '1'}, {'b', '2'}};

	printMove(m);
	
	struct Piece knightHawiBlack = {KNIGHT, BLACK};

	printf("%c ", signFromBoardPiece(knightHawiBlack));

	return 0;
}
