#include "/players/dusan/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("claws");
set_alias("claws");
set_short(""+BOLD+""+BLK+"Vraaak's"+NORM+" claws");
set_long(
  "These long razor sharp claws used to belong to an unfortunate vraaak. \n"+
  "They are six inches long and attacked to each other via a scaley leather. \n"+
  "They look like they could be wielded. \n" );

set_type("knife");  /*  sword/knife/club/axe/bow/polearm  */
set_class(15);
set_weight(2);
set_value(600);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
object user;
user = environment(this_object())->query_name();
W = random(12);
if(W>7)  {
  say(
  ""+user+" "+HIR+"RIPS"+NORM+" through their enemy.\n");

  write(
  "You "+HIR+"RIP"+NORM+" through your enemy with ease . \n");
  return 2;
   }
return;
}
