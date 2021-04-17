#include "usefull_functions.hpp"
#define USAGE_ERROR 2
using namespace std ;


void usage( string msg )
{
	cerr << "Usage : " << msg << endl ;
	exit ( USAGE_ERROR ) ;
}


int my_strtol ( string str )
{
	char* tester ;
	int result = strtol ( str.c_str () , &tester , 10 ) ;

	if ( ( result  == 0 ) && ( tester == str ) )
		usage ( "String conversion error" ) ;
	
	else 
		return result ;

	return USAGE_ERROR ;
}


int get_nb_of_line ( string coordinates )
{
	if ( coordinates.length() > 2 )
		usage ( "Bad coordinates (length)" ) ;
	
	int line = my_strtol ( & ( coordinates[1] ) ) ;
	
	if ( ( line >= 0 ) && ( line <= 8 ) ) 
		return abs ( line - 8 ) ;

	else
		usage ( "Bad coordinates (out of range)" ) ;
	
	return ( USAGE_ERROR ) ;
}


int get_nb_of_column ( string coordinates )
{
	if ( coordinates.length () > 2 )
		usage ("Bad coordinates (length)" ) ;

	int column = coordinates[0] - 'a' ;

	if ( ( column >= 0 ) && ( column <= 8 ) ) 
		return column ;

	else
		usage ( "Bad coordinates (out of range)" ) ;

	return USAGE_ERROR ;
}