#include "Chessboard.hpp"

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


Chessboard:: Chessboard ()	
{
	int	i , j ;
	
	for ( i = 0 ; i < 8 ; i ++ )
	{
		for ( j = 0 ; j < 8 ; j ++ )
			pieces[i][j] 		= NULL ;
	}

	CHECK ( pieces[0][0] = MYNEW Rook	( "\u2656" , BLK )) ;
	CHECK ( pieces[0][1] = MYNEW Knight	( "\u2658" , BLK )) ;
	CHECK ( pieces[0][2] = MYNEW Bishop	( "\u2657" , BLK )) ;
	CHECK ( pieces[0][3] = MYNEW Queen	( "\u2655" , BLK )) ;
	CHECK ( pieces[0][4] = MYNEW King	( "\u2654" , BLK )) ;
	CHECK ( pieces[0][5] = MYNEW Bishop	( "\u2657" , BLK )) ;
	CHECK ( pieces[0][6] = MYNEW Knight	( "\u2658" , BLK )) ;
	CHECK ( pieces[0][7] = MYNEW Rook	( "\u2656" , BLK )) ;
	for ( i = 0 ; i < 8 ; i ++ )
		CHECK ( pieces[1][i] = MYNEW Pawn ( "\u2659" , BLK )) ;

	CHECK ( pieces[7][0] = MYNEW Rook	( "\u265C" , WHT )) ;
	CHECK ( pieces[7][1] = MYNEW Knight	( "\u265E" , WHT )) ;
	CHECK ( pieces[7][2] = MYNEW Bishop	( "\u265D" , WHT )) ;
	CHECK ( pieces[7][3] = MYNEW Queen	( "\u265B" , WHT )) ;
	CHECK ( pieces[7][4] = MYNEW King	( "\u265A" , WHT )) ;
	CHECK ( pieces[7][5] = MYNEW Bishop	( "\u265D" , WHT )) ;
	CHECK ( pieces[7][6] = MYNEW Knight	( "\u265E" , WHT )) ;
	CHECK ( pieces[7][7] = MYNEW Rook	( "\u265C" , WHT )) ;
	for ( i = 0 ; i < 8 ; i ++ )
		CHECK ( pieces[6][i] = MYNEW Pawn ( "\u265F" , WHT )) ;
}


Chessboard:: ~Chessboard ()
{
	int	i , j ;
	
	for ( i = 0 ; i < 8 ; i ++ )
		for ( j = 0 ; j < 8 ; j ++ )
		{
			if ( pieces[i][j] != NULL )
				delete pieces[i][j] ;
		}
}


void Chessboard:: print () const
{
	cout << endl ;
	cout << WHITE ;
	cout << "       a     b     c     d     e     f     g     h   " << endl ;
	cout << RESET ;
	cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+" << endl ;
	for ( int i = 0 ; i < 8 ; i ++ )
	{
		cout << " " << WHITE << abs ( i - 8 ) << RESET << "  |" ; 
		for ( int j = 0 ; j < 8 ; j ++ )
		{
			if ( pieces[i][j] != NULL)
				cout << "  " << pieces[i][j]->get_utf_code() << "  |" ;
			else
				cout << "     |" ;
		}
		cout << endl ;
		cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+" ;
		cout << endl ;
	}
 	cout << endl ;
}


Pieces* Chessboard:: get_pieces ( int coord[2] ) const 
{
	return pieces[coord[0]][coord[1]] ;
}


