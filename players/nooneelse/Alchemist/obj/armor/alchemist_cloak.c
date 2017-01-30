/*
  alchemist_cloak.c - made from skins
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

  set_name("cloak");
  set_short("A leather cloak");
  set_long("A finely-crafted leather cloak.\n");
  set_value(0);
  set_weight(1);
  set_ac(1);
  set_type("shield");
}

prevent_insert() {
  write("You don't really want to hide your cloak do you?\n");
  return 1;
}

id(str) {
  return str=="shield" ||
         str=="cloak" ||
         str=="alchemist cloak" ||
         str=="alchemist_cloak" ||
         str=="alchemist_skin_armor";
}
