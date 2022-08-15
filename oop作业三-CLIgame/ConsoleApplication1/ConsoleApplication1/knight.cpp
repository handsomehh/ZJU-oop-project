/*-----------------------------------------
*File name:knight.cpp
* functon: define class knight and
* functions for knight
* ----------------------------------------
*/
#include <iostream>
using namespace std;
class knight {
protected:
	int kx, ky;//position
	int tools_number;//radar's number
	int map_number;//map's number
	int goal_state;//current statment
public:
/*
*function:DecreaseTools(int x)
* -----------------------
* usage:use one tools and decrease the number
*/
	void DecreaseTools(int x) {
		if (x == 1) {
			tools_number--;
		}
		if (x == 2) {
			map_number--;
		}
	}
	/*
	*function:Utools(pair<bool, bool> temp)
	* -----------------------------------------------
	* usage:Pick up tools and uopdate number
	*/
	void Utools(pair<bool, bool> temp) {
		if (temp.first == true)tools_number++;
		if (temp.second == true)map_number++;
	}
	/*
	*function:pair<int, int> Ltools() 
	* -----------------------------------------------
	* usage:return the number of tools
	*/
	pair<int, int> Ltools() {
		return make_pair(tools_number, map_number);
	}
	/*
	*function:Uknight(int x, int y)
	* -----------------------------------------------
	* usage:update the position of knight
	*/
	void Uknight(int x, int y) {
		kx = x;
		ky = y;
	}
	/*
		*function:Ugoal(int t_goal) 
		* -----------------------------------------------
		* usage:update the goal of knight
		*/
	void Ugoal(int t_goal) {
		goal_state = t_goal;
	}
	/*
	*function:printgoal() 
	* -----------------------------------------------
	* usage:get the goal of the knight
	*/
	int printgoal() {
		return goal_state;
	}
	/*
	*function:Newknight(int x, int y)
	* -----------------------------------------------
	* usage:cretae new knight
	*/
	void Newknight(int x, int y) {
		kx = x;
		ky = y;
		tools_number = 0;
		map_number = 0;
		goal_state = 1;
	}
	knight(int x, int y) {
		kx = x;
		ky = y;
		tools_number = 0;
		map_number = 0;
		goal_state = 1;
	}
	/*
	*function:Isknight(int x, int y) 
	* -----------------------------------------------
	* usage:Judge whether is a knight
	*/
	bool Isknight(int x, int y) {
		if (x == kx && y == ky) {
			return true;
		}
		else {
			return false;
		}
	}
	/*
	*function:printx()
	* function:printy()
	* -----------------------------------------------
	* usage:Get the  horizontal coordinates
	*/
	int printx() {
		return kx;
	}
	int printy() {
		return ky;
	}
	/*
	*function:Move(string position)
	* -----------------------------------------------
	* usage:Move knight according position
	*/
	bool Move(string position) {
		if (position == "east") ky++;
		else if (position == "west")  ky--;
		else if (position == "north") kx--;
		else if (position == "south") kx++;
		else return false;
		return true;
	}
	~knight() {}
};