#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int score;

    bool operator<(const Student &other_student)
    {
        // return score < other_student.score;
        return score != other_student.score ? score < other_student.score : name < other_student.name;
    }

    friend ostream &operator<<(ostream &os, const Student &student)
    {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }
};
#endif // SELECTIONSORT_STUDENT_H