/*
  alchemist_leather_gloves.c - made from skins
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "obj/armor";

init() {
  ::init();

  if (!living(environment(this_object())) ||
      !present("Alchemist Pouch", environment(this_object())))
    call_out("trash_this", 10);
}

trash_this() { destruct(this_object()); }

reset(arg) {
  ::reset(arg);

  set_name("leather gloves");
  set_short(NORM+CYN+"A pair of leather gloves"+NORM);
  set_long(NORM+CYN+"A pair of sturdy leather gloves.\n"+NORM);
  set_value(0);
  set_weight(1);
  set_ac(1);
  set_type("misc");
}

prevent_insert() {
  write("You don't really want to hide your gloves do you?\n");
  return 1;
}

id(str) {
  return str=="misc" ||
         str=="leather gloves" ||
         str=="alchemist_leather_gloves" ||
         str=="gloves" ||
         str=="alchemist_skin_armor";
}
