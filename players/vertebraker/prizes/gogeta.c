#include <ansi.h>

inherit "/obj/armor";

reset(arg){
  if(arg) return;
  set_id("Gogeta's Itachi Ring");
  set_alias("gogeta's itachi ring");
  set_type("ring");
  SetMultipleIds(({"itachi ring","generic_wc_bonus"}));
  set_short(RED+"Gog"+HIK+"eta's "+NORM+RED+"Ita"+HIK+"chi"+NORM+RED+" Ri"+HIK+"ng"+NORM);
  set_long("\
A sparkling band of bloodstone and adamantite, this has been forged\n\
by the great wizard Vertebraker as a reward for Gogeta on\n\
May 3, 2007. It is priceless.\n");
  set_weight(1);
  set_value(0); /* priceless */
}

gen_wc_bonus(){
  if(environment()->query_real_name() == "gogeta" &&
     environment()->query_attrib("dex") > random(50)){
    tell_object(environment(),
      "Your Itachi Ring flashes a deep "+RED+"blood-red"+NORM+".\n");
    tell_room(environment(environment()),
      "\t"+BOLD+this_player()->query_name()+"'s ring releases its power!\n"+NORM);
    return 5 + random(5);
  }
}
