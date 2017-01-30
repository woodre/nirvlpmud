/*
  ruby_ring.c - made from skins
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

  set_name("ruby ring");
  set_short(NORM+CYN+"A ruby ring"+NORM);
  set_long(NORM+CYN+"A heavy leather band, with a huge blood red ruby set in it.\n"+NORM);
  set_value(25);
  set_weight(1);
  set_ac(1);
  set_type("ring");
}

prevent_insert() {
  write("You don't really want to hide your ring do you?\n");
  return 1;
}

id(str) {
  return str=="ring" ||
         str=="ruby ring" ||
         str=="alchemist_ruby_ring" ||
         str=="alchemist_skin_armor";
}
