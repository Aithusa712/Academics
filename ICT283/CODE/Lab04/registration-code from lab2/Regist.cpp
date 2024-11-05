#include "Regist.h"


Registration::Registration()
{
    m_count = 0;
}

void Registration::SetCount(unsigned count)
{
    m_count = count;
}
void Registration::SetStudentId(long studentid)
{
    m_studentId = studentid;
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
long Registration::GetStudentId() const
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

istream & operator >>( istream & input, Registration & R )
{

    long studentId = 0;
    unsigned semester = 0;
    unsigned count = 0;


    input >> studentId >> semester >> count;

    R.SetStudentId(studentId);
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

    Result result;
    os << "Student ID: " << R.GetStudentId() << '\n'
       << "Semester:   " << R.GetSemester() << '\n';

    for(unsigned i = 0; i < R.GetCount(); i++)
        os << R.GetResults(i) << '\n';

    return os;
}
