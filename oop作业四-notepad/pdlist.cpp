#include "pad_head.h"

bool Read(int argc, char** argv);//read the file and deal with it according the arcg
void Show(int argc,char **argv);//print the data in the console
static int index = 0;//current's index we will deal with
vector<PD>list;//a list of the diary
PD newpd;//will insert this diary
string path1;//finally path of the file
int main(int argc,char **argv)
{
    if (!Read(argc, argv)) {
        return -1;//read error, return -1 directly
    }
    Show(argc, argv);//show the data
}
bool Read(int argc,char **argv) {
    if (argc == 1|| argc == 3) {//when input 0 or 2 arguments(argc - 1)
        path1 = path;
    }
    else {
        path1 = argv[1];
    }
    ifstream  File(path1);//open the file
    if (!File.is_open()) {
        cout << "Can't open the file" << endl;
        return false;
    }
    while (!File.eof()) { //read all diarys store in the file
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
void Show(int argc, char** argv){
    vector<PD>::iterator p;
    if (argc == 4) {//we input 3 argu
        string low = argv[2];
        string high = argv[3];
        if (low > high) {
            cout << "Invalid input" << endl;
            return;
        }
        int flag = 0;
        for (p = list.begin(); p < list.end(); p++) {
            if ((*p).GetDate() >= low && (*p).GetDate() <= high) {//output date between high and low
                if (flag == 0) {
                    cout << (*p).GetDate() << endl;
                    flag++;
                }
                else {
                    cout <<endl<< (*p).GetDate() << endl;
                }
                for (int k = 0; k < (*p).GetSize(); k++) {
                    if((*p).GetContent(k)==".")cout << (*p).GetContent(k);
                    else cout << (*p).GetContent(k) << endl;
                    
                }
            }
        }
    }
    else if (argc == 3) {//we input 3 argu
        string low = argv[1];
        string high = argv[2];
        if (low > high) {
            cout << "Invalid input" << endl;
            return;
        }
        int flag = 0;
        for (p = list.begin(); p < list.end(); p++) {
            if ((*p).GetDate() >= low && (*p).GetDate() <= high) {//output date between high and low
                if (flag == 0) {
                    cout << (*p).GetDate() << endl;
                    flag++;
                }
                else {
                    cout << endl << (*p).GetDate() << endl;
                }
                for (int k = 0; k < (*p).GetSize(); k++) {
                    if ((*p).GetContent(k) == ".")cout << (*p).GetContent(k);
                    else cout << (*p).GetContent(k) << endl;

                }
            }
        }
    }else {
        int flag = 0;
        for (p = list.begin(); p < list.end(); p++) {//output all datas
            if (flag == 0) {
                cout << (*p).GetDate() << endl;
                flag++;
            }
            else {
                cout << endl << (*p).GetDate() << endl;
            }
            for (int k = 0; k < (*p).GetSize(); k++) {
                if ((*p).GetContent(k) == ".")cout << (*p).GetContent(k);
                else cout << (*p).GetContent(k) << endl;

            }
        }
    }
}