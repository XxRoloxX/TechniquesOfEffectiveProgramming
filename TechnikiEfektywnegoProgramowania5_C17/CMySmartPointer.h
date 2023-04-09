//
// Created by wieslaw on 10.12.22.
//

#ifndef TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CMYSMARTPOINTER_H
#define TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CMYSMARTPOINTER_H

#include "CRefCounter.h"
#include <iostream>

#define DEBUG true

template<typename T>
class CMySmartPointer
{
public:
    CMySmartPointer(T *pcPointer);
    CMySmartPointer(const CMySmartPointer &pc_smart_pointer);
    ~CMySmartPointer();
    T& operator*();
    T* operator->();
    void operator=(const CMySmartPointer<T> &pc_other);
    void copySmartPointer(const CMySmartPointer<T> &pc_other);
    bool deleteSmartPointer();
private:
    CRefCounter *pc_counter;
    T *pc_pointer;
};

template<typename T>
CMySmartPointer<T>::CMySmartPointer(T *pc_pointer){
    this->pc_pointer=pc_pointer;
    pc_counter = new CRefCounter();
    pc_counter->iAdd();
}
template<typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer<T> &pc_smart_pointer){
    copySmartPointer(pc_smart_pointer);
    if(DEBUG) std::cout<<"Copy SmartPointer"<<std::endl;
}
/*
template<typename T>

CMySmartPointer<T>::CMySmartPointer(const T table_pointer[]){
    //copySmartPointer(*pc_smart_pointer);
    this->pc_pointer=table_pointer;
    pc_counter = new CRefCounter();
    this->pc_counter->iAdd();

    if(DEBUG) std::cout<<"Copy SmartPointer Table"<<std::endl;
}
 */
template<typename T>
CMySmartPointer<T>::~CMySmartPointer() {
    deleteSmartPointer();
    if(DEBUG) std::cout<<"Dest SmartPointer"<<std::endl;

}
template<typename T>
T& CMySmartPointer<T>::operator*() {
    return *pc_pointer;
}
template<typename T>
T* CMySmartPointer<T>::operator->() {
    return pc_pointer;
}

template<typename T>
void CMySmartPointer<T>::copySmartPointer(const CMySmartPointer<T> &pc_other){
    this->pc_pointer=pc_other.pc_pointer;
    this->pc_counter=pc_other.pc_counter;

    this->pc_counter->iAdd();
}
template<typename T>
bool CMySmartPointer<T>::deleteSmartPointer(){

    if(pc_counter->iDec()==0){
        delete [] pc_pointer;
        delete pc_counter;
        return true;
    }
    return false;
}
template<typename T>
void CMySmartPointer<T>::operator=(const CMySmartPointer<T>&pc_other){

    deleteSmartPointer();
    copySmartPointer(pc_other);
    if(DEBUG) std::cout<<"op= SmartPointer"<<std::endl;


}



#endif //TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CMYSMARTPOINTER_H
