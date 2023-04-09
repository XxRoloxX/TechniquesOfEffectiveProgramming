//
// Created by donkey2 on 13.11.22.
//

#include "CTreeStatic.h"
#include <iostream>

#define DEBUG false

//CTreeStatic::CTreeStatic();
//CTreeStatic::~CTreeStatic();
CTreeStatic::CNodeStatic* CTreeStatic::pcGetRoot(){
    return(&c_root);
}
void CTreeStatic::vPrintTree(){
    c_root.vPrintAllBelow();
}
/*
bool CTreeStatic::bMoveSubtree(CTreeStatic::CNodeStatic* pc_parent_node, CTreeStatic::CNodeStatic* pc_new_child_node){

    CNodeStatic* old_child_parent = pc_new_child_node->getParentNode();

    pc_parent_node->vAddNewChild(*pc_new_child_node);

    pc_parent_node->pcGetChild(pc_parent_node->iGetChildrenNumber()-1)->setParent(pc_parent_node);

    return old_child_parent->removeChild(*pc_new_child_node);


}
 */
bool CTreeStatic::bMoveSubtree(CTreeStatic::CNodeStatic* pc_parent_node, CTreeStatic::CNodeStatic* pc_new_child_node){

    if(pc_parent_node==NULL || pc_new_child_node==NULL){
        return false;
    }

    CNodeStatic* old_child_parent = pc_new_child_node->getParentNode();
    int old_child_index = pc_new_child_node->getChildIndex();



    pc_new_child_node->setParent(pc_parent_node);
    pc_parent_node->vAddNewChild(pc_new_child_node);

    if(old_child_parent!=NULL) {
        old_child_parent->removeChild(old_child_index);
    }

    return true;


}
CTreeStatic::CNodeStatic::CNodeStatic(){
    i_val = 0;
    pc_parent_node = NULL;
    child_index=0;
}
CTreeStatic::CNodeStatic::~CNodeStatic(){
    if(DEBUG){
        std::cout<<"Usuwanie"<<std::endl;
    }
}
void CTreeStatic::CNodeStatic::vSetValue(int i_new_val) {
    i_val = i_new_val;
}
int CTreeStatic::CNodeStatic::iGetChildrenNumber() {
    return(v_children.size());
}
void CTreeStatic::CNodeStatic::vAddNewChild(){
    CNodeStatic new_child;
    new_child.pc_parent_node=this;
    new_child.setChildIndex(v_children.size());
    v_children.push_back(new_child);
    vUpdateParents();

}
void CTreeStatic::CNodeStatic::vAddNewChild(CNodeStatic* new_child){
    new_child->setParent(this);
    new_child->setChildIndex(v_children.size());
    v_children.push_back(*new_child);
    vUpdateParents();

}

void CTreeStatic::CNodeStatic::vUpdateParents(){

    for(int i=0;i<iGetChildrenNumber();i++){
        pcGetChild(i)->vUpdateParents();
        pcGetChild(i)->setParent(this);
    }

}
CTreeStatic::CNodeStatic* CTreeStatic::CNodeStatic::pcGetChild(int i_child_offset){
    if(i_child_offset<v_children.size()){
        return &(v_children.at(i_child_offset));
    }
    else{
        return NULL;
    }

}
void CTreeStatic::CNodeStatic::vPrint() {
    std::cout << " " << i_val;
}
void CTreeStatic::CNodeStatic::vPrintAllBelow(){
    vPrint();
    for(int i=0;i<v_children.size();i++){
        v_children.at(i).vPrintAllBelow();
    }
}
void CTreeStatic::CNodeStatic::vPrintUp() {

    vPrint();
    if(pc_parent_node!=NULL){
        pc_parent_node->vPrintUp();
    }
}
void CTreeStatic::CNodeStatic::vAddNewChild(CNodeStatic new_child){
    new_child.setParent(this);
    new_child.setChildIndex(v_children.size());
    v_children.push_back(new_child);

}
void CTreeStatic::CNodeStatic::setChildIndex(int new_child_index) {
    child_index=new_child_index;
}
int CTreeStatic::CNodeStatic::getChildIndex() {
    return child_index;
}
CTreeStatic::CNodeStatic* CTreeStatic::CNodeStatic::getParentNode(){
    return pc_parent_node;
}
void CTreeStatic::CNodeStatic::setParent(CTreeStatic::CNodeStatic* new_parent){
    pc_parent_node=new_parent;
}

/*
bool CTreeStatic::CNodeStatic::removeChild(CTreeStatic::CNodeStatic node_to_remove){
    std::vector<CNodeStatic> new_v_children;

    for(int i=0;i<v_children.size();i++){

        if(!((v_children.at(i)) == node_to_remove)){
            new_v_children.push_back(v_children.at(i));
        }
    }
    if(v_children.size()==new_v_children.size()){
        return false;
    }
    else {
        v_children = new_v_children;
        return true;
    }
}
 */
bool CTreeStatic::CNodeStatic::removeChild(int index_of_node_to_remove){

    std::vector<CTreeStatic::CNodeStatic> new_v_children;
    CTreeStatic::CNodeStatic child_to_be_copied;

    if(index_of_node_to_remove<0 || index_of_node_to_remove>=v_children.size())
    {
        return false;
    }

    for(int i=0;i<v_children.size();i++){
        child_to_be_copied = v_children.at(i);

        if(i>index_of_node_to_remove){
            child_to_be_copied.child_index--;
            new_v_children.push_back(child_to_be_copied);
        }
        else if(i<index_of_node_to_remove){
            new_v_children.push_back(child_to_be_copied);
        }
    }

    v_children = new_v_children;
    return true;

}
/*
bool CTreeStatic::CNodeStatic::operator==(CTreeStatic::CNodeStatic node_to_compare) {
    if(this->v_children.size() != node_to_compare.v_children.size()){
        return false;
    }
    if(this->i_val != node_to_compare.i_val)
    {
        return false;
    }

    for(int i=0;i<v_children.size();i++)
    {
        if(!(v_children.at(i)==node_to_compare.v_children.at(i))){
            return false;
        }
    }

    return true;

}
 */
/*
 * Klasy szablonowe muszą mieć implementacje w pliku .h
 *
 * Klasy szablonowe = generyczne
 * CTable<int> *pc_tab_int;
 */

