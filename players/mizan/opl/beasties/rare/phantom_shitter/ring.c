inherit "obj/armor";
#include "/obj/ansi.h"

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("A promise ring " + HIM + "(FABULOUS)" + NORM );
    set_long(
    "    This is a small gold ring, probably 10K or even brass plated for all you\n"+
    "  know... it is rather substantial in size, and has the word '" + HIM + "FABULOUS" + NORM + "' etched\n"+
    "  into it. The ring has a distinctly sour odor eminating from it.\n");

    set_ac(1);
    set_weight(1);
    set_value(500);
    set_name("ring");
    set_type("ring");
}
