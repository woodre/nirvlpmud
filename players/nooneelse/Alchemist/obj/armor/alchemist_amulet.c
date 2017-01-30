/*
  alchemist_amulet.c - made from skins
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "obj/armor";

init() {
  ::init();

  if (!living(environment(this_object())) ||
      !present("Alchemist Pouch", environment(this_object())))
    call_out("trash_this", 2);
}

trash_this() { destruct(this_object()); }

reset(arg) {
  ::reset(arg);

  set_name("amulet");
  set_short(NORM+CYN+"A leather amulet with a bright blue stone in it"+NORM);
  set_long(NORM+CYN+"A leather amulet with a bright blue stone in it.\n"+NORM);
  set_value(0);
  set_weight(1);
  set_ac(1);
  set_type("amulet");
}

prevent_insert() {
  write("You don't really want to hide your amulet do you?\n");
  return 1;
}

id(str) {
  return str=="amulet" ||
         str=="alchemist amulet" ||
         str=="alchemist_amulet" ||
         str=="alchemist_skin_armor";
}
