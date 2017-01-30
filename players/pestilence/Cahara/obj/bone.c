#include "/players/pestilence/ansi.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("bones");
  set_alias("bone");
  set_short("human "+HIW+"bones"+NORM+"");
  set_long(
"These are some human "+HIW+"bones"+NORM+".  They seem to have\n"+
"been acquired a long time ago.  There is a nice "+HIW+"white"+NORM+" finish\n"+
"to them.  It appears that these bones could be bartered to the\n"+
"right person.\n"
  );
  set_weight(2);
  set_value(3000+random(1000));
}

init() {
  add_action("cmd_barter","barter");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("bill",environment(this_player()))) {
      write("Bill says: Wow these are just what i needed for my collection.\n"+
            "Bill says: I'll give you "+value+" coins for it.\n");
      this_player()->add_money(value);
      this_player()->add_weight(-2);
      destruct(this_object());
      return 1;
    }
  }
  notify_fail("Barter what?\n");
}
