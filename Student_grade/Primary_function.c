#include <stdio.h>
#include "Tools.h"

int main(void)
{
	printf("\n\n     ---------------------------------------     "
		   "Welcome"
		   "     ---------------------------------------\n\n"	  
	);
	printf("\t\t\t   1. Add Student Grade.");
	printf("\t   2. Delete Student Grade.\n");
	printf("\t\t\t   3. Edit Student Grade.");
	printf("\t   4. Inquire Student Grade.\n");
	printf("Now enter your choice(1-4): ");
	char myChoice = getchar();
	while ((getchar()) != '\n') {
		continue;
	}
	while (myChoice > '4' || myChoice < '0') {
		printf("Invalid choice.\n");
		printf("Now Re-enter your choice(1-4): _\b");
		scanf("%c", &myChoice);
		while ((getchar()) != '\n') {
			continue;
		}
	}

	float chineseGrade = (float)0;
	float mathGrade = (float)0;
	float englishGrade = (float)0;
	char studentId[11] = {"a"};
	char majorName[24] = { "a" };
	char classNumber[5] = { "a" };
	char studentName[24] = { "a" };
	int id_count = 0;
	char singleChar, sure; 
	switch (myChoice)
	{
	case '1':
		printf("\nYou choose to add a student grade\n");
		printf("---------------notice---------------\n");
		printf("    example: \n\tstudent_Id: 2012004937\n"
			"\tclassNumber: 1201\n"
		);
		printf("    extra numbers will be ignored\n");
		printf("\n\nEnter stu_Id: ");		
		while (1) 
		{	
			singleChar = getchar();
			if(singleChar == '\n')
			{
				continue;
			}
			++id_count;
			if (singleChar < '0' || singleChar > '9')
			{			
				while ((getchar()) != '\n') {
					continue;
				}
				printf("\nPlease enter 10 numbers (0-9) .\nRe-enter stu_Id: ");
				id_count = 0;				
				continue;
			}
			studentId[id_count - 1] = singleChar;
			if (id_count < 10) {
				continue;
			}
			
			if (id_count == 10)
			{
				while ((getchar()) != '\n') {
					continue;
				}
				printf("Is %s a correct stu_Id? (Y or N) ", studentId);
				if ((sure = getchar()) == 'Y')
				{
					break;
				}
				id_count = 0;
				printf("\nRe-Enter stu_Id: ");
				while ((getchar()) != '\n') {
					continue;
				}
				continue;
			}			
		}

		//begin to get major name
		printf("\nEnter major_Name: ");
		while (1)
		{
			if (scanf_s("%24s", majorName, 24) != 1) {
				printf("\nInvalid length of majorName\n Re-enter major_Name: ");
			}
			printf("Is %s a correct major_Name? (Y or N) ", majorName);
			while ((getchar()) != '\n') {
				continue;
			}
			if ((sure = getchar()) == 'Y')
			{
				break;
			}
			printf("\nRe-Enter major_Name: ");
			while ((getchar()) != '\n') {
				continue;
			}
		}

		//begin to get class_Name
		printf("\nEnter class_Number: ");
		id_count = 0;
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
				while ((getchar()) != '\n') {
					continue;
				}
				printf("\nPlease enter 4 numbers (0-9) .\nRe-enter class_Number: ");
				id_count = 0;
				continue;
			}
			classNumber[id_count - 1] = singleChar;
			if (id_count < 4) {
				continue;
			}

			if (id_count == 4)
			{
				while ((getchar()) != '\n') {
					continue;
				}
				printf("Is %s a correct class_Number? (Y or N) ", classNumber);
				if ((sure = getchar()) == 'Y')
				{
					break;
				}
				id_count = 0;
				printf("\nRe-Enter class_Number: ");
				while ((getchar()) != '\n') {
					continue;
				}
				continue;
			}
		}
		
		//begin to get student_Name
		printf("\nEnter student_Name:");
		while (1)
		{
			if (scanf_s("%24s", studentName, 24) != 1) {
				printf("\nInvalid length of student_Name\n Re-enter student_Name: ");
			}
			printf("Is %s a correct student_Name? (Y or N) ", studentName);
			while ((getchar()) != '\n') {
				continue;
			}
			if ((sure = getchar()) == 'Y')
			{
				break;
			}
			printf("\nRe-Enter student_Name: ");
			while ((getchar()) != '\n') {
				continue;
			}
		}
		
		//begin to get chinese grade
		printf("\nEnter chinese_Grade: ");
		while (1) 
		{			
			scanf("%f", &chineseGrade);
			if (chineseGrade < (float)0 || chineseGrade >(float)100)
			{
				printf("Please enter number between 0 and 100.\n");
				printf("Re-Enter chinese_Grade: ");
				continue;
			}
			printf("Is %4.1f a correct chinese_Grade? (Y or N) ", chineseGrade);
			while ((getchar()) != '\n') {
				continue;
			}
			if ((sure = getchar()) == 'Y')
			{
				break;
			}
			printf("Re-Enter chinese_Grade: ");
			while ((getchar()) != '\n') {
				continue;
			}
		}

		//begin to get math grade
		printf("\nEnter math_Grade: ");
		while (1)
		{
			scanf("%f", &mathGrade);
			if (mathGrade < (float)0 || mathGrade >(float)100)
			{
				printf("Please enter number between 0 and 100.\n");
				printf("Re-Enter math_Grade: ");
				continue;
			}
			printf("Is %4.1f a correct math_Grade? (Y or N) ", mathGrade);
			while ((getchar()) != '\n') {
				continue;
			}
			if ((sure = getchar()) == 'Y')
			{
				break;
			}
			printf("Re-Enter math_Grade: ");
			while ((getchar()) != '\n') {
				continue;
			}
		}
		//begin to get english grade
		printf("\nEnter english_Grade: ");
		while (1)
		{
			scanf("%f", &englishGrade);
			if (englishGrade < (float)0 || englishGrade >(float)100)
			{
				printf("Please enter number between 0 and 100.\n");
				printf("Re-Enter english_Grade: ");
				continue;
			}
			printf("Is %4.1f a correct english_Grade? (Y or N) ", englishGrade);
			while ((getchar()) != '\n') {
				continue;
			}
			if ((sure = getchar()) == 'Y')
			{
				break;
			}
			printf("Re-Enter english_Grade: ");
			while ((getchar()) != '\n') {
				continue;
			}
		}

		printf("\n\nThis is the student information you entered\n");
		printf("StudentId    : %s\n", studentId);
		printf("MajorName    : %s\n", majorName);
		printf("ClassNumber  : %s\n", classNumber);
		printf("StudentName  : %s\n", studentName);
		printf("chineseGrade : %-5.1f\n", chineseGrade);
		printf("MathGrade    : %-5.1f\n", mathGrade);
		printf("EnglighGrade : %-5.1f\n", englishGrade);

		printf("Do you want to add it ?");
		while ((getchar()) != '\n') {
			continue;
		}
		if ((sure = getchar()) == 'Y')
		{
			//add student to list
		}

		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	
	}
	
	return 0;
}