#include "student.h"

Student::Student()
{

}

Student Student::operator=(const Student& st)
{
    this->engMark = st.engMark;
    this->mathMark = st.mathMark;
    this->name = st.name;
    this->ukrMark = st.ukrMark;
    this->studentNumber = st.studentNumber;
    return *this;
}

int Student::getStudNumber()
{
    return studentNumber;
}
