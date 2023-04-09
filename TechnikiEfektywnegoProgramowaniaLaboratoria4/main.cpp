#include <iostream>
#include "CTreeDynamic.h"


void vPrintDynamicTreeTest()
{
    CTreeDynamic<int>* c_tree = new CTreeDynamic<int>();
    c_tree->createRootNode();
    CTreeDynamic<int>::CNodeDynamic* c_root = (c_tree->pcGetRoot());
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
    c_tree->vPrintTree();
}
void bMoveSubTreeTestDynamic(){
    CTreeDynamic<int>* c_tree = new CTreeDynamic<int>();
    c_tree->createRootNode();
    CTreeDynamic<int>::CNodeDynamic* c_root = (c_tree->pcGetRoot());
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    CTreeDynamic<int>* c_tree2 = new CTreeDynamic<int>();
    c_tree2->createRootNode();
    CTreeDynamic<int>::CNodeDynamic* c_root2 = (c_tree2->pcGetRoot());
    c_root2->vAddNewChild();
    c_root2->vAddNewChild();
    c_root2->pcGetChild(0)->vSetValue(10);
    c_root2->pcGetChild(1)->vSetValue(20);
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue(110);
    c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue(120);
    c_root2->pcGetChild(1)->vAddNewChild();
    c_root2->pcGetChild(1)->vAddNewChild();
    c_root2->pcGetChild(1)->pcGetChild(0)->vSetValue(210);
    c_root2->pcGetChild(1)->pcGetChild(1)->vSetValue(220);

    std::cout<<"Drzewo 1"<<std::endl;
    c_tree->vPrintTree();
    std::cout<<std::endl;
    std::cout<<"Drzewo 2"<<std::endl;
    c_tree2->vPrintTree();
    std::cout<<std::endl;


    c_tree->bMoveSubtree(c_root->pcGetChild(1),c_root2->pcGetChild(1));

    std::cout<<"Drzewo 1 Po zmianach"<<std::endl;
    c_tree->vPrintTree();
    std::cout<<std::endl;
    std::cout<<"Drzewo 2 Po zmianach"<<std::endl;
    c_tree2->vPrintTree();
    std::cout<<std::endl;



}

void bMoveSubTreeTestDynamicString(){
    CTreeDynamic<std::string>* c_tree = new CTreeDynamic<std::string>();
    c_tree->createRootNode();
    CTreeDynamic<std::string>::CNodeDynamic* c_root = (c_tree->pcGetRoot());
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue("a");
    c_root->pcGetChild(1)->vSetValue("b");
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue("c");
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue("d");
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue("e");
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue("f");

    CTreeDynamic<std::string>* c_tree2 = new CTreeDynamic<std::string>();
    c_tree2->createRootNode();
    CTreeDynamic<std::string>::CNodeDynamic* c_root2 = (c_tree2->pcGetRoot());
    c_root2->vAddNewChild();
    c_root2->vAddNewChild();
    c_root2->pcGetChild(0)->vSetValue("aa");
    c_root2->pcGetChild(1)->vSetValue("bb");
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue("cc");
    c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue("dd");
    c_root2->pcGetChild(1)->vAddNewChild();
    c_root2->pcGetChild(1)->vAddNewChild();
    c_root2->pcGetChild(1)->pcGetChild(0)->vSetValue("ee");
    c_root2->pcGetChild(1)->pcGetChild(1)->vSetValue("ff");

    std::cout<<"Drzewo 1"<<std::endl;
    c_tree->vPrintTree();
    std::cout<<std::endl;
    std::cout<<"Drzewo 2"<<std::endl;
    c_tree2->vPrintTree();
    std::cout<<std::endl;


    c_tree->bMoveSubtree(c_root->pcGetChild(1),c_root2->pcGetChild(1));

    std::cout<<"Drzewo 1 Po zmianach"<<std::endl;
    c_tree->vPrintTree();
    std::cout<<std::endl;
    std::cout<<"Drzewo 2 Po zmianach"<<std::endl;
    c_tree2->vPrintTree();
    std::cout<<std::endl;



}

void TestMultiplication()
{
    CTreeDynamic<int>* c_tree = new CTreeDynamic<int>();
    c_tree->createRootNode();
    CTreeDynamic<int>::CNodeDynamic* c_root = (c_tree->pcGetRoot());
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(3);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(4);
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(5);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(6);
    c_tree->vPrintTree();
    int* result = c_tree->ptMul();
    std::cout<<"Wynik mnozenia intow: "<<(*result)<<std::endl;


}


int main() {

    TestMultiplication();

    ///vPrintDynamicTreeTest();
   /// bMoveSubTreeTestDynamic();
   /// bMoveSubTreeTestDynamicString();
/*
    int a =50;
    CTreeDynamic<int> *c_tree = new CTreeDynamic<int>();
    c_tree->createRootNode();
    CTreeDynamic<int>::CNodeDynamic* c_root = (c_tree->pcGetRoot());
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(1000);
    c_root->pcGetChild(1)->vSetValue(3000);
    c_root->pcGetChild(0)->vPrint();
*/




    return 0;
}
