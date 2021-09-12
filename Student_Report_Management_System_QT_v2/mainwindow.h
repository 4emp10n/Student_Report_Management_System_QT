#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "QString"
#include "addstudwindow.h"
#include "delstudwindow.h"
#include "changestudwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void addStudent();
    void delStudent();
    void printStudents();
    void changeStudent();
    friend std::ifstream& operator>> (std::ifstream& is, Student& st);
    ~MainWindow();

private slots:
    void on_AddStudent_clicked();

    void on_DeleteStudent_clicked();

    void on_PrintStudents_clicked();

    void on_ChangeStudent_clicked();


private:
    Ui::MainWindow *ui;
    addStudWindow* studWindow;
    delStudWindow* delStudentWindow;
    changeStudWindow* changeStudentWindow;
};
#endif // MAINWINDOW_H
