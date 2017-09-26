#pragma once
//#include <string.h>

class String{
public:
    String();
    String(const char Data);
    String(const char* Data);
    String(const String& Data);

    char* getString() const;
    int getLength() const;
    char  getChar(int index) const;

    friend std::ostream& operator<<(std::ostream&, const String&);
    const String operator+(const String& other);
    const String operator+(const char* other);
    bool operator==(const String& other);
    bool operator==(const char* other);
    bool operator!=(const String& other);
    bool operator!=(const char* other);

    int find(const String& pattern);
    int find(const char* pattern);

    String& insert(int Pos, const String& other);
    String& insert(int Pos, const char* other);

    String substr(int l, int r);

private:
    char* value;
    int length;
//    int BUFFER = 64;
};

int kmp(const String& source, const String& pattern);