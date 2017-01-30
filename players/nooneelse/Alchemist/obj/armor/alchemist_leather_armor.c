/*
  alchemist_leather_armor.c - made from skins
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

  set_name("leather armor");
  set_short(NORM+CYN+"Leather armor"+NORM);
  set_long(NORM+CYN+"A finely-crafted suit of leather armor.\n"+NORM);
  set_value(0);
  set_weight(1);
  set_ac(4);
  set_type("armor");
}

prevent_insert() {
  write("You don't really want to hide your armor do you?\n");
  return 1;
}

id(str) {
  return str=="armor" ||
         str=="leather armor" ||
         str=="alchemist_leather_armor" ||
         str=="alchemist_skin_armor";
}