bool Chessboard:: classic_move ( int from0 , int from1 , int to0 , 
								 int to1 , color_t color )
{
	from[0] = from0 ; from[1] = from1 ;
	to[0] = to0 ; to[1] = to1 ;

	Pieces* attacker = pieces[from[0]][from[1]] ;
	Pieces* defender = pieces[to[0]][to[1]] ;

	cout << YELLOW ;
	if ( attacker == NULL )
	{
		cout << "    The case you selected is empty." ;
		cout << RESET << endl << endl ;
		return false ;
	}
	if ( attacker->get_color() != color )
	{
		cout << "    You tried to move a piece from your opponent." ;
		cout << RESET << endl << endl ;
		return false ;
	}
	if (( defender != NULL ) && ( defender->get_color() == color ))
	{
		cout << "    You cannot smash your allies !" ;
		cout << RESET << endl << endl ;
		return false ;
	}

	if ( attacker->is_move_legal( from , to ) )
	{
		bool taking = false ;
		if (( defender != NULL ) 
			&& ( defender->get_color() != attacker->get_color()))
			taking = true ;

		bool move = false ;

		if ( attacker->get_name() == "King" )
			move = this->move_King ( NULL , NULL ) ;
		else if ( attacker->get_name() == "Queen" )
			move = this->move_Queen ( NULL , NULL ) ;
		else if ( attacker->get_name() == "Rook" )
			move = this->move_Rook ( NULL , NULL ) ;
		else if ( attacker->get_name() == "Bishop" )
			move = this->move_Bishop ( NULL , NULL ) ;
		else if ( attacker->get_name() == "Knight" )
			move = this->move_Knight ( NULL , NULL ) ;	
		else if ( attacker->get_name() == "Pawn" )
			move = this->move_Pawn( NULL , NULL , taking ) ;

		if ( move == true )
		{
			if ( taking == true )
			{
				cout << RESET << "    The " ;
				if ( defender->get_color() == WHT )
					cout << CYAN ;
				else
					cout << MAGENTA ;
				cout << defender->str_color() << YELLOW << defender->get_name() ;
				cout << RESET << " has been taken." << endl << endl ;
				delete defender ;
			}

			pieces[to[0]][to[1]] = attacker ;
			pieces[to[0]][to[1]]->it_has_moved() ;
			pieces[from[0]][from[1]] = NULL ;
		}

		if ( !move )
			cout << "    Invalid move." << endl << endl << RESET ;
		else
		{
			cout << RESET ;
			return true ;
		}
	}
	else
	{
		cout << "    Invalid move." << endl << endl << RESET ;
		return false ;
	}
	cout << RESET ;
	return false ;
}


bool Chessboard:: move_King ( int from_[2] , int to_[2] )  
{
	if (!( this->check ( this->pieces[from[0]][from[1]]->get_color() , to_ )))
		return true ;
	
	cout << "    You cannot make this move, your King will be exposed !" ;
	cout << endl ;
	return false ;
}


bool Chessboard:: move_Queen ( int from_[2] , int to_[2] )  
{
	if ( from_ == NULL )
		from_ = from ;
	if ( to_ == NULL )
		to_ = to ;

	if (( from_[0] == to_[0] ) || ( from_[1] == to_[1] ))
		return this->move_Rook ( from_ , to_ ) ;
	else
		return this->move_Bishop ( from_ , to_ ) ;
}


bool Chessboard:: move_Rook ( int from_[2] , int to_[2] )  
{
	if ( from_ == NULL )
		from_ = from ;
	if ( to_ == NULL )
		to_ = to ;

	bool move = true ;	

	if ( from_[0] == to_[0] ) 
	{
		if ( from_[1] > to_[1] )
		{
			for ( int i = from_[1] - 1 ; i > to_[1] ; i -- )
				if ( pieces[from_[0]][i] != NULL )
					move = false ;
		}
		else
		{
			for ( int i = from_[1] + 1 ; i < to_[1] ; i ++ )
				if ( pieces[from_[0]][i] != NULL )
					move = false ;
		}
	}
	else if ( from_[1] == to_[1] ) 
	{
		if ( from_[0] > to_[0] )
		{
			for ( int i = from_[0] - 1 ; i > to_[0] ; i -- )
				if ( pieces[i][from_[1]] != NULL )
					move = false ;
		}
		else
		{
			for ( int i = from_[0] + 1 ; i < to_[0] ; i ++ )
				if ( pieces[i][from_[1]] != NULL )
					move = false ;
		}
	}

	return move ;
}


bool Chessboard:: move_Bishop ( int from_[2] , int to_[2] ) 
{
	bool move = true ;

	if ( from_ == NULL )
		from_ = from ;
	if ( to_ == NULL )
		to_ = to ;

	if ( from_[0] > to_[0] )
	{
		if ( from_[1] > to_[1] )
		{
			for ( int i = 1 ; i < from_[0]-to_[0] ; i ++ )
				if ( pieces[from_[0]-i][from_[1]-i] != NULL )
					move = false ;
		}
		else
		{
			for ( int i = 1 ; i < from_[0]-to_[0] ; i ++ )
				if ( pieces[from_[0]-i][from_[1]+i] != NULL )
					move = false ;
		}
	}
	else
	{
		if ( from_[1] > to_[1] )
		{
			for ( int i = 1 ; i < to_[0]-from_[0] ; i ++ )
				if ( pieces[from_[0]+i][from_[1]-i] != NULL )
					move = false ;
		}
		else
		{
			for ( int i = 1 ; i < to_[0]-from_[0] ; i ++ )
				if ( pieces[from_[0]+i][from_[1]+i] != NULL )
					move = false ;
		}
	}

	return move ;
}


bool Chessboard:: move_Knight ( int from_[2] , int to_[2] ) 
{
	return true ;
}


