//Spencer Krum
//Assignment 5
// March 15, 2010
//CS 161-1, Karla Fant
//dbad license
//Oddly game

/* algorithim

My function:
First it declares variables and global environment stuff
Then it starts a very short main loop
Then it informs the user of whats happening and calls a status function
Then it begins its first turn, executes, calls the status function, and picks the next person who will have a turn.
Then the turn function loops until the win/lose conditions are met, which is anyone scoring 10 or more points.
Then it declares the winner as the person who did not score 10 points.
This could be pretty trivially expanded out into multiple users.


*/

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>


using namespace std;
//some useful global variables

int playerScore[2] = {0,0};
int round = 0;

string currentPlayer = "Gamestart";	//gamestart is teh guy who is playing before everyone else gets there
string otherPlayer = "Gamestart's evil twin";
string player1 = "Player One";
string player2 = "Player Two";
string gamestart = "Gamestart";




					//variable declarations i think
void setupGame();
void statusGame();
void nextTurn();
void winner();
string jumble(string& word);


int main(){				//short and sweet main, left the deffinition of game over inside a while loop	
	srand(time(0));
	setupGame();
	while (!((playerScore[0] == 10 ) || ( playerScore[1] == 10))){ //had to throw a not in there to get the behavior i wanted, pulled out a few hairs trying to figure it out as well.
	nextTurn();
	}
	winner();
	return 0;
}

void setupGame(){		
	//tell the audience what is up
	cout << "Assignment 5 - Spencer Krum\n";
	cout << "Welcome!\n";
	cout << "Today we are playing the word jumble game. You will give a word\n";
	cout << " to the computer which will jumble it. \nYou and a buddy will ";
	cout << "take turns trying to guess the other guy's word. \n";
	cout << "Each time you guess wrong you get a point. If your opponent reaches 10  \n";
	cout << "points before you, you win! Good Luck and follow on screen instructions!\n";
	statusGame();
	
}	

//function to tell the user the status of the game as it moves forward
void statusGame(){	
	cout << "The current game status is: \n";
	cout << "Player One has " << playerScore[0] << ".\n";
	cout << "Player Two has " << playerScore[1] << ".\n";
	cout << "It is now round " << round << ".\n";
	cout << "It is now " << currentPlayer << "'s turn to pick a word.\n" ;
	cout << "And it is now " << otherPlayer << "'s turn to guess at it. \n";
}


void nextTurn(){
	if (currentPlayer == gamestart){ 	//then it is the very first turn of the very first round
		currentPlayer = player1;
		otherPlayer = player2;
		round = 1;
	}
	cout << "It is now " << currentPlayer << "'s turn. Which word would you like to use? Max 10 chars.\n";
	string word;
	cin >> word;
	cout << "You have entered " << word << "\n" << endl;
	if (word.size() > 10){
	 	cout << "Your selections are incompatible with the physical system. Try again.\n"; //smarmy kids trying to ruin the game for everyone
		nextTurn();
	}
	cout << "Clearing screen: \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	string jumbled = jumble(word);
	string guess;
	while (guess != word){
	cout << otherPlayer << ", it is your turn. Guess at will. The hint is: " << jumbled << "\n";
	cin >> guess;
	if (guess == word){
		cout << "Great Job! You guessed the word.\n";
	}
	else{
		cout << "That wasn't the word. Try again.\n";
		if (currentPlayer == player1){
			playerScore[1] += 1;
			statusGame();
		}
		else{
			playerScore[0] += 1;
			statusGame();		
		}
	}
	}
	if (currentPlayer == player1){
		currentPlayer = player2;
		otherPlayer = player1;
		statusGame();
	}
	else{
		round +=1;				//keeping track of rounds seems like a good idea
		currentPlayer = player1;
		otherPlayer = player2;		//by using a next step and currentPlayer model, this could be expanded to more players without too much grief.
		statusGame();		
	}
}

void winner(){
	if ((playerScore[0] == 10)) {
		cout << "Congratulations " << player2 << ". You won the game!\n" <<endl; //this win decision system makes it a lot easier for player one to win by cheating, but I like to assume an honest world. 
	}
	else{
		cout << "Congratulations " << player1 << ". You won the game!\n" <<endl; 
	}
}


string jumble(string& word){		//this guy grabs the word by reference, then jogs through it a few times mixing it all up, finally it returns a string, i think its returning the string
					//by value
	
	string jumble_word = word;
	int length = jumble_word.size();
	for (int i = 0; i < length; ++i){
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char t = jumble_word[index1];
		jumble_word[index1] = jumble_word[index2];
		jumble_word[index2] = t;
	}
	cout << jumble_word;
 	return jumble_word;
}