#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <iostream>
#include <exception>

using namespace std;

class Error : public std::exception 
{
    public:
    Error();
    Error(string m);
    const char * what() const noexcept;
    
    protected:
    std::string msg;
    std::string type = "SudokuException";
    void setType(string t);
};

class FileNotOpenException : public Error { 
    public: FileNotOpenException (string msg) : Error(msg) {
        setType("FileNotOpenException");
    }
};

class InvalidFile : public Error { 
    public: InvalidFile (string msg) : Error(msg) {
        setType("InvalidFileException");
    }
};

#endif
