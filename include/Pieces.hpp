#ifndef PIECES_HPP
#define PIECES_HPP

/**
 * @file	Pieces.hpp
 * @brief	Pieces used in the Chess game.
 * @author	Simon Willer
 */

#include "usefull_functions.hpp"

/**
 * @brief	2 colors used in Chess.
 */
typedef enum { WHT , BLK } color_t ;

/**
 * @brief 	Different types of pieces used in Chess.
 * 
 * This class defines the differents pieces used in chess, with some usefull
 * attributes & methods used in this game.
 */
class Pieces
{
	protected :
		std::string name ;	/**< Name of the piece 
								(for the specific moves)*/
		std::string utf_code ;	/**< Code used to print 
									the pieces in the console*/
		color_t color ;	/**< Color of the piece*/
		bool has_moved = false ;	/**< Bool to know if the piece
											already moved (Pawns, roque, ..)*/

	public :
	
		/**
		 * @brief	Constructor of the class Pieces.
		 * @param	name : type of the piece (redundant but used)
		 * @param	utf_code : code to print the right symbol
		 * @param	color : color_t of the color of the piece
		 */
		Pieces ( std::string name , std::string utf_code , color_t color ) ;

		/**
		 * @brief	Destructor of the class Pieces.
		 */
		virtual	~Pieces () ;

		/**
		 * @brief	Accessor to the name of the piece.
		 */
		std::string get_name () const ;

		/**
		 * @brief	Accessor to the utf8 code of the piece.
		 */
		std::string get_utf_code () const ;

		/**
		 * @brief	Accessor to the color of the piece.
		 */
		color_t get_color () const ;

		/**
		 * @brief	Returns the color of the piece as a string.
		 */
		std::string str_color () const ;

		/**
		 * @brief	Returns the bool representing the fact that the piece
		 * 			already moved.
		 */
		bool has_it_moved () const ;

		/**
		 * @brief	Method to signal that the piece has moved at least once.
		 */
		void it_has_moved () ;

		/**
		 * @brief	Checks if the move between the 2 coordinates does
		 * 			geometrically match the moves that the piece can make.
		 * @param	from array containing the coordinates of the departure
		 * 			of the move to check
		 * @param	to array containing the coordinates of the arrival
		 * 			of the move to check
		 */
		virtual bool is_move_legal ( int from [2] , int to[2] ) = 0 ;

} ;


class King : public Pieces
{
	public :
		King ( std::string utf_code , color_t color ) ;
		~King () ;

		/**
		 * @brief	Checks if the move between the 2 coordinates does
		 * 			geometrically match the moves that the King can make.
		 * @param	from array containing the coordinates of the departure
		 * 			of the move to check
		 * @param	to array containing the coordinates of the arrival
		 * 			of the move to check
		 */
		bool is_move_legal ( int from[2] , int to[2] ) override ;

} ;


class Queen : public Pieces
{
	public :
		Queen			( std::string utf_code , color_t color ) ;
		~Queen			() ;

		/**
		 * @brief	Checks if the move between the 2 coordinates does
		 * 			geometrically match the moves that the Queen can make.
		 * @param	from array containing the coordinates of the departure
		 * 			of the move to check
		 * @param	to array containing the coordinates of the arrival
		 * 			of the move to check
		 */
		bool is_move_legal ( int from[2] , int to[2] ) override ;
		
} ;


class Rook : public Pieces
{
	public :
		Rook ( std::string utf_code , color_t color ) ;
		~Rook () ;

		/**
		 * @brief	Checks if the move between the 2 coordinates does
		 * 			geometrically match the moves that the Rook can make.
		 * @param	from array containing the coordinates of the departure
		 * 			of the move to check
		 * @param	to array containing the coordinates of the arrival
		 * 			of the move to check
		 */
		bool is_move_legal ( int from[2] , int to[2] ) override ;

} ;


class Bishop : public Pieces
{
	public :
		Bishop ( std::string utf_code , color_t color ) ;
		~Bishop () ;

		/**
		 * @brief	Checks if the move between the 2 coordinates does
		 * 			geometrically match the moves that the Bishop can make.
		 * @param	from array containing the coordinates of the departure
		 * 			of the move to check
		 * @param	to array containing the coordinates of the arrival
		 * 			of the move to check
		 */
		bool is_move_legal ( int from[2] , int to[2] ) override ;

} ;


class Knight : public Pieces
{
	public :
		Knight ( std::string utf_code , color_t color ) ;
		~Knight () ;

		/**
		 * @brief	Checks if the move between the 2 coordinates does
		 * 			geometrically match the moves that the Knight can make.
		 * @param	from array containing the coordinates of the departure
		 * 			of the move to check
		 * @param	to array containing the coordinates of the arrival
		 * 			of the move to check
		 */
		bool is_move_legal ( int from[2] , int to[2] ) override ;

} ;


class Pawn : public Pieces
{
	public :
		Pawn ( std::string utf_code , color_t color ) ;
		~Pawn () ;

		/**
		 * @brief	Checks if the move between the 2 coordinates does
		 * 			geometrically match the moves that the Pawn can make.
		 * @param	from array containing the coordinates of the departure
		 * 			of the move to check
		 * @param	to array containing the coordinates of the arrival
		 * 			of the move to check
		 */
		bool is_move_legal ( int from[2] , int to[2] ) override ;

} ;


#endif