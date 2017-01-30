#include <ansi.h>

inherit "obj/treasure";
int barter;
reset(arg) {
  if(arg) return;
  set_id("hump");
  set_alias("hump from a camel");
set_short("The hump from a camel");
  set_long(
"This is a thing.\n");
  set_weight(1);
  set_value(2000);
  set_barter(2000+random (3000));
}
set_barter(int n){ barter = n; }
query_barter(){ return barter; }
init() {
  add_action("cmd_barter","barter");
}

cmd_barter(str) {
int value;
  if(id(str)) {
if(!present("rhoalia",environment(this_player()))) {
write("What?\n");
		return 1;
	}
value = this_object()->query_barter();
	this_player()->add_money(value);
write("Hey, Thanks\n");
write("The monster says 'Here's "+value+" coins for the thing'");
      this_player()->add_money(value);
      move_object(this_object(), "room/void");
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
