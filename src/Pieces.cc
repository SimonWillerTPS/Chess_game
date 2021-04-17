#include "Pieces.hpp"

using namespace std ;


Pieces:: Pieces	( string name , string utf_code , color_t color )
				: name ( name ) , utf_code ( utf_code ) , color ( color ) 
{
}


Pieces:: ~Pieces () 
{}


string Pieces:: get_name () const
{
	return name ;
}


string Pieces:: get_utf_code () const
{
	return utf_code ;
}


color_t Pieces:: get_color () const 
{
	return color ;
}


string Pieces:: str_color () const 
{
	if ( color == WHT )
		return "White " ;
	else
		return "Black " ;
}


bool Pieces:: has_it_moved () const
{
	return has_moved ;
}


void Pieces:: it_has_moved ()
{
	if ( has_moved == false )
		has_moved = true ;
}


King:: King	( string utf_code , color_t color )
			: Pieces ( "King" , utf_code , color )
{

}


King:: ~King ()
{}


bool King:: is_move_legal ( int from[2] , int to[2] )
{
	if (( abs ( from[0] - to[0] ) <= 1) && ( abs ( from[1] - to [1] ) <= 1 ))
		return true ;
	else 
		return false ;
}


Queen:: Queen	( string utf_code , color_t color )
				: Pieces ( "Queen" , utf_code , color )
{}


Queen:: ~Queen ()
{}


bool Queen:: is_move_legal ( int from[2] , int to[2] )
{
	if (( abs ( from[0] - to[0] ) == abs ( from[1] - to [1] ))
		|| ( from[0] == to[0] ) || ( from[1] == to[1] ))
		return true ;
	else
		return false ;
}


Rook:: Rook	( string utf_code , color_t color )
			: Pieces ( "Rook" , utf_code , color )
{}


Rook:: ~Rook ()
{}


bool Rook:: is_move_legal ( int from[2] , int to[2] )
{
	if (( from[0] == to[0] ) || ( from[1] == to[1] ))
		return true ;
	else
		return false ;
}


Bishop:: Bishop	( string utf_code , color_t color )
				: Pieces ( "Bishop" , utf_code , color )
{}


Bishop:: ~Bishop ()
{}


bool Bishop:: is_move_legal ( int from[2] , int to[2] )
{
	if ( abs ( to[0] - from[0] ) == abs ( to[1] - from[1] ) )
		return true ;
	else
		return false ; 
}


Knight:: Knight	( string utf_code , color_t color )
				: Pieces ( "Knight" , utf_code , color )
{}


Knight:: ~Knight ()
{}


bool Knight:: is_move_legal ( int from[2] , int to[2] )
{
	if ((( abs (from[0] - to[0]) == 2) && ( abs ( from[1] - to[1] ) == 1 ))
		|| (( abs (from[0] - to[0]) == 1) && ( abs ( from[1] - to[1] ) == 2 )))
		return true ;
	else
		return false ;
}


Pawn:: Pawn	( string utf_code , color_t color )
			: Pieces ( "Pawn" , utf_code , color )
{}


Pawn:: ~Pawn ()
{}


bool Pawn:: is_move_legal ( int from[2] , int to[2] )
{
	if ( color == BLK )
	{
		if (( to[0] - from[0] <= 2 ) && abs ( to[1] - from[1] <= 1 ))
			return true ;
		else 
			return false ;
	}
	else
	{
		if (( from[0] - to[0] <= 2 ) && abs ( to[1] - from[1] <= 1 ))
			return true ;
		else
			return false ;
	}
	
}