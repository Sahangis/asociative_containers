#include "funkcijos.h"

int main()
{
    map<string, Token> zodziai;
    set<string> url;
    skaitymas(zodziai, url);
    rasymas(zodziai, url);
}