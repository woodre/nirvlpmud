#include <ansi.h>
#define tp this_player()->query_name()
#define targ capitalize(attacker->query_name())
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Fog Mace");
set_type("mace");
set_short("Mace of Fog");
set_long("A massive and heavy mace, the head of the weapon is almost \n"+
         "translucent in appearance, giving it the name of Fog Mace.\n");
set_class(17);
set_weight(3);
set_value(750+random(750));
set_hit_func(this_object());
}

weapon_hit(attacker){
string here;
a = random(4);
here = environment(this_player());

if(a == 0){
tell_room(here,
  tp+" smashes the "+targ+" with the Mace of Fog.\n");
if(call_other(this_player(),"query_attrib","str") > random(40)) {
  return 7; }
}
}
