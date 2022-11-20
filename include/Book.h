#ifndef BOOK
#define BOOK
#include <iostream>
#include "Date.h"
#include "Isbn.h"

class Book
{
private:
    Isbn isbn;
    std::string titolo;
    std::string nome;
    std::string cognome;
    Date dataCopyright;
    bool stato;

public:

    Book()
        : titolo{""}, nome{""}, cognome{""}, stato{true}, dataCopyright{Date{1970,Date::Month::jan,1}}, isbn{"000-000-000-0"}
    {}
    Book(const std::string& nom,const std::string& cog, const std::string& tit, bool sta, Date dataCop,Isbn i)
        : titolo{tit}, nome{nom}, cognome{cog}, stato{sta}, dataCopyright{dataCop}, isbn{i}
        {}
    Book(const std::string& nom,const std::string& cog, const std::string& tit,const char* is = "000-000-000-0", bool sta = true, Date dataCop = Date{1970,Date::Month::jan,1})
        : titolo{tit}, nome{nom}, cognome{cog}, stato{sta}, dataCopyright{dataCop}, isbn{Isbn{is}}
        {}
    std::string getTitolo();
    std::string getNome();
    std::string getCognome();
    bool getStato();
    bool prestito();
    bool restituzione();
    bool operator==(const Book &libro);
    bool operator!=(const Book &libro);
    friend std::ostream& operator<<(std::ostream& os,const Book &libro);
};
#endif