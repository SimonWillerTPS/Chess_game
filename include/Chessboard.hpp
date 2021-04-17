#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

/**
 * @file	Chessboard.hpp
 * @brief	Chessboard and methods.
 * @author	Simon Willer
 */

#include "Pieces.hpp"

/**
 * @brief	Chessboard used to play the Chess game.
 * 
 * Basically a 2 dimensions array of pieces with all the methods
 * used to manage the game.
 */
class Chessboard
{
	private : 
		Pieces* pieces[8][8] ; /**< Pointer to a 2 dimension array of Pieces*/
		int from[2] ;
		int to[2] ;
		int buf1[2] ;
		int buf2[2]	;

	public :
	
		/**
		 * @brief	Constructor of the class Chessboard.
		 * 
		 * Creates the chessboard used to start a Chess game : all the pieces
		 * are places at the right place
		 */
		Chessboard	() ;

		/**
		 * @brief	Destructor of the class Chessboard.
		 * 
		 * Free the memory used by the pieces still active on the chessboard
		 */
		~Chessboard	() ;

		/**
		 * @brief	Prints the chessboard and the pieces still "alive"
		 */
		void print () const ;

		/**
		 * @brief	Returns a pointer to the Pieces placed at the coordinates
		 * 			given.
		 */
		Pieces* get_pieces ( int coord[2] ) const ;

		/**
		 * @brief	Launchs the moving phase
		 * 
		 * It checks if the move that the user wants to do is legal at all
		 * levels : geometrically and if it follows Chess rules (it
		 * refers to all the sub_methods made for each type of piece)
		 * 
		 * All those functions return a bool, allowing to check and print
		 * what needs to be printed
		 */
		bool classic_move ( int from0 , int from1 , int to0 , 
							int to1 , color_t color ) ;

		/**
		 * @brief	Checks if the move respects the rules regarding the
		 * 			King's moves.
		 */
		bool move_King ( int from_[2] , int to_[2] ) ;

		/**
		 * @brief	Checks if the move respects the rules regarding the
		 * 			Queens's moves.
		 */
		bool move_Queen ( int from_[2] , int to_[2] ) ;

		/**
		 * @brief	Checks if the move respects the rules regarding the
		 * 			Rook's moves.
		 */
		bool move_Rook ( int from_[2] , int to_[2] ) ;

		/**
		 * @brief	Checks if the move respects the rules regarding the
		 * 			Bishop's moves.
		 */
		bool move_Bishop ( int from_[2] , int to_[2] ) ;

		/**
		 * @brief	Checks if the move respects the rules regarding the
		 * 			Knight's moves.
		 */
		bool move_Knight ( int from_[2] , int to_[2] ) ;

		/**
		 * @brief	Checks if the move respects the rules regarding the
		 * 			Pawn's moves.
		 */
		bool move_Pawn (  int from_[2] , int to_[2] , bool taking ) ;

		/**s
		 * @brief	Launch the small roque after checking if it is possible
		 * 			to do so, regarding the rules of Chess.
		 */
		bool sroque ( color_t color ) ;
		
		/**
		 * @brief	Launch the big roque after checking if it is possible
		 * 			to do so, regarding the rules of Chess.
		 */
		bool broque ( color_t color ) ;
	
		/**
		 * @brief	Sets the couple buf1 at the coordinates of the King of
		 * 			the color given in argument.
		 */
		void get_king ( color_t color ) ;

		/**
		 * @brief	Check if the King from the color given is in check.
		 */
		bool check ( color_t color , int coord_King[2] ) ;
}	;

#endif