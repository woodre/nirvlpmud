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
/*
TP->set_al_title(""+HIK+"Dark Side"+NORM+"");
TP->set_title(""+HIK+"Master"+HIR+" Sith "+HIK+"Lord"+NORM+"");
*/
TP->set_pretitle("------------COMMITTED------------COMMITTED------------\n"+HIR+"booyaa->"+NORM+"");
TP->set_title(""+HIK+"Waiting for a return ticket from "+HIR+"HELL"+NORM+"");
TP->set_al_title(""+HIK+"InSaNe"+NORM+"");
TP->set_guild_name("cyberninja");
return 1; }
