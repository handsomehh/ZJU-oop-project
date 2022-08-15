#include <iostream>
#include <fstream>
#include<string>
#include<iomanip>
using namespace std;


const int MAXSIZE = 100;						// define the maxsize of the input
struct student {										//define the structure to store and process the data
	string name;										//the name of a student
	string number;										//the number of a student
	int sco1;												//the score1 of a student
	int sco2;												//the sco2 of a student
	int sco3;												//the sco3 of a student
	float average;										//the average score of a student
}*stud[MAXSIZE];
int index, mi[3], ma[3];							//index is the size of data you put in,mi is min score ,ma is max score
float average[3];										//average of the total students
int Read_File(string file_name);				//read a file data from 'filename' file ,eg. data.txt
void ProcessData();									//calculate data
void PrintResult();									//control the output,one in console and the other in the file you put name in
int main() {
	string file_name;									//input your data source from file name 
	int num;

	cout << "Input the file name which will be processed" << endl;
	cin >> file_name;
	if (!Read_File(file_name))return 0;
	ProcessData();
	PrintResult();
}

int Read_File(string file_name) {	//read data
	ifstream in_file(file_name);
	if (!in_file.is_open()) {					//judge whether the file you input doesn't exist
		cout << "fatal error,file doesn't exist" << endl;
		return 0;
	}
	else {
		int i = 0;
		while (!in_file.eof()) {					//read until file is empty
			stud[i] = new struct student;//allocate the memory to struct
			in_file >> stud[i]->number;
			if (in_file.eof())break;			//avoid the '\n' and ' 'in the tail of file
			in_file >> stud[i]->name;
			in_file >> stud[i]->sco1;
			in_file >> stud[i]->sco2;
			in_file >> stud[i]->sco3;
			i++;
		}
		index = i - 1;
		in_file.close();
	}
	return 1;
}
void ProcessData() {//process the data
	int i;
	mi[0] = stud[0]->sco1;
	mi[1] = stud[0]->sco2;
	mi[2] = stud[0]->sco3;
	ma[0] = stud[0]->sco1;
	ma[1] = stud[0]->sco2;
	ma[2] = stud[0]->sco3;
	average[0] = 0;
	average[1] = 0;
	average[2] = 0;
	for (i = 0; i <= index; i++) {
		if (mi[0] > stud[i]->sco1)mi[0] = stud[i]->sco1;
		if (mi[1] > stud[i]->sco2)mi[1] = stud[i]->sco2;
		if (mi[2] > stud[i]->sco3)mi[2] = stud[i]->sco3;
		if (ma[0] < stud[i]->sco1)ma[0] = stud[i]->sco1;
		if (ma[1] < stud[i]->sco2)ma[1] = stud[i]->sco2;
		if (ma[2] < stud[i]->sco3)ma[2] = stud[i]->sco3;
		average[0] += stud[i]->sco1;
		average[1] += stud[i]->sco2;
		average[2] += stud[i]->sco3;
		stud[i]->average = (stud[i]->sco1 + stud[i]->sco2 + stud[i]->sco3) / 3.0;
	}
	average[0] /= index;
	average[1] /= index;
	average[2] /= index;
}
void PrintResult() {//control the output 
	cout << setiosflags(ios::fixed) << setprecision(6) << setiosflags(ios::left);
	cout << setw(10) << "no" << setw(10) << "name";
	cout << setw(10) << "score1" << setw(10) << "score2";
	cout << setw(10) << "score3" << setw(10) << "average" << endl;
	for (int i = 0; i <= index; i++) {
		cout << setw(10) << stud[i]->number << setw(10) << stud[i]->name << setw(10) << stud[i]->sco1;
		cout << setw(10) << stud[i]->sco2 << setw(10) << stud[i]->sco3 << setw(10) << stud[i]->average << endl;
	}
	cout << setw(10) << " " << setw(10) << "average" << setw(10) << average[0] << setw(10) << average[1] << setw(10) << average[2] << endl;
	cout << setw(10) << " " << setw(10) << "min" << setw(10) << mi[0] << setw(10) << mi[1] << setw(10) << mi[2] << endl;
	cout << setw(10) << " " << setw(10) << "max" << setw(10) << ma[0] << setw(10) << ma[1] << setw(10) << ma[2] << endl;
}