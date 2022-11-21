#ifndef BOOK
#define BOOK
#include <iostream>
#include "Date.h"
#include "Isbn.h"
/**
 * @brief Classe Book usata per la manipolazione di un libro
*/
class Book
{
private:

    Isbn isbn;/**!< */
    std::string titolo;/**!< */
    std::string nome;/**!< */
    std::string cognome;/**!<*/
    Date dataCopyright;/**!< */
    bool stato;/**!< */

public:
    /**
     * @brief Construct a new Book object
     * 
     */
    Book()
        : titolo{""}, nome{""}, cognome{""}, stato{true}, dataCopyright{Date{1970,Date::Month::jan,1}}, isbn{"000-000-000-0"}
    {}
    /**
     * @brief Construct a new Book object
     * 
     * @param nom 
     * @param cog 
     * @param tit 
     * @param sta 
     * @param dataCop 
     * @param i 
     */
    Book(const std::string& nom,const std::string& cog, const std::string& tit, bool sta, Date dataCop,Isbn i)
        : titolo{tit}, nome{nom}, cognome{cog}, stato{sta}, dataCopyright{dataCop}, isbn{i}
        {}
    /**
     * @brief Construct a new Book object
     * 
     * @param nom 
     * @param cog 
     * @param tit 
     * @param is 
     * @param sta 
     * @param dataCop 
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