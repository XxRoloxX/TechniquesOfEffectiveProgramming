//
// Created by donkey2 on 21.10.22.
//

#ifndef TEP_LABORATORIA1_C_TABLE_H
#define TEP_LABORATORIA1_C_TABLE_H

#include <iostream>

const std::string DEFAULT_S_NAME="Table";
const int DEFAULT_TABLE_SIZE =5;



class C_table {

public:
    C_table();
    C_table(std::string s_name, int i_table_len);
    C_table(C_table &pc_other);
    ~C_table();
    void v_set_name(std::string s_name);
    bool b_set_new_size(int i_table_len);
    C_table *pcClone();
    void print_int_table();
    bool copy_table(int *pointer_to_table, int table_size);

private:
    std::string s_name;
    int* pointer_to_table;
    int table_length;




};


#endif //TEP_LABORATORIA1_C_TABLE_H
