//
// Created by donkey2 on 21.10.22.
//

#ifndef TEP_LABORATORIA1_ALLOCATION_MODIFICATION_FUNCTIONS_AND_CONSTANTS_H
#define TEP_LABORATORIA1_ALLOCATION_MODIFICATION_FUNCTIONS_AND_CONSTANTS_H


#include "C_table.h"

const int VALUE_TO_FILL_EX1=34;

const int LENGTH_OF_TABLE_OF_C_TABLE=10;

const int I_SIZE_X_EX1=10;

const int I_SIZE_X_EX2_3=20;

const int I_SIZE_Y_EX2_3=15;

const std::string MODIFIED_DYNAMIC_C_TABLE_NAME="Dynamic Table";

const int MODIFIED_DYNAMIC_C_TABLE_SIZE=5;

bool v_alloc_table_fill_34(int i_size);

bool b_alloc_table_2_dim(int ***pi_Table, int i_size_x, int i_size_y);

bool b_dealloc_table_2_dim(int ***pi_table, int i_size_x, int i_size_y);

bool b_dealloc_table_2_dim_shortened(int ***pi_table, int i_size_x);

void v_mod_tab(C_table *pc_tab, int i_new_size);

void v_mod_tab(C_table c_tab, int i_new_size);

bool allocate_and_fill_table_with_values(int* &pi_table, int value, int table_size);


bool print_one_dimensional_table(int **pi_table, int i_size);


bool print_two_dimensional_table(int ***pi_table, int i_x_size, int i_y_size);

bool check_if_null_pointer_in_table(int ***pi_table, int table_size);

bool allocate_triange(int ***pi_table, int i_size);

bool b_alloc(int ***pi_table, int i_size);


#endif //TEP_LABORATORIA1_ALLOCATION_MODIFICATION_FUNCTIONS_AND_CONSTANTS_H
