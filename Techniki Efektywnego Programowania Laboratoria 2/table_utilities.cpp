//
// Created by donkey2 on 03.11.22.
//

#include "table_utilities.h"
#include <iostream>

bool fill_int_table_with_consecutive_values(int *pointer_to_table, int starting_value, int table_length)
{
    if(pointer_to_table==NULL)
    {
        return false;
    }
    else {
        for (int i = 0; i < table_length; i++) {
            pointer_to_table[i]=starting_value+i;

        }
        return true;
    }
}