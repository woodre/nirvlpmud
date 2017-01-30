#include "/players/vertebraker/define.h"
inherit TREASURE
int Wizard;
reset(arg) {
    if(arg) return;
    set_id("thing");
    set_short("thing");
    set_long(
    "a thing.  type 'use'\n");
    set_value(0);
    set_weight(0);
    }
init() {
    ::init();
    add_action("use_me","use");
    }
use_me() {
TP->set_al_title(""+BLU+"slumber"+NORM+"");
TP->set_title(""+CYN+"is dreaming"+NORM+"");
/*  TP->set_title("the Dreamer"); */
/* TP->set_pretitle("My""+WHT+ "Fangs""+WHT+"+NORM+" "are dripping""+NORM+""+RED+" "Blood"+NORM,); */
/* TP->set_guild_name("vampire"); */
return 1; }
