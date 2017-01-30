#include "/players/eurale/defs.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("staff");
  set_alias("shadowstaff");
set_short("Shadowstaff");
set_long(
	"This long, carved wooden pole has a wickedly curved hook on\n"+
	"the end to both restrain and attack opponents.  Once an \n"+
	"opponent has been impaled, they will suffer extreme damage\n"+
	"if they can get away at all.\n");
set_type("club");
  set_class(16 + random(3));
  set_weight(4);
  set_value(900);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say("\nThe shadowstaff "+BOLD+"IMPALES"+NORM+" it's target..\n\n");

  write("\nYou "+BOLD+"IMPALE"+NORM+" your target...\n\n");
  return 3;
   }
return;
}

init() {
move_object(clone_object("players/eurale/Keep/OBJ/shadowstaff"),TP);
destruct(TO);
}
