#include "Error.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <cstring>

/*
 * Implementation der Klasse Error
 */

/* Allgemeiner Konstruktor */
Error::Error() 
{
    msg = "";
}

/* Konstruktor mit String als Argument */
Error::Error(std::string m)
{
    msg = m;
}

void Error::setType(std::string t) {
    type = t;
}

/* Standardfunktion: gibt Fehlermeldung weiter */
const char * Error::what() const noexcept
{
    const string s = (msg == "") ? type : type + ": " + msg;
    char * cstr = new char [s.length()+1];
    std::strcpy (cstr, s.c_str());
    return cstr;
}
