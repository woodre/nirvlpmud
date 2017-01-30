#include "/players/vertebraker/define.h"
inherit "/obj/treasure.c";
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
TP->set_al_title("neutral");
TP->set_title(HIK+"is the Army Mistress of the "+NORM+HIW+">"+NORM+HIR+"A"+NORM+HIW+"."+NORM+HIR+"o"+NORM+HIW+"."+NORM+HIR+"P"+NORM+HIW+"<"+NORM);
TP->set_pretitle(HIM+"{<{*}>}"+NORM);
/*  TP->set_title("the Dreamer"); */
/* TP->set_pretitle("My""+WHT+ "Fangs""+WHT+"+NORM+" "are dripping""+NORM+""+RED+" "Blood"+NORM,); */
TP->set_guild_name("Goonies");
TP->set_race("human");
return 1; }
