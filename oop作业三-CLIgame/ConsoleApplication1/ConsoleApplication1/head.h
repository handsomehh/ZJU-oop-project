#ifndef _CLI_H_
#define _CLI_H_

//文件引用
#include "knight.cpp"
#include "castle.cpp"
#include "monster.cpp"
#include "Princess.cpp"
#include<iostream>
#include<string>
//宏定义
#define EASY 1
#define NORMAL 2
#define HARD 3
#define SELFDEFINE 4
#define SUCCESS 1
#define FAIL 2
#define GAMEING 3
#define ERROR -4
//全局变量定义
using namespace std;
const int maxsize = 301;
const int INF = 9999999;
string name;
int mode, err = 0;
long int size1;
int** map;
int monster_number;
Princess p1;
monster m[maxsize];
castleGenerate castle;
knight Player(1, 1);
#endif