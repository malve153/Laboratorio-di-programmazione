#ifndef ISBN
#define ISBN
#include <iostream>

/**
 * @brief Classe Isbn usata per la gestione dell'Isbn di un libro
*/

class Isbn
{
    private:

        int n1;/**!< Prima terna di numeri dell'isbn*/
        int n2;/**!< Seconda terna di numeri dell'isbn*/
        int n3;/**!< Terza terna di numeri dell'isbn*/
        char x;/**!< Ultimo carattere dell'isbn*/
        /**
         * @brief Determina se il codice Isbn è valido partendo da 3 int e un char
         * 
         * @return true Se il codice è valido
         * @return false Se il codice non è valido
         */
        bool isValid();
        /**
         * @brief Determina se il codice Isbn è valido partendo da una stringa
         * 
         * @return true Se il codice è valido
         * @return false Se il codice non è valido
         */
        bool isValidString(const char* isbn);
        
    public:
        /**
         * @brief Utilizzata come eccezione per Isbn non valido
         * 
         */
        class InvalidIsbn{};
        /**
         * @brief Costruttore Isbn. 
         * 
         * Crea un nuovo oggetto Isbn da 3 int e un char
         * @param v1 Prima terna di numeri dell'isbn
         * @param v2 Seconda terna di numeri dell'isbn
         * @param v3 Terza terna di numeri dell'isbn
         * @param val Ultimo carattere dell'isbn
         */
        Isbn(int v1,int v2,int v3,char val);
        /**
         * @brief Costruttore Isbn. 
         * 
         * Crea un nuovo oggetto Isbn da una stringa
         * @param isbn Stringa di lunghezza uguale a quella di isbn
         */
        Isbn(const char* isbn);
        /**
         * @brief Overloading operatore di equivalenza
         * 
         * @param code Codice Isbn di un altro libro
         * @return true Se i 2 codici sono uguali
         * @return false Se i 2 codici sono diversi
         */
        bool operator==(const Isbn &code);
         /**
         * @brief Overloading operatore diverso
         * 
         * @param code Codice Isbn di un altro libro
         * @return true Se i 2 codici sono diversi
         * @return false Se i 2 codici sono uguali
         */
        bool operator!=(const Isbn &code);
        /**
         * @brief Overloading operatore di stampa
         * 
         * @param os 
         * @param isbn 
         * @return std::ostream& 
         */
        friend std::ostream& operator<<(std::ostream& os,const Isbn &isbn);

};

#endif