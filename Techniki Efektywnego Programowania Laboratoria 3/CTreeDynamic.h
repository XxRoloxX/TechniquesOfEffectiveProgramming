//
// Created by donkey2 on 13.11.22.
//

#ifndef TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIA_LABORATORIA_3_CTREEDYNAMIC_H
#define TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIA_LABORATORIA_3_CTREEDYNAMIC_H

#include <iostream>
#include <vector>


class CTreeDynamic {

public:
    class CNodeDynamic {
    public:
        CNodeDynamic();
        ~CNodeDynamic();
        void vSetValue(int iNewVal);
        void vSetParent(CNodeDynamic* pc_new_parent);
        CNodeDynamic* getParent();
        int iGetChildrenNumber();
        void vAddNewChild();
        void vAddNewChild(CNodeDynamic* pc_child_node);
        CNodeDynamic* pcGetChild(int iChildOffset);
        void vPrint();
        void vPrintAllBelow();
        void removeChildWithoutDeallocation(CNodeDynamic* node_to_remove);
        int iCount(int i_val);

    private:
        std::vector<CNodeDynamic*> v_children;
        CNodeDynamic *pc_parent_node;
        int i_val;
    };

    CTreeDynamic();
    CTreeDynamic(CNodeDynamic *new_pc_root);
    void setPcRoot(CNodeDynamic* pc_new_root);
    ~CTreeDynamic();
    CNodeDynamic *pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
    void createRootNode();
    int iCount(int i_val);

private:
    CNodeDynamic *pc_root;
};






#endif //TECHNIKI_EFEKTYWNEGO_PROGRAMOWANIA_LABORATORIA_3_CTREEDYNAMIC_H
