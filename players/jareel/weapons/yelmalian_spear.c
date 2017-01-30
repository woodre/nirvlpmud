#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alt_name("yelmalian spear");
  set_id("spear");
    set_alias("spear");
    set_short("A "+BOLD+YEL+"Yelmalian "+NORM+"Spear");
    set_long("This finely crafted spear was forged in the heat of the yelmalian\n"+
    "blast furnaces, that are powererd with yelmalian solar magiks.  Its golden\n"+
    "glow from the spears tip strikes fear in the hearts of evil.\n");
set_class(16);
    set_weight(2);
    set_type("spear");
    set_value(500);
    set_light(1);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int i;
i = random(7);
if(i==1){
write(BOLD+YEL+"The golden spear stabs deep\n"+
"              S U N F I R E !!!!!!\n"+
"                          "+NORM+BOLD+"burns its foe!!"+NORM+"\n");
return 3;
}
}
