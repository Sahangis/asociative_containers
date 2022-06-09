#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

/**
 * @brief Klase kuria naudojame saugoti unikalius zodzius, kiek kartu jie pasikartoja texte, bei kurioje eiluteje tas zodis pasirodo
 * 
 */
class Token
{
private:
    std::string _word = "";
    unsigned int _counter = 0;
    vector<int> _lines;

public:
    Token()
        : _word(), _counter(), _lines() { }

    Token(std::string word, unsigned int counter, const vector<int>& lines)
        : _word(word), _counter(counter), _lines(lines) { }

    ~Token() { }

    Token& increment(int line, int amount = 1)
    {
        this->_counter += amount;
        this->_lines.push_back(line);
        return *this;
    }

    const std::string& word() const { return this->_word; }

    unsigned int counter() const { return this->_counter; }

    const vector<int>& lines() const { return this->_lines; }
};

/**
 * @brief skaitymo funkcija naudojama nuskaityti is failo teksta
 * 
 * @param zodziai 
 * @param url 
 */
void skaitymas(map<string, Token>& zodziai, set<string>& url);

/**
 * @brief rasymo funkcija naudojama israsyti nuskaitytus duomenis
 * 
 * @param zodziai 
 * @param url 
 */
void rasymas(const map<string, Token>& zodziai, const set<string>& url);
