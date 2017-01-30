#define tp this_player()->query_name()
int w;
#include "/players/pestilence/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("jack-knife");
  set_alias("knife");
  set_alt_name("jack knife");
  set_short("Jack-knife");
  set_long(
"This is Ray Johnson's jack-knife.  It has a short blade, but if close enough\n"+
"to an attacker, it can do decent damage.  The handle is made of deer horn,\n"+
"with some dried blood on it.\n"
  );
  set_type("dagger");
  set_class(16);
  set_weight(2);
  set_value(1000);
  set_hit_func(this_object());


}

weapon_hit(attacker){
w = random(20);

if(w > 15){
write("You "+HIR+"slice "+NORM+ attacker->query_name()+" with a fierce slash.\n");
say(tp+ ""+HIR+" slice "+NORM+ attacker->query_name()+" with a fierce slash.\n");
return 5;
}


}
