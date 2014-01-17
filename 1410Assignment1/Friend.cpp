#include "Friend.h"
#include <iostream>
#include <algorithm>
#include <string>

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

void Friend::AddFriend (FRIEND_STRUCT friendArr[], int size)
{
	string screenName="", interests="";
	int i=0, age=0;
	bool found=false;
	
	while (found==false)
	{
		for(i=0; i<size; i++)
		{
			if (friendArr[i].ScreenName=="EMPTY" && friendArr[i].Age==0 && friendArr[i].Interests=="EMPTY")
			{
				//clear and sync allow me to use multiple getline functions
				cin.clear();
				cin.sync();
	
				//Get new friend input
				cout<<"*** Add a new friend profile \n";
				cout<<"ScreenName: \n";
				getline(cin, screenName);
				cout<<"Interests: \n";
				getline(cin, interests);
				cout<<"Age: \n";
				cin>> age;

				//Fill new friend info into available space
				friendArr[i].ScreenName=screenName;
				friendArr[i].Age=age;
				friendArr[i].Interests=interests;
				found=true;
				return;
			}
		}
			
			//If no available index is found, inform user
			if(found==false)
			{
				cout<<"\nSorry, there is no available space.\n\n";
				return;
			}
		
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
	if(indexChoice<5 && indexChoice>-1)
	{
		//Set the values back to the default
		friendArr[indexChoice].ScreenName="EMPTY";
		friendArr[indexChoice].Interests="EMPTY";
		friendArr[indexChoice].Age=0;
	}
	else
	{
		cout<<"\nInvalid input.\n\n";
		return;
	}
}

void Friend::SearchInterest(FRIEND_STRUCT friendArr[], int size, string keywords)
{
	//*NOTE*: Checks for valid friend input aren't necessary all input is valid.
	//variables and temps needed to preserve original array values
	int i=0, j=0;
	string tempInterests, screenName;
	string tempInterestsArr[5];
	
	//Check only occupied indexes- no need to check empty indexes for keywords
	for(i=0; i<size; i++)
	{
		if (friendArr[i].ScreenName!="EMPTY" && friendArr[i].Age!=0 && friendArr[i].Interests!="EMPTY")
		{
			//Put array values into temp arrays and change to lowercase
			for(j=0; j<size; j++)
			{
				tempInterests=friendArr[j].Interests;
				transform(tempInterests.begin(), tempInterests.end(), tempInterests.begin(), ::tolower);
				tempInterestsArr[j]=tempInterests;

				//Make the keywords string lowercase
				transform(keywords.begin(), keywords.end(), keywords.begin(), :: tolower);

				//Compare lowercase interests to lowercase keywords
				if(tempInterests.compare(keywords) == 0)
				{
					//Print ScreenName associated with matching keywords
					cout<< "***" << friendArr[j].ScreenName<< endl<<endl;
					return;
				}
			}
		}
	}
}
//Print the current values in the struct array.
void Friend::DisplayFriend (FRIEND_STRUCT friendArr[], int size)
{
	for (int i=0; i<size; i++)
	{
		cout<< "Index: "<<i<< endl;
		cout<< "ScreenName: "<<friendArr[i].ScreenName<< endl;
		cout<< "Interests: " << friendArr[i].Interests<<endl;
		cout<< "Age: " << friendArr[i].Age<< endl<<endl;
	}
}

void Friend::ListFriend (FRIEND_STRUCT friendArr[], int size)
{
	FRIEND_STRUCT tempArr[5];
	string testFr1, testFr2;
	int i=0, j=0, k=0;
	for(i=0; i<size; i++)
	{
		tempArr[i]=friendArr[i];
		//Make sure that the "EMPTY" indexes are not included
		/*if(friendArr[i].ScreenName!="EMPTY")
		{
			tempArr[i]=friendArr[i];
		}
		else if(friendArr[i].ScreenName=="EMPTY")
		{
			tempArr[i].ScreenName=" ";
			tempArr[i].Age=0;
			tempArr[i].Interests=" ";
		}*/
	}
	//int tempArrSize=tempArr.size();
	BubbleSort(tempArr, 5);//***figure out size
	for(j=0; j<5; j++)
	{
		if(tempArr[j].ScreenName!="EMPTY")
		{
			cout<<tempArr[j].ScreenName<<endl;
		}
	}	
	cout<<endl;
}

bool Friend::IsBefore(FRIEND_STRUCT friend1, FRIEND_STRUCT friend2)
{
	int length=3, i=0;
	bool before=true;
	//Create and initiallize temp variables
	string tempF1N=	friend1.ScreenName;
	string tempF2N=	friend2.ScreenName;
	int tempF1A=friend1.Age;
	int tempF2A=friend2.Age;

	//Set all chars in temp variables to lowercase 
	transform(tempF1N.begin(), tempF1N.end(), tempF1N.begin(), ::tolower);
	transform(tempF2N.begin(), tempF2N.end(), tempF2N.begin(), ::tolower);
	
	//Find the shortest string
	if(tempF1N.length() > tempF2N.length())
	{
		length=tempF2N.length();
	}
	else if(tempF1N.length() < tempF2N.length())
	{
		length=tempF1N.length();
	}

	//Compare to find if it is before
	for(i=0; i<length-1; i++)
	{
		if(tempF1N.at(i)>tempF2N.at(i))
		{
			return false;
		}
	}
	//If the strings are equal, organize by age
	if(tempF1N==tempF2N)
	{
		if(tempF1A>tempF2A)
		{
			return false;
		}
		else if (tempF1A<tempF2A)
		{
			return true;
		}
		else
		{
			return true;
		}
	}
return before;
}

void Friend::BubbleSort (FRIEND_STRUCT friendArr[ ], int size)
	{
		bool isBefore=true;
		int i=0, j=0;
		FRIEND_STRUCT tempArr[5];//***Find better way to determine how many elements are in temp array.
		
		//Check and swap
		for(i=0; i<size; i++)
		{
			isBefore=IsBefore(friendArr[i], friendArr[i++]);
			if(isBefore==false)
			{
				tempArr[i++]=friendArr[i];
				tempArr[i]=friendArr[i++];
			}
			else if(isBefore==true)
			{
				tempArr[i]=friendArr[i];
				tempArr[i++]=friendArr[i++];
			}
		}
		//Print to see if it is working...its not.
		for(j=0; j<size; j++)//**always throws exceptions because I don't know how many elements are in the array when the "EMPTY"s are removed. I put in 4 for testing purposes.
		{
			cout<<tempArr[j].ScreenName;
		}
	}
		