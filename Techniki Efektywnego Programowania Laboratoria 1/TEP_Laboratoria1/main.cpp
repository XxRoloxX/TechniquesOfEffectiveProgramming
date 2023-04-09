#include <iostream>
#include "allocation_modification_functions_and_constants.h"
#define DEBUG true

void independent_functions_testing()
{
    int **pi_table;

    std::cout<<"Alokacja i i zapis do pamieci: Zadanie 1"<<std::endl;

    v_alloc_table_fill_34(I_SIZE_X_EX1);

    std::cout<<"Alokacja dwuwymiarowej tablicy: Zadanie 2"<<std::endl;

    b_alloc_table_2_dim(&pi_table,  I_SIZE_X_EX2_3, I_SIZE_Y_EX2_3);

    print_two_dimensional_table(&pi_table, 2, 3);

    std::cout<<"Dealokacja dwuwymiarowej tablicy: Zadanie 3"<<std::endl;

    b_dealloc_table_2_dim(&pi_table,  I_SIZE_X_EX2_3,I_SIZE_Y_EX2_3);


    b_dealloc_table_2_dim(&pi_table,  I_SIZE_X_EX2_3,I_SIZE_Y_EX2_3);


    print_two_dimensional_table(&pi_table, 2, 3);






}

void c_table_testing()
{
    C_table c_table_static;
    C_table *c_table_copy;
  //  int *pointer_to_table_to_be_copied;

    //allocate_and_fill_table_with_values(pointer_to_table_to_be_copied,VALUE_TO_FILL_EX1,MODIFIED_DYNAMIC_C_TABLE_SIZE);

    std::cout<<"Tworzenie tablicy obiektow alokowanych statycznie"<<std::endl;
    C_table static_table_of_c_table[LENGTH_OF_TABLE_OF_C_TABLE];

    std::cout<<"Deklarowanie tablicy alokowanej dynamicznie z domyslnym konstruktorem"<<std::endl;
    C_table* dynamic_table_of_c_table = new C_table[LENGTH_OF_TABLE_OF_C_TABLE];


    std::cout<<"Modyfikacja obiektu przekazanego przez referenecje"<<std::endl;
    v_mod_tab(&c_table_static, 77);
    std::cout<<"Modyfikacja obiektu przekazanego przez kopie"<<std::endl;
    v_mod_tab(c_table_static, 22);

    std::cout<<"Modyfikacja dynamicznej tablicy obiektow"<<std::endl;
    for(int i=0;i<LENGTH_OF_TABLE_OF_C_TABLE;i++)
    {
        dynamic_table_of_c_table[i].v_set_name(MODIFIED_DYNAMIC_C_TABLE_NAME);
        dynamic_table_of_c_table[i].b_set_new_size(MODIFIED_DYNAMIC_C_TABLE_SIZE);
    }
    std::cout<<"Zapisywanie wartosci to tablicy obiektu"<<std::endl;

   // dynamic_table_of_c_table[0].copy_table(pointer_to_table_to_be_copied, MODIFIED_DYNAMIC_C_TABLE_SIZE);


    std::cout<<"Klonowanie obiektow z tablicy dynamicznej do tablicy statycznej"<<std::endl;

    c_table_copy = dynamic_table_of_c_table[0].pcClone();



    c_table_copy->print_int_table();

    delete c_table_copy;

    std::cout<<"Klonowanie obiektu przy uzyciu konstruktora"<<std::endl;

    c_table_copy = new C_table(dynamic_table_of_c_table[0]);

    std::cout<<"Zmiana rozmiaru c_table_copy"<<std::endl;
    c_table_copy->b_set_new_size(3);

    std::cout<<"Dealokowanie tablicy dynamicznej"<<std::endl;
    delete [] dynamic_table_of_c_table;
    std::cout<<"Koniec dealokowania tablicy dynamicznej"<<std::endl;




}


/*
 * VECTOR<CTable> v_list
 * v_list.push_back(CTable)
 *
 *
 */

int main() {

    c_table_testing();
    independent_functions_testing();

   // int **pi_table;

    //b_alloc(&pi_table, 5);



    return 0;
}
