#include <iostream>
#include "Friend.h"

using namespace std;

void printMenu();
void main ()
{
	const int SIZE = 5;
	Friend *f1 = new Friend();

	FRIEND_STRUCT Arr[SIZE];
	f1->resetToDefault(Arr, SIZE);
	//char userChoice;
	//printMenu();
	//cin>>userChoice;

	/*switch(userChoice)
	{
		case "a" || "A":
			AddFriend(Friend friend[], int size);
			break;
		case "r" || "R":
			RemoveFriend(Friend friendArr[], int size);
			break;
		case "s" || "S":
			SearchInterest(Friend friendArr[], int size, string keywords);
			break;
		case "d" || "D":
			DisplayFriend (Friend friendArr[], int size);
			break:
		case "l" || "L":
			ListFriend (Friend friendArr[], int size);
			break;
		case "c" || "C":
			float ReportAge (Friend friendArr[], int size);
			break:
		case "e" || "E":
			return;
	}*/

	
}
void printMenu ()
{
	cout<< "*** Network of My Friends ***\n"
	<<"A: Add a Friend\n"
	<<"R:Remove a Friend\n"
	<<"S: Search Interests\n"
	<<"D: Display All Friends\n"
	<<"L: List All Friends in Alphabetic Order Based on ScreenName\n"
	<<"C: Calculate the Average Age of All Friends in MY Network\n"
	<<"E: Exit\n";
}


