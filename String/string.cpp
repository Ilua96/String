#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>

#include "stringlib.h"

int kmp(const String& source, const String& pattern)
{
    int k = 0;
	std::vector < int > prefix;
	prefix.resize(source.getLength());
    for (int i = 0; i < source.getLength(); i++)
        prefix[i] = 0;
    for (int i = 1; i < source.getLength(); i++)
    {
        k = prefix[i-1];
        while ((k > 0) && (source.getChar(k) != source.getChar(i)))
            k = prefix[k-1];
        if (source.getChar(k) == source.getChar(i))
            k++;
        prefix[i] = k;
    }
    int index = -1;
    k = 0;
    for (int i = 0; i < source.getLength(); i++)
    {
        while ((k > 0) && (pattern.getChar(k) != source.getChar(i)))
            k = prefix[k-1];
        if (pattern.getChar(k) == source.getChar(i))
            k++;
        if (k == pattern.getLength())
        {
            index = i - pattern.getLength() + 1;
            break;
        }
    }
    return index;
}
String::String(){
    length = 0;
    value = new char[1];
    value = '\0';
}

String::String(const char Data){
    length = 1;
    value = new char[1];
	value = _strdup(&Data);
}

String::String(const char* Data){
	length = strlen(Data);
    value = new char[length];
	value = _strdup(Data);
}

String::String(const String& Data){
	length = strlen(Data.getString());
    value = new char[length];
	value = _strdup(Data.getString());
}

char* String::getString() const{
    return value;
}

int String::getLength() const{
    return length;
}

char String::getChar(int index) const{
    return this->getString()[index];
}

std::ostream& operator<<(std::ostream& out, const String& Data){
    out << Data.getString();
    return out;
}

const String String::operator+(const String& other){
    char* result = new char[this->getLength() + other.getLength()];
    result = _strdup(this->getString());
    strncat(result, other.getString(), other.getLength());
    return String(result);
}

const String String::operator+(const char* other){
    char* result = new char[this->getLength() + strlen(other)];
    result = _strdup(this->getString());
    strncat(result, other, strlen(other));
    return String(result);
}

bool String::operator==(const String& other){
    return (strcmp(this->getString(), other.getString()) == 0);
}

bool String::operator==(const char* other){
    return (strcmp(this->getString(), other) == 0);
}

bool String::operator!=(const String& other){
    return !(*this == other);
}

bool String::operator!=(const char* other){
    return !(*this == other);
}

int String::find(const String& pattern){
    return kmp(*this, pattern);
}

int String::find(const char* pattern){
    return kmp(*this, String(pattern));
}

String& String::insert(int Pos, const String& other)
{
    this->length += other.getLength();
    for (int i = length; i >= Pos + other.getLength(); i--){
        value[i] = value[i - other.getLength()];
    }
    for (int i = Pos, j = 0; i < Pos + other.getLength(); i++, j++){
        value[i] = other.getString()[j];
    }
    return *this;
}

String& String::insert(int Pos, const char* other){
    return insert(Pos, String(other));
}

String String::substr(int l, int r){
    if(l < 0 || l > r || r > this->getLength()){
        return String("");
    }
    String t("");
	for (unsigned int i = l - 1; i < r; i++)
		t = t + getString()[i];
    String res(t);
    return res;
}