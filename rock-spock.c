/**
 * @file rock-spock.c
 * @brief Play Rock-paper-scissors-lizard-Spock against the machine
 * @details A program that plays a modified version of rock paper scissors.
 * Where it will be played against a machine that randomly picked a choice
 * out of rock, spock, paper, scissors, or lizard.
 * 
 * @author Kassidy Maberry
 * @date 2022/2/11
 * @bugs None
 * @todo Complete
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define COMPUTER 8088
#define PLAYER 1000

#define CHOICES 5

#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'
#define LIZARD 'L'
#define SPOCK 'V'

void move(int who, int move);
int winner(int computer, int player);
void print_winner(int winner, int comp_move, int player_move);
int nrand(int range);
void seed();
int pinput(void);
int pcheck(int player);
void again(void);


int main(void)
{
	int computer;
	int player;
	int senario;

	/* set up the seed value for the random number generator */
	/* call only once */
	seed();

	player = pinput();
	/* otherwise play a game of rock-paper-scissors-lizard-spock */

        /* debug -- you don't need move() to play game  */
	move(PLAYER, player);

        /* generate random number for computers play */
        switch(nrand(CHOICES)) {
        case 0:
                computer = ROCK;
                break;
        case 1:
                computer = PAPER;
                break;
        case 2:
                computer = SCISSORS;
                break;
        case 3:
                computer = LIZARD;
                break;
        case 4:
                computer = SPOCK;
                break;
        }
	

	/*debug -- you don't need this to play the game */
	move(COMPUTER, computer);

	senario = winner(computer, player);
	print_winner(senario, computer, player);
}

/**
 * Asks the player for an input, checks the input if it is accepted and if not
 * it calls upon itself again.
 * @return player or it's updated input.
 */
int pinput(void)
{
	int player;
        int tmp;
	printf("Enter a move:\n");
	printf("R for ROCK\n");
	printf("P for PAPER\n");
	printf("S for SCISSORS\n");
	printf("L for LIZARD\n");
	printf("V for SPOCK\n");
	printf("Q to have SPOCK eat a ROCK while chasing a LIZARD and quit\n");
	printf("Move: ");
	while ((tmp = getchar()) != '\n')
		if (tmp > 94){
                player = tmp - 32;
		} else {
		player = tmp;
		}
	
	player = pcheck(player);
	
	return player;
}

/**
 * Checks if the player input is an accepted input if not it will call pinput()
 * @param player the player's requested action.
 * @return player or it's updated input.
 */
int pcheck(int player)
{
	switch (player){
	case ROCK:
		break;
	case SCISSORS:
		break;
	case SPOCK:
		break;
	case LIZARD:
		break;
	case PAPER:
		break;
	case 'Q':
		printf("Spock ate a rock chasing lizard.\n");
		exit(0);
	default:
		printf("Error| %c is not a accepted input!\n", player);
		player = pinput();
		break;
	}
	return player;
}

/** prints the player's or computer's  move to stdin
 * used in debugging
 * @param who is it the computer or the player's move?
 * @param move what move did they make
 * @return void
 */
void move(int who, int move)
{

	if (who == COMPUTER)
		printf("Computer's play is ");
	else
		printf("Player's play is ");


	switch(move) {
	case ROCK:
		printf("ROCK\n");
		break;
	case PAPER:
		printf("PAPER\n");
		break;
	case SCISSORS:
		printf("SCISSORS\n");
		break;
	case SPOCK:
		printf("SPOCK\n");
		break;
	case LIZARD:
		printf("LIZARD\n");
		break;
    	}
}


/**
 * determines the winner either COMPUTER or PLAYER
 * @param computer the computer's move
 * @param player the player's move
 * @return the winner of the game
 */
