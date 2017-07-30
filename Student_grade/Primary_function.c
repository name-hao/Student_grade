#include "Primary_function.h"
#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

bool init_Student_List()
{
	if (all_Student.size != 0)
	{
		printf("You've already init a Student_List. Do not Re-init!");
		return false;
	}
	all_Student.size = 0;
	all_Student.head = NULL;
	all_Student.tail = NULL;
	return true;
}


bool add_Student(Student* init)
{
	Student* tmp_student = NULL;
	tmp_student = (Student*)malloc(sizeof(Student));
	if (tmp_student)
	{
		memcpy(tmp_student, init, sizeof(Student));
		if (all_Student.size == 0)
		{
			all_Student.head = tmp_student;
			all_Student.tail = tmp_student;
		}
		else 
		{
			all_Student.tail->next = tmp_student;
			all_Student.tail = tmp_student;
			++all_Student.size;
		}
		return true;
	}
	printf("Can't alloc memory for Student");
	return false;
}

bool delete_Student(char student_Id[11])
{
	if (all_Student.size == 0)
	{
		printf("There is no one student! Please add a new student.");
		return false;
	}
	Student* prev = NULL;
	Student* current = NULL;
	if (strcmp(all_Student.head->studentId, student_Id) != 0)
	{
		current = all_Student.head->next;
		prev = all_Student.head;
	}
	else 
	{
		Student* temp = all_Student.head;
		all_Student.head = temp->next;
		free(temp);
		--all_Student.size;
	}
	while (strcmp(current->studentId, student_Id) != 0)
	{
		prev = prev->next;
		if (current->next == NULL) {
			printf("There is no Student which id is %s", student_Id);
			current = all_Student.tail;
			return false;
		}
		current = current->next;			
	}
	if (current == all_Student.tail)
	{
		free(prev->next);
		printf("Delete %s success", student_Id);
		prev->next = NULL;
	}
	else
	{
		prev->next = current->next;
		free(current);
		printf("Delete %s success", student_Id);
	}
	return true;
}

bool edit_Student(char student_Id[11], Student* new_Student)
{
	Student* temp = query_Student_by_Id(student_Id);
	if (temp != NULL)
	{
		memcpy(temp, new_Student, sizeof(Student));
	}
	else
	{
		printf("There is no one student which Stu_Id is %s.", student_Id);
		return false;
	}
}

Student* query_Student_by_Id(char student_Id[11])
{
	Student* temp = all_Student.head;
	while (strcmp(temp->studentId, student_Id) != 0)
	{
		temp = temp->next;
		if (temp == NULL)
		{
			break;
		}
	}
	return temp;
}

void query_Student_by_majorName(char major_Name[24])
{
	Student* temp = all_Student.head;
	while (strcmp(temp->majorName, major_Name) != 0)
	{
		show_single_Student(temp);
		temp = temp->next;
		if (temp == NULL)
		{
			break;
		}
	}
}

void delete_Student_List()
{
	printf("\n------------------------------\n\n");
	printf("Begin to delete all Student.\n");
	if (all_Student.size == 0)
	{
		printf("There is no one to delete.\n");
	}
	Student* temp = all_Student.head;
	while (all_Student.head != NULL)
	{
		all_Student.head = temp->next;
		free(temp);
		--all_Student.size;
	}
	printf("Delete Success!\n");
	printf("\n------------------------------\n");
}

void show_all_Student()
{
	Student* temp = all_Student.head;
	while (temp->next != NULL)
	{
		show_all_Student(temp);
		temp = temp->next;
	}
}

void show_single_Student(Student* stu)
{
	printf("------------------------------------\n");
	printf("StudentId    : %s\n", stu->studentId);
	printf("MajorName    : %s\n", stu->majorName);
	printf("ClassNumber  : %s\n", stu->classNumber);
	printf("StudentName  : %s\n", stu->studentName);
	printf("chineseGrade : %-5.1f\n", stu->chineseGrade);
	printf("MathGrade    : %-5.1f\n", stu->mathGrade);
	printf("EnglighGrade : %-5.1f\n", stu->englishGrade);
	printf("------------------------------------\n");
}
