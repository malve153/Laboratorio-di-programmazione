/*
@Clauze @gioia @malve
*/
#include <iostream>
#include "Book.h"

bool Book::prestito(){
    if(!this->stato) return false;
    else{
        this->stato = false;
        return true;
    }
}

bool Book::restituzione(){
    if(this->stato) return false;
    else{
        this->stato = true;
        return true;
    }
}

bool Book::operator==(const Book &libro){
    if(isbn == libro.isbn) return true;
    else return false;
}

bool Book::operator!=(const Book &libro){
    if(this->isbn != libro.isbn) return true;
    else return false;
}

std::ostream& operator<<(std::ostream& os,const Book &libro){

    os << "\n\nTitolo: " << libro.titolo << "\nAutore: " << libro.nome << " " << libro.cognome;

    if(libro.stato) os << "\nStato: disponibile"; 
    else os << "\nStato: in prestito";

    os << "\nData copyright: " << libro.dataCopyright << "\nISBN: " << libro.isbn; 

    return os;
}

