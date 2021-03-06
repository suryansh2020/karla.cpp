//Spencer Krum
//CS161 Assignment #4
//March 14, 2010
//DBAD Licencse 
//Using OpenGL(glut) for graphics
//gl is for openGl functions, GLU for openGL utility, and GLUT for openGL Utility Toolkit




#include <stdlib.h>
#include <string>
#include <iostream>

#include <ctime>

#include <GL/glut.h>
//namespace
using namespace std;
//global variables
bool intro = true;
bool rules = false;
bool game_begin = false;
bool randomized = false;
bool someonesturn = false;
bool Spencer = false;
bool Georgia = false;
bool game_playing = false;
bool pickpile = false;
bool picknum = false;

bool winner = 0;
int playerballs1, playerballs2 = 0;
int pile;					// which pile are we taking from?
int pick;					//how many balls are we taking from the pile

int piles[3] = {0,0,0};				//this creates the three piles as an int array

char player1[] = "Spencer";
char player2[] = "Georgia";

string playerSpencer = "Spencer";
string playerGeorgia = "Georgia";
//variable declarations
void drawPiles();			//draw the balls in their respective piles using glutsolidsphere
void drawInstr();			//prints out instructions before each turn
void youWin(string player);		//yay you win! game over!
void outputError();			//you did something wrong

void handleKeypress (unsigned char key, int x, int y)
{
	//function to deal with keyboard input, x and y are mouse positions (for later?)
	switch (key) {
		case 98:				//98  is the b key
			intro = false;
			game_begin = true;
			break;
		case '\r':				// '\r' is return key
			game_begin = true;
			game_playing =true;
			break;
		case 27: 				//27 is ascii for escape key
			exit(0); 			//its nice to let people quit if they want to
			break; 				//not really necessary, but we all love continuity -->actually very necessary
		case 49: 				//49 is ascii for 1 key
			if (pickpile){
				pick = 1;
			}
			else {
				pile = 1;
			}
			break;
		case 50:
			if (pickpile) {				//50 is ascii for 2 key
			pick = 2;
			}
			else {
			pile = 2;
			}
			break;
		case 51: 				//51 is ascii for 3 key
			if(pickpile) {
			pick = 3;
			}
			else {
			pile = 3;
			}
			break;
		case 52:				//52 is ascii for 4 key
			pick = 4;
			break;
		case 53:				//53 is ascii for 5 key
			pick = 5;
			break;
		case 54:				//54 is ascii for 6 key
			pick = 6;
			break;
		case 55:				//55 is ascii for 7 key
			pick = 7		;
			break;
		case 56:				//56 is ascii for 8 key
			pick = 8;
			break;
		case 57:				//57 is ascii for 9 key
			pick = 9;
			break;

		default:				//catchall
			outputError();
			break;
	}
}


//OpenGl goodness, initalzing 3d, layering, colors
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}


//you want to be able to resize the window? Good thing this function is here!
void handleResize(int w, int h){
	glViewport(0, 0, w, h); 			//set the viewport, affine transformation is involved
	glMatrixMode(GL_PROJECTION); 			//applies subsequent matrix opperations to the projection matrix stack, which means very little to me so far, but commented for posterity
	glLoadIdentity(); 				//replaces the current matrix with the identity matrix
	gluPerspective(	45.0,  				//camera angle
			(double)w / (double)h,  	//width to height ratio
			1.0,				//near z clipping coordinate			
			200.0);				//far z clipping coordinate
}

void update (int value){				//the timer/update function, the value is always zero, glut things, hand waving 
	
	glutPostRedisplay(); 				//tell glut the scene has changed
	glutTimerFunc(25, update, 0);			//tell glut to update again in 25 milliseconds, the function asks glut to call itself again in 25 seconds , recursion?

}


void bitmapString(	float x, //accepts coordinates, where to put the word
			float y,
			float z,
			char *text) { //*text is a pointer its value is the address of the start of the text to print out
	char *p;
	glRasterPos3f(x, y, z);	 //glutbitmapcharacter will automatically advance this one step per character
	
	for (p = text; *p !='\0'; p++){ // move along the memory 
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p); //write down the value in the memory
	}
}
/*
void bitmapStringString(	float x,
				float y,
				float z,
				string *text) {

		glRasterPos3f(x, y, z);
		
		for (int i = 0; i < text.size(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
		}
}
*/
void introFunc(){
	glColor3f(1.0f, 1.0f, 1.0f); 				//white text is esay to read isn't it?
	char title[] = "Assignment 4 - Spencer Krum";		//output to user
	bitmapString(-2.0f, 1.5f, 0.0f, title);
	char welcome[] = "Welcome! You can exit with the escape key.";
	bitmapString(-2.0f, -1.0f, 0.0f, welcome);
	char beginthegame[] = "Press the b key to begin the game.";
	bitmapString(-1.0f, 0.0f, 0.0f, beginthegame);
}

