#include "inputvalidation.h"
#include <iomanip>
#include <QMessageBox>

std::ifstream& operator>>(std::ifstream& is, Student& st)
{
    std::string name;
    is >> st.studentNumber >> name >> st.engMark >> st.ukrMark >> st.mathMark;
    st.name = QString::fromUtf8(name.c_str());
    return is;
}
std::ofstream& operator<<(std::ofstream& os, Student& st)
{
    os << st.studentNumber << " " << std::left << std::setw(10) << std::setfill(' ') << st.name.toStdString() << st.engMark << "\t" << st.ukrMark << "\t" << st.mathMark;
    return os;
}

bool nameInputValidation(QWidget* parent, QString name)
{
    if(name.isEmpty())
    {
        QMessageBox::critical(parent, "Wrong enter", "Name field is empty!");

        return false;
    }
    else
    {
        for(auto i : name.toStdString())
        {
            if(std::isdigit(i))
            {
                QMessageBox::critical(parent, "Wrong enter", "Name field has wrong enter");
                return false;
            }
        }
    }
    return true;
}

bool markInputValidation(QWidget* parent, QString text, QString subjName)
{
    if(text.isEmpty())
    {
        QMessageBox::critical(parent, "Wrong enter", subjName+ " field is empty!");
        return false;
    }
    else
    {
        for(auto i : text.toStdString())
        {
            if(std::isalpha(i))
            {
                QMessageBox::critical(parent, "Wrong enter", subjName + " has wrong enter");
                return false;
            }
            if (text.toInt() < 0 || text.toInt() > 5)
            {
                QMessageBox::critical(parent, "Wrong enter", subjName + " has wrong mark. Enter the number between (0 - 5)!");
                return false;
            }
        }
    }
    return true;
}
bool studNumberInputValidation(QWidget* parent, QString text, int maxStudentNumber)
{
    if(text.isEmpty())
    {
        QMessageBox::critical(parent, "Wrong enter", "Field is empty!");
        return false;
    }

    else
    {

        for(auto i : text.toStdString())
        {
            if(std::isalpha(i))
            {
                QMessageBox::critical(parent, "Wrong enter", "Wrong enter");
                return false;
            }
            if (text.toInt() < 0 || text.toInt() > maxStudentNumber)
            {
                QMessageBox::critical(parent, "Wrong enter", "Student not found");
                return false;
            }
        }
    }
    return true;
}


