#pragma once
#include <string>

using namespace std;

typedef	struct friendStruct
	{
		int Age;
		string ScreenName;
		string Interests;
	}FRIEND_STRUCT;
class Friend
{	
public:
	Friend(void);
	void resetToDefault(FRIEND_STRUCT friendArr[], int size);
	//void printArr(friendStruct friendArr[], int size);
	//void AddFriend (Friend friendArr[], int size);
	//void RemoveFriend(Friend friendArr[], int size);
	//void SearchInterest(Friend friendArr[], int size, string keywords);
	//void DisplayFriend (Friend friendArr[], int size);
	//void ListFriend (Friend friendArr[], int size);
	//float ReportAge (Friend friendArr[], int size);
	//bool IsBefore (Friend friend1, Friend friend2);
	~Friend(void);
};

