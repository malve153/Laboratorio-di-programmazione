#ifndef BOOK
#define BOOK
#include <iostream>
#include "Date.h"
#include "Isbn.h"
/**
 * @brief Classe Book usata per la manipolazione di un libro
 * @author Anello Gioia,Claudio Battistin, Andrea Malvestio
*/
class Book
{
private:

    Isbn isbn;/**!< Codice identificativo del libro*/
    std::string titolo;/**!< Titolo del libro*/
    std::string nome;/**!< Nome autore*/
    std::string cognome;/**!< Cognome autore*/
    Date dataCopyright;/**!< Data copyright*/
    bool stato;/**!< True se disponibile e false se in prestito*/

public:
    /**
     * @brief Costruttore di default
     * 
     */
    Book()
        : titolo{""}, nome{""}, cognome{""}, stato{true}, dataCopyright{Date{1970,Date::Month::jan,1}}, isbn{"000-000-000-0"}
    {}
    /**
     * @brief Costruttore con parametri e Isbn passato come oggetto
     * 
     * @param nom nome autore
     * @param cog cognome autore
     * @param tit titolo libro
     * @param sta stato del libro
     * @param dataCop data copyright
     * @param i codice identificativo libro isbn
     */
    Book(const std::string& nom,const std::string& cog, const std::string& tit, bool sta, Date dataCop,Isbn i)
        : titolo{tit}, nome{nom}, cognome{cog}, stato{sta}, dataCopyright{dataCop}, isbn{i}
        {}
    /**
     * @brief Costruttore con parametri e Isbn passato come puntatore char
     * 
     * @param nom nome autore
     * @param cog cognome autore
     * @param tit titolo libro
     * @param sta stato del libro
     * @param dataCop data copyright
     * @param is codice identificativo libro isbn
     */
    Book(const std::string& nom,const std::string& cog, const std::string& tit,const char* is = "000-000-000-0", bool sta = true, Date dataCop = Date{1970,Date::Month::jan,1})
        : titolo{tit}, nome{nom}, cognome{cog}, stato{sta}, dataCopyright{dataCop}, isbn{Isbn{is}}
        {}
    /**
     * @brief Get the Titolo object
     * 
     * @return std::string 
     */
    std::string getTitolo(){ return this->titolo; }
    /**
     * @brief Get the Nome object
     * 
     * @return std::string 
     */
    std::string getNome() { return this->nome; }
    /**
     * @brief Get the Cognome object
     * 
     * @return std::string 
     */
    std::string getCognome(){ return this->cognome; }
    /**
     * @brief Get the Stato object
     * 
     * @return true 
     * @return false 
     */
    bool getStato() { return this->stato; }
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool prestito();
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool restituzione();
    /**
     * @brief 
     * 
     * @param libro 
     * @return true 
     * @return false 
     */
    bool operator==(const Book &libro);
    /**
     * @brief 
     * 
     * @param libro 
     * @return true 
     * @return false 
     */
    bool operator!=(const Book &libro);
    /**
     * @brief 
     * 
     * @param os 
     * @param libro 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os,const Book &libro);
};
#endif