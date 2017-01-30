/*
    basic/orientation.c - orientation routines
    Jan 1992 by marion@cs.tu-berlin.de

    Where mode is given, it specifies whether the input is a long direction
    name (mode=0) or a short direction name (mode!=0). Long direction names
    are 'north', 'northeast' ... and short direction names are 'n', 'ne' ... .

    int orientation_index(string str, int mode)
        Compute direction index - not very useful from outside the module.
    string orientation_verb(string str, int mode)
        Convert from long to short and vice versa.
    string orientation_long(string str)
        Convert to long, regardless of mode.
    string orientation_reverse(string str, int mode)
        Reverse direction.
    string orientation_right(string str, int mode)
        Right direction.
    string orientation_left(string str, int mode)
        Left direction.
    int *orientation_delta(string str, int mode)
        Give the 3D direction delta.

*/

#include "orientation.h"

#define THIS "basic/orientation"

#define LONG    0
#define SHORT   1
#define REVERSE 2
#define DELTA   3
#define RIGHT   4
#define LEFT    5

private mixed *orientation_table;
private mixed *orientation_long;
private mixed *orientation_short;

void init_orientation_table() {
    if (!orientation_table) {
        if (object_name(this_object()) != THIS) {
            orientation_table = (mixed *)THIS->query_orientation_table();
            orientation_long  = (mixed *)THIS->query_orientation_long();
            orientation_short = (mixed *)THIS->query_orientation_short();
        } else {
            orientation_table = ({
                ({ ORIENTATION_LONG    }),
                ({ ORIENTATION_SHORT   }),
                ({ ORIENTATION_REVERSE }),
                ({ ORIENTATION_DELTA   }),
                ({ ORIENTATION_RIGHT   }),
                ({ ORIENTATION_LEFT    }),
            });
            orientation_long = order_alist(({
                ({ ORIENTATION_LONG }), ({ ORIENTATION_FORWARD })
            }));
            orientation_short = order_alist(({
                ({ ORIENTATION_SHORT }), ({ ORIENTATION_FORWARD })
            }));
        }
    }
}

mixed * query_orientation_table() {
    init_orientation_table();
    return orientation_table;
}

mixed * query_orientation_long() {
    init_orientation_table();
    return orientation_long;
}

mixed * query_orientation_short() {
    init_orientation_table();
    return orientation_short;
}

int orientation_index(string str, int mode) {
    init_orientation_table();
    return assoc(str, mode ? orientation_short : orientation_long, -1);
}

string orientation_verb(string str, int mode) {
    int i;

    if ((i = orientation_index(str, mode)) >= 0) {
        return orientation_table[!mode][i];
    }
    return 0;
}

string orientation_long(string str) {
    if (orientation_index(str, 0) < 0) {
        return orientation_verb(str, 1);
    }
    return str;
}

varargs string orientation_reverse(string str, int mode) {
    int i;

    if ((i = orientation_index(str, mode)) >= 0) {
        return orientation_table[LONG][orientation_table[REVERSE][i]];
    }
    return 0;
}

varargs string orientation_right(string str, int mode) {
    int i;

    if ((i = orientation_index(str, mode)) >= 0) {
        return orientation_table[LONG][orientation_table[RIGHT][i]];
    }
    return 0;
}

varargs string orientation_left(string str, int mode) {
    int i;

    if ((i = orientation_index(str, mode)) >= 0) {
        return orientation_table[LONG][orientation_table[LEFT][i]];
    }
    return 0;
}

// The 3D orientation delta is a 3D vector on the dimensions
// east-west, north-south, up-down
// For example:
// ({ 1, -1,  0}) =^= northeast
// ({ 0,  0,  1}) =^= up
// ({ 2,  1,  0}) =^= eastsoutheast
// ({ 0,  0,  0}) =^= in / out
int * orientation_delta(string str, int mode) {
    int i;

    if ((i = orientation_index(str, mode)) >= 0) {
        return orientation_table[DELTA][i];
    }
    return 0;
}

