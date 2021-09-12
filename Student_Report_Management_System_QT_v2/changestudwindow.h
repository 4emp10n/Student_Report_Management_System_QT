#ifndef CHANGESTUDWINDOW_H
#define CHANGESTUDWINDOW_H

#include <QDialog>
#include "student.h"

namespace Ui {
class changeStudWindow;
}

class changeStudWindow : public QDialog
{
    Q_OBJECT

public:
    explicit changeStudWindow(QWidget *parent = nullptr);
    ~changeStudWindow();

private slots:
    void on_Enter_clicked();

private:
    Ui::changeStudWindow *ui;
    int maxStudentNumber();
};

#endif // CHANGESTUDWINDOW_H
