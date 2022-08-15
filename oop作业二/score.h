//#pragma once
#ifndef SCORE_H_
#define SCORE_H_
// 头文件定义
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
//宏定义，在函数调用中起到指示作用
#define COURSE -3
#define STUDENT -5
#define ERROR -2
using namespace std;
const int maxsize = 7;//课程科目数量，若要增加或减少txt文件中的课程数量，只需更改该值即可
//类的定义
class table {
private :
	int student_num;		//学生人数
	string course[maxsize];//课程列表
	struct student {	//对一个学生的信息描述
		string name;	//学生姓名
		int score[maxsize];//学生分数
		struct student* next;//链表指向下一个节点
	}*stu,*head;
public:
	void Init(string name[maxsize]);//类的初始化
	void Add(string student_name,int temp[maxsize]);//添加一个学生信息
	double Cal_average(int flag,string name);//计算学生或课程的平均分
	int Cal_max(string course_name);//计算课程最高分
	int Cal_min(string course_name);//计算课程最低分
	int outone(string  student_name, int temp);//访问一个学生的某门课程分数
};

#endif