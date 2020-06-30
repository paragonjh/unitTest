#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class String
{
public:
    String();
    String(const char *string);
    String(const String &string);
    ~String();

    const char* get() const;

    String& operator=(const String& string);
    bool operator==(const String &string);
    bool operator!=(const String &string);

    friend std::ostream& operator<<(std::ostream &os, const String &string);

private:
    void set(const char *string);

private:
    char *m_string;
};

#endif

