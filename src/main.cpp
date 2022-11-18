#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    
    cout<<"creo";
    Isbn i{9,99,999,'Z'};
    Isbn i2{4,229,423,'F'};
    cout<<"\n"<<i;
    
    try{
        Book b{"marco","rossi","c++",true,Date{2000,Date::Month::apr,5}, Isbn{9,99,150,'Z'}};
        cout<<"\nlibro"<<b;
        if(b.prestito()){
            cout<<"\nLibro correttamente preso in prestito\n";
        }
        else cout << "\nLibro non disponibile";

        if(b.restituzione()){
            cout<<"\nLibro correttamente restituito dal prestito";
        }
        else cout << "\nIl libro non era in prestito";
    }
    catch(Date::InvalidDate){
        cerr<<"inserita data non valida";
    }
    catch(Isbn::InvalidIsbn){
        cerr<<"inserito isbn non valido";
    }

    try{
        Book b{"marco","rossi","g++",false,Date{2000,Date::Month::apr,5}, Isbn{9,99,150,'Z'}};
        cout<<"\nlibro"<<b;
        if(b.prestito()){
            cout<<"\nLibro correttamente preso in prestito\n";
        }
        else cout << "\nLibro non disponibile";

        if(b.restituzione()){
            cout<<"\nLibro correttamente restituito dal prestito";
        }
        else cout << "\nIl libro non era in prestito";
    }
    catch(Date::InvalidDate){
        cerr<<"inserita data non valida";
    }
    catch(Isbn::InvalidIsbn){
        cerr<<"inserito isbn non valido";
    }

    


    Book b{"marco","rossi","c++",false,Date{2000,Date::Month::apr,22},i};
    Book b2{"carlo","mariconda","esploratore",true,Date{2000,Date::Month::apr,22},i2};
    if(b==b2) cout << "== libri uguali\n";
    else cout << "== libri diversi\n";
    if(b!=b2) cout << "!= libri diversi\n";
    else cout << "!=libri uguali\n";
    cout<<"\nlibro"<<b;
    cout << "\nlibro"<<b2;
    if(b.restituzione()) cout << "\n\nlibro restituito correttamente\n";
    else cout << "\n\nRestituzione fallita, libro gia' disponibile\n";
    if(b2.prestito()) cout << "libro prestato correttamente\n";
    else cout << "impossibile effettuare il prestito, libro non disponibile\n";
    cout<<"\nlibro"<<b;
    cout << "\nlibro"<<b2;

    vector<Book> shelf(10);
    try{
        Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "999-999-150-Z");
        cout << "\n" << my_favourite_book;
    }
    catch(Isbn::InvalidIsbn){
        cerr<<"\ninserito isbn non valido\n";
    }
    
    return 0;
}