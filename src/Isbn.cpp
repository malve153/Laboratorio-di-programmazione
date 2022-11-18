#include "Isbn.h"

Isbn::Isbn(int v1,int v2,int v3,char val)
    : n1{v1},n2{v2},n3{v3},x{val}
{
    if(!isValid()) throw InvalidIsbn();
}

Isbn::Isbn(const char* isbn)
{
    if(!isValidString(isbn)) throw InvalidIsbn();
}

bool Isbn::isValid(){

    if((n1<0 || n1>999) || (n2<0 || n2>999) || (n3<0 || n3>999))return false;
    
    if(x<48 || (x>57 && x<65) || (x>90 && x<97) || x>122)  return false;

    return true;
}

bool Isbn::isValidString(const char* isbn){
    int size=0;
    std::string s="";
    
    while(isbn[size]!='\0') {
        size++;
    }
    
    if(size!=13) return false;
    else {
    	try {
    		n1 = (isbn[0]-'0')*100 + (isbn[1]-'0')*10 + (isbn[2]-'0');
    		n2 = (isbn[4]-'0')*100 + (isbn[5]-'0')*10 + (isbn[6]-'0');
    		n3 = (isbn[8]-'0')*100 + (isbn[9]-'0')*10 + (isbn[10]-'0');
		}
		catch(std::invalid_argument) {
			std::cout << "isbn non valido";
			return false;
		}
		
		x = isbn[12];
		
		if(x<48 || (x>57 && x<65) || (x>90 && x<97) || x>122)  return false;
		
		return true;
	}
}

bool Isbn::operator==(const Isbn &code){
    if((this->n1 == code.n1) && (this->n2 == code.n2) && (this->n3 == code.n3) && (this->x == code.x))
        return true;
    else return false;
}

bool Isbn::operator!=(const Isbn &code){
    if((this->n1 != code.n1) || (this->n2 != code.n2) || (this->n3 != code.n3) || (this->x != code.x))
        return true;
    else return false;
}

std::ostream& operator<<(std::ostream& os,const Isbn &isbn){

    if(isbn.n1>=0 && isbn.n1<=9) os<< "00" << isbn.n1;
    else if(isbn.n1>=10 && isbn.n1<=99) os << "0" << isbn.n1;
    else os << isbn.n1;

    if(isbn.n2>=0 && isbn.n2<=9) os << "-00" << isbn.n2;
    else if(isbn.n2>=10 && isbn.n2<=99) os << "-0" << isbn.n2;
    else os << "-" << isbn.n2;

    if(isbn.n3>=0 && isbn.n3<=9) os << "-00" << isbn.n3;
    else if(isbn.n3>=10 && isbn.n3<=99) os << "-0" << isbn.n3;
    else os << "-" << isbn.n3;

    return os<< "-" << isbn.x << "\n";

}