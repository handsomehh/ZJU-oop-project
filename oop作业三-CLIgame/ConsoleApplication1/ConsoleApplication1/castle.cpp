/*-----------------------------------------
*File name:castle.cpp
* functon: define class castle and
* functions for castle
* ----------------------------------------
*/
#include "room.cpp"
class castleGenerate : public room {
private:
	int size;//teh scale of castle
	int room_number;//room_number
	room** rooms;//rooms
	int** map;//map of the input
public:
	/*
	*function:castleGenerate()
	* --------------------------------------
	* usage:Initial part
	*/
	castleGenerate() {
		size = -1;
		room_number = -1;
		rooms = NULL;
		map = NULL;
	}
	/*
	*function: IsExit(int x, int y) {
	* --------------------------------------
	* usage:Judge exit
	*/
	bool IsExit(int x, int y) {
		if (x == size && y == size) {
			return true;
		}
		else {
			return false;
		}
	}
	/*
	*function: UcastleGenerate(int** a, int t_size) 
	* --------------------------------------
	* usage:update the statment of the castle
	*/
	void UcastleGenerate(int** a, int t_size) {
		size = t_size;
		room_number = 0;
		map = a;
		rooms = new room * [size + 2];
		for (int i = 1; i <= size; i++) {
			rooms[i] = new room[size + 2];
		}
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				if (a[i][j] == 1) {
					room_number++;
					bool tool = false, map = false;
					if ((rand() % 3) == 1&& (i!=1|| j!=1)) {
						tool = true;
					}
					if (tool == 0) {
						if ((rand() % 2) == 1&&(i != 1 || j != 1)) {
							map = true;
						}
					}
					rooms[i][j].Uroom(i, j, tool, map);
					int temp[4], count = 0;
					if (a[i][j - 1] == 0) {
						temp[0] = 0;
					}
					else {
						temp[0] = 1;
						count++;
					}
					if (a[i - 1][j] == 0) {
						temp[1] = 0;
					}
					else {
						temp[1] = 1;
						count++;
					}
					if (a[i][j + 1] == 0) {
						temp[2] = 0;
					}
					else {
						temp[2] = 1;
						count++;
					}
					if (a[i + 1][j] == 0) {
						temp[3] = 0;
					}
					else {
						temp[3] = 1;
						count++;
					}
					rooms[i][j].Door(temp);
					if (count == 4) {
						rooms[i][j].Uname("Hall");
					}
					else if (count == 1) {
						rooms[i][j].Uname("Blind alley");
					}
					else {
						rooms[i][j].Uname(NameDict(rand() % 7));
					}
					if(i==size&&j==size)rooms[i][j].Uname("Exit");
				}
			}
		}
	}
	/*
	*function: NameDict(int i)
	* --------------------------------------
	* usage:generate the word dictionaries
	*/
	string NameDict(int i) {
		if (i < 0 || i >= 7) return "dark room";
		string name[7];
		name[0] = "Cellar";
		name[1] = "Kitch";
		name[2] = "Toilet";
		name[3] = "Secret room";
		name[4] = "balcony";
		name[5] = "hall way";
		name[6] = "Living room";
		return name[i];
	}
	/*
	*function: printName(int x, int y)
	* --------------------------------------
	* usage:print the name of room at (x,y)
	*/
	string printName(int x, int y) {
		return rooms[x][y].print_room_name();
	}
	/*
	*function:  PrintNumber(int x, int y) 
	* --------------------------------------
	* usage:print the number of room's doors at (x,y)
	*/
	int PrintNumber(int x, int y) {
		return rooms[x][y].GetDoorNumber();
	}
	void printDoor(int x, int y) {
		rooms[x][y].PrintDoorNames();
	}
	/*
	*function:  printtools(int x, int y)
	* --------------------------------------
	* usage:print the tools of room's doors at (x,y)
	*/
	pair<bool, bool> printtools(int x, int y) {
		return rooms[x][y].GetTools();
	}
	/*
	*function:CanMove(int x, int y, int i)
	* --------------------------------------
	* usage:Judge whether can move
	*/
	bool CanMove(int x, int y, int i) {
		return rooms[x][y].JudgeDoor(i);
	}
	/*
	*function:printAll() 
	* --------------------------------------
	* usage:Print the rooms of the castle
	*/
	void printAll() {
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				if (map[i][j] == 1) {
					rooms[i][j].printRAll();
					cout << "  ";
				}
				else {
					cout << "(0 0 00 0000)";
					cout << "  ";
				}
			}
			cout << endl;
		}
	}
	/*
	*function:Utools(int x, int y) 
	* --------------------------------------
	* usage:Update the tools' state
	*/
	void Utools(int x, int y) {
		rooms[x][y].Urtool();
	}
	//print map
	void print_map(int x,int y) {
		rooms[x][y].print_map();
	}
};