void drawRules(){
	glColor3f(1.0f, 1.0f, 1.0f); 
	char rules[] = "Each player chooses a pile and then pulls a number of balls from it." ;
	char rules2[] = "When all the balls are gone, the player with an odd number wins.";
	bitmapString( -2.0f, 1.90f, 0.0f, rules);	
	bitmapString( -2.0f, 1.75f, 0.0f, rules2);
}

void gamebegin(){
	glColor3f(1.0f, 1.0f, 1.0f); 
	char begin[] = "Press return to continue." ;
	bitmapString( -1.0f, -1.25f, 0.0f, begin);
}


void drawName(){
	if (Spencer) {
		char name[] = "Spencer's Turn";	
		glColor3f(1.0f, 1.0f, 1.0f);
		bitmapString(-2.0f, 1.60f, 0.0f, name);
	}
	else{
		if (Georgia){
			char name[] = "Georgia's Turn";
			glColor3f(1.0f, 1.0f, 1.0f);
			bitmapString(-2.0f, 1.60f, 0.0f, name);
		}
	}
	
}

void outputError(){
	glColor3f(1.0f, 1.0f, 1.0f); 
	char error[] = "Please use your keyboard buttons 1, 2, 3...";
	bitmapString( 0.0f, -1.5f, 0.0f, error);	
}

void drawInstr(){
	glColor3f(1.0f, 1.0f, 1.0f); 
	char Instr[] = "Please use your shell.";
	bitmapString( -2.0f, -1.75f, 0.0f, Instr);
}

void youWin(string player){
	char win[] ="You have won the game! Please press escape to exit Assignment 4.";
	bitmapString( -2.0f, 0.0f, 0.0f, win);
}
	
int pickPile(){
	
	glColor3f(1.0f, 1.0f, 1.0f); 				//white text is esay to read isn't it?
	char whichpile[] = "Which pile do you want to take from?";		//output to user
	bitmapString(-2.0f, 1.30f, 0.0f, whichpile);
	//cout<<"Which pile do you want to take from?\n";
	//cin>>pile;
	return pile;
}

int pickNumber(){
	
	glColor3f(1.0f, 1.0f, 1.0f); 				//white text is esay to read isn't it?
	char whichpick[] = "How many balls do you want?";		//output to user
	bitmapString(-2.0f, 1.5f, 0.0f, whichpick);
	//cout<< "How many balls do you want?\n";
	//cin>>pick;
	return pick;
}

void setupGame(){	
	
	//set up three piles
	srand(time(0));
	if (!randomized){
	for (int i = 0; i < 3; ++i){
		int random = rand();
		random = random % 10;
		if ((random % 2) != 0){
 			piles[i] = random;
		}
		else{
			if (random == 0){
				random += 1;
			}
			else{	
				random -= 1;
				piles[i] = random;
			}
	
		}
		randomized = true;
	}
	}
	
}

