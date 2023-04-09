//
// Created by wieslaw on 10.12.22.
//

#ifndef TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CTAB_H
#define TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CTAB_H


#define DEF_TAB_SIZE 4
#define DEBUG true
#include <iostream>

class CTab {
public:
    CTab();
    CTab(const CTab &cOther);
    CTab(CTab &&cOther);
    void operator=(const CTab& c_other);
    void operator=(CTab&& c_other);
    ~CTab();
    //bool bSetSize(int iNewSize);
    int iGetSize();
private:
    void v_copy(const CTab &cOther);
    int *pi_tab;
    int i_size;
};


#endif //TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CTAB_H
