#include <iostream>
#include "CTreeStatic.h"
#include "CTreeDynamic.h"

void vTreeTest()
{
    //Adding new child causes the vector to resize which in turn creates new table to witch
    //old elements are copied and deleted. So every vAddNewChild causes ~CNodeStatic n-times
    //where n is the size of the vector

    CTreeStatic::CNodeStatic c_root;
    c_root.vAddNewChild();
    std::cout<<std::endl;

    c_root.vAddNewChild();
    std::cout<<std::endl;

    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root.vPrintAllBelow();

}
void vPrintUpTest(){
    CTreeStatic::CNodeStatic c_root;
    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
}
void vPrintTreeTest()
{
    CTreeStatic c_tree;
    CTreeStatic::CNodeStatic* c_root = c_tree.pcGetRoot();
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

    c_tree.vPrintTree();

}
void vPrintDynamicTreeTest()
{
    CTreeDynamic* c_tree = new CTreeDynamic();
    c_tree->createRootNode();
    CTreeDynamic::CNodeDynamic* c_root = (c_tree->pcGetRoot());
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
    CTreeDynamic* c_tree = new CTreeDynamic();
    c_tree->createRootNode();
    CTreeDynamic::CNodeDynamic* c_root = (c_tree->pcGetRoot());
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

    CTreeDynamic* c_tree2 = new CTreeDynamic();
    c_tree2->createRootNode();
    CTreeDynamic::CNodeDynamic* c_root2 = (c_tree2->pcGetRoot());
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
void bMoveSubTreeTestStatic()
{
    CTreeStatic c_tree;
    CTreeStatic::CNodeStatic* c_root = c_tree.pcGetRoot();
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

    CTreeStatic c_tree2;
    CTreeStatic::CNodeStatic* c_root2 = c_tree2.pcGetRoot();
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
    c_tree.vPrintTree();
    std::cout<<std::endl;
    std::cout<<"Drzewo 2"<<std::endl;
    c_tree2.vPrintTree();
    std::cout<<std::endl;
    c_tree.bMoveSubtree(c_tree.pcGetRoot()->pcGetChild(1),c_tree2.pcGetRoot()->pcGetChild(1));
    std::cout<<"Drzewo 1 Po zmianie"<<std::endl;
    c_tree.vPrintTree();
    std::cout<<std::endl;
    std::cout<<"Drzewo 2 po zmianie"<<std::endl;
    c_tree2.vPrintTree();
    std::cout<<std::endl;
}
void iCountTest(){
    CTreeDynamic* c_tree = new CTreeDynamic();
    c_tree->createRootNode();
    CTreeDynamic::CNodeDynamic* c_root = (c_tree->pcGetRoot());
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

    CTreeDynamic* c_tree2 = new CTreeDynamic();
    c_tree2->createRootNode();
    CTreeDynamic::CNodeDynamic* c_root2 = (c_tree2->pcGetRoot());
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
    c_root2->pcGetChild(1)->vAddNewChild();
    c_root2->pcGetChild(1)->pcGetChild(0)->vSetValue(210);
    c_root2->pcGetChild(1)->pcGetChild(1)->vSetValue(220);
    c_root2->pcGetChild(1)->pcGetChild(2)->vSetValue(210);
    c_root2->pcGetChild(1)->pcGetChild(2)->vAddNewChild();
    c_root2->pcGetChild(1)->pcGetChild(2)->pcGetChild(0)->vSetValue(210);




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

    std::cout<<"Liczba 210"<<std::endl;
    std::cout<<c_root->iCount(210)<<std::endl;


}

int main() {
    ///vTreeTest();
    ///vPrintTreeTest();
    ///vPrintDynamicTreeTest();
    std::cout<<"Test dynamicznego podpinania drzewa"<<std::endl;;
    ///bMoveSubTreeTestDynamic();
    std::cout<<"Test statycznego podpinania drzewa"<<std::endl;;
    bMoveSubTreeTestStatic();
    ///vPrintUpTest();

    ///std::cout<<"Test iCount"<<std::endl;
    ///iCountTest();
    return 0;
}
