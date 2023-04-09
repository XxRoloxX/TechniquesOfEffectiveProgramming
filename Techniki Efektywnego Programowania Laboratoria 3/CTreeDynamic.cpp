//
// Created by donkey2 on 13.11.22.
//

#include "CTreeDynamic.h"
#include <iostream>
#include <vector>

CTreeDynamic::CNodeDynamic::CNodeDynamic() {
    i_val = 0;
    pc_parent_node = NULL;
}
CTreeDynamic::CNodeDynamic::~CNodeDynamic(){

    for(int i=0;i<v_children.size();i++){
        delete v_children.at(i);
    }

}
void CTreeDynamic::CNodeDynamic::vSetParent(CNodeDynamic* pc_new_parent_node){
    pc_parent_node = pc_new_parent_node;
}
CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::getParent() {
    return pc_parent_node;
}

void CTreeDynamic::CNodeDynamic::vSetValue(int i_new_val) {
    i_val = i_new_val;
}
int CTreeDynamic::CNodeDynamic::iGetChildrenNumber() {
    return(v_children.size());
}
void CTreeDynamic::CNodeDynamic::vAddNewChild(){
    CNodeDynamic* pc_child_node = new CNodeDynamic();
    vAddNewChild(pc_child_node);
    pc_child_node ->vSetParent(this);
}
void CTreeDynamic::CNodeDynamic::vAddNewChild(CNodeDynamic* pc_child_node){
    pc_child_node->vSetParent(this);
    v_children.push_back(pc_child_node);
}
CTreeDynamic::CNodeDynamic * CTreeDynamic::CNodeDynamic::pcGetChild(int i_child_offset){

    if(i_child_offset<v_children.size() && i_child_offset>=0){
        return (v_children.at(i_child_offset));
    }
    else{
        return NULL;
    }
}
void CTreeDynamic::CNodeDynamic::vPrint() {
    std::cout << " " << i_val;
}
void CTreeDynamic::CNodeDynamic::vPrintAllBelow(){

    vPrint();
    for(int i=0;i<v_children.size();i++)
    {
        v_children.at(i)->vPrintAllBelow();
    }
}
void CTreeDynamic::CNodeDynamic::removeChildWithoutDeallocation(CNodeDynamic* node_to_remove){
    std::vector<CNodeDynamic*> new_v_children;

    for(int i=0;i<v_children.size();i++){

        if(v_children.at(i)!=node_to_remove){
            new_v_children.push_back(v_children.at(i));
        }
    }

    v_children=new_v_children;
}
int CTreeDynamic::CNodeDynamic::iCount(int i_val){
    int sum=0;

    for(int i=0;i<v_children.size();i++){
        sum+= v_children.at(i)->CTreeDynamic::CNodeDynamic::iCount(i_val);
    }

    if(this->i_val==i_val){
        return 1+sum;
    }
    else{
        return sum;
    }
}

CTreeDynamic::CTreeDynamic(){
    pc_root=NULL;
}
void CTreeDynamic::createRootNode(){
    if(pc_root==NULL){
        pc_root = new CNodeDynamic();
    }
}
CTreeDynamic::~CTreeDynamic(){

    if(pc_root!=NULL){
        delete pc_root;
    }

}
CTreeDynamic::CTreeDynamic(CNodeDynamic *new_pc_root){
    pc_root=new_pc_root;
}
void CTreeDynamic::setPcRoot(CNodeDynamic* pc_new_root){
    pc_root = pc_new_root;
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::pcGetRoot() {
    return(pc_root);
}
void CTreeDynamic::vPrintTree(){
    if(pc_root !=NULL){
        pc_root->vPrintAllBelow();
    }

}
bool CTreeDynamic::bMoveSubtree(CNodeDynamic *pc_parent_node, CNodeDynamic *pc_new_child_node){

    if(pc_parent_node==NULL || pc_new_child_node==NULL){
        return false;
    }
    CNodeDynamic* old_parent_node = pc_new_child_node->getParent();

    if(old_parent_node!=NULL){
        old_parent_node->removeChildWithoutDeallocation(pc_new_child_node);
    }

    pc_parent_node->vAddNewChild(pc_new_child_node);

    return true;


}

int CTreeDynamic::iCount(int i_val){
    return pc_root->iCount(i_val);
}
