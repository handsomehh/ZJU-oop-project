//#pragma once
#ifndef SCORE_H_
#define SCORE_H_
// ͷ�ļ�����
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
//�궨�壬�ں�����������ָʾ����
#define COURSE -3
#define STUDENT -5
#define ERROR -2
using namespace std;
const int maxsize = 7;//�γ̿�Ŀ��������Ҫ���ӻ����txt�ļ��еĿγ�������ֻ����ĸ�ֵ����
//��Ķ���
class table {
private :
	int student_num;		//ѧ������
	string course[maxsize];//�γ��б�
	struct student {	//��һ��ѧ������Ϣ����
		string name;	//ѧ������
		int score[maxsize];//ѧ������
		struct student* next;//����ָ����һ���ڵ�
	}*stu,*head;
public:
	void Init(string name[maxsize]);//��ĳ�ʼ��
	void Add(string student_name,int temp[maxsize]);//���һ��ѧ����Ϣ
	double Cal_average(int flag,string name);//����ѧ����γ̵�ƽ����
	int Cal_max(string course_name);//����γ���߷�
	int Cal_min(string course_name);//����γ���ͷ�
	int outone(string  student_name, int temp);//����һ��ѧ����ĳ�ſγ̷���
};

#endif