#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QMessageBox>
#include "inputvalidation.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddStudent_clicked()
{
    addStudent();
}

void MainWindow::addStudent()
{
    studWindow = new addStudWindow;
    studWindow->setModal(true);
    studWindow->exec();
    //this->student = studWindow->stud;
    printStudents();
    delete studWindow;
}

void MainWindow::delStudent()
{
    delStudentWindow = new delStudWindow;
    delStudentWindow->setModal(true);
    delStudentWindow->exec();

    if (delStudentWindow->getLastStud())
    {
        ui->tableWidget->setVisible(true);
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(5);
        ui->horizontalSpacer->changeSize(0,0);
        ui->tableWidget->setHorizontalHeaderLabels({"Number", "Name", "English mark", "Ukraine mark", "Math mark"});
    }
    else
    {
        printStudents();
    }
    delete delStudentWindow;
}
void MainWindow::on_DeleteStudent_clicked()
{
    delStudent();
}

void MainWindow::printStudents()
{
    Student stud;
    std::ifstream File("test.txt");
    std::vector<Student> students;
    if (!File.is_open())
    {
        QMessageBox::critical(this, "Error", "File open error!");
        return;
    }
    while (File >> stud)
    {
        students.push_back(stud);
    }
    if (students.empty())
    {
        QMessageBox::critical(this, "Error", "There aren't students in the file");
        ui->tableWidget->setVisible(true);
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(5);
        ui->horizontalSpacer->changeSize(0,0);
        ui->tableWidget->setHorizontalHeaderLabels({"Number", "Name", "English mark", "Ukraine mark", "Math mark"});

    }
    else
    {

        ui->tableWidget->setVisible(true);
        ui->tableWidget->setRowCount(students.size());
        ui->tableWidget->setColumnCount(5);
        ui->horizontalSpacer->changeSize(0,0);
        ui->tableWidget->setHorizontalHeaderLabels({"Number", "Name", "English mark", "Ukraine mark", "Math mark"});

        for (int i = 0; i < static_cast<int>(students.size()) ;i++ )
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(students[i].studentNumber)));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(students[i].name));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(students[i].engMark)));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(students[i].ukrMark)));
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(students[i].mathMark)));
        }
    }

    File.close();
}

void MainWindow::on_PrintStudents_clicked()
{
    printStudents();
}

void MainWindow::changeStudent()
{
    changeStudentWindow = new changeStudWindow;
    changeStudentWindow->setModal(true);
    changeStudentWindow->exec();
    printStudents();
    delete changeStudentWindow;
}

void MainWindow::on_ChangeStudent_clicked()
{
    changeStudent();
}
