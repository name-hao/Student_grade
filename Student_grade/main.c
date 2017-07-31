#include <stdio.h>
#include "Primary_function.h"

Student temp_Student = {
	.chineseGrade = (float)97,
	.mathGrade = (float)98,
	.englishGrade = (float)99,
	.studentId = { "2012001234" },
	.majorName = { "Computer Science" },
	.classNumber = { "1201" },
	.studentName = { "Cheng Hao" },
	.next = NULL
};
char singleChar, sure;

void pass_Redundancy_Character()
{
	while ((getchar()) != '\n') {
		continue;
	}
}

void get_Student_Id()
{
	printf("\nEnter stu_Id: ");
	int id_count = 0;
	while (1)
	{
		singleChar = getchar();
		if (singleChar == '\n')
		{
			continue;
		}
		++id_count;
		if (singleChar < '0' || singleChar > '9')
		{
			pass_Redundancy_Character();
			printf("\nPlease enter 10 numbers (0-9) .\nRe-enter stu_Id: ");
			id_count = 0;
			continue;
		}
		temp_Student.studentId[id_count - 1] = singleChar;
		if (id_count < 10) {
			continue;
		}

		if (id_count == 10)
		{
			pass_Redundancy_Character();
			printf("Is %s a correct stu_Id? (Y or N) ", temp_Student.studentId);
			if ((sure = getchar()) == 'Y')
			{
				break;
			}
			id_count = 0;
			printf("\nRe-Enter stu_Id: ");
			pass_Redundancy_Character();
			continue;
		}
	}
}

void get_Student_MajorName()
{
	printf("\nEnter major_Name: ");
	while (1)
	{
		if (scanf_s("%24s", temp_Student.majorName, 24) != 1) {
			printf("\nInvalid length of majorName\n Re-enter major_Name: ");
		}
		printf("Is %s a correct major_Name? (Y or N) ", temp_Student.majorName);
		pass_Redundancy_Character();
		if ((sure = getchar()) == 'Y')
		{
			break;
		}
		printf("\nRe-Enter major_Name: ");
		pass_Redundancy_Character();
	}
}

void get_Student_ClassName()
{
	printf("\nEnter class_Number: ");
	int id_count = 0;
	while (1)
	{
		singleChar = getchar();
		if (singleChar == '\n')
		{
			continue;
		}
		++id_count;
		if (singleChar < '0' || singleChar > '9')
		{
			pass_Redundancy_Character();
			printf("\nPlease enter 4 numbers (0-9) .\nRe-enter class_Number: ");
			id_count = 0;
			continue;
		}
		temp_Student.classNumber[id_count - 1] = singleChar;
		if (id_count < 4) {
			continue;
		}

		if (id_count == 4)
		{
			pass_Redundancy_Character();
			printf("Is %s a correct class_Number? (Y or N) ", temp_Student.classNumber);
			if ((sure = getchar()) == 'Y')
			{
				break;
			}
			id_count = 0;
			printf("\nRe-Enter class_Number: ");
			pass_Redundancy_Character();
			continue;
		}
	}
}

void get_Student_Name()
{
	//begin to get student_Name
	printf("\nEnter student_Name:");
	while (1)
	{
		if (scanf_s("%24s", temp_Student.studentName, 24) != 1) {
			printf("\nInvalid length of student_Name\n Re-enter student_Name: ");
		}
		printf("Is %s a correct student_Name? (Y or N) ", temp_Student.studentName);
		pass_Redundancy_Character();
		if ((sure = getchar()) == 'Y')
		{
			break;
		}
		printf("\nRe-Enter student_Name: ");
		pass_Redundancy_Character();
	}
}

void get_Student_ChineseGrade()
{
	//begin to get chinese grade
	printf("\nEnter chinese_Grade: ");
	while (1)
	{
		scanf("%f", &temp_Student.chineseGrade);
		if (temp_Student.chineseGrade < (float)0 || temp_Student.chineseGrade >(float)100)
		{
			printf("Please enter number between 0 and 100.\n");
			printf("Re-Enter chinese_Grade: ");
			continue;
		}
		printf("Is %4.1f a correct chinese_Grade? (Y or N) ", temp_Student.chineseGrade);
		pass_Redundancy_Character();
		if ((sure = getchar()) == 'Y')
		{
			break;
		}
		printf("Re-Enter chinese_Grade: ");
		pass_Redundancy_Character();
	}
}

void get_Student_MathGrade()
{
	//begin to get math grade
	printf("\nEnter math_Grade: ");
	while (1)
	{
		scanf("%f", &temp_Student.mathGrade);
		if (temp_Student.mathGrade < (float)0 || temp_Student.mathGrade >(float)100)
		{
			printf("Please enter number between 0 and 100.\n");
			printf("Re-Enter math_Grade: ");
			continue;
		}
		printf("Is %4.1f a correct math_Grade? (Y or N) ", temp_Student.mathGrade);
		pass_Redundancy_Character();
		if ((sure = getchar()) == 'Y')
		{
			break;
		}
		printf("Re-Enter math_Grade: ");
		pass_Redundancy_Character();
	}
}

