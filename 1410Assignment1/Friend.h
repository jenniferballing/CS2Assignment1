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
	void AddFriend (FRIEND_STRUCT friendArr[], int size);
	void RemoveFriend(FRIEND_STRUCT friendArr[], int size);
	void SearchInterest(FRIEND_STRUCT friendArr[], int size, string keywords);
	void DisplayFriend (FRIEND_STRUCT friendArr[], int size);
	void ListFriend (FRIEND_STRUCT friendArr[], int size);
	bool IsBefore(FRIEND_STRUCT friend1, FRIEND_STRUCT friend2);
	//float ReportAge (Friend friendArr[], int size);
	void BubbleSort (FRIEND_STRUCT friendArr[ ], int size);
	~Friend(void);
};

