#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon.c";

reset(arg){
  set_id("knife");
  set_alias("butterknife");
  set_short(HIC+"A deadly butterknife"+NORM+" (FOR TESTCHAR USE ONLY)");
  set_type("knife");
  set_class(18);
  set_weight(2);
  set_value(-1000000);
  set_hit_func(this_object());
}

weapon_hit(){
int i;
i = random(3);
if(i==2){
    write(HIC+"The butterknife cuts deep into "+this_player()->query_name()+"'s foe.\n"+NORM);
  return 5;
}
return 0;
}
