//
// Created by wieslaw on 10.12.22.
//

#ifndef TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CREFCOUNTER_H
#define TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CREFCOUNTER_H


class CRefCounter {
public:
    CRefCounter();
    int iAdd();
    int iDec();
    int iGet();
private:
    int i_count;
};



#endif //TECHNIKIEFEKTYWNEGOPROGRAMOWANIA5_C17_CREFCOUNTER_H
