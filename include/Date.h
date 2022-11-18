#ifndef DATE
#define DATE
#include <iostream>

class Date
{
public:
    class InvalidDate{};
    enum Month{ 
        jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
    };

    Date(int yy, Month mm, int dd);
    friend std::ostream& operator<<(std::ostream& os,const Date &data);
    
private:

    int day;
    Month month;
    int year;
    bool isValid();

};

#endif