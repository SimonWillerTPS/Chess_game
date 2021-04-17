#ifndef GAME_HPP
#define GAME_HPP

/**
 * @file	Game.hpp
 * @brief	Game and methods.
 * @author	Simon Willer
 */

#include "Chessboard.hpp"

/**
 * @brief	Defines the action that the user wants to do.
 */
typedef enum { 	HELP , MOVE , S_ROQUE , 
				B_ROQUE , QUIT , PRINT , 
				ELSE } input_t ;

/**
 * @brief	This class stands to control the chessboard and and to take
 * 			care of the user's commands, as for most of the printing part.
 */
class Game
{
	private :
		Chessboard*	chessboard ;	/**< Chessboard of the game*/
		color_t		color_playing = WHT;	/**< Color curently playing*/
		input_t		act ;	/**< Action that the user wants to do*/
		std::string input = "" ; /**< String to stock the command of the user*/
		int			number = 1 ; /**< Move number*/

	public :

		/**
		 * @brief	Constructor to launch a chess game.
		 */
		Game () ;
		/**
		 * @brief	Destructor to free the memory used by a chess game.
		 */
		~Game () ;

		/**
		 * @brief	Accessor to access to the color currently playing.
		 */
		color_t get_color_playing () const ;
		
		/**
		 * @brief	Accessor to know which action was lastly made by the user.
		 */
		input_t get_act () const ;

		/**
		 * @brief	Shows the chessboard at the current state of game.
		 */
		void print_chessboard () const ;
		
		/**
		 * @brief	Launchs the next turn of the chess game.
		 */
		void play () ;

		/**
		 * @brief	Gets the next command of the user after asking him.
		 */
		void ask_input () ;
		
		/**
		 * @brief	Checks what type of command was input by the user.
		 */
		void check_input () ;

		/**
		 * @brief	Prints the list of commands and what they are made for.
		 */
		void print_help () const ;
		
		/**
		 * @brief	Checks if the command made by the user is 
		 * 			a normal chess move.
		 */
		bool is_input_classic_move () const ; 

		/**
		 * @brief	Launchs the move when the program knows that
		 * 			the command given by the user asks to move a piece.
		 */
		void launch_move () ;

		/**
		 * @brief	Prints a goodbye message, free all the memory used and
		 * 			exits the program.
		 */
		void say_goodbye () const ;
		
		/**
		 * @brief	Prints a welcome message & the chessboard ready to start.
		 */
		void say_welcome () const ;
		
		/**
		 * @brief	Prints the error message followed by the help message
		 * 			when the command given is unknown.
		 */
		void print_error () const ;
		
		/**
		 * @brief	Switchs color_playing, used after a move successfully
		 * 			happened.
		 */
		void color_switch () ;


} ;

#endif