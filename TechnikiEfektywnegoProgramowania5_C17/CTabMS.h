//
// Created by wieslaw on 10.12.22.
//

#ifndef TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CTABMS_H
#define TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CTABMS_H


#define DEF_TAB_SIZE 4
#define DEBUG true
#include <iostream>

class CTabMS {
public:
    CTabMS();
    CTabMS(int initial_size);
    CTabMS(const CTabMS &c_other);
    CTabMS(CTabMS &&c_other);
    CTabMS& operator=(const CTabMS& c_other);
    CTabMS& operator=(CTabMS&& c_other) noexcept ;
    CTabMS operator+(const CTabMS& c_other);
    bool setValueAt(int index, int value);
    ~CTabMS();
    //bool bSetSize(int iNewSize);
    int iGetSize();
private:
    void vCopy(const CTabMS &cOther);
    int *pi_tab;
    int i_size;
};


#endif //TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CTABMS_H
