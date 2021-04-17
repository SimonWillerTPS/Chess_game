#ifndef USEFULL_FUNCTIONS_HPP
#define USEFULL_FUNCTIONS_HPP

/**
 * @file 	usefull_functions.hpp
 * @brief	Functions used in the Chess game.
 * @author	Simon Willer
 */

#include <iostream>
#include <vector>
#include <string>
#include <regex>

/**
 * @brief	Prints an error message in the error output and exits the
 * 			program with the code 2.
 * @param 	str string to print.
 */
void usage ( std::string str ) ;

/**
 * @brief	Read an integer in a string.
 * 
 * Uses the function strtol to convert a string to an integer
 * and tests the case where the int to convert is 0. If the function
 * does not succeed to read an integer, it quits the program with
 * the function "usage".
 * 
 * @param	str string where to read the integer.
 * @return	integer read in the string
 */
int my_strtol ( std::string str ) ;

/**
 * @brief	Converts the first caracter of a string used is the Chess game.
 * 			It is used for the coordinates system used to represent
 * 			the chessboard of the game.
 * @param  	coordinates a string of length 2, matching the format [a-h][1-8]
 * @return	integer resulting from the following conversion
 * 			'8' returns 0 , '7' returns 1 , ... , '1' returns 7.
 */
int get_nb_of_line ( std::string coordinates ) ;

/**
 * @brief	Converts the second caracter of a string used in the Chess game.
 * 			It is used for the coordinates system used to represent
 * 			the chessboard of the game.
 * @param 	coordinates a string of length 2, matching the format [a-h][1-8]
 * @return	integer resulting from the following conversion :
 * 			'a' returns 0 , 'b' retruns 1 , ... , 'h' returns 7.
 */
int get_nb_of_column ( std::string coordinates ) ;

#endif