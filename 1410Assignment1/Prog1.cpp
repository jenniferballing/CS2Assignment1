#include <iostream>
#include "Friend.h"

using namespace std;

void printMenu(void);
void main ()
{
	const int SIZE = 5;
	char userChoice='t';
	bool exit=false;
	string test="test";

	FRIEND_STRUCT friend1, friend2, friend3, friend4;
	friend1.Age=26;
	friend1.Interests="running";
	friend1.ScreenName="Aabbie";
	friend2.Age=22;
	friend2.Interests="running";
	friend2.ScreenName="Jabbie";
	friend3.ScreenName="JABC";
	friend4.ScreenName="zyx";

	Friend *f1 = new Friend();//instance of Friend
	FRIEND_STRUCT Arr[SIZE];//instance of FRIEND_STRUCT
	f1->resetToDefault(Arr, SIZE);//Initialize struct with default values
		
	//loop that runs the console
	while (exit==false)
	{
		printMenu();
		cin>>userChoice;
		
		if(userChoice=='a' || userChoice == 'A')
		{
			f1->AddFriend(Arr, SIZE);
		}
		else if(userChoice=='r' || userChoice == 'R')
		{
			f1->RemoveFriend(Arr, SIZE);
		}
		else if(userChoice=='s' || userChoice == 'S')
		{
			string keyword;
			cout<< "Search keyword: ";
			cin>> keyword;
			cout<<endl;
			f1->SearchInterest(Arr, SIZE, keyword);
		}
		else if(userChoice=='d' || userChoice == 'D')
		{
			f1->DisplayFriend(Arr, SIZE); 
		}
		else if(userChoice=='l' || userChoice == 'L')
		{
			f1->ListFriend(Arr, SIZE);
		}
		else if(userChoice=='c' || userChoice == 'C')
		{
			cout<<"\nAverage age: "<<f1->ReportAge (Arr, SIZE)<<endl;
		}
		else if(userChoice=='e' || userChoice == 'E')
		{
			return;
		}
	}
}
						
void printMenu (void)
{
	cout<< "\n*** Network of My Friends ***\n"
	<<"A: Add a Friend\n"
	<<"R: Remove a Friend\n"
	<<"S: Search Interests\n"
	<<"D: Display All Friends\n"
	<<"L: List All Friends in Alphabetic Order Based on ScreenName\n"
	<<"C: Calculate the Average Age of All Friends in MY Network\n"
	<<"E: Exit\n"
	<<"\nSelection: ";
}


