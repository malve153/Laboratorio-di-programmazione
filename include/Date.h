#ifndef DATE
#define DATE
#include <iostream>

/**
 * @brief Classe Date usata per la manipolazione delle date
 * @author Anello Gioia,Claudio Battistin, Andrea Malvestio
*/

class Date
{
public:
    /**
     * @brief Utilizzata come eccezione per data non valida
     * 
     */
    class InvalidDate{};
    /**
     * @brief Enum contentent tutti i mesi dell'anno 
     * 
     */
    enum Month{ 
        jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
    };
    /**
     * @brief Costruttore oggetto Date
     * 
     * @param yy anno
     * @param mm mese
     * @param dd giorno
     */
    Date(int yy, Month mm, int dd);
    /**
     * @brief Overloading operatore di stampa
     * 
     * @param os 
     * @param data 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os,const Date &data);
    
private:

    int day;/**!<Giorno inserito */
    Month month;/**!<Mese inserito */
    int year;/**!< Anno inserito*/
    /**
     * @brief Determina se la data inserita è valida
     * 
     * @return true Se la data è valida
     * @return false Se la data non è valida
     */
    bool isValid();

};

#endif