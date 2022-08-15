#include"pad_head.h"

void PD::AddContent(string str) {
	content.push_back(str);//add a item into diary
}

void PD::AddDate(string str) {
	date = str;//add a date into diary
}

void PD::clear() {//clead this item
	date = "";
	content.clear();
}

string PD::GetContent(int index) {//get content of block k
	return content[index];
}

string PD::GetDate() {//gete date of this diary
	return date;
}

vector<string>::size_type PD::GetSize() {//get size
	return content.size();
}