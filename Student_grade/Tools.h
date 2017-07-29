#pragma once

typedef struct {
	float chineseGrade;
	float mathGrade;
	float englishGrade;
	char studentId[11];
	char majorName[24];
	char className[5];
	char studentName[24];
} Primary_Student;

typedef struct {
	Primary_Student* stuNode;
};