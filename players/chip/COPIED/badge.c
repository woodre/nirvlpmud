#include "/players/fred/ansi.h"
inherit "/obj/armor";

  reset(arg){
    if(arg) return;
    set_name("badge");
    set_alias("badge");
    set_short(HIY+"A Policeman Badge"+NORM);
    set_long(
     "A policeman badge.  Maybe you could wear it.\n");
    set_ac(0);
    set_type("button");
    set_weight(1);
    set_value(100); }
