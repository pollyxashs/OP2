#include "primer.h"
LABfile::LABfile(std::string name_file) {
    LABfile::name=name_file;
}
void LABfile::open() {
    out.open(name);
    if(!out.is_open()){
        throw std::exception();
        cout<<"ERROR"<<"\n";
    }
}

void LABfile::close(){
    out.close();
    if(out.is_open()){
       throw std::exception();
    }
}
bool LABfile::check(){
    return out.is_open();
}

//
void LABfile::inSTRING(std::string str){
    out << str <<"\n";
}
void LABfile::inINT(int a){
    out << a << "\n";
}

void LABfile::inFLOAT(float b){
    out << b <<"\n";
}
