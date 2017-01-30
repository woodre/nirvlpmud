#include "/players/languilen/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("sabre");
set_short("A calvary officer's Sabre");
set_long(
  "This four foot long shining steel blade is light, strong and sharp.\n");

set_type("sword");
set_class(15);
set_weight(2);
set_value(0);
set_hit_func(this_object());
}

weapon_hit(attacker){
     int d;
     d = random(13);
     if(d>9)  {
        say(
"The bright blade flashes!\n");

        write(
"You feel the blade vibrate. \n");
        return 2;
     }
     return;
}
