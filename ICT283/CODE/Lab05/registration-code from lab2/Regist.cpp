#include "Regist.h"


Registration::Registration()
{
    m_count = 0;
}

void Registration::SetCount(unsigned count)
{
    m_count = count;
}
void Registration::SetStudentId(long studentId, string studentName)
{
    for (char& c : studentName)
    {
        if (c == '_')
        {
            c = ' ';
        }
    }
    m_studentId[studentId] = studentName;
}
void Registration::SetSemester(unsigned semester)
{
    m_semester = semester;
}
void Registration::SetResult(const Result& result, unsigned count)
{
    m_results[count] = result;
}

const Result& Registration::GetResults(unsigned count) const
{
    return m_results[count];
}
unsigned Registration::GetSemester() const
{
    return m_semester;
}


map<long, string> Registration::GetStudentMap() const
{
    return m_studentId;
}
unsigned Registration::GetCredits() const
{
    unsigned sum = 0;
    for(unsigned i = 0; i < m_count; i++)
        sum += GetResults(i).GetUnit().GetCredits();

    return sum;
}

unsigned Registration::GetCount() const
{
    return m_count;
}


// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.

istream & operator >>( istream & input, Registration & R )
{

    long studentId = 0;
    unsigned semester = 0;
    unsigned count = 0;
    string studentName = "";


    input >> studentId >> studentName >> semester >> count;
    R.SetStudentId(studentId, studentName);
    R.SetSemester(semester);
    R.SetCount(count);

    Result result[count];

    for(unsigned i = 0; i < count; i++)
    {
        input >> result[i];
        R.SetResult(result[i], i);
    }



    return input;
}


ostream & operator <<( ostream & os, const Registration & R )
{
    map <long, string> studentId = R.GetStudentMap();
    for (auto itr = studentId.begin(); itr != studentId.end(); ++itr) {
        Result result;
    os << "Student ID: " << itr->first << '\n'
       << "Student Name: " << itr->second << '\n'
       << "Semester:   " << R.GetSemester() << '\n';

    for(unsigned i = 0; i < R.GetCount(); i++)
        os << R.GetResults(i) << '\n';
    }


    return os;
}
