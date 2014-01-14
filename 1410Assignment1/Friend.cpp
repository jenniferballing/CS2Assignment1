#include "Friend.h"
#include <iostream>

using namespace std;


Friend::Friend(void)
{
	
}

void Friend::resetToDefault(FRIEND_STRUCT friendArr[], int size)
{
	for(int i=0; i<size; i++)
	{
		friendArr[i].ScreenName="EMPTY";
		friendArr[i].Interests="EMPTY";
		friendArr[i].Age=0;
	}
}
/*void Friend::printArr (FRIEND_STRUCT friendArr[], int size)
{
	for (int i=0; i<size; i++)
	{
		cout<< "ScreenName: "<<friendArr[i].ScreenName<< endl;
		cout<< "Age " << friendArr[i].Age<< endl;
		cout<< "Interests" << friendArr[i].Interests<<endl;
	}
}*/
/*void AddFriend (Friend friendArr[], int size)
{
	for( int i=0; i<size; i++)
	{
		if(friendArr.ScreenName[i]=="EMPTY")
		{
			//Add the friend?
		}
	}
}*/