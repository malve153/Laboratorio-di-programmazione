#include "Date.h"

Date::Date(int yy, Month mm, int dd)
    :year{yy},month{mm},day{dd}
{
    if(!isValid()) throw InvalidDate();
}

bool Date::isValid(){
    if(month<1 || month>12) return false;
    else if(month==2){
        if( year % 4==0 || (year % 100==0 && year % 400==0)) {
            if(day<1 || day >29) return false;
        }
        else {
            if(day<1 || day>28) return false;
        }
    }
    else if(month<=7){
        if(month%2!=0){
            if(day<1 || day>31) return false;
        }
        else{
            if(day<1 || day>30) return false;
        }
    }
    else{
        if(month%2==0){
            if(day<1 || day>31) return false;
        }
        else{
            if(day<1 || day>30) return false;
        }
    }

    return true;
    

}

std::ostream& operator<<(std::ostream& os,const Date &data) {

    return os << data.day << "/" << data.month << "/" << data.year;
}