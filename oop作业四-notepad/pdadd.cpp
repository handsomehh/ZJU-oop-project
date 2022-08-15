#include "pad_head.h"
//the file is to insert a item into diary file
bool Read(int argc, char** argv);
void modify();//modify if necessary
void Write();//write into file directly
static int index = 0;//current index we will deal 
vector<PD>list;//a lsit 
PD newpd;
static string path1;//finally path
int main(int argc, char** argv)
{
    if (!Read(argc, argv)) {//if read error, return directly
        return 0;
    }
    modify();
    Write();
}
bool Read(int argc, char** argv){
    if (argc == 1) {
        path1 = path;
    }
    else {
        path1 = argv[1];
    }
    ifstream  File(path1);
    if (!File.is_open()) {
        cout << "Can't open the file" << endl;
        return false;
    }
    while (!File.eof()) {//store diary in list one by one 
        string str;
        getline(File, str);
        if (File.eof())break;
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
void modify() {
    string da;
    cin >> da;
    newpd.AddDate(da);
    while (da!=".") {
        cin >> da;
        newpd.AddContent(da);
    }
}
void Write() {
    int i,flag=0;
    vector<PD>::iterator p;
    for (p = list.begin(); p < list.end();p++) {
        if (p->GetDate() == newpd.GetDate()) {//if we find a item date is same 
            flag = 1;
            break;
        }
        else if (p->GetDate() > newpd.GetDate()) {//verify the correct sort
            flag = 2;
            break;
        }
    }
    if (p == list.end()) {//add item in the tail 
        list.push_back(newpd);
    }
    if (flag == 1) {//modify the item
        *p = newpd;
    }
    if (flag == 2) {
        list.insert(p, newpd);//insert in the middle of file
    }
    ofstream File2(path1);
    if (!File2.is_open()) {
        cout << "Can't open the file" << endl;
        return ;
    }
    /*vector<string>::iterator p;*/
    for (p = list.begin(); p < list.end(); p++) {//write data in to file
        File2 << (*p).GetDate() << endl;
        for (int k = 0; k < (*p).GetSize();k++) {
            if ((*p).GetContent(k) == "." && p == list.end() - 1) {
                File2 << (*p).GetContent(k);
            }
            else {
                File2 << (*p).GetContent(k)<<endl;
            }
        }
    }
}