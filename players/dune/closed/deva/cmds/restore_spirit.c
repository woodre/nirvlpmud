/*
 * RESTORE_SPIRIT command fetches guild statistics
 */
#include "../def.h"

status main() {
    write("Your spiritual essence has been restored.\n");
    PRE->restore_me();
    return 1;
}
