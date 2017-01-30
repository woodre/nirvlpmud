#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

int new_ac;

reset(arg) {
  ::reset(arg);

set_name("vampire tuxedo");
set_alias("tuxedo");
set_short("a "+BOLD+"black vampire tuxedo"+NORM);
set_value(0);
set_weight(2);
set_ac(2);
set_type("armor");
}

query_save_flag() { return 1; }

prevent_insert() {
  write("You don't really want to hide your guild's tuxedo do you?\n");
  return 1; }

drop(str) {
if(worn) {
  write("You must remove your tuxedo before you can discard it.\n");
  return 1; }
  write("The tuxedo smokes and then disintegrates as it leaves your "+
        "hand...\n");
  destruct(this_object());
  return 1; }
