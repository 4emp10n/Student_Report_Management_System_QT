#include "changestudwindow.h"
#include "ui_changestudwindow.h"
#include <fstream>
#include <QMessageBox>
#include "inputvalidation.h"

changeStudWindow::changeStudWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeStudWindow)
{
    ui->setupUi(this);
}

changeStudWindow::~changeStudWindow()
{
    delete ui;
}

int changeStudWindow::maxStudentNumber()
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

void changeStudWindow::on_Enter_clicked()
{
    if(!(studNumberInputValidation(this, ui->studNumber->text(), maxStudentNumber()) && nameInputValidation(this, ui->Name->text())
         && markInputValidation(this, ui->engMark->text(), "English mark") && markInputValidation(this, ui->ukrMark->text(), "Ukraine mark") &&
       markInputValidation(this, ui->mathMark->text(), "Math mark")))
    {
        return;
    }

    Student stud;
    std::ifstream File("test.txt");
    if (!File.is_open())
    {
        QMessageBox::critical(this, "Error", "File is not open");
    }

    std::vector<Student> students;
    bool isNumber = 0;
    while (File >> stud)
    {
        if (stud.getStudNumber() == ui->studNumber->text().toInt()) isNumber = 1;

        students.push_back(stud);
    }
    File.close();

    if (isNumber == 1)
    {
        std::ofstream  oFile("test.txt");
        if (!oFile.is_open())
        {
            QMessageBox::critical(this, "Error", "File is not open");
        }

        for (int i = 0; i < static_cast<int>(students.size()); i++)
        {
            if (students[i].getStudNumber() == ui->studNumber->text().toInt())
            {
                students[i].studentNumber = i + 1;
                students[i].name = ui->Name->text();
                students[i].ukrMark = ui->ukrMark->text().toInt();
                students[i].engMark = ui->engMark->text().toInt();
                students[i].mathMark = ui->mathMark->text().toInt();
                oFile << students[i] << std::endl;


            }
            else
            {
                oFile << students[i] << std::endl;
            }
        }
        oFile.close();
    }
    else
    {
        QMessageBox::critical(this, "Wrong enter", "Student with this number was not found");
        return;
    }


     close();
}
