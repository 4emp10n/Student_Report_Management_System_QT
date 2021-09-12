#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <fstream>
#include "student.h"
#include <QWidget>
std::ofstream& operator<< (std::ofstream& os, Student& st);
std::ifstream& operator>> (std::ifstream& is, Student& st);
bool nameInputValidation(QWidget* parent, QString name);
bool markInputValidation(QWidget* parent, QString text, QString subjName);
bool studNumberInputValidation(QWidget* parent, QString text, int maxStudentNumber);

#endif // INPUTVALIDATION_H
