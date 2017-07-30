#pragma once
#pragma once
#include<stdbool.h>
typedef struct Student {
	float chineseGrade;
	float mathGrade;
	float englishGrade;
	char studentId[11];
	char majorName[24];
	char classNumber[5];
	char studentName[24];
	struct Student * next;
} Student;

typedef struct Student_List {
	long long size;
	Student* head;
	Student* tail;
} Student_List;

Student_List all_Student;

bool init_Student_List();
bool add_Student(Student* init);
bool delete_Student(char student_Id[11]);
bool edit_Student(char student_Id[11], Student* new_Student);
Student* query_Student_by_Id(char student_Id[11]);
void query_Student_by_majorName(char major_Name[24]);
void delete_Student_List();
void show_all_Student();
void show_single_Student(Student* stu);