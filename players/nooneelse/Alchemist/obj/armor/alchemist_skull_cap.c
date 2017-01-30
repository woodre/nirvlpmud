/*
  alchemist_skull_cap.c - made from skins
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

  set_name("skull cap");
  set_short(NORM+CYN+"A leather skull cap"+NORM);
  set_long(NORM+CYN+"A sturdy leather skull cap.\n"+NORM);
  set_value(300);
  set_weight(1);
  set_ac(1);
  set_type("helmet");
}

prevent_insert() {
  write("You don't really want to hide your skull cap do you?\n");
  return 1;
}

id(str) {
  return str=="helmet" ||
         str=="skull cap" ||
         str=="alchemist_skull_cap" ||
         str=="alchemist_skin_armor";
}
