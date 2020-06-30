#include "mystring.h"
#include <string.h>

String::String()
    : m_string(nullptr)
{
}

String::String(const char *string)
    : m_string(nullptr)
{
    set(string);
}

String::String(const String &string)
    : String(string.m_string)
{
}

String::~String()
{
    delete [] m_string;
}

void String::set(const char *string)
{
    delete [] m_string;
    m_string = nullptr;

    if (string)
    {
        m_string = new char[strlen(string) + 1];
        strcpy(m_string, string);
    }
}

const char* String::get() const
{
    return m_string;
}

String& String::operator=(const String& string)
{
    if (m_string == string.m_string)
        return *this;

    set(string.get());
    return *this;
}

bool String::operator==(const String& string)
{
    return strcmp(m_string, string.get()) == 0 ? true : false;
}

bool String::operator!=(const String& string)
{
    return !(*this == string);
}

std::ostream& operator<<(std::ostream &os, const String &string)
{
    os << string.m_string;
    return os;
}

