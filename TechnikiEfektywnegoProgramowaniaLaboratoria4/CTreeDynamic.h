//
// Created by donkey2 on 26.11.22.
//

#ifndef TECHNIKIEFEKTYWNEGOPROGRAMOWANIALABORATORIA4_CTREEDYNAMIC_H
#define TECHNIKIEFEKTYWNEGOPROGRAMOWANIALABORATORIA4_CTREEDYNAMIC_H

#endif //TECHNIKIEFEKTYWNEGOPROGRAMOWANIALABORATORIA4_CTREEDYNAMIC_H

#include <iostream>
#include <vector>

#include <signal.h>
#include <unistd.h>


template<typename T> class CTreeDynamic {

public:
    class CNodeDynamic {
    public:
        CNodeDynamic();
        ~CNodeDynamic();
        void vSetValue(T new_val);
        void vSetParent(CNodeDynamic* pc_new_parent);
        CNodeDynamic* getParent();
        int iGetChildrenNumber();
        void vAddNewChild();
        void vAddNewChild(CNodeDynamic* pc_child_node);
        CNodeDynamic* pcGetChild(int i_child_offset);
        void vPrint();
        void vPrintAllBelow();
        void removeChildWithoutDeallocation(CNodeDynamic* node_to_remove);
        int iCount(T i_val);
        void ptMulRec(T* result);
    private:
        std::vector<CNodeDynamic*> v_children;
        CNodeDynamic *pc_parent_node;
        T t_val;
    };

    CTreeDynamic();
    CTreeDynamic(CNodeDynamic *new_pc_root);
    void setPcRoot(CNodeDynamic* pc_new_root);
    ~CTreeDynamic();
    CNodeDynamic *pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
    void createRootNode();
    int iCount(T i_val);
    T* ptMul();

private:
    CNodeDynamic *pc_root;
};

template<typename T>
CTreeDynamic<T>::CNodeDynamic::CNodeDynamic() {
    pc_parent_node = NULL;
}
template<>
CTreeDynamic<int>::CNodeDynamic::CNodeDynamic() {
    pc_parent_node = NULL;
    t_val=1;
}
template<typename T>
CTreeDynamic<T>::CNodeDynamic::~CNodeDynamic(){

    for(int i=0;i<v_children.size();i++){
        delete v_children.at(i);
    }

}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vSetParent(CNodeDynamic* pc_new_parent_node){
    pc_parent_node = pc_new_parent_node;
}

template<typename T>
typename CTreeDynamic<T>::CNodeDynamic* CTreeDynamic<T>::CNodeDynamic::getParent() {
    return pc_parent_node;
}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vSetValue(T i_new_val) {
    t_val = i_new_val;
}

template<typename T>
int CTreeDynamic<T>::CNodeDynamic::iGetChildrenNumber() {
    return(v_children.size());
}
template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vAddNewChild(){
    CNodeDynamic* pc_child_node = new CNodeDynamic();
    vAddNewChild(pc_child_node);
    pc_child_node ->vSetParent(this);
}
template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vAddNewChild(CNodeDynamic* pc_child_node){
    pc_child_node->vSetParent(this);
    v_children.push_back(pc_child_node);
}
template<typename T>
typename CTreeDynamic<T>::CNodeDynamic * CTreeDynamic<T>::CNodeDynamic::pcGetChild(int i_child_offset){

    if(i_child_offset<v_children.size() && i_child_offset>=0){
        return (v_children.at(i_child_offset));
    }
    else{
        return NULL;
    }
}
/*
template<typename T>
void printPointer(T val){

    T copy = val;

    try{

        //delete val;
        printPointer(val);

    }catch(const std::exception&e ){

        std::cout<<val<<std::endl;
    }



}
 */


template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vPrint() {


/*
    try {
        *(int*)0=0;
        T copy = t_val;

        //*(char*)(void *) (t_val)=copy;

    }catch (...){
        std::cout << " " << t_val;
        std::cout << " " << t_val;
    }
    //char result = *(char*)b;
*/
    std::cout << " " << t_val;


}


template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vPrintAllBelow(){

    vPrint();
    for(int i=0;i<v_children.size();i++)
    {
        v_children.at(i)->vPrintAllBelow();
    }
}
template<typename T>
void CTreeDynamic<T>::CNodeDynamic::removeChildWithoutDeallocation(CNodeDynamic* node_to_remove){
    std::vector<CNodeDynamic*> new_v_children;

    for(int i=0;i<v_children.size();i++){

        if(v_children.at(i)!=node_to_remove){
            new_v_children.push_back(v_children.at(i));
        }
    }

    v_children=new_v_children;

}
template<typename T>
int CTreeDynamic<T>::CNodeDynamic::iCount(T i_val){
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
template<typename T>
CTreeDynamic<T>::CTreeDynamic(){
    pc_root=NULL;
}
template<typename T>
void CTreeDynamic<T>::createRootNode(){
    if(pc_root==NULL){
        pc_root = new CNodeDynamic();
    }
}
template<typename T>
CTreeDynamic<T>::~CTreeDynamic(){

    if(pc_root!=NULL){
        delete pc_root;
    }

}
template<typename T>
CTreeDynamic<T>::CTreeDynamic(CNodeDynamic *new_pc_root){
    pc_root=new_pc_root;
}
template<typename T>
void CTreeDynamic<T>::setPcRoot(CNodeDynamic* pc_new_root){
    pc_root = pc_new_root;
}
template<typename T>
typename CTreeDynamic<T>::CNodeDynamic* CTreeDynamic<T>::pcGetRoot() {
    return(pc_root);
}
template<typename T>
void CTreeDynamic<T>::vPrintTree(){
    if(pc_root !=NULL){
        pc_root->vPrintAllBelow();
    }

}
template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic *pc_parent_node, CNodeDynamic *pc_new_child_node){

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
template<typename T>
int CTreeDynamic<T>::iCount(T i_val){
    return pc_root->iCount(i_val);
}

//Jeżeli T = Int i Double to zwroc iloczyn wszystkich wezlow (wynik to dynamiczny
template<typename T>
T* CTreeDynamic<T>::ptMul(){
    return NULL;
}
template<>
int* CTreeDynamic<int>::ptMul(){

    int *result = new int();
    *result=1;
    pc_root->ptMulRec(result);
    return result;
}
template<>
double* CTreeDynamic<double>::ptMul(){

    double *result = new double();
    *result=1;
    pc_root->ptMulRec(result);
    return result;
}


template<typename T>
void CTreeDynamic<T>::CNodeDynamic::ptMulRec(T* result){
    *result *=(t_val);
    for(int i=0;i<v_children.size();i++){
        v_children.at(i)->ptMulRec(result);
    }
}




//Inne typy zwracają null
