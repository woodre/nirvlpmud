#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon";

string str;

int new_wc;

reset(arg) {
  ::reset(arg);

set_name("vampire dagger");
set_alias("dagger");
set_short(BOLD+"a black vampire dagger"+NORM);
set_long(
  "A sharp, black-metal dagger used exclusively by Vampires.\n");
set_class(8);
set_weight(2);
set_value(0);
}

prevent_insert() {
  write("You don't really want to hide your guild's dagger do you?\n");
  return 1;
}

set_class(new_wc) { class_of_weapon = new_wc; }

query_save_flag() { return 1; }

drop(str) {
  write("The dagger disintegrates as it leaves your hand...\n");
  destruct(this_object());
  return 1; }
