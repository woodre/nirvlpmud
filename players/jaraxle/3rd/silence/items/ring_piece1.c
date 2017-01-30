#include "/players/jaraxle/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
    if(arg) return;
    set_id("ring_piece1");
    set_alias("piece");
    set_short("A shattered ring piece");
    set_long("This is a small, "+HIM+"pink"+NORM+" piece of a ring band.\n");
set_value(100);
}

