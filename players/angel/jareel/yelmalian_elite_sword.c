#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alt_name("elitesword");
  set_id("bastard sword");
    set_alias("bastard sword");
    set_short(RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"]"+BOLD+YEL+" Elite bastard sword"+NORM);
    set_long("This finely crafted sword was forged in the heat of the yelmalian\n"+
    "blast furnaces, that are powererd with yelmalian solar magiks.  Its golden\n"+
    "glow strikes fear in the hearts of evil.\n");
set_class(17);
    set_weight(2);
    set_type("sword");
    set_value(1000);
    set_light(1);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int i;
i = random(3);
if(i==1){
write(BOLD+YEL+"The golden sword cuts deep\n"+
"              S U N F I R E !!!!!!\n"+
"                          "+NORM+BOLD+"burns its foe!!"+NORM+"\n");
return 7;
}
}
