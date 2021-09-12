#include "addstudwindow.h"
#include "ui_addstudwindow.h"
#include <fstream>
#include <QMessageBox>
#include <vector>
#include "student.h"
#include "inputvalidation.h"

addStudWindow::addStudWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStudWindow)
{
    ui->setupUi(this);
}

addStudWindow::~addStudWindow()
{
    delete ui;
}

int addStudWindow::maxStudentNumber()
{
    Student stud;
    std::ifstream File("test.txt");
    std::vector<Student> students;
    if (!File.is_open())
    {
        QMessageBox::critical(this, "Error", "File open error!");
    }
    while (File >> stud)
    {
        students.push_back(stud);
    }
    File.close();

    int maxStudentNumber = 0;
    for (auto i : students)
    {
        if (i.getStudNumber() > maxStudentNumber) maxStudentNumber = i.getStudNumber();
    }

    return maxStudentNumber;
}

void addStudWindow::on_Enter_clicked()
{
    if(!(nameInputValidation(this, ui->Name->text()) && markInputValidation(this, ui->engMark->text(), "English mark") &&
         markInputValidation(this, ui->ukrMark->text(), "Ukraine mark") && markInputValidation(this, ui->mathMark->text(), "Math mark")))
    {
        return;
    }
    Student stud;
    stud.name = ui->Name->text();
    stud.ukrMark =ui->ukrMark->text().toInt();
    stud.engMark = ui->engMark->text().toInt();
    stud.mathMark = ui->mathMark->text().toInt();
    stud.studentNumber = maxStudentNumber() + 1;
    std::ofstream oFile("test.txt",std::ios::app);
    oFile<<stud<<'\n';

    close();
}
