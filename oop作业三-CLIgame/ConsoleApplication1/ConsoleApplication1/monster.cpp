/*-----------------------------------------
*File name:monstert.cpp
* functon: define class mnster and
* functions for monster
* ----------------------------------------
*/
#include<iostream>
using namespace std;
class monster {
protected:
	int mx, my;//position of the monster
public:
	/*
	*function:monster
	* --------------------------------------
	* usage:initial
	*/
	monster() {
		mx = -1;
		my = -1;
	}
	/*
	*function: Umonster(int x, int y)
	* --------------------------------------
	* usage:update the state of the monster
	*/
	void Umonster(int x, int y) {
		mx = x;
		my = y;
	}
	/*
	*function:IsMonster(int x, int y) 
	* --------------------------------------
	* usage:Judge whether is a monster
	*/
	bool IsMonster(int x, int y) {
		if (x == mx && y == my) {
			return true;
		}
		else {
			return false;
		}
	}
	/*
	*function:IGetmpos() 
	* --------------------------------------
	* usage:get the position of monster
	*/
	pair<int, int> Getmpos() {
		return make_pair(mx, my);
	}
	~monster() {}
};