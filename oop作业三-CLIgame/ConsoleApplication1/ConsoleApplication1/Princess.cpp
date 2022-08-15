/*-----------------------------------------
*File name:Princess.cpp
* functon: define class Princess and
* functions for Princess
* ----------------------------------------
*/
#include<iostream>
using namespace std;
class Princess {
protected:
	int px, py;
public:
/*
*function:Princess
* -----------------------
* usage: initial Princess
*/
	Princess() {
		px = -1;
		py = -1;
	}
	/*
	*function:Getppos()
	* --------------------------------------
	* usage:Output position of Princess
	*/
	pair<int, int> Getppos() {
		return make_pair(px, py);
	}
	/*
	*function:UPrincess(int x, int y) 
	* --------------------------------------
	* usage:Update position of Princess
	*/
	void UPrincess(int x, int y) {
		px = x;
		py = y;
	}
	/*
	*function:IsPrincess(int x, int y) 
	* --------------------------------------
	* usage:Judge whether this is Princess
	*/
	bool IsPrincess(int x, int y) {
		if (x == px && y == py) {
			return true;
		}
		else {
			return false;
		}
	}
	~Princess() {}
};