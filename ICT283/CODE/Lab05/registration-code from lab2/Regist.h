#ifndef REGIST_H
#define REGIST_H

#include "Result.h"
#include <map>
#include <iostream>


using namespace std;

const unsigned MaxResults= 10;

class Registration
{
public:
    Registration();
    void SetCount(unsigned count);
    void SetStudentId(long studentId, string studentName);
    void SetSemester(unsigned semester);
    void SetResult(const Result& result, unsigned count);
    const Result& GetResults(unsigned count) const;
    unsigned GetSemester() const;
    map<long, string> GetStudentMap() const;
    unsigned GetCredits() const;
    unsigned GetCount() const;

private:
    map <long, string> m_studentId;     // student ID number
    unsigned m_semester;          // semester year, number
    unsigned m_count;             // number of courses
    Result m_results[MaxResults]; // array of Results
};

ostream & operator <<( ostream & os, const Registration & R);
istream & operator >>( istream & input, Registration & R );


#endif