int winner(int computer, int player)
{
	int senario;
	if (computer == player){
		senario = 0;
		return senario;
	}
	// Odd = player victory; even = computer victory.
	switch (computer){
	case ROCK:
		switch (player){
			case SPOCK:
				senario = 1;
				break;
			case PAPER:
				senario = 3;
				break;
			case LIZARD:
				senario = 6;
				break;
			case SCISSORS:
				senario = 8;
				break;

		}
		break;
	case PAPER:
		switch (player){
			case ROCK:
				senario = 4;
				break;
			case SPOCK:
				senario = 10;
				break;
			case SCISSORS:
				senario = 11;
				break;
			case LIZARD:
				senario = 13;
				break;
		}
		break;
	case SPOCK:
		switch (player){
			case PAPER:
				senario = 9;
				break;
			case ROCK:
				senario = 2;
				break;
			case LIZARD:
				senario = 15;
				break;
			case SCISSORS:
				senario = 18;
				break;
		
		}
		break;
	case LIZARD:
		switch (player){
			case PAPER:
				senario = 14;
				break;
			case ROCK:
				senario = 5;
				break;
			case SPOCK:
				senario = 16;
				break;
			case SCISSORS:
				senario = 19;
				break;
		
		}
		break;
	case SCISSORS:
		switch (player){
			case PAPER:
				senario = 12;
				break;
			case ROCK:
				senario = 7;
				break;
			case SPOCK:
				senario = 18;
				break;
			case LIZARD:
				senario = 20;
				break;
		
		}
		break;
	
	default:
		break;
	}
	return senario;
}

/**
 * prints the winner of the game to stdin
 * @param winner who won the computer or player
 * @param comp_move what move did the computer make
 * @param play_move what move did the player make
 * @return void
 */
void print_winner(int senario, int comp_move, int player_move)
{

	if (senario == 0){
		printf("An eternal battle with the same thing ensues.\n");
		again();
	} else {
		switch (senario%2)
		{
		case 1:
			printf("Player wins!\n");
			break;
		
		case 0:
			printf("Computer wins!\n");
			break;
		}	
	}
	switch (senario){
	case 1:
	case 2:
		printf("Spock vaporizes rock.\n");
		break;
	case 3:
	case 4:
		printf("Paper covers rock.\n");
		break;
	case 5:
	case 6:
		printf("Rock crushes Lizard.\n");
		break;
	case 7:
	case 8:
		printf("Rock crushes scissors.\n");
		break;
	case 9:
	case 10:
		printf("Paper disproves Spock.\n");
		break;
	case 11:
	case 12:
		printf("Scissors cuts papers.\n");
		break;
	case 13:
	case 14:
		printf("Lizard eats paper.\n");
		break;
	case 15:
	case 16:
		printf("Lizard poisons Spock\n");
		break;
	case 17:
	case 18:
		printf("Spock smashes Scissors.\n");
		break;
	case 19:
	case 20:
		printf("Scissors decapitates lizard.\n");
		break;
	default:
		printf("not accounted for.\n");
		break;
	}
	again();
}

/**
 * returns a uniform random integer n, between 0 <= n < range
 * @param range defines the range of the random number [0,range)
 * @return the generated random number
 */
int nrand(int range)
{
	return rand() % range;
}

/**
 * Asks the user if they would like to play a second time or not
 * if they say yes it will call main again. Otherwise it closes
 * the program.
 */
void again(void)
{
	int tmp;
	int again;
	printf("Y - Yes \nN - No\nPlay again? ");
	while ((tmp = getchar()) != '\n')
		if (tmp > 94){
		again = tmp - 32;
		} else {
		again = tmp;
		}
	switch (again){
		case 'Y':
			main();
			break;
	
		default:
			printf("Closing...\n");
			exit(0);
			break;
	}
		
}

/**
 * call this to seed the random number generator rand()
 * uses a simple seed -- the number of seconds since the epoch
 * call once before using nrand and similar functions that call rand()
 */
void seed(void)
{
  	srand((unsigned int)time(NULL));
}