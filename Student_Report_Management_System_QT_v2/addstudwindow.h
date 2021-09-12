#ifndef ADDSTUDWINDOW_H
#define ADDSTUDWINDOW_H

#include <QDialog>
#include <fstream>
#include "student.h"

namespace Ui {
class addStudWindow;
}

class addStudWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addStudWindow(QWidget *parent = nullptr);
    ~addStudWindow();

private slots:
    void on_Enter_clicked();

private:
    Ui::addStudWindow *ui;
    int maxStudentNumber();
};

#endif // ADDSTUDWINDOW_H
