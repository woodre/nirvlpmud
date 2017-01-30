#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
  if(arg) return;
  ::reset(arg);

set_alt_name("iron bastard sword");
set_alias("bastard sword");
set_id("bastard sword");

set_short(HIK+"Iron Bastard Sword"+NORM);
set_long(
  "This finely crafted iron sword bares the markings of a dwarven\n"+
  "master.  Its dull gray sheen absorbs the surrounding light, with\n"+
  "light only gleaming of the weapons edge.\n");

set_class(18);
set_weight(2);
set_type("sword");
set_value(1200);
set_hit_func(this_object());
}

weapon_hit(attacker){
  int i;
    i = random(3);
    if(i==1){
      write("Iron bites deep into its foe.\n");
    return 1;
}
}
