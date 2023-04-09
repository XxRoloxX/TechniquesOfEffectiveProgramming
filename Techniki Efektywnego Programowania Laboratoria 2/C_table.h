//
// Created by donkey2 on 23.10.22.
//

#ifndef TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIA_LABORATORIA_2_C_TABLE_H
#define TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIA_LABORATORIA_2_C_TABLE_H


#include <iostream>
#include "table_utilities.h"
#define DEBUG true

const std::string DEFAULT_S_NAME="Table";
const int DEFAULT_TABLE_SIZE =5;



class C_table {

public:
    C_table();
    C_table(std::string s_name, int i_table_len);
    C_table(const C_table &pc_other);
    ~C_table();
    void v_set_name(std::string s_name);
    bool b_set_new_size(int i_table_len);
    C_table *pc_clone();
    void operator=(const C_table &pc_other);
    //C_table* operator+(C_table &pc_other);
    C_table operator+(const C_table &pc_other);
    bool fill_table_with_consecutive_values(int starting_value);


    bool set_value_at(int i_offset, int i_new_val);
    void v_print();

    void operator++(int);
    /*
     * cObj.bsetLentgth(2)
     * cObjt.bsetLength(0,5)
     * cObj.bsetLength(1,42)
     * cObj++
     *
     * [5,42,0]
     * cObj++
     * [5,42,0,0]
     *
     */

    std::string get_s_name();

    int *get_pointer_to_table();

    int get_table_length() const;

private:
    std::string s_name;
    int* pointer_to_table;
    int table_length;
    void copy_object_without_previous_deallocation(const C_table &pc_other);




};



#endif //TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIA_LABORATORIA_2_C_TABLE_H
