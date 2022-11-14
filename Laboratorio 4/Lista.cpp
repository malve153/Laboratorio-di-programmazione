#include <iostream>
#include <string.h>
using namespace std;


class Link {
   
    public:
        Link(const string& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, succ{s} {}

        Link* insert(Link* p);//inserisce l'elemento prima di un altro nodo
        Link* add(Link* p);//inserimento dopo un elemento
        Link* erase();//rimozione elemento
        Link* find(const string& v);//trova un elemento con un certo valore
        void print_all();//stampa tutti i valori 
        void push_back(Link*p);//aggiunge elemento in coda
        Link* push_front(Link*p);//aggiunge elemento in testa
        void pop_back();//rimuove l'elemento in coda
        Link* pop_front();//rimuove l'elemento in testa
    private:
        string value;
        Link* prev;
        Link* succ;
};

Link* Link::insert(Link* p){
    Link* t=this;

    if(!p){
        return t;
    }

    p->succ=t;

    if (t->prev)
    {
        cout<<"cè succ";
        t->prev->succ=p;
        cout<<"t prev "<<t->prev->succ<<" e p "<<p;
        p->prev=t->prev;
    }

     t->prev=p;

    return p;
    
}
Link* Link::add(Link* p){
    Link* t=this;

    if(!p){
        return t;
    }

    
    if (t->succ)
    {
        t->succ->prev=p;
        p->succ=t->succ;
    }
    p->prev=t;
    t->succ=p;

    return t;
}

Link* Link::erase(){
    
    if(!this) return nullptr;

    if(this->prev){
        this->prev->succ=this->succ;
    }
    else if(this->succ){
        this->succ->prev=this->prev;
    }
    return this->succ;
}

void Link::print_all(){

    Link*t=this;

    while(t)
    {
        cout<<"valore: "<<t->value<<"\n";
        t=t->succ;
    }
    
    
}

Link* Link::find(const string& v){
    Link*t=this;

    while(t)
    {
        if(v.compare(t->value)==0) {
            return this;
        }
        t=t->succ;
    }
    return nullptr;
    
}

void Link::push_back(Link*p){

    if(!this)return;

    Link*t=this;

    while(t->succ)
    {
        t=t->succ;
    }
    t->succ=p;
    p->prev=t;
}

Link* Link::push_front(Link*p){
    if(!this)return p;;

    Link*t=this;

    p->succ=t;
    t->prev=p;
}

void Link::pop_back(){
    if(!this)return ;

    Link*t=this;

    while(t->succ)
    {
        t=t->succ;
    }
    t=t->prev;
    t->succ=nullptr;
}

Link* Link::pop_front(){
    if(!this)return nullptr;

    Link* t=this;

    while(t->prev)
    {
        t=t->prev;
    }
    t=t->succ;
    t->prev=nullptr;
    return t;
}

int main(void){
    Link* lista=new Link{"Valore 1"};
    lista=lista->insert(new Link("Valore 2"));
    lista=lista->insert(new Link("Valore 3"));
    lista->print_all();
    lista->add(new Link("Valore 4"));
    cout<<"aggiungo valore 4\n";
    lista->print_all();
     lista->add(new Link("Valore 5"));
    cout<<"aggiungo valore 5\n";
    lista->print_all();
    cout<<"elimino valore in p1\n";
    lista=lista->erase();
    lista->print_all();
    cout<<"elimino valore in p1\n";
    lista=lista->erase();
    lista->print_all();

    cout<<"cerco valore 4\n";
    Link*t=lista->find("Valore 4");

    if(t){
        cout<<"trovato\n";
    }
    else{
        cout<<"non trovato\n";
    }

    cout<<"elimino valore 4\n";
    lista=t->erase();
    lista->print_all();

    cout<<"cerco Valore 7\n";
    t=lista->find("valore 7");

    if(t){
        cout<<"trovato\n";
    }
    else{
        cout<<"non trovato\n";
    }

    cout<<"aggiungo in coda Valore 15\n";
    lista->push_back(new Link("Valore 15"));
    lista->print_all();

    cout<<"aggiungo in testa Valore 19\n";
    lista->push_back(new Link("Valore 19"));
    lista->print_all();

    cout<<"rimuovo in coda\n";
    lista->pop_back();
    lista->print_all();

    cout<<"rimuovo in testa\n";
    lista=lista->pop_front();
    lista->print_all();

    return 0;
}