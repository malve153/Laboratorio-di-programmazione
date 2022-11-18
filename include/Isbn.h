//Classe isbn
#ifndef ISBN
#define ISBN
#include <iostream>
class Isbn
{
    private:
        int n1;
        int n2;
        int n3;
        char x;
        bool isValid();
        bool isValidString(const char* isbn);
        
    public:
        class InvalidIsbn{};
        Isbn(int v1,int v2,int v3,char val);
        Isbn(const char* isbn);
        bool operator==(const Isbn &code);
        bool operator!=(const Isbn &code);
        friend std::ostream& operator<<(std::ostream& os,const Isbn &isbn);

};

#endif