#include"head.h"
#include<time.h>
#include<windows.h>
void Radar();
void Map();
void PlayerInput();
void CreateMap();
void Playing();
void UseTools();
void InitialMap();
void Addnpc();
int Process(string pos);
bool NotConnect();
void AddPrincess();
void AddMonster(int mode);
void DepthSearch(int i, int j, int** temp, int** unknown);
void PrintState();
bool FindMonster(int x, int y);
void printsentence();
int main() {
	srand((unsigned)time(NULL));//time seed, make sure generate random number
	PlayerInput();//input and select mode
	if (err == 1)return 0;//illegal input, return directly
	CreateMap();//create map according mode
	Playing();//playing

}
/*
*function:FindMonster(int x, int y)
* --------------------------------------
* usage:judge whether (x,y) have monster
*/
bool FindMonster(int x, int y) {
	bool temp = false;
	for (int i = 0; i < monster_number; i++)
		temp = temp || m[i].IsMonster(x, y);
	return temp;
}
/*
*function:PrintState() {
* --------------------------------------
* usage: print state of the Player
*/
void PrintState() {
	int count = 0;
	for (int i = Player.printx() - 1; i <= Player.printx() + 1; i++) {
		for (int j = Player.printy() - 1; j <= Player.printy() + 1; j++) {
			if (FindMonster(i, j))count++;
		}
	}
	cout << count << " monsters are near you, be careful" << endl;
}
/*
*function:PlayerInput() {
* --------------------------------------
* usage: control the input
*/
void PlayerInput() {
	cout << "Please Input your name" << endl;
	cin >> name;
	cout << "Please Select game difference:" << endl;
	cout << "[1] easy\n" << "[2] normal\n" << "[3] hard\n" <<"[4] self define map's size" << endl;
	cin >> mode;
	if (mode <= 0 || mode >= 5) {
		cout << "error input" << endl;
		err = 1;
		return;
	}
	 if (mode == SELFDEFINE) {
		cout << "input size of map(between 3 to 50)" << endl;
		cin >> size1;
		if (size1 >= 51 || size1 <= 2) {
			cout << "illegal input" << endl;
			err = 1;
			return;
		}
		cout << "input number of monster(between 1 and " << (int)(size1 * size1) / (4 + (int)(size1 / 10) * 1) << ")" << endl;
		cin >> monster_number;
		if (monster_number <= 0 || monster_number > (int)(size1 * size1) / (4 + (int)(size1 / 10) * 1)) {
			cout << "illegal input" << endl;
			err = 1;
			return;
		}
	}
	cout << "Game start:" << endl;
	cout << "Map is generating, please wait a moment" << endl;
	cout << "You are a knight, your task is to rescue the princess in the castle" << endl;
	Sleep(1000);
	cout << "with many monsters, you will see two props: radar and map in " << endl;
	Sleep(1000);
	cout << "the room, radar can help you avoid monsters, map can help you " << endl;
	Sleep(1000);
	cout << "find the princess and exit, Come on, and good luck. " << endl;
	Sleep(1000);
}
/*
*function:CreateMap() {
* --------------------------------------
* usage: ccreate map according the mode
*/
void CreateMap() {
	if (mode == EASY) {
		size1 = 3;
		monster_number = 2;
	}
	else if (mode == NORMAL) {
		size1 = 6;
		monster_number = 10;
	}
	else if (mode == HARD) {
		size1 = 10;
		monster_number = 30;
	}
	else if (mode == SELFDEFINE) {
		;
	}
	else{
		cout << "fata error, undefined mode" << endl;
		return;
	}
	InitialMap();
}
/*
*function:InitialMap() {
* --------------------------------------
* usage: generate the map of the castle
*/
void InitialMap() {
	map = new int* [size1 + 2];
	for (int i = 0; i <= size1 + 1; i++) {
		map[i] = new int[size1 + 2];
	}
	for (int i = 0; i <=size1+1; i++) {
		for (int j = 0; j <=size1+1; j++) {
			if ((i == 0 || i == size1 + 1) || (j == 0 || j == size1 + 1)) {
				map[i][j] = 0;
			}
			else {
				if (i == 1 && j == 1)map[i][j] = 1;
				else if (i == size1 && j == size1) {
					map[i][j] = 1;
				}
				else {
					if (rand() % 4 == 0)map[i][j] = 0;
					else map[i][j] = 1;
				}
			}
		}
	}
	Addnpc();
	if (!NotConnect()) {
		delete[] map;
		InitialMap();
	}
}
/*
*function:NotConnect() {
* --------------------------------------
* usage: judge whether map is resonable
*/
bool NotConnect() {
	int** temp = new int* [size1+2];
	for (int i = 0; i < size1 + 2; i++)temp[i] = new int[size1 + 2];
	for (int i = 0; i < size1 + 2; i++)
		for (int j = 0; j < size1 + 2; j++)
			temp[i][j] = map[i][j];
	for (int i = 0; i < monster_number; i++) {
		temp[m[i].Getmpos().first][m[i].Getmpos().second] = 0;
	}
	int** know = new int* [size1 + 2];
	for (int i = 0; i <= size1 + 1; i++) {
		know[i] = new int[size1 + 2];
	}
	for (int i = 0; i <= size1 + 1; i++) {
		for (int j = 0; j <= size1 + 1; j++) {
			know[i][j] = 1;
		}
	}
	DepthSearch(1, 1, temp, know);
	if (know[size1][size1] == 0 && know[p1.Getppos().first][p1.Getppos().second] == 0) {
		delete[]temp;
		delete[]know;
		return true;
	}
	else {
		delete[]temp;
		delete[]know;
		return false;
	}
}
/*
*function:DepthSearch
* --------------------------------------
* usage: using depth first search to judge whether graph is connected
*/
void DepthSearch(int i,int j,int **temp,int **unknown) {
	if (i == 0 || i == size1 + 1 || j == 0 || j == size1 + 1)return;
	unknown[i][j] = 0;
	if (temp[i - 1][j] == 1 && unknown[i - 1][j] == 1) {
		DepthSearch(i-1, j, temp, unknown);
	}
	if (temp[i ][j-1] == 1 && unknown[i ][j-1] == 1) {
		DepthSearch(i, j-1, temp, unknown);
	}
	if (temp[i + 1][j] == 1 && unknown[i + 1][j] == 1) {
		DepthSearch(i+1, j, temp, unknown);
	}
	if (temp[i ][j+1] == 1 && unknown[i ][j+1] == 1) {
		DepthSearch(i, j+1, temp, unknown);
	}
}
/*
*function:Addnpc
* --------------------------------------
* usage: add princess and monster
*/
void Addnpc() {
	AddPrincess();
	AddMonster(mode);
}
void AddPrincess() {
	while (true) {
		int x = (rand() % size1) + 1;
		int y = (rand() % size1) + 1;
		if (map[x][y] == 1&&(x!=1||y!=1)&&(x != size1 || y != size1)) {
			p1.UPrincess(x, y);
			break;
		}
	}
}
void AddMonster(int mode) {
	int count = 0;
		while (true) {
			int x = (rand() % size1) + 1;
			int y = (rand() % size1) + 1;
			if (map[x][y] == 1&&!p1.IsPrincess(x,y)&& (x != 1 || y != 1)&&!FindMonster(x,y)) {
				m[count].Umonster(x, y);
				count++;
			}
			if (count == monster_number)return;
		}
}
/*
*function:Playing
* --------------------------------------
* usage: Playing function to play
*/
void Playing() {
	int state;
	Player.Newknight(1,1);
	castle.UcastleGenerate(map, size1);
	////hashdash
	//for (int i = 1; i <= size1; i++) {
	//	for (int j = 0; j <= size1; j++) {
	//		if (FindMonster(i, j))cout << "# ";
	//		else if (p1.IsPrincess(i, j))cout << "* ";
	//		else if (map[i][j])cout << "1 ";
	//		else cout << "0 ";
	//	}
	//	cout << endl;
	//}
	////jhdsjadja
	while (1) {
		string pos,temp;
		cout << "Welcome To " << castle.printName(Player.printx(), Player.printy()) << ", There are " << castle.PrintNumber(Player.printx(), Player.printy()) << " exits: ";
		castle.printDoor(Player.printx(), Player.printy());
		printsentence();
		cout << "Enter your command: ";
		cin >> temp >> pos;
		while ((state = Process(pos)) == ERROR) {
			cout << "Enter your command again: ";
			cin >> temp >> pos;
		}
		if (state == SUCCESS) {
			cout << "Exit is here! "<<name<<" knight,Your succeed!";
			return;
		}
		else if (state == FAIL) {
			cout << "you failed!" << endl;
			return;
		}else if(state == GAMEING){
		}
	}
}
/*
*function:Process
* --------------------------------------
* usage: process positon 
*/
int Process(string pos) {
	int pos_num;
	if (pos == "east") pos_num = 2;
	else if (pos == "west") pos_num = 0;
	else if (pos == "north")pos_num = 1;
	else if (pos == "south")pos_num = 3;
	else pos_num = -1;
	if (pos_num == -1) {
		return ERROR;
	}
	else {
		if (pos == "east") {
			if (castle.CanMove(Player.printx(), Player.printy(),pos_num)) {
				Player.Move(pos);
			}
			else {
				cout << "move fail" << endl;
				return ERROR;
			}
		}
		else if (pos == "west") {
			if (castle.CanMove(Player.printx(), Player.printy(), pos_num)) {
				Player.Move(pos);
			}
			else {
				cout << "move fail" << endl;
				return ERROR;
			}
		}
		else if (pos == "north") {
			if (castle.CanMove(Player.printx(), Player.printy(), pos_num)) {
				Player.Move(pos);
			}
			else {
				cout << "move fail" << endl;
				return ERROR;
			}
		}
		else if (pos == "south") {
			if (castle.CanMove(Player.printx(), Player.printy(), pos_num)) {
				Player.Move(pos);
			}
			else {
				cout << "move fail" << endl;
				return ERROR;
			}
		}
	}
	if (Player.printgoal() == 1) {
		if (p1.IsPrincess(Player.printx(), Player.printy())) {
			cout <<"Look! Princess is here"<<endl;
			p1.UPrincess(-1, -1);
			Player.Ugoal(2);
		}
		else if (FindMonster(Player.printx(), Player.printy())) {
			cout << "Look! monster is here" << endl;
			return FAIL;
		}
		castle.print_map(Player.printx(), Player.printy());
		Player.Utools(castle.printtools(Player.printx(), Player.printy()));
		castle.Utools(Player.printx(), Player.printy());
		UseTools();
		PrintState();
		return GAMEING;
	}
	else if(Player.printgoal() == 2) {
		if (FindMonster(Player.printx(), Player.printy())) {
			cout  << "Look! monster is here" << endl;
			return FAIL;
		}
		if (castle.IsExit(Player.printx(), Player.printy())) {
			return SUCCESS;
		}
		Player.Utools(castle.printtools(Player.printx(), Player.printy()));
		UseTools();
		PrintState();
		return GAMEING;
	}
}
/*
*function:UseTools
* --------------------------------------
* usage:player use tools 
*/
void UseTools() {
	cout << name << " knight, you have " << Player.Ltools().first << " radars";
	cout << " and " << Player.Ltools().second << " maps" << endl;
	cout << "Use tools? [y]/[n]" << endl;
	string valid;
	cin >> valid;
	if (valid == "y") {
		string temp;
		cout << "[1] radar\n[2] map" << endl;
		cin >> temp;
		if (temp != "1" && temp != "2") {
			return;
		}
		else if (temp == "1") {
			Radar();
		}
		else if (temp == "2")
		{
			Map();
		}
		else {
			cout << "error input, game is going next" << endl;
		}
	}
	else {
		return;
	}
}
/*
*function:Radar
* --------------------------------------
* usage:the function of the radar
*/
void Radar() {
	if (Player.Ltools().first == 0) {
		cout << "sorry,you don't have radar" << endl;
	}
	else {
		pair<int, int> pos1, pos2, min_pos3;
		int distant1, distant2, distant3,min = INF;
		for (int i = 0; i < monster_number; i++) {
			pos1 = m[i].Getmpos();
			distant1 = abs(pos1.first - Player.printx()) + abs(pos1.second - Player.printy());
			if (distant1 < min) {
				min_pos3 = pos1;
				min = distant1;
			}
		}
		cout << "the nearest monster is " << min << " away from you";
		pos1 = min_pos3;
		if (pos1.first - Player.printx() > 0 && pos1.second - Player.printy() > 0) {
			cout << ". And going toward southeast is bad choice";
		}
		else if (pos1.first - Player.printx() == 0 && pos1.second - Player.printy() > 0) {
			cout << ". And going toward east is bad choice";
		}
		else if (pos1.first - Player.printx() < 0 && pos1.second - Player.printy() > 0) {
			cout << ". And going toward northeast is bad choice";
		}
		else if (pos1.first - Player.printx() > 0 && pos1.second - Player.printy() == 0) {
			cout << ". And going toward south is bad choice";
		}
		else if (pos1.first - Player.printx() == 0 && pos1.second - Player.printy() == 0) {
			cout << ". Monster is Here";
		}
		else if (pos1.first - Player.printx() < 0 && pos1.second - Player.printy() == 0) {
			cout << ". And going toward north is bad choice";
		}
		else if (pos1.first - Player.printx() > 0 && pos1.second - Player.printy() < 0) {
			cout << ". And going toward southwest is bad choice";
		}
		else if (pos1.first - Player.printx() == 0 && pos1.second - Player.printy() < 0) {
			cout << ". And going toward west is bad choice";
		}
		else if (pos1.first - Player.printx() < 0 && pos1.second - Player.printy() < 0) {
			cout << ". And going toward northwest is bad choice";
		}
		cout << endl;
		Player.DecreaseTools(1);
	}
}
/*
*function:Map
* --------------------------------------
* usage:the function of the map
*/
void Map() {
	if (Player.Ltools().second == 0) {
		cout << "sorry,you don't have map" << endl;
	}
	else {
		if (Player.printgoal() == 1) {
			string recorder;
			pair<int, int> pos1;
			int distant1;
			pos1 = p1.Getppos();
			distant1 = abs(pos1.first - Player.printx()) + abs(pos1.second - Player.printy());
			cout << "the princess is " << distant1 << " away from you";
			Player.DecreaseTools(2);
			if (pos1.first - Player.printx() > 0 && pos1.second - Player.printy() > 0) {
				cout << ". And going toward southeast is good choice";
			}
			else if (pos1.first - Player.printx() == 0 && pos1.second - Player.printy() > 0) {
				cout << ". And going toward east is good choice";
			}
			else if (pos1.first - Player.printx() < 0 && pos1.second - Player.printy() > 0) {
				cout << ". And going toward northeast is good choice";
			}
			else if (pos1.first - Player.printx() > 0 && pos1.second - Player.printy() == 0) {
				cout << ". And going toward south is good choice";
			}
			else if (pos1.first - Player.printx() == 0 && pos1.second - Player.printy() == 0) {
				cout << ". She is Here";
			}
			else if (pos1.first - Player.printx() < 0 && pos1.second - Player.printy() == 0) {
				cout << ". And going toward north is good choice";
			}
			else if (pos1.first - Player.printx() > 0 && pos1.second - Player.printy() < 0) {
				cout << ". And going toward southwest is good choice";
			}
			else if (pos1.first - Player.printx() == 0 && pos1.second - Player.printy() < 0) {
				cout << ". And going toward west is good choice";
			}
			else if (pos1.first - Player.printx() < 0 && pos1.second - Player.printy() < 0) {
				cout << ". And going toward northwest is good choice";
			}
			cout << endl;
		}
		else {
			string recorder;
			pair<int, int> pos1 = make_pair(size1,size1);
			int distant1;
			distant1 = abs(pos1.first - Player.printx()) + abs(pos1.second - Player.printy());
			cout << "the exit is " << distant1 << " away from you";
			Player.DecreaseTools(2);
			if (pos1.first - Player.printx() > 0 && pos1.second - Player.printy() > 0) {
				cout << ". And going toward southeast is good choice";
			}
			else if (pos1.first - Player.printx() == 0 && pos1.second - Player.printy() > 0) {
				cout << ". And going toward east is good choice";
			}
			else if (pos1.first - Player.printx() < 0 && pos1.second - Player.printy() > 0) {
				cout << ". And going toward northeast is good choice";
			}
			else if (pos1.first - Player.printx() > 0 && pos1.second - Player.printy() == 0) {
				cout << ". And going toward south is good choice";
			}
			else if (pos1.first - Player.printx() == 0 && pos1.second - Player.printy() == 0) {
				cout << ". Exit is Here";
			}
			else if (pos1.first - Player.printx() < 0 && pos1.second - Player.printy() == 0) {
				cout << ". And going toward north is good choice";
			}
			else if (pos1.first - Player.printx() > 0 && pos1.second - Player.printy() < 0) {
				cout << ". And going toward southwest is good choice";
			}
			else if (pos1.first - Player.printx() == 0 && pos1.second - Player.printy() < 0) {
				cout << ". And going toward west is good choice";
			}
			else if (pos1.first - Player.printx() < 0 && pos1.second - Player.printy() < 0) {
				cout << ". And going toward northwest is good choice";
			}
			cout << endl;
		}
	}
}
void printsentence() {
	const int maxsize = 20;
	string name[maxsize] = {
		"The ancient castle is forever dark",
		"Monsters are still demons, the journey of knights is full of thorns",
		"What is the sound of ticking",
		"Evil does not prevail, always",
		"Hurry up, the princess will find it",
		"Monsters are most afraid of sharp swords",
		"Be careful, the strange sound is getting closer",
		"The queen is bright on the outside, but dark on the inside",
		"never stop",
		"Forward forward!!",
		"No one knows what's at the end of the hallway",
		"Watch out for that statue, he'll steal your soul",
		"Don't look in the mirror! !",
		"Princess likes to watch fireworks on the rooftop",
		"A former king died in an accident",
		"The dark queen is jealous of the beautiful princess"
	};
	cout << name[rand() % 16] << endl;
}