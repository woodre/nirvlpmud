#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit WEAPON;

reset(arg) {
    if(arg) return;
    set_id("log");
    set_alias("wood");
    set_alt_name("piece");
    set_short("A large, blunt piece of wood");
    set_long(
    "This large log has had the branches snapped off to inflict more damage.\n"+
    "It has a few bloodstains on it as if it has seen some fights or\n"+
    "confrontations, and resolved them.  A few finger grooves can be \n"+
    "seen on the underside.\n");
    set_value(10);
    set_class(14);
    set_type("club");
    set_weight(3); }
