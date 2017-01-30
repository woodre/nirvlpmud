/*
 amulet.c
*/

#include "/players/eurale/defs.h"
inherit "obj/armor";

string amulet_color;

init() {
  ::init();

  if (!living(environment(this_object()))) call_out("trash_this", 10);
}

trash_this() { destruct(this_object()); }

reset(arg) {
  ::reset(arg);

  set_name("amulet");
  set_alias("nooneelseamulet");
  set_value(0);
  set_weight(1);
  set_ac(1);
  set_params("other|dark",0,10,0);
  set_type("amulet");
  amulet_color = "black";
}

short() { return
  "A two inch rectangular "+BOLD+"black"+NORM+" amulet"; }

long() {
  write("A two inch rectangular "+amulet_color+" amulet.\n"+
        "On the front it says in black letters:\n"+
        "     When there's nowhere to go and things look black, "+
        "push to the north.\n"+
        "On the back it says:\n"+
        "     Member - Rainbow Club Inn\n");
}

set_amulet_color(arg) { amulet_color = arg; }

query_save_flag() { return 1; }

drop() {
  call_out("trash_this", 10);
  return 0;
} /* 8/16/97 N - test this idea out */
