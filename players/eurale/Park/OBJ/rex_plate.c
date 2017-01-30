/*  Changed to barterable item 8/17/02 - Eurale  */

/*  Leather plate armor from T-Rex  */

#include "/players/eurale/closed/ansi.h"
#define ETP environment(this_player())
inherit "obj/armor";

reset(arg) {
  set_name("plate");
  set_alias("tyrannosaurus plate");
  set_short(GRY+"tyrannosaurus plate"+NORM);
  set_long(
	"This indestructable leather plate armor is some of the finest \n"+
	"available and can be bartered with.  It is light and durable. \n");
  set_ac(5);
  set_type("armor");
  set_weight(3);
  set_value(10000);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int money;
if(!str) { write("What?\n"); return 1; }
if(str == "plate" || str == "tyrannosaurus plate") {
if(!present("sedjak",ETP)) { write("What?\n"); return 1; }
 money = 4800 + random(400);
 write(
  "Sedjak takes the beautiful tyrannosaurus plate and without a word hands\n"+
  "you "+money+" coins from his purse.\n");
 this_player()->add_money(money);
 destruct(this_object());
return 1; }
}
