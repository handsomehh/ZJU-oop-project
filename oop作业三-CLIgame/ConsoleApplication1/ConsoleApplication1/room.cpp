/*-----------------------------------------
*File name:roomt.cpp
* functon: define class room and
* functions for room
* ----------------------------------------
*/
#include<iostream>
using namespace std;
class room {
protected:
	int rx, ry;//position
	int door[4];//door of the room
	bool tools;//radar in the room
	bool map;//map in the room
	string name;//the name of the room
public:
	/*
	*function:room()
	* --------------------------------------
	* usage:initial
	*/
	room() {
		rx = -1;
		ry = -1;
		tools = false;
		map = false;
		for (int i = 0; i < 4; i++) {
			door[i] = -1;
		}
	}
	void print_map() {
		if (tools)cout << "Wow, Look! a radar is here, maybe can help me escape monsters" << endl;
		if(map)cout << "Wow, Look! a map is here, maybe can help me find princess and exit" << endl;
	
	}
	/*
	*function:Urtool() 
	* --------------------------------------
	* usageupdate tools
	*/
	void Urtool() {
		tools = false;
		map = false;
	}
	/*
	*function:printRAll()
	* --------------------------------------
	* usage:print all rooms
	*/
	void printRAll() {
		cout << "(" << rx << " " << ry << " " << tools << map << " ";
		for (int i = 0; i < 4; i++)cout << door[i];
		cout << ")";
	}
	/*
	*function:GetTools() 
	* --------------------------------------
	* usage:get the statment of the room
	*/
	pair<bool, bool> GetTools() {
		return make_pair(tools, map);
	}
	/*
	*function:Uroom(int x, int y, bool t_radar, bool t_map)
	* --------------------------------------
	* usage:update the rooms' statement
	*/
	void Uroom(int x, int y, bool t_radar, bool t_map) {
		rx = x;
		ry = y;
		tools = t_radar;
		map = t_map;
	}
	/*
	*function:Uname(string t_name)
	* --------------------------------------
	* usage:assign name to the room
	*/
	void Uname(string t_name) {
		name = t_name;
	}
	/*
	*function:print_room_name()
	* --------------------------------------
	* usage:print name to the room
	*/
	string print_room_name() {
		return  name;
	}
	int GetDoorNumber() {
		int i = 0;
		for (int j = 0; j < 4; j++) {
			if (door[j] == 1)i++;
		}
		return i;
	}
	void Door(int temp[4]) {
		for (int i = 0; i < 4; i++) {
			door[i] = temp[i];
		}
	}

	bool JudgeDoor(int i) {
		if (door[i] == 1)return true;
		else return false;
	}
	/*
	*function:PrintDoorNames() 
	* --------------------------------------
	* usage:print name of the door of the room
	*/
	void PrintDoorNames() {
		if (GetDoorNumber() == 0) {
			cout << "There are no doors" << endl;
		}
		if (GetDoorNumber() == 1) {
			for (int i = 0; i < 4; i++) {
				printdoor(i);
				//cout << "." << endl;
			}
			cout << "." << endl;
		}
		int put = 0;
		if (GetDoorNumber() == 2) {
			for (int i = 0; i < 4; i++) {
				if (printdoor(i)) {
					put++;
					if (put == 1) {
						cout << " and ";
					}
					else if (put == 2) {
						cout << "." << endl;
					}
				}
			}
		}
		if (GetDoorNumber() == 3) {
			for (int i = 0; i < 4; i++) {
				if (printdoor(i)) {
					put++;
					if (put == 1) {
						cout << ", ";
					}
					else if (put == 2) {
						cout << " and ";
					}
					else {
						cout << "." << endl;
					}
				}
			}
		}
		if (GetDoorNumber() == 4) {
			for (int i = 0; i < 4; i++) {
				if (printdoor(i)) {
					put++;
					if (put == 1 || put == 2) {
						cout << ", ";
					}
					else if (put == 3) {
						cout << " and ";
					}
					else {
						cout << "." << endl;
					}
				}
			}
		}
	}
	//count number of the door
	int printdoor(int i) {
		if (door[i] == 1) {
			if (i == 0)cout << "west";
			else if (i == 1)cout << "north";
			else if (i == 2)cout << "east";
			else if (i == 3)cout << "south";
			return 1;
		}
		return 0;
	}
	void printtools() {
		if (tools) cout << endl << "Look! A Radar is here!" << endl;
		if (map) cout << endl << "Look, it's a map!" << endl;
	}
};