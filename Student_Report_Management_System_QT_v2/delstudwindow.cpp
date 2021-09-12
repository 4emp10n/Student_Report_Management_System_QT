#include "delstudwindow.h"
#include "ui_delstudwindow.h"
#include "QMessageBox"
#include <fstream>
#include <vector>
#include "inputvalidation.h"

delStudWindow::delStudWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delStudWindow)
{
    ui->setupUi(this);
}

delStudWindow::~delStudWindow()
{
    delete ui;
}

int delStudWindow::maxStudentNumber()
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


void delStudWindow::on_Enter_clicked()
{
    if(!(studNumberInputValidation(this, ui->delStudNumber->text(), maxStudentNumber())))
    {
        return;
    }
    std::ifstream File("test.txt");
    if (!File.is_open())
    {
        QMessageBox::critical(this, "Error", "File open error!");
        return;
    }

    std::vector<Student> students;
    Student stud;
    bool isNumber = 0;
    while (File >> stud)
    {
        if (stud.getStudNumber() != ui->delStudNumber->text().toInt())
        {
            students.push_back(stud);
        }
        else
        {
            isNumber = 1;
        }
    }
    File.close();

    if(students.empty()) lastStud = 1;

    std::ofstream  Ofile("test.txt");
    if (!Ofile.is_open())
    {
        QMessageBox::critical(this, "Error", "File open error!");
        return;
    }

    for (int i = 0; i < static_cast<int>(students.size()); i++)
    {
        students[i].studentNumber = i + 1;
        Ofile << students[i] << std::endl;

    }

    if (isNumber == 0)
    {
        QMessageBox::critical(this, "Error", "Student with this number was not found!");
    }
    Ofile.close();

    close();

}
