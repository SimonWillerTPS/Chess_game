#include "Game.hpp"

using namespace std ;

#define CHECK(op) do { if ((op) == NULL) usage (#op) ; } while (0) 
#define MYNEW new (nothrow)

int main ( void )
{
	Game* chess_game ;
	CHECK ( chess_game = MYNEW Game ) ;

	chess_game->say_welcome() ;

	do
	{
		chess_game->play() ;
	}
	while ( chess_game->get_act() != QUIT ) ;

	delete chess_game ;

	return 0 ;
}