void get_Student_EnglishGrade()
{
	//begin to get english grade
	printf("\nEnter english_Grade: ");
	while (1)
	{
		scanf("%f", &temp_Student.englishGrade);
		if (temp_Student.englishGrade < (float)0 || temp_Student.englishGrade >(float)100)
		{
			printf("Please enter number between 0 and 100.\n");
			printf("Re-Enter english_Grade: ");
			continue;
		}
		printf("Is %4.1f a correct english_Grade? (Y or N) ", temp_Student.englishGrade);
		pass_Redundancy_Character();
		if ((sure = getchar()) == 'Y')
		{
			break;
		}
		printf("Re-Enter english_Grade: ");
		pass_Redundancy_Character();
	}
}
void get_Student_Info()
{
	get_Student_Id();
	get_Student_MajorName();
	get_Student_ClassName();
	get_Student_Name();
	get_Student_ChineseGrade();
	get_Student_MathGrade();
	get_Student_EnglishGrade();
}

int main(void)
{
	init_Student_List();
	printf("\n\n     ---------------------------------------     "
		"Welcome"
		"     ---------------------------------------\n\n"
	);
	printf("\t\t\t   1. Add Student Grade.");
	printf("\t   2. Delete Student Grade.\n");
	printf("\t\t\t   3. Edit Student Grade.");
	printf("\t   4. query Student Grade.\n");
	printf("\t\t\t   5. Show All Student");
	printf("\t\t   6. Exit.\n");
	printf("     --------------------------------------------"
		   "--------"
		   "-------------------------------------------\n\n"
	);
all_Begin:
	printf("Now enter your choice(1-6): ");
	
	char myChoice ;
	/*scanf("%c", &myChoice);
	pass_Redundancy_Character();*/
	while (1) {
		myChoice = getchar();
		if (myChoice == '\n')
		{
			continue;
		}
		if (myChoice > '6' || myChoice < '0')
		{
			printf("Invalid choice.\n");
			printf("Now Re-enter your choice(1-6): _\b");
			myChoice = getchar();
			pass_Redundancy_Character();
			continue;
		}
		break;
		
	}
	int id_count = 0;
	switch (myChoice)
	{
	case '1':
		printf("\n---------------notice---------------\n");
		printf("    example: \n\tstudent_Id: 2012004937\n"
			"\tclassNumber: 1201\n"
		);
		printf("    extra numbers will be ignored\n");
		printf("------------------------------------\n");

	add_Another_Student:

		get_Student_Info();
		printf("\n\nThis is the student information you entered\n");
		
		show_single_Student(&temp_Student);
		pass_Redundancy_Character();
		printf("Do you want to add it ? (Y or N) ");
		if ((sure = getchar()) == 'Y')
		{
			if (!add_Student(&temp_Student))
			{
				printf("Do you want to add another one ? (Y or N) ");
				pass_Redundancy_Character();
				if ((sure = getchar()) == 'Y')
				{
					goto add_Another_Student;
				}
			}
			show_all_Student();
			pass_Redundancy_Character();
			printf("Do you want to add another one ? (Y or N) ");
			if ((sure = getchar()) == 'Y')
			{
				goto add_Another_Student;
			}
			printf("\n\n------------------------------------\n");
			printf("            Back to menu.\n");
			printf("------------------------------------\n\n\n");
			pass_Redundancy_Character();
			goto all_Begin;
		}
		else
		{
			pass_Redundancy_Character();
			printf("Do you want to add another one ? (Y or N) ");		
			if ((sure = getchar()) == 'Y')
			{
				goto add_Another_Student;
			}
			printf("\n\n------------------------------------\n");
			printf("            Back to menu.\n");
			printf("------------------------------------\n\n\n");
			pass_Redundancy_Character();
			goto all_Begin;
		}
		break;
	case '2':
		//begin to delete student by StudentId
		printf("\n\nEnter stu_Id you want to delete: ");
		get_Student_Id();
		if (delete_Student(temp_Student.studentId))
		{
			//printf("Delete %s Success\n", temp_Student.studentId);
		}
		printf("\n\n------------------------------------\n");
		printf("            Back to menu.\n");
		printf("------------------------------------\n\n\n");
		pass_Redundancy_Character();
		goto all_Begin;
		break;
	case '3':
		printf("\n\nEnter stu_Id you want to Edit: ");
		get_Student_Info();
		if (edit_Student(temp_Student.studentId, &temp_Student))
		{
			printf("Edit %s Success.\n", temp_Student.studentId);
			show_single_Student(&temp_Student);
		}
		else
		{
			printf("Something happened wrong.\n");
		}
		printf("\n\n------------------------------------\n");
		printf("            Back to menu.\n");
		printf("------------------------------------\n\n\n");
		pass_Redundancy_Character();
		goto all_Begin;
		break;
	case '4':
		printf("\n\nEnter stu_Id you want to query: ");
		get_Student_Id();
		show_single_Student(query_Student_by_Id(temp_Student.studentId));
		printf("\n\n------------------------------------\n");
		printf("            Back to menu.\n");
		printf("------------------------------------\n\n\n");
		pass_Redundancy_Character();
		goto all_Begin;
		break;
	case '5':
		show_all_Student();
		//printf("\n\n------------------------------------\n");
		//printf("\n            Back to menu.\n");
		printf("\n\n\n-----------------Back to menu-------------------\n");
		goto all_Begin;
	case '6':
		break;
	}
	delete_Student_List();
	return 0;
}