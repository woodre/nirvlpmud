#include "/players/hippo/bs.h"
inherit "obj/weapon";
int w;
 reset(arg) {
    ::reset();
    if (arg) return;
   set_name("skinbite");
set_short("An acid called skinbite");
set_long("A very hot acid, that could hurt an enemy badly"+BS);
set_class(16);
set_weight(3);
set_value(1700);
set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(10);
   if (w>8) {
   write("Your acid scrumbles the skin of the opponent very badly,"+BS+
    "you smell something.. and you look hopeful to his skin:"+BS+
    "you can see blisters start to raise and bubble."+BS);
   say("You see the acid scrumbles the skin of the opponent very badly,"+BS+
    "you smell something.. and you look hopeful to his skin:"+BS+
    "you can see blisters start to raise and bubble."+BS);
    return;
}
}
