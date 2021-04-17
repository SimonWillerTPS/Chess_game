#include "Game.hpp"

using namespace std ;

#define RESET   "\033[0m"
#define BLACK   "\033[1m\033[30m"		/* Bold Black */
#define RED     "\033[1m\033[31m"		/* Bold Red */
#define GREEN   "\033[1m\033[32m"		/* Bold Green */
#define YELLOW  "\033[1m\033[33m"		/* Bold Yellow */
#define BLUE    "\033[1m\033[34m"		/* Bold Blue */
#define MAGENTA "\033[1m\033[35m"		/* Bold Magenta */
#define CYAN    "\033[1m\033[36m"		/* Bold Cyan */
#define WHITE   "\033[1m\033[37m"		/* Bold White */

#define CHECK(op) do { if ((op) == NULL) usage (#op) ; } while (0) 
#define MYNEW new (nothrow)


Game:: Game ()
{
	CHECK ( chessboard = MYNEW Chessboard ) ;
}


Game:: ~Game ()
{
	delete chessboard ;
}


color_t Game:: get_color_playing () const
{
	return color_playing ;
}


input_t Game:: get_act () const 
{
	return act ;
}


void Game:: print_chessboard () const
{
	chessboard->get_king ( color_playing ) ;
	if ( chessboard->check ( color_playing , NULL ))
	{
		cout << YELLOW << "    The " ;
		if ( color_playing == WHT )
			cout << CYAN << "WHITE " ;
		else
			cout << MAGENTA << "BLACK " ;
		cout << YELLOW << "King is in " << RED << "CHECK" ;
		cout << YELLOW << " !" << endl << RESET ;
	}
	cout << "    Last command  : " << BLUE << input << RESET << endl ;
	cout << "    Move number   : " << BLUE << number << RESET << endl ;
	if ( color_playing == WHT )
	{
		cout << "    Color playing : " << CYAN << "WHITE" << RESET ;
		cout << endl ;
	}
	else
	{
		cout << "    Color playing : " << MAGENTA << "BLACK" << RESET ;
		cout << endl ;
	}	
	chessboard->print () ;
}


void Game:: play ()
{
	this->ask_input() ;
	this->check_input() ;
	switch ( act )
	{
		case B_ROQUE :
		case S_ROQUE :
		case MOVE  :
			this->launch_move() ;
			this->print_chessboard() ;
			break ;

		case PRINT :
			this->print_chessboard() ;
			break ;
		
		case HELP :
			this->print_help() ;
			break ;
		
		case QUIT :
			this->say_goodbye() ;
			break ;
		
		default :
			this->print_chessboard() ;
			this->print_error() ;
			this->print_help() ;
			break ;
	}
}


void Game:: ask_input () 
{
	cout << WHITE << "    What do you want to do ? " << RESET ;
	cout << "(help : '" << GREEN << "/help" << RESET << "')" << endl << endl ;
	cout << "    " ;
	cin >> input ; 
	cout << endl ;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl ;
	cout << endl ;
}


void Game:: check_input ()
{
	if (( input == "/help" ) || ( input == "/h" ))
		act = HELP ;

	else if (( input == "/quit" ) || ( input == "/q" ))
		act = QUIT ;

	else if (( input == "/refresh") || ( input == "/r" ))
		act = PRINT ;

	else if (( input == "O-O" ) || ( input == "o-o" ) || ( input == "0-0" ))
		act = S_ROQUE ;

	else if (( input == "O-O-O" ) || ( input == "o-o-o" )
				|| ( input == "0-0-0" ))
		act = B_ROQUE ;

	else if ( this->is_input_classic_move() )
		act = MOVE ;
	
	else 
		act = ELSE ;
}


void Game:: print_help () const
{
	cout << endl << GREEN ;
	cout << "             List of commands :" << RESET << endl << endl ;
	cout << "  - '/help'    (or '/h') : prints this list" << endl ;
	cout << "  - '/quit'    (or '/q') : quits the game" << endl ;
	cout << "  - '/refresh' (or '/r') : refresh the screen" << endl << endl ;
	cout << "  - 'e2e4'               : moves the piece in the" << endl ;
	cout << "                           case e2 to the case e4" << endl ;
	cout << "  - 'O-O'                : does a small roque" << endl ;
	cout << "  - 'O-O-O'              : does a big roque" << endl ;
	cout << endl ;
}


void Game:: say_welcome () const
{
	cout << endl ;
	cout << "     ------------     " << RED << "CHESS GAME" << RESET ;
	cout << "     ------------     " << endl ;
	cout << "          Welcome to my chess game." << WHITE << " Enjoy !" ;
	cout << RESET << endl << endl ;
	this->print_chessboard() ;
}


void Game:: say_goodbye () const
{
	cout << endl << MAGENTA ;
	cout << "    I hope that you enjoyed the game." << endl ;
	cout << "    Thank you for playing, see you soon !" << endl << RESET ;
	cout << endl << endl ;
}


void Game:: print_error () const
{
	cout << endl << RED ;
	cout << "    Invalid command. Move n°" << number << RESET << endl ;
} 


bool Game:: is_input_classic_move () const 
{
	regex mouvmtpattern ( "[a-h][1-8][a-h][1-8]" ) ;
    return regex_match ( input , mouvmtpattern ) ;
}


void Game:: launch_move ()
{
	if ( act == S_ROQUE )
	{
		if ( chessboard->sroque( color_playing ) )
			this->color_switch() ;
		else
		{
			cout << YELLOW << "    Impossible roque. Move n°" << number ;
			cout << RESET << endl << endl ;
		}
	}
	else if ( act == B_ROQUE )
	{
		if ( chessboard->broque( color_playing ) )
			this->color_switch() ;
		else
		{
			cout << YELLOW << "    Impossible roque. Move n°" << number ;
			cout << RESET <<endl << endl ;
		}
	}
	else if ( act == MOVE )
	{
		int from0 = get_nb_of_line ( input.substr( 0 , 2 ) ) ;
		int from1 = get_nb_of_column ( input.substr( 0 , 2 ) ) ;
		int to0 = get_nb_of_line ( input.substr( 2 , 2 ) ) ;
		int to1 = get_nb_of_column ( input.substr( 2 , 2 ) ) ;

		if ( chessboard->classic_move( from0 , from1 ,
								 	   to0 , to1 , color_playing ) )
			this->color_switch() ;
	}
}


void Game:: color_switch ()
{
	if ( color_playing == WHT )
		color_playing = BLK ;
	else
		color_playing = WHT ;
	
	number ++ ;
}