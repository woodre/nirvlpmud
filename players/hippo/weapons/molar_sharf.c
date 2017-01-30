#include "/players/hippo/bs.h"
inherit "obj/weapon";
int w;
 reset(arg) {
    ::reset();
    if (arg) return;
   set_name("molar sharf");
   set_alias("sharf");
   set_short("A molar sharf");
   set_long("This is the sharf of a molar. It has some sharp edges"+BS);
   set_class(15);
set_weight(3);
set_value(1400);
set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(10);
   if (w>6) {
   write("You see the sharf cuts a deep hole in that badly hurt skin"+BS);
   say("You see the sharf cuts a deep hole in that badly hurt skin"+BS);
    return;
}
}
