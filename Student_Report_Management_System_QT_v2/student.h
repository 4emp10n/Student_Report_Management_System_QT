#ifndef STUDENT_H
#define STUDENT_H
#include <QString>


struct Student
{
    Student();
    Student operator=(const Student& st);
    int studentNumber = 0;
    int engMark = 0, ukrMark = 0, mathMark = 0;
    QString name = "";
    int getStudNumber();
};

#endif // STUDENT_H
