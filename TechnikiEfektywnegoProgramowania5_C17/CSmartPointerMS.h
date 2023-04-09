//
// Created by wieslaw on 10.12.22.
//

#ifndef TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CSMARTPOINTERMS_H
#define TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CSMARTPOINTERMS_H


#include <utility>
#include "CRefCounter.h"
#include <iostream>

#define DEBUG true

template<typename T>
class CMySmartPointerMS
{
public:
    CMySmartPointerMS(T *pcPointer);
    CMySmartPointerMS(const CMySmartPointerMS &pc_smart_pointer);
    ~CMySmartPointerMS();
    T& operator*();
    T* operator->();
    CMySmartPointerMS operator=(const CMySmartPointerMS<T> &pc_other);
    //void operator=(const CMySmartPointerMS<T> &pc_other)
    void copySmartPointer(const CMySmartPointerMS<T> &pc_other);
    bool deleteSmartPointer();
private:
    CRefCounter *pc_counter;
    T* pc_pointer;
};

template<typename T>
CMySmartPointerMS<T>::CMySmartPointerMS(T *pc_pointer){
    this->pc_pointer=pc_pointer;
    pc_counter = new CRefCounter();
    pc_counter->iAdd();
}
template<typename T>
CMySmartPointerMS<T>::CMySmartPointerMS(const CMySmartPointerMS<T> &pc_smart_pointer){
    copySmartPointer(pc_smart_pointer);
    if(DEBUG) std::cout<<"Copy"<<std::endl;

}
template<typename T>
CMySmartPointerMS<T>::~CMySmartPointerMS() {
    deleteSmartPointer();
    if(DEBUG) std::cout<<"Dest"<<std::endl;

}
template<typename T>
T& CMySmartPointerMS<T>::operator*() {
    return *pc_pointer;
}
template<typename T>
T* CMySmartPointerMS<T>::operator->() {
    return pc_pointer;
}

template<typename T>
void CMySmartPointerMS<T>::copySmartPointer(const CMySmartPointerMS<T> &pc_other){
    this->pc_pointer=pc_other.pc_pointer;
    this->pc_counter=pc_other.pc_counter;

    this->pc_counter->iAdd();
}
template<typename T>
bool CMySmartPointerMS<T>::deleteSmartPointer(){

    if(pc_counter->iDec()==0){
        delete pc_pointer;
        delete pc_counter;
        return true;
    }
    return false;
}
template<typename T>
CMySmartPointerMS<T> CMySmartPointerMS<T>::operator=(const CMySmartPointerMS<T>&pc_other){

    deleteSmartPointer();
    copySmartPointer(pc_other);
    if(DEBUG) std::cout<<"op ="<<std::endl;


    return std::move(*this);

}
/*
 * operator = with void as a return type
template<typename T>
void CMySmartPointerMS<T>::operator=(const CMySmartPointerMS<T>&pc_other){

    deleteSmartPointer();
    copySmartPointer(pc_other);

}
*/
#endif //TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CSMARTPOINTERMS_H
