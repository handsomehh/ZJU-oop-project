#include "score.h"
//全局变量定义
table scot;//定义table类变量scot储存学生信息
string name[maxsize];//定义课程清单
struct sco {//定义学生清单以访问学生信息
    string sname;//学生姓名
    struct sco* next;
}*head;//头指针
//函数定义
int Read(string str);//读取数据
void Print();//打印数据

int main()
{
    string str;
    cout << "请输入要处理的文件名：" << endl;//输入要处理的文件名
    cin >> str;
    if (!Read(str))return 0;
    Print();
}
int Read(string str) {
    ifstream File1(str);
    string ptr;
    if (!File1) {
        cout << "fatal error, file doesn't exist" << endl;
        return 0;
    }
    for (int i = 0; i <= maxsize; i++) {
        if (i != 0)File1 >> name[i - 1];//读取第一行以初始化课程信息
        else File1 >> ptr;
    }
    table sco;
    scot.Init(name);//初始化table
    head = NULL;
    struct sco* temp=NULL;
    while (!File1.eof()) {//读取学生数据
        struct sco* node = new struct sco;
        File1 >> node->sname;//读学生姓名
        string b[maxsize];
        int a[maxsize];     
        for (int i = 0; i < maxsize; i++)//读取各科成绩，'#'表示该同学没有这门课的成绩
        {
            File1 >> b[i];
            if (File1.eof()){
                return 1;//防止文件末尾的多余空格
            }
            const char* ch = b[i].c_str();
            if (ch[0] == '#')a[i] = -1;//将string转为整型
            else a[i] = ch[0] - '0' + 0;
        }
        if (head == NULL) {//读学生姓名
            head = node;
            head->next = NULL;
            temp = head;
        }
        else {
            node->next = NULL;
            temp->next = node;
            temp = temp->next;
        }
        if (head->next == NULL)scot.Add(head->sname, a);//写入一项新数据
        else scot.Add(temp->sname, a);
    }
    File1.close();
    return 1;
}
void Print() {//打印最终结果
    int index;//每一行头部的序号
    cout << setiosflags(ios::fixed) << setprecision(6) << setiosflags(ios::left);
    cout << setw(10) << "no" << setw(10) << "name";
    for (index = 0; index < maxsize; index++)cout << setw(10) << name[index];
    cout << setw(10) << "average" << endl;//打印第一行
    index = 1;
    struct sco* temp = head;
    for (; temp != NULL; temp = temp->next) {
        cout << setw(10) << index++;
        cout << setw(10) << temp->sname;//打印学生姓名
        for (int j = 0; j < maxsize; j++)
            if (scot.outone(temp->sname, j) != -1)cout << setw(10) << scot.outone(temp->sname, j);//打印成绩
            else cout << setw(10) << '#';//未选的课程打印'#'
        if (scot.Cal_average(STUDENT, temp->sname) != ERROR)cout << setw(10) << scot.Cal_average(STUDENT, temp->sname);
        else cout << setw(10) << '#';//未选任何课程打印'#'
        cout << endl;
    }
    cout << setw(10) << " " << setw(10) << "average";
    for (int i = 0; i < maxsize; i++)
        if (scot.Cal_average(COURSE, name[i]) != ERROR)cout << setw(10) << scot.Cal_average(COURSE, name[i]);//打印课程均分
        else cout << setw(10) << '#';//无人选该科打印'#'
    cout << endl << setw(10) << " " << setw(10) << "max";
    for (int i = 0; i < maxsize; i++)
        if (scot.Cal_max(name[i]) != ERROR)cout << setw(10) << scot.Cal_max(name[i]);//打印课程最高
        else cout << setw(10) << '#';//无人选该科打印'#'
    cout << endl << setw(10) << " " << setw(10) << "min";
    for (int i = 0; i < maxsize; i++)
        if (scot.Cal_min(name[i]) != ERROR)cout << setw(10) << scot.Cal_min(name[i]);//打印课程最低分
        else cout << setw(10) << '#';//无人选该科打印'#'
}