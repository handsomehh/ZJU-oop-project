#include "pad_head.h"

void Read();//read the file and deal with it according the arcg
void Show(int argc, char** argv);//print the data in the console
static int index = 0;//current's index we will deal with
vector<PD>list;//a list of the diary
PD newpd;//will insert this diary
int main(int argc,char **argv)
{
    Read();
    Show(argc,argv);
}
void Read() { //read data by standard input stream
    while (1){
        string str;
        getline(cin, str);
        //cout << str<<endl;
        PD temp;
        temp.AddDate(str);
        while (str != ".") {
            getline(cin, str);
           //cout << str << endl;
            temp.AddContent(str);
        }
        
        list.push_back(temp);
        if (cin.eof())break;
       //cout << "input one" << endl;
    }
}
void Show(int argc,char **argv) {//show the data item by iytem
    vector<PD>::iterator p;
    int flag = 0;
    if (argc == 2) {
        string low = argv[1];
       // cout << argv[1] << endl;
        for (p = list.begin(); p < list.end(); p++) {
            //cout << (*p).GetDate() << endl;
            if ((*p).GetDate() == low) {
                flag = 1;
                cout << (*p).GetDate() << endl;
                for (int k = 0; k < (*p).GetSize(); k++) {
                    if ((*p).GetContent(k) == ".")cout << (*p).GetContent(k);
                    else cout << (*p).GetContent(k) << endl;
                }
            }
        }
        if (flag == 0) {
            cout << "没有满足条件的查询结果" << endl;
        }
    }
    else {
        cout << "(arguments warning) Invalid input" << endl;
    }
}