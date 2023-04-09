#include <iostream>
#include "CMySmartPointer.h"
#include "CSmartPointerMS.h"
#include "CTab.h"
#include "CTabMS.h"
void TestPointerToTable(){
    CMySmartPointer test(new CTab[10]);


}

void CMySmartPointerTest(){
    CTab* i_tab = new CTab();
    CTab* i_tab_2 = new CTab();

    std::cout<<"Default constructor i_tab"<<std::endl;
    CMySmartPointer<CTab> smart_pointer(i_tab);
    std::cout<<"Copying constructor i_tab"<<std::endl;
    CMySmartPointer<CTab> smart_pointer_copy = smart_pointer;
    CMySmartPointer<CTab>* test2 = new CMySmartPointer<CTab>(i_tab);

    std::cout<<"Default constructor i_tab_2"<<std::endl;
    CMySmartPointer<CTab> smart_pointer_copy2(i_tab_2);
    std::cout<<"op = i_tab_2"<<std::endl;
    smart_pointer_copy2 = smart_pointer_copy;
    std::cout<<"After op = i_tab_2"<<std::endl;

};
CTab cCreateTab(){
    CTab c_result;
    //c_result.bSetSize(5);
    return(std::move(c_result));
};//CTab cCreateTab()
CTabMS cCreateTabMS(){
    std::cout<<"Creaing c_result in function"<<std::endl;
    CTabMS c_result;
    //c_result.bSetSize(5);
    return(std::move(c_result));
};//CTab cCreateTab()
CTabMS cCreateTabMS(CTabMS* copy){
    std::cout<<"Creaing c_result in function"<<std::endl;
    CTabMS c_result;
    //c_result.bSetSize(5);
    return(std::move(c_result));
};//CTab cCreateTab()

void CTabMSTest(){
    /*
    CTab i_tab;
    CTab i_tab_2 = cCreateTab();
     */
    std::cout<<"Creating i_tab_ms"<<std::endl;
    CTabMS i_tab_ms;
    std::cout<<"Creating i_tab_ms_2 with MOVE Constructor"<<std::endl;
    CTabMS i_tab_ms_2 = cCreateTabMS();

    CTabMS copied = std::move(i_tab_ms);
    std::cout<<"triple="<<std::endl;
    i_tab_ms = copied = i_tab_ms_2;
    std::cout<<"end of triple="<<std::endl;

    CTabMS added = cCreateTabMS() + cCreateTabMS();


    std::cout<<"Using = MS operator with cCreateFunction"<<std::endl;
    i_tab_ms = cCreateTabMS();
    std::cout<<"End of function"<<std::endl;

    /*
     * Aby wywołać konstruktor kopiujący przy wywołaniu metody (zamiast kopiowania wartości)
     * CTabMS result = function(std::move(other_object))
     *
     */

};



int main() {
    //CTabMSTest();
    TestPointerToTable();
    //CMySmartPointerTest();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
