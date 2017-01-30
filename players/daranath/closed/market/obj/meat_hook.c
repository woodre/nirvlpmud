#include <ansi.h>
#define targ capitalize(attacker->query_name())
#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("meat hook");
set_type("exotic");
set_alias("hook");
set_short("Rusty Meat Hook");
set_long("Not having been taken care of for a number of years, this Meat Hook\n"+
         "is covered in large amounts of rust, adding to the damage the\n"+
         "damage that the hook does.\n");
set_class(18);
set_weight(1);
set_value(350);
set_hit_func(this_object());
}

weapon_hit(attacker){
  a = random(4);

if(a == 0) {
write("You cut "+targ+" deeply with the Rusty Meat Hook.\n");
say(tp+" sticks "+targ+" with the Rusty Meat Hook.\n");
return 6;
}
if(a == 1) {
write(targ+" screams in pain from the damage inflicted by the Rusty Meat Hook.\n");
return 8;
}
}
