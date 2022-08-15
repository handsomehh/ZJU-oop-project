#include "pad_head.h"

bool Read(int argc, char** argv);//read the file and deal with it according the arcg
bool Show(int argc, char** argv);//print the data in the console
static int index = 0;//current's index we will deal with
vector<PD>list;//a list of the diary
PD newpd;//will insert this diary
string path1;//finally path of the file
int main(int argc, char** argv)
{
    if (!Read(argc, argv)) {//if read error ,return directly
        return -1;
    }
    if (Show(argc, argv)) {//show the data 
        return 0;
    }
    else {
        return -1;
    }
}
bool Read(int argc, char** argv){
    if (argc == 2) {//assign the path according to the arguments's number
        path1 = path;
    }
    else if(argc == 3) {
        path1 = argv[1];
    }
    else {
        cout << "arguments are conflict" << endl;
        return false;
    }
    ifstream  File(path1);
    if (!File.is_open()) {
        cout << "Can't open file" << endl;
        return false;
    }
    while (!File.eof()) {//read diary into list 
        string str;
        getline(File, str);
        PD temp;
        temp.AddDate(str);
        while (str != "." && !File.eof()) {
            getline(File, str);
            temp.AddContent(str);
        }
        list.push_back(temp);
    }
    File.close();
}
void Write() {//write data item by item
    int i, flag = 0;
    vector<PD>::iterator p;
    ofstream File2(path1);
    /*vector<string>::iterator p;*/
    for (p = list.begin(); p < list.end(); p++) {
        File2 << (*p).GetDate() << endl;
        for (int k = 0; k < (*p).GetSize(); k++) {
            if ((*p).GetContent(k) == "." && p == list.end() - 1) {
                File2 << (*p).GetContent(k);
            }
            else {
                File2 << (*p).GetContent(k) << endl;
            }
        }
    }
}
bool Show(int argc, char** argv) {//show the data accoring to the arguements' number
    vector<PD>::iterator p;
    int flag = 0;
    if (argc == 3) {
        string low= argv[2];
        for (p = list.begin(); p < list.end(); p++) {
            if ((*p).GetDate() == low) {
                list.erase(p);
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return false;
        }
        else {
            Write();
            return true;
        }
    }
    else if (argc == 2) {
        string low = argv[1];
        for (p = list.begin(); p < list.end(); p++) {
            if ((*p).GetDate() == low) {
                list.erase(p);
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return false;
        }
        else {
            Write();
            return true;
        }
    }
    else{
        cout << "Invalid input" << endl;
        return false;
    }
}