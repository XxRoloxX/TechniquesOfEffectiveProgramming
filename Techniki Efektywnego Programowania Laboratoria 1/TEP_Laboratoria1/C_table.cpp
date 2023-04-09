//
// Created by donkey2 on 21.10.22.
//

#include "C_table.h"

#include "C_table.h"
#define DEBUG true

C_table::C_table()
{
    s_name=DEFAULT_S_NAME;
    table_length=DEFAULT_TABLE_SIZE;
    pointer_to_table = new int [table_length];

    std::cout<<"bezp: "<<s_name<<std::endl;

}
C_table::C_table(std::string s_name, int i_table_len)
{
    this->s_name = s_name;
    table_length=i_table_len;
    pointer_to_table = new int [i_table_len];

    std::cout<<"parametr: "<<s_name<<std::endl;
}
C_table::C_table(C_table &pc_other)
{
    s_name=pc_other.s_name+"_copy";
    table_length = pc_other.table_length;

    pointer_to_table = new int [table_length];

    for(int i=0;i<table_length;i++)
    {
        pointer_to_table[i]=pc_other.pointer_to_table[i];
    }

    std::cout<<"kopiuj:"<<s_name<<std::endl;


}
C_table::~C_table()
{
    delete pointer_to_table;
    std::cout<<"usuwam: "<<s_name<<std::endl;
}

void C_table::v_set_name(std::string s_name) {

    this->s_name = s_name;
}
bool C_table::b_set_new_size(int i_table_len) {

    if(i_table_len<=0)
    {
        return false;
    }
    else
    {
        int cells_of_table_to_copy = std::min(i_table_len, table_length);
        int* new_pointer_to_table;

        this->table_length=i_table_len;
        new_pointer_to_table = new int[table_length];


        for(int i=0;i<cells_of_table_to_copy;i++)
        {
            new_pointer_to_table[i]=pointer_to_table[i];
        }

        delete pointer_to_table;

        pointer_to_table=new_pointer_to_table;

        return true;
    }


}

C_table* C_table::pcClone() {

    C_table *cloned_c_table;
    //cloned_c_table = new C_table(s_name,table_length);
    cloned_c_table = new C_table(*this);
    // cloned_c_table->pointer_to_table = copy_int_table(this->pointer_to_table,this->table_length);

    return cloned_c_table;



}

bool C_table::copy_table(int *pointer_to_new_table, int new_table_size)
{
    if(new_table_size>table_length || new_table_size<0)
    {
        return false;
    }
    else
    {
        for(int i=0;i<new_table_size;i++)
        {
            pointer_to_table[i]=pointer_to_new_table[i];
        }

        return true;
    }


}


void C_table::print_int_table()
{

    for(int i=0;i<table_length;i++)
    {
        std::cout<<pointer_to_table[i]<<std::endl;
    }

}
