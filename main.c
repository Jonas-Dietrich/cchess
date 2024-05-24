#include <stdio.h>

typedef struct {
	char col; 
	char row; 
} Position;

typedef struct {
	Position from;
	Position to;
} Move;

typedef enum {
	PAWN,
	BISHOP,
	KNIGHT,
	ROOK,
	QUEEN,
	KING, 
	EMPTY 
} PieceType; 

typedef enum {
	WHITE,
	BLACK,
	NONE
} PieceColor;

typedef struct {
	PieceType type; 
	PieceColor color;
} Piece;

typedef struct {
	Piece piece;
	Position position;
} Square;

typedef struct {
	Square board[8][8];
	int turn;
} Game;


Piece constructPiece(int pos) {
	Piece returnPiece = {PAWN, WHITE};

	switch (pos) {
		case 0: 
		case 7:
			returnPiece.type = ROOK;
			break;
		case 1:
		case 6: 
			returnPiece.type = KNIGHT;
			break;
		case 2: 
		case 5: 
			returnPiece.type = BISHOP;
			break;
		case 3:
			returnPiece.type = QUEEN;
			break;
		case 4:
			returnPiece.type = KING;
			break;
		case 8 ... 15: 
			break;

		case 48 ... 55: 
			returnPiece.color = BLACK;
			break;

		case 56:
		case 63: 
			returnPiece.color = BLACK;
			returnPiece.type = ROOK;
			break;
		case 57: 
		case 62: 
			returnPiece.color = BLACK;
			returnPiece.type = BISHOP;
			break;
		case 58: 
		case 61: 
			returnPiece.color = BLACK;
			returnPiece.type = KNIGHT;
			break;
		case 59: 
			returnPiece.color = BLACK;
			returnPiece.type = KING;
			break;
		case 60: 
			returnPiece.color = BLACK;
			returnPiece.type = QUEEN;
			break;

		default:
			returnPiece.type = EMPTY;
			returnPiece.color = NONE;
			break;
	}
	
	return returnPiece;
}

void initGame(Game * game) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			game -> board[i][j].position.col = 97 + j;
			game -> board[i][j].position.row = 49 + i;

			game -> board[i][j].piece = constructPiece(i * 8 + j);
		}
	}
}


char signFromBoardPiece(Piece piece) {
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
		default: 
			returnChar = '#';
			break;
	
	}

	if (piece.color == BLACK) returnChar += 32;

	return returnChar;
}

void printBoard(Game * game) {
	printf("\n0 A B C D E F G H ");

	for (int i = 0; i < 8; i++) {
		printf("\n%i", i + 1);
		for (int j = 0; j < 8; j++) {
			printf(" %c", signFromBoardPiece(game -> board[i][j].piece));
		}
	}
}


void printMove(Move m) {
	printf("%c %c \n", m.from.col, m.to.row);
}

int main(int argc, char *argv[])
{	
	Move m = {{'a', '1'}, {'b', '2'}};

	printMove(m);
	
	Piece knightHawiBlack = {KNIGHT, BLACK};

	printf("%c ", signFromBoardPiece(knightHawiBlack));

	Game theGame;
	theGame.turn = 1;

	initGame(&theGame);
	printBoard(&theGame);

	return 0;
}
