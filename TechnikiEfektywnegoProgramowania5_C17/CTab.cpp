//
// Created by wieslaw on 10.12.22.
//

#include "CTab.h"
CTab::CTab(){
     pi_tab = new int[DEF_TAB_SIZE];
     i_size = DEF_TAB_SIZE;
}
CTab::CTab(const CTab &cOther)
{
    v_copy(cOther);
    if(DEBUG) std::cout << "Copy CTab ";
}//CTab::CTab(const CTab &cOther)
CTab::~CTab()
{
    if (pi_tab != NULL) delete pi_tab;
    if(DEBUG) std::cout << "Destr CTab ";
}//CTab::~CTab()
void CTab::operator=(const CTab &cOther)
{
    if (pi_tab != NULL) delete pi_tab;
    v_copy(cOther);
    if(DEBUG) std::cout << "op= CTab ";
}//CTab CTab::operator=(const CTab &cOther)
void CTab::v_copy(const CTab &cOther)
{
    pi_tab = new int[cOther.i_size];
    i_size = cOther.i_size;
    for (int ii = 0; ii < cOther.i_size; ii++)
        pi_tab[ii] = cOther.pi_tab[ii];
}//void CTab::v_copy(CTab &cOther)
int CTab::iGetSize() {
    return i_size;
}
CTab::CTab(CTab &&pc_other)
{
    pi_tab = pc_other.pi_tab;
    i_size = pc_other.i_size;
    pc_other.pi_tab = NULL;
    if(DEBUG) std::cout << "MOVE CTab ";
}//CTab::CTab(CTab &&cOther)
void CTab::operator=(CTab &&pc_other){
    if (pi_tab != NULL) delete pi_tab;
    pi_tab = pc_other.pi_tab;
    i_size=pc_other.i_size;
    pc_other.pi_tab=NULL;
    if(DEBUG) std::cout << "op= MS CTab";

}