/*
 * SAVE_SPIRIT command for Ascension
 * save guild statistics
 */
#include "../def.h"

status main() {
    PRE->save_me();
    write("Your spiritual essence has been saved.\n");
    return 1;
}
