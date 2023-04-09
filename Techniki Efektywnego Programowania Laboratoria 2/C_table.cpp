//
// Created by donkey2 on 23.10.22.
//

#include "C_table.h"
#define DEBUG true

C_table::C_table()
{
    s_name=DEFAULT_S_NAME;
    table_length=DEFAULT_TABLE_SIZE;
    pointer_to_table = new int [table_length];

    if(DEBUG) {
        std::cout << "bezp: " << s_name << std::endl;
    }

}
C_table::C_table(std::string s_name, int i_table_len)
{
    this->s_name = s_name;
    table_length=i_table_len;
    pointer_to_table = new int [i_table_len];

    if(DEBUG) {
        std::cout << "parametr: " << s_name << std::endl;
    }
}

 C_table::C_table(const C_table &pc_other)
{

    copy_object_without_previous_deallocation(pc_other);
    s_name = pc_other.s_name+"_copy";
    if(DEBUG) {
        std::cout << "kopiuj:" << s_name << std::endl;
    }

}

C_table::~C_table()
{
    delete pointer_to_table;
    if(DEBUG) {
        std::cout << "usuwam: " << s_name << std::endl;
    }
}

void C_table::v_set_name(std::string s_name) {

    this->s_name = s_name;
}
bool C_table::b_set_new_size(int i_table_len) {

    if(i_table_len<=0)
    {
        return false;
    }
    else if(i_table_len==table_length)
    {
       return true;
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

C_table* C_table::pc_clone() {

    C_table *cloned_c_table;
    //cloned_c_table = new C_table(s_name,table_length);
    cloned_c_table = new C_table(*this);
    // cloned_c_table->pointer_to_table = copy_int_table(this->pointer_to_table,this->table_length);

    return cloned_c_table;
}
/*
 * Niepoprawny =
void C_table::operator=(const C_table &pc_other)
{
    std::cout<<"W trakcie wykonania ="<<std::endl;
    pointer_to_table = pc_other.pointer_to_table;
    table_length = pc_other.table_length;



}
 */
void C_table::operator=(const C_table &pc_other)
{
    if(pointer_to_table!=NULL)
    {
        delete pointer_to_table;
    }

    copy_object_without_previous_deallocation(pc_other);

}
bool C_table::set_value_at(int i_offset, int i_new_val)
{
    if(i_offset>=table_length || i_offset<0){

        return false;
    }
    else{
        pointer_to_table[i_offset]=i_new_val;
        return true;

    }
}
/*
void C_table::v_print()
{
    for(int i=0;i<table_length;i++)
    {
        std::cout<<"Index "<<i<<": " <<pointer_to_table[i]<<std::endl;
    }
}
 */
void C_table::v_print()
{
    std::cout<<"Table: [";
    for(int i=0;i<table_length;i++)
    {
        if(i>0)
        {
            std::cout<<", ";
        }

        std::cout<<pointer_to_table[i];
    }
    std::cout<<"]"<<std::endl;
}

std::string C_table::get_s_name() {
    return s_name;
}

int *C_table::get_pointer_to_table() {
    return pointer_to_table;
}

int C_table::get_table_length() const{
    return table_length;
}

C_table C_table::operator+(const C_table &pc_other){

    int final_table_length = table_length + pc_other.table_length;
    C_table result(s_name+"+"+pc_other.s_name, final_table_length);

    for(int i=0;i<final_table_length;i++)
    {
        if(i<table_length)
        {
            result.set_value_at(i,pointer_to_table[i]);
        }
        else
        {
            result.set_value_at(i,pc_other.pointer_to_table[i-table_length]);
        }
    }

    return result;

}
void C_table::operator++(int)
{
    b_set_new_size(table_length+1);
    set_value_at(table_length-1,0);
}


/*  Wykorzystanie zwracania obiektu jako wartości pod wskaźnikiem z użyciem return *result
C_table C_table::operator+(const C_table &pc_other) {
    int final_table_length = table_length + pc_other.table_length;

    C_table* result = new C_table(s_name, final_table_length);
    //C_table* result = new C_table(s_name, final_table_length);
    result->v_set_name("RESULT");


    for(int i=0;i<table_length;i++)
    {
        result->set_value_at(i,pointer_to_table[i]);
    }

    for(int i=0;i<final_table_length-table_length;i++)
    {
        result->set_value_at(table_length+i, pc_other.pointer_to_table[i]);
    }

    std::cout<<"Przed zwróceniem obiektu z +: "<<std::endl;
    return *result; //Następuje kopiowanie RESULT - wynik to RESULT_COPY

}
*/

bool C_table::fill_table_with_consecutive_values(int starting_value)
{
    fill_int_table_with_consecutive_values(pointer_to_table, starting_value, table_length);
}

void C_table::copy_object_without_previous_deallocation(const C_table &pc_other)
{
    table_length = pc_other.table_length;
    s_name = pc_other.s_name;
    if(pointer_to_table==NULL || pc_other.table_length != table_length) {
        pointer_to_table = new int[table_length];
    }

    for(int i=0;i<table_length;i++)
    {
        pointer_to_table[i]=pc_other.pointer_to_table[i];
    }

}