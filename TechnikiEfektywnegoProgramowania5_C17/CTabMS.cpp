//
// Created by wieslaw on 10.12.22.
//

#include "CTabMS.h"
CTabMS::CTabMS(){
    pi_tab = new int[DEF_TAB_SIZE];
    i_size = DEF_TAB_SIZE;
    std::cout<<"Default Constructor"<<std::endl;
}
CTabMS::CTabMS(int initialSize){
    pi_tab = new int[initialSize];
    i_size = initialSize;

}
CTabMS::CTabMS(const CTabMS &cOther)
{
    vCopy(cOther);
    std::cout << "Copy "<<std::endl;
}//CTab::CTab(const CTab &cOther)
CTabMS::~CTabMS()
{
    if (pi_tab != NULL) delete pi_tab;
    std::cout << "Destr "<<std::endl;
}//CTab::~CTab()

///Operator= który zwraca wartość z użyciem MS , nieoptymalne
/*
CTabMS CTabMS::operator=(const CTabMS &cOther)
{
    if (pi_tab != NULL) delete pi_tab;
    v_copy(cOther);
    std::cout << "op= "<<std::endl;
    ///To powoduje wywołanie konstructora przenoszącego dla OBECNEGO OBIEKTU dlatego operator = jest lepszy jak zwraca void
    return(std::move(*this));
}//CTab CTab::operator=(const CTab &cOther)
*/

CTabMS& CTabMS::operator=(const CTabMS &cOther)
{
    if (pi_tab != NULL) delete pi_tab;
    vCopy(cOther);
    std::cout << "op= "<<std::endl;

    return *this;
}//CTab CTab::operator=(const CTab &cOther)

bool CTabMS::setValueAt(int index, int value){
    if(index<0 || index>=i_size || pi_tab==NULL){
        return false;
    }else{
        pi_tab[index]=value;
        return true;
    }
}


CTabMS CTabMS::operator+(const CTabMS &c_other){
    int final_table_length = i_size + c_other.i_size;
    CTabMS result(final_table_length);

    for(int i=0;i<final_table_length;i++)
    {

        if(i<i_size)
        {
            result.setValueAt(i,pi_tab[i]);
        }
        else
        {
            result.setValueAt(i,c_other.pi_tab[i-i_size]);
        }

    }

    return std::move(result);
}
void CTabMS::vCopy(const CTabMS &c_other)
{
    pi_tab = new int[c_other.i_size];
    i_size = c_other.i_size;
    for (int ii = 0; ii < c_other.i_size; ii++)
        pi_tab[ii] = c_other.pi_tab[ii];
}//void CTab::v_copy(CTab &cOther)
CTabMS::CTabMS(CTabMS &&pc_other)
{
    pi_tab = pc_other.pi_tab;
    i_size = pc_other.i_size;
    pc_other.pi_tab = NULL;
    std::cout << "MOVE Constructor"<<std::endl;
}//CTab::CTab(CTab &&cOther)
int CTabMS::iGetSize() {
    return i_size;
}
CTabMS& CTabMS::operator=(CTabMS &&pc_other) noexcept{
    if (pi_tab != NULL) delete pi_tab;
    pi_tab = pc_other.pi_tab;
    i_size=pc_other.i_size;
    pc_other.pi_tab=NULL;
    std::cout << "op= MS"<<std::endl;
    return *this;
}




