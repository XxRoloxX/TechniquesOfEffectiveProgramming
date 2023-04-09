//
// Created by donkey2 on 21.10.22.
//

#include "allocation_modification_functions_and_constants.h"
#include "allocation_modification_functions_and_constants.h"
#define DEBUG true

bool v_alloc_table_fill_34(int i_size)
{
    int *i_pointer;

    if(i_size<=0)
    {
        return false;
    }
    else {

        i_pointer = new int[i_size];

        for(int i=0;i<i_size;i++)
        {
            i_pointer[i]=VALUE_TO_FILL_EX1;
        }

        if(DEBUG) {
            for (int i = 0; i < i_size; i++) {
                std::cout << "Komórka: " << i << " " << i_pointer[i] << std::endl;
            }
        }


        delete [] i_pointer;
        return true;
    }


}
bool b_alloc_table_2_dim(int ***pi_table, int i_size_x, int i_size_y){

    *pi_table = new int*[i_size_x];

    if(i_size_x<=0 || i_size_y<=0)
    {
        return false;
    }
    else {
        for (int i = 0; i < i_size_x; i++) {
            (*pi_table)[i]= new int[i_size_y];
        }

        return true;
    }


}

bool b_dealloc_table_2_dim(int ***pi_table, int i_size_x, int i_size_y)
{
    if(i_size_y<=0 || *pi_table==NULL)
    {
        return false;
    }
    else{

        return b_dealloc_table_2_dim_shortened(pi_table, i_size_x);
    }
}
bool b_dealloc_table_2_dim_shortened(int ***pi_table, int i_size_x)
{

    if(i_size_x<=0 || *pi_table==NULL)
    {
        return false;
    }
    else {

        if(check_if_null_pointer_in_table(pi_table, i_size_x))
        {
            return false;
        }

        for (int i = 0; i < i_size_x; i++) {
            delete (*pi_table)[i];
        }

        delete *pi_table;

        *pi_table=NULL;

        return true;

    }

}
void v_mod_tab(C_table *pc_tab, int i_new_size)
{
    pc_tab->b_set_new_size(i_new_size);
}
void v_mod_tab(C_table c_tab, int i_new_size)
{
    c_tab.b_set_new_size(i_new_size);
}
bool allocate_and_fill_table_with_values(int*& pi_table, int value, int table_size)
{
    if(table_size<=0)
    {
        return false;
    }
    else
    {
        pi_table= new int[table_size];
        for(int i=0;i<table_size;i++)
        {
            pi_table[i]=value;
        }

        return true;
    }
}

bool print_one_dimensional_table(int **pi_table, int i_size)
{
    if(i_size<=0 || *pi_table==NULL)
    {
        return false;
    }
    else {
        for (int i = 0; i < i_size; i++) {
            std::cout << (*pi_table)[i] << ", ";
        }

        return true;
    }
}

bool print_two_dimensional_table(int ***pi_table, int i_x_size, int i_y_size)
{
    //check if in table are nulls
    if(check_if_null_pointer_in_table(pi_table, i_x_size))
    {
        return false;
    }

    else {

        for (int i = 0; i < i_x_size; i++) {
            print_one_dimensional_table(&(*pi_table)[i], i_y_size);
            std::cout << std::endl;
        }
        return true;
    }

}

bool check_if_null_pointer_in_table(int ***pi_table, int table_size)
{
    int i=0;
    bool null_in_table=false;

    if(*pi_table==NULL || table_size<=0)
    {
        return true;
    }
    else
    {
        while(i<table_size && !null_in_table )
        {
            if((*pi_table)[i]==NULL)
            {
                null_in_table=true;
            }
            i++;
        }
    }

    return null_in_table;
}

bool b_alloc(int ***pi_table, int i_size)
{
    if(i_size<=0)
    {
        return false;
    }

    else {

        *pi_table = new int*[i_size];

        for (int i = 0; i < i_size; i++)
        {
            (*pi_table)[i] = new int[i+1];
        }

        return true;


    }

}
