#ifndef DELSTUDWINDOW_H
#define DELSTUDWINDOW_H

#include <QDialog>
#include "student.h"

namespace Ui {
class delStudWindow;
}

class delStudWindow : public QDialog
{
    Q_OBJECT

public:
    explicit delStudWindow(QWidget *parent = nullptr);
    bool getLastStud() const {return lastStud;}
    ~delStudWindow();

private slots:
    void on_Enter_clicked();

private:
    Ui::delStudWindow *ui;
    int maxStudentNumber();
    bool lastStud = 0;
};

#endif // DELSTUDWINDOW_H
