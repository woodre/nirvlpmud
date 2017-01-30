#include "/players/vertebraker/define.h"
inherit ITEM;

reset(arg) {
    if(arg) return;
    set_id("cord");
    set_short("A broken cord");
    set_long("This cord snapped off a light bulb.  Nothing much to see here.\n");
    set_value(1);
    }