bool Chessboard:: move_Pawn (  int from_[2] , int to_[2] , bool taking ) 
{
	if ( from_ == NULL )
		from_ = from ;
	if ( to_ == NULL )
		to_ = to ;
	Pieces* attacker = pieces[from_[0]][from_[1]] ;

	bool move = false ;

	if ( attacker->get_color() ==  WHT )
	{
		if (( from_[0] - to_[0] == 2 ) && ( from_[1] - to_[1] == 0 )
			&& ( attacker->has_it_moved() == false )
			&& ( pieces[from_[0]-1][from_[1]] == NULL ))
			move = true ;

		else if (( from_[0] - to_[0] == 1 ) 
				&& ( abs ( from_[1] - to_[1] ) == 1 )
				&& ( taking == true ))
			move = true ;

		else if (( from_[0] - to_[0] == 1 ) && ( from_[1] - to_[1] == 0 )
				&& ( taking == false ))
			move = true ;
	}
	else
	{
		if (( to_[0] - from_[0] == 2 ) && ( from_[1] - to_[1] == 0 )
			&& ( attacker->has_it_moved() == false )
			&& ( pieces[from_[0]+1][from_[1]] == NULL ))
			move = true ;

		else if (( to_[0] - from_[0] == 1 ) 
				&& ( abs ( from_[1] - to_[1] ) == 1 )
				&& ( taking == true ))
			move = true ;

		else if (( to_[0] - from_[0] == 1 ) && ( from_[1] - to_[1] == 0 )
				&& ( taking == false ))
			move = true ;
	}

	return move ;
}


bool Chessboard:: sroque ( color_t color )
{
	int line ;

	if ( color == WHT )
		line = 7 ;
	else
		line = 0 ;

	if (( pieces[line][4] == NULL ) || ( pieces[line][7] == NULL ))
		return false ;
	if (( pieces[line][4]->has_it_moved() != false )
		|| ( pieces[line][7]->has_it_moved() != false ))
		return false ;
	else if (( pieces[line][5] != NULL ) || ( pieces[line][6] != NULL ))
		return false ;
	else
	{
		pieces[line][6] = pieces[line][4] ;
		pieces[line][5] = pieces[line][7] ;
		pieces[line][4] = NULL ;
		pieces[line][7] = NULL ;
		return true ;
	}
}


bool Chessboard:: broque ( color_t color )
{
	int line ;

	if ( color == WHT )
		line = 7 ;
	else
		line = 0 ;

	if (( pieces[line][4] == NULL ) || ( pieces[line][0] == NULL ))
		return false ;
	if (( pieces[line][4]->has_it_moved() != false )
		|| ( pieces[line][0]->has_it_moved() != false ))
		return false ;
	else if (( pieces[line][3] != NULL ) || ( pieces[line][2] != NULL )
			|| ( pieces[line][1] != NULL ))
		return false ;
	else
	{
		pieces[line][2] = pieces[line][4] ;
		pieces[line][3] = pieces[line][0] ;
		pieces[line][0] = NULL ;
		pieces[line][4] = NULL ;
		return true ;
	}
}


void Chessboard:: get_king ( color_t color )
{
	for ( int i = 0 ; i < 8 ; i ++ )
		for ( int j = 0 ; j < 8 ; j ++ )
			if ( pieces[i][j] != NULL )
				if (( pieces[i][j]->get_name() == "King" ) 
					&& ( pieces[i][j]->get_color() == color ))
					{
						buf1[0] = i ;
						buf1[1] = j ;
						break ;
					}
}

bool Chessboard:: check ( color_t color , int coord_King[2] )
{
	if ( coord_King == NULL )
		coord_King = buf1 ;

	bool check = false ;

	for ( int i = 0 ; i < 8 ; i ++ )
		for ( int j = 0 ; j < 8 ; j ++ )
		{
			buf2[0] = i ;
			buf2[1] = j ;

			if ( pieces[i][j] != NULL )
				if (( pieces[i][j]->get_color() != color)
					&& ( pieces[i][j]->is_move_legal( buf2 , coord_King )))
				{
					if ( pieces[i][j]->get_name() == "King" )
						check = this->move_King ( buf2 , coord_King ) ;
					else if ( pieces[i][j]->get_name() == "Queen" )
						check = this->move_Queen ( buf2 , coord_King ) ;
					else if ( pieces[i][j]->get_name() == "Rook" )
						check = this->move_Rook ( buf2 , coord_King ) ;
					else if ( pieces[i][j]->get_name() == "Bishop" )
						check = this->move_Bishop ( buf2 , coord_King ) ;
					else if ( pieces[i][j]->get_name() == "Knight" )
						check = this->move_Knight ( buf2 , coord_King ) ;	
					else if ( pieces[i][j]->get_name() == "Pawn" )
						check = this->move_Pawn ( buf2 , coord_King , true ) ;
				}
		}
	
	return check ;
}