//
// Created by donkey2 on 13.11.22.
//

#ifndef TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIA_LABORATORIA_3_CTREESTATIC_H
#define TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIA_LABORATORIA_3_CTREESTATIC_H
#include <vector>

class CTreeStatic {
public:
    //CTreeStatic();
    //~CTreeStatic();
    class CNodeStatic {
    public:
        CNodeStatic();
        ~CNodeStatic();
        void vSetValue(int iNewVal);
        int iGetChildrenNumber();
        void vAddNewChild();
        void vAddNewChild(CNodeStatic* new_child);

        void vAddNewChild(CNodeStatic new_child);
        CNodeStatic* getParentNode();
        void setParent(CNodeStatic* new_parent);
        CNodeStatic *pcGetChild(int iChildOffset);
        void vPrint();
        void vPrintAllBelow();
        void vPrintUp();
        //bool removeChild(CNodeStatic node_to_remove);
        bool removeChild(int index_of_node_to_remove);
        void setChildIndex(int new_child_index);
        int getChildIndex();
        void vUpdateParents();

        //bool operator==(CNodeStatic node_to_compare);
    private:
        std::vector<CNodeStatic> v_children;
        CNodeStatic *pc_parent_node;
        int i_val;
        int child_index;
    };

    CNodeStatic *pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNodeStatic* pc_parent_node, CNodeStatic* pc_new_child_node);
    //bool bMoveSubtree2(CNodeStatic* pc_parent_node, CNodeStatic* pc_new_child_node);

private:
    CNodeStatic c_root;

};


#endif //TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIA_LABORATORIA_3_CTREESTATIC_H
