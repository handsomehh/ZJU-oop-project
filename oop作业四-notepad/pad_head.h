#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

const string path = "1.txt";//设置默认文件的缺省值，当后续pdadd等四个操作参数不够时，会调用缺省的路径，可自己更改

class PD {//record a piece of diary 
private:
	string date;//record diary's date
	vector<string> content;//record diary's content
public:
	PD() {};
	void AddContent(string str);//add text to the pd
	void clear();//clear text in the pd
	void AddDate(string str);//set the date to the pd
	string GetDate();//read in the date of the diary
	string GetContent(int index);//read the diary's content of k block
	vector<string>::size_type GetSize();//read the size of the elements storing in the diary
	~PD() {};
};