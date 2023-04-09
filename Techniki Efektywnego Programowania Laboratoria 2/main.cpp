#include <iostream>
#include "C_table.h"
#include "table_utilities.h"
void excerise1_test()
{
    C_table c_tab_0, c_tab_1;
    c_tab_0.b_set_new_size(6);
    c_tab_0.b_set_new_size(4);
    c_tab_0 = c_tab_1;

    //Both objects (c_tab_0 and c_tab_1 have pointers pointing to the SAME int table (according to the definition op operator=)
    //Therefore when the destructor is called for the second object, it tries to do "delete pointer_to_table" (both have the same address)
    //Program crashes becouse it is not allowed to dealocate already dealocated memory


    //When destructor is removed from C_table declaration program does not crash, but only automatic destructor is called, which does not deallocate
    //memory that pointer_to_table is pointing at. This causes memory leakage, so thats not a viable solution.

}


void exercise3_test()
{
    C_table c_tab_0, c_tab_1;
    c_tab_0.b_set_new_size(6);
    c_tab_1.b_set_new_size(4);

    c_tab_0.fill_table_with_consecutive_values(1);
    c_tab_1.fill_table_with_consecutive_values(51);


    c_tab_0 = c_tab_1;
    c_tab_1.set_value_at(2,13);
    std::cout<<"c_tab_0"<<std::endl;
    c_tab_0.v_print();
    std::cout<<"c_tab_1"<<std::endl;
    c_tab_1.v_print();

    //With this test again program tries to deallocate the memory under the same addres (pointer_to_table) twice.
    //Becouse operator= is defined to copy value of pointer pointer_to_table, it is obvious that after this operator is called both of the
    //object operate on the SAME int table, therefor changes done via one object will "affect" second one.

}
void exercise4_test()
{
    C_table c_tab_0, c_tab_1;

    c_tab_0.b_set_new_size(6);
    c_tab_1.b_set_new_size(4);


    c_tab_0.fill_table_with_consecutive_values(1);
    c_tab_1.fill_table_with_consecutive_values(51);

    std::cout<<"Pierwszy c_table"<<std::endl;
    c_tab_0.v_print();
    std::cout<<"Drugi c_table"<<std::endl;
    c_tab_1.v_print();

    C_table c_tab3(c_tab_0);

    std::cout<<"Tablica skopiowana c_tab3"<<std::endl;
    c_tab3.v_print();

    C_table c_tab_2;
    std::cout<<"Operator +"<<std::endl;
    c_tab_2 = (c_tab_0+c_tab_1);    //zwrócenie jako wynik obiektu z funkcji c_tab_0+c_tab_1. Jest wobec niego wykonywany =, a następnie po wykonaniu linijki zostanie on zniszczony,
                                    //W przypadku kiedy funkcja zwraca obiekt statyczny to musi go najpierw zwrócić a dopiero później usunąć (inaczej statycznie się nie da)
    std::cout<<"Trzeci c_table"<<std::endl;

    c_tab_2.v_print();


}
void modification_test()
{
    C_table c_tab_0;
    c_tab_0.fill_table_with_consecutive_values(1);
    c_tab_0.v_print();

    std::cout<<"Przed inkrementacją"<<std::endl;

    c_tab_0++;

    std::cout<<"Po inkrementacji"<<std::endl;


    c_tab_0.v_print();
}

int main() {
   // excerise1_test();
   // exercise3_test();
   // exercise4_test();

    modification_test();

    return 0;
}
