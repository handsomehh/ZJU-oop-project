/*����ļ���score.h��ʵ���ļ����Ƕ���table�ĺ�������ʵ��*/
#include"score.h"

//��ʼ�������
void table::Init(string name[maxsize]) {
	student_num = 0;
	stu = new struct student;
	stu->next = NULL;
	head = stu;
	for (int i = 0; i < maxsize ; i++) {
		course[i] = name[i];
	}
}
//��table������һ���µ�ѧ����Ϣ��student_name��ѧ������,temp���鴢��ѧ���ĳɼ�
void table::Add(string student_name, int temp[maxsize]) {
	stu = head;
	student_num++;
	while (stu->next != NULL)stu = stu->next;
	stu->name = student_name;
	memcpy(stu->score, temp,maxsize*sizeof(int));
	stu->next = new struct student;
	stu->next->next = NULL;
}
//����ƽ��ֵ����flag�Ǻ�COURSEʱ����γ���Ϊname�ĳɼ����֣����ÿ�Ŀ����ѡ�񷵻�ERROR��־
//ͬ��flag�Ǻ�STUDENTʱ����������Ϊname��ѧ�����֣��������ڷ����񷵻�ERROR��־
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
/*����γ���Ϊcourse_Name�Ŀγ̿γ�������*/
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
/*����γ���Ϊcourse_Name�Ŀγ̿γ���ͷ���*/
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
/*���ѧ��"student_name"�ĵ�temp�ſγ̷���*/
int table::outone(string  student_name, int temp) {
	for (stu = head; stu != NULL; stu = stu->next) {
		if (stu->name == student_name) {
			return stu->score[temp];
		}
	}
}