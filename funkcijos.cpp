#include "funkcijos.h"

const char DF[] = "Tekstas.txt";

void skaitymas(map<string, Token>& zodziai, set<string>& url)
{
    int eile = 0;
    ifstream fd(DF);
    if (fd.fail()) cout << "hey nera failo!" << endl;
    while (!fd.eof())
    {
        eile++;
        string eilute, zodis = "";
        bool rastas_tinklalapis = false;
        getline(fd, eilute);
        if (eilute != "")
        {
            for (int i = 0; i <= eilute.length() - 1; i++)
            {
                if (zodis == "www" || zodis == "https") rastas_tinklalapis = true;
                if (rastas_tinklalapis)
                {
                    if (eilute[i] != ' ' && eilute[i] != '\n') zodis += eilute[i];
                    else
                    {
                        url.insert(zodis);
                        zodis = "";
                        rastas_tinklalapis = false;
                    }
                }
                else
                {
                    if (isalpha(eilute[i])) zodis += eilute[i];
                    else if (zodis.length() > 0)
                    {
                        if (!zodziai[zodis].counter())
                        {
                            zodziai[zodis] = Token(zodis, 1, { eile });
                        }
                        else zodziai[zodis].increment(eile);
                        zodis = "";
                    }
                }
            }
        }
    }
    fd.close();
}

void rasymas(const map<string, Token>& zodziai, const set<string>& url)
{
    cout << "cross reference:" << endl;
    cout << left << setw(20) << "zodziai" << left << setw(10) << "kartai" << "eilute kurioje egzistuoja zodis" << endl;
    for (auto& pair : zodziai)
    {
        if (pair.second.counter() > 1)
        {
            cout << left << setw(20) << pair.second.word() << left << setw(10) << pair.second.counter();
            for (auto& line : pair.second.lines())
            {
                cout << line << "  ";
            }
            cout << endl;
        }
    }
    cout << "found url's:" << endl;
    for (auto& linkai : url)
    {
        cout << linkai << endl;
    }
}