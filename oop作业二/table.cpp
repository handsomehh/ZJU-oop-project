/*这个文件是score.h的实现文件，是对类table的函数功能实现*/
#include"score.h"

//初始化这个类
void table::Init(string name[maxsize]) {
	student_num = 0;
	stu = new struct student;
	stu->next = NULL;
	head = stu;
	for (int i = 0; i < maxsize ; i++) {
		course[i] = name[i];
	}
}
//在table中增加一个新的学生信息，student_name是学生姓名,temp数组储存学生的成绩
void table::Add(string student_name, int temp[maxsize]) {
	stu = head;
	student_num++;
	while (stu->next != NULL)stu = stu->next;
	stu->name = student_name;
	memcpy(stu->score, temp,maxsize*sizeof(int));
	stu->next = new struct student;
	stu->next->next = NULL;
}
//计算平均值，当flag是宏COURSE时计算课程名为name的成绩均分，若该科目无人选择返回ERROR标志
//同理当flag是宏STUDENT时，计算名称为name的学生均分，若不存在分数择返回ERROR标志
double table::Cal_average(int flag, string name) {
	if (flag == COURSE) {
		int index;
		for (index = 0; index < maxsize; index++) {
			if (name == course[index])break;
		}
		double sum=0, num1=0;
		for (stu = head; stu ->next!= NULL; stu = stu->next) {
			if (stu->score[index] != -1) {
				sum += stu->score[index];
				num1++;
			}
		}
		if (num1 != 0)
			return sum / num1;
		else
			return ERROR;
	}
	else if (flag == STUDENT) {
		double sum = 0, num1 = 0;
		for (stu = head; stu->next != NULL; stu = stu->next) {
			if (stu->name==name) {
				for (int i = 0; i < maxsize; i++) {
					if (stu->score[i] != -1) {
						sum += stu->score[i];
						num1++;
					}
				}
				if (num1 != 0)
					return sum / num1;
				else
					return ERROR;
			}
		}
	}
}
/*计算课程名为course_Name的课程课程最大分数*/
int table::Cal_max(string course_name) {
	int index;
	for (index = 0; index < maxsize; index++) {
		if (course_name == course[index])break;
	}
	int flag = 0,max=0;
	for (stu = head; stu ->next!= NULL; stu = stu->next) {
		if (flag == 0 && stu->score[index] != -1) {
			max = stu->score[index];
			flag = 1;
		}
		else if (stu->score[index] != -1&&max<stu->score[index] ) {
			max = stu->score[index];
		}
	}
	if (flag == 0)return ERROR;
	return max;
}
/*计算课程名为course_Name的课程课程最低分数*/
int table::Cal_min(string course_name) {
	int index;
	for (index = 0; index < maxsize; index++) {
		if (course_name == course[index])break;
	}
	int flag = 0, min=0;
	for (stu = head; stu ->next!= NULL; stu = stu->next) {
		if (flag == 0 && stu->score[index] != -1) {
			min = stu->score[index];
			flag = 1;
		}
		else if (stu->score[index] != -1 && min > stu->score[index]) {
			min = stu->score[index];
		}
	}
	if (flag == 0)return ERROR;
	return min;
}
/*输出学生"student_name"的第temp门课程分数*/
int table::outone(string  student_name, int temp) {
	for (stu = head; stu != NULL; stu = stu->next) {
		if (stu->name == student_name) {
			return stu->score[temp];
		}
	}
}