#include "Friend.h"
#include <iostream>

using namespace std;


Friend::Friend(void)
{
	
}

//Set all of the values back to default of "EMPTY", "EMPTY" and 0.
void Friend::resetToDefault(FRIEND_STRUCT friendArr[], int size)
{
	int i=0;
	for(i=0; i<size; i++)
	{
		friendArr[i].ScreenName="EMPTY";
		friendArr[i].Interests="EMPTY";
		friendArr[i].Age=0;
	}
}
//Print the current values in the struct array.
void Friend::printArr (FRIEND_STRUCT friendArr[], int size)
{
	for (int i=0; i<size; i++)
	{
		cout<< "Friend at index: "<<i<< endl;
		cout<< "ScreenName: "<<friendArr[i].ScreenName<< endl;
		cout<< "Interests: " << friendArr[i].Interests<<endl;
		cout<< "Age: " << friendArr[i].Age<< endl<<endl;
	}
}

void Friend::AddFriend (FRIEND_STRUCT friendArr[], int size)
{
	string screenName="", interests="";
	int age=0, i=0;
	bool found=false;
	
	//Get input
	cout<<"*** Add a new friend profile \n";
	cout<<"ScreenName: \n";
	getline(cin, screenName);
	cout<<"Interests: \n";
	getline(cin, interests);
	cout<<"Age: \n";
	cin>> age;
	
	//Check for available friend index- Must have available ScreenName, Age and Interests
	//If available index is found fill with userChoice input
	while(found==false)
	{
		for(i=0; i<size; i++)
		{
			if (friendArr[i].ScreenName=="EMPTY" && friendArr[i].Age==0 && friendArr[i].Interests==" EMPTY")
			{
				friendArr[i].ScreenName=screenName;
				friendArr[i].Age=age;
				friendArr[i].Interests=interests;
				found=true;
			}
		}
	//If no available index is found, inform user
		/*if (found==false)
		{
			cout<<"There is no available space. You may wish to remove another friend to create room.\n";
		}*/
	}
}
void Friend::RemoveFriend(FRIEND_STRUCT friendArr[], int size)
{
	//The index of the removed friend
	int indexChoice;
	cout<< "*** Remove a friend ***\n";
	for (int i=0; i<size; i++)
	{
		cout<< i<< friendArr[i].ScreenName<< endl;
	}
	cout<<"Which to remove:\n";
	cin>>indexChoice;
	
	//Set the values back to the default
	friendArr[indexChoice].ScreenName="EMPTY";
	friendArr[indexChoice].Interests="EMPTY";
	friendArr[indexChoice].Age=0;

}
void SearchInterest(FRIEND_STRUCT friendArr[], int size, string keywords)
{


}
