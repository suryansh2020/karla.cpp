//Spencer Krum
//Assignment 6
// March 15, 2010
//CS 161-1, Karla Fant
//dbad license
//Hodgepoge

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>


using namespace std;


/*



//6.     Write ONE if statement to find out if the first letter of the name is a letter (Something between A to Z); display an error if it is not the case.

 



8.     Now, write a for loop that allows the user to enter a word – five times. Each time a word is entered compare the word to see if it is “Fun”. If it is, display a message. Only have one cin statement (not five) and only 1 array in the loop! That is the beauty of a loop.

 

9.     Count how many numbers were typed in for the phone number to see if it is correct (there should be 10 digits).

10.  Display a message if the 4th character of the phone number is a hyphen, eg., “503-725-5394”

11.  Sometimes, when you type in an email address, you are asked to type it in twice just to make sure you didn’t make any typos.

12.  Show an example where it would be useful to use cin.ignore(100,’\n’) versus cin.ignore().

 

13.  Show an example of an if statement that uses the && operation

14.  Show an example of an if statement that uses an || operation

 

15.  For two of the above questions – re-write them as functions showing pass by value and pass by reference.

16.  Show how you can call these functions (show all variables)*/

//1.     Show the variable definitions necessary for holding your full name, address, email address, and phone number

int main() {
string fullName1 = "Spencer Olin Krum\n";
string address1 = "1500 SW Park Ave, #321, Portland OR, 97201\n";
string email1 = "krum.spencer@gmail.com\n";
string phone1 = "(619)-980-7820\n";


//2.     Prompt the user for your each of the items listed in question #1 and read them in. Be careful how you read!

string name;
string address;
string email;
string phone;
string firstname;
string middlename;
string lastname;
cout << "Please give you first, middle and last names separated by cairrage returns but not spaces.\n";
cin >> firstname;
cin >> middlename;
cin >> lastname;
cout << "Please give your full address following this example : 1500 SW Park Ave, #321, Portland OR, 97201\n";
cin >> address;
cout << "Please give your full email address following this example : krum.spencer@gmail.com\n";
cin >> email;
cout << "Please give your full phone number following this example : (619)-980-7820\n";
cin >> phone;

//3.     Display just your last name

cout << lastname<< "\n";

//4.     Capitalize just the first letter of your last name

lastname[0] = toupper(lastname[0]);
cout << lastname << "\n" ;

//5.     How would question #4 change if you wanted to upper case ALL letters in your entire name? Explain
//there would be a for loop and I would toupper() all of the letters using lastname.length() as the upper limit for the for loop

//6.     Write ONE if statement to find out if the first letter of the name is a letter (Something between A to Z); display an error if it is not the case.

if ((65 <= ((int)lastname[0]))&&(((int)lastname[0]) <= 90) ){
	cout << "Yep, its between A and Z.";
	}
	else{
		cout << "Nope it ain't.";
	}

//7.     Write a do while loop to read in a name, echo the name, and ask the user if it is correct. If not, allow the user to re-enter their name.

do{
	cout << "Give me a name.";
	string name;
	cin >> name;
	cout << "Is " << name << " correct? y/n";
	char yesno;
	cin >> yesno;
}
while(yesno != y);

//8.     Now, write a for loop that allows the user to enter a word – five times. Each time a word is entered compare the word to see if it is “Fun”. If it is, display a message. Only have one //cin statement (not five) and only 1 array in the loop! That is the beauty of a loop.
string fun[5];
for (int i = 0; i < 5; ++i){
	cin >> fun[i];
	if (fun[i] == "Fun"){
		cout << "We're fun now!";
	}
}

//9.     Count how many numbers were typed in for the phone number to see if it is correct (there should be 10 digits).

int digits = phone.size();

// Display a message if the 4th character of the phone number is a hyphen, eg., “503-725-5394”

if (phone[4] = "-"){
	cout << "Hyphen detected!";
	}

//11.  Sometimes, when you type in an email address, you are asked to type it in twice just to make sure you didn’t make any typos.

cin >> email2;
if (email2 != email) {
	cout << "We need to fix something here!";
	doitover();
}

//12.  Show an example where it would be useful to use cin.ignore(100,’\n’) versus cin.ignore().

when trying to import data into a database, riding that line between wanting as much data as you can but needing it to be in a certain form to fit your database

13.  Show an example of an if statement that uses the && operation

if (spencer does hw && does well on final){
	cout << spencer gets good graedes
	}
	else{
	cout << back to community college
}

14.  Show an example of an if statement that uses an || operation

if (spencer fails cs || spencer fails black studies){
	cout << spencer will be in big do do
	}

15.  For two of the above questions – re-write them as functions showing pass by value and pass by reference.

void function(string email2, string phone){

if (email2 != email) {
	cout << "We need to fix something here!";
	doitover();
}

if (phone[4] = "-"){
	cout << "Hyphen detected!";
	}

}
void function(string& email2, string& phone){

if (email2 != email) {
	cout << "We need to fix something here!";
	doitover();
}

if (phone[4] = "-"){
	cout << "Hyphen detected!";
	}

}

16.  Show how you can call these functions (show all variables)*/

string lasers, pinnaple;
function(lasers,pinnaple);


return 0;

}