void turn(string player){
	someonesturn = true;
	pickpile = false;
	picknum = true;
	int *playerscore;
	string skrum = "Spencer";
	if (player == skrum)  {
		Spencer = true;
		Georgia = false;
		*playerscore = playerballs1;

	}
	else{
		Georgia = true;
		Spencer = false;
		*playerscore = playerballs2;
	}
	
	int whichPile = 0;
	int howMany = 0;
	pickpile = true;
	picknum = false;
	whichPile = pickPile();
	if (whichPile != 0){
		pickpile = false;
		picknum = true;
		howMany = pickNumber();
		piles[whichPile] -= howMany;
		*playerscore += howMany;
	}
	
	if ((piles[0] + piles[1] + piles[3]) == 0) {
		winner = true;
		youWin(player);
	}	
}
void drawPiles(){ 						//function to draw the piles with their values in them
	int i = 0;						//it does no calculating, it only reads from the piles[] array 
	glTranslatef(0.0f, 0.0f, 0.0f);				//moves to the origin
	//randomized piles
		glPushMatrix();					//push and pop are action pairs
		glColor3f(1.0f, 0.0f, 0.0f);			//red color
		glTranslatef(-1.0f, -1.0f, 0.0f);		//sets up a line one unit left and one unit down
		for (i = 0; i <= piles[0]; ++i){		//iterates through the array
			glTranslatef(0.0f, 0.20f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glutSolidSphere( 0.10f, 15, 8);
		}
		glPopMatrix();

		glPushMatrix();					
		glColor3f(0.0f, 1.0f, 0.0f);			//green color
		glTranslatef(0.0f, -1.0f, 0.0f);		//sets up a line on the origin, down one
		for (i = 0; i <= piles[1]; ++i){		//iterates through the array
			glTranslatef(0.0f, 0.20f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glutSolidSphere( 0.10f, 15, 8);
		}
		glPopMatrix();

		glPushMatrix();					
		glColor3f(0.0f, 0.0f, 1.0f);			//blue color
		glTranslatef(1.0f, -1.0f, 0.0f);		//sets up a line one unit down and one unit right
		for (i = 0; i <= piles[2]; ++i){		//iterates through the array
			glTranslatef(0.0f, 0.20f, 0.0f);	//originally there weren't three for loops here but two, one nested in the other, but that was failing, hard
			glVertex3f(0.0f, 0.0f, 0.0f);		//and I mean really really HARD, openGL wouldn't even write into its window I had to ctrl C it. 
			glutSolidSphere( 0.10f, 15, 8);		//so we have a longish function.
		}
		glPopMatrix();
			
		glPushMatrix();
		glColor3f(.35f, .35f, .35f);
		glTranslatef(-1.5f, -1.0f, 0.0f);
		for (i = 0; i <= playerballs1; ++i){
			glTranslatef(0.0f, 0.20f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glutSolidSphere( 0.10f, 15, 8);
		}
		glPopMatrix();
	
		glPushMatrix();
		glColor3f(.35f, .55f, 0.0f);
		glTranslatef(1.5f, -1.0f, 0.0f);
		for (i = 0; i <= playerballs1; ++i){
			glTranslatef(0.0f, 0.20f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glutSolidSphere( 0.10f, 15, 8);
		}
		glPopMatrix();
		
		
	
}





void playGame(){
	if (game_begin){
		setupGame();
		if (game_playing){
			turn(playerSpencer);
			turn(playerGeorgia);
		}
	}	
}
//draw the scene!
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clears the last draw, sneak a | in there for ... idunno .. lost a fair ammount of time here on it though ...(the binary OR i mean)
	glMatrixMode(GL_MODELVIEW); 			//switch the mode back to modelview
	glLoadIdentity();				//replaces the current matrix with the identity matrix
	glTranslatef(0.0f, 0.0f, -5.0f);		//move forward 5 units, (move what forward?)

	/*glTranslatef(-1.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f); 
	glVertex3f(0.0f, 3.0f, 0.0f);
	glutSolidSphere( 0.10f, 15, 8);

	glTranslatef(0.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); 
	glVertex3f(0.0f, 0.0f, 0.0f);
	glutSolidSphere( 0.10f, 15, 8);


	glColor3f(1.0f, 0.0f, 0.0f); 
	glVertex3f(0.0f, 1.0f, 0.0f);
	glutSolidSphere( 0.10f, 15, 8);
	*/
	glPushMatrix();					//save what we've done so far

	if (intro){
		introFunc();
	}
	if (game_begin){
		drawRules();
		drawPiles();
	}
	if (game_begin && !game_playing){
		gamebegin();
	}
	if (someonesturn){
		drawName();
		drawInstr();
	}
	glPopMatrix();					//undo the move to the center of the trapezoid
	glPushMatrix();					//again, saving state
	playGame();
			
			

	glutSwapBuffers(); 			//sends the scene off to the screen
}


/*
//this is the glut stuff that needs to be here for glut to work properly
void glutstuff(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500); 		//this is self-explanatory 
	glutCreateWindow("Assignment #4");
	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
}

//the programs main
//for assignment 4 the main must be less than 10 lines of code, so some of this will need to be put into functions
int main(int argc, char** argv){
	glutstuff(argc, argv);
	playGame();
	return 0; //never reached
}

*/

int main(int argc, char** argv) {  //I did not come up with the double asterisks. I will change this comment if/when i figure out what's goin on 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500); 		//this is self-explanatory 
	glutCreateWindow("Assignment #4");
	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0; //doesn't return though
}
/*
//the programs main
//for assignment 4 the main must be less than 10 lines of code, so some of this will need to be put into functions.
int main(int argc, char** argv) {  //I did not come up with the double asterisks. I will change this comment if/when i figure out what's goin on 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500); 		//this is self-explanatory 
	glutCreateWindow("Assignment #4");
	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0; //doesn't return though
}
	

*/






















