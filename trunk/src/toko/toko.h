#ifndef _TOKO_H
#define	_TOKO_H

#include "../grid/grid.h"
class Toko: public Grid {
//    Inventory barang;
    Toko();
    Toko(const Toko&);
    ~Toko();
    void listItem();
};

#endif	/* _TOKO_H */

