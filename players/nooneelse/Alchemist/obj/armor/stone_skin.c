/*
  stone_skin.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "obj/armor";

init() {
  ::init();

  if (!living(environment(this_object())) ||
      !present("Alchemist Pouch", environment(this_object())))
    call_out("trash_this", 10);

  add_action("wear",             "wear");
  add_action("trash_stone_skin", "trash");
}

wear(str) {
  if (str!="stone_skin") {
    write(NORM+CYN+"You cannot wear armor while you have stone skin.\n"+NORM);
    return 1;
  }
  return;
}

trash_stone_skin(str) {
  if (!str || str!="skin") {
    write("use: trash skin\n");
    return 1;
  }
  call_out("trash_this", 2);
}

trash_this() { destruct(this_object()); }

query_save_flag() { return 1; }

reset(arg) {
  ::reset(arg);

  set_name("stone_skin");
  set_short(NORM+CYN+"A hard, stone-like, coating on your skin\n"+
            "('trash skin' to get rid of it)"+NORM);
  set_value(0);
  set_weight(1);
  set_ac(2);
  set_type("armor");
}

prevent_insert() {
  write(NORM+CYN+"You can't do that!\n"+NORM);
  return 1;
}

set_ac(new_ac) { ac = new_ac; }

id(str) { return str=="stone skin" ||
                 str=="stone_skin" ||
                 str=="alchemist_skin_armor"; }
