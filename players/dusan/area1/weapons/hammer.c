#include "/players/dusan/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("hammer");
set_alias("hammer");
set_short("A blacksmiths hammer");
set_long(
  "This is a large metal rectangle with a stout oak handle thrust through it. \n");

set_type("club");  /*  sword/knife/club/axe/bow/polearm  */
set_class(14);
set_weight(4);
set_value(200);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
object user;
user = environment(this_object())->query_name();
W = random(15);
if(W>9)  {
  say(
  ""+user+" "+HIR+"crushes"+NORM+" his enemy with a powerful blow.\n");

  write(
  "You "+HIR+"crush"+NORM+" your enemy with a powerful blow . \n");
  return 3;
   }
return;
}
