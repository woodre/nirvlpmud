#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}

reset(arg) {
set_name("penny");
set_alias("penny");
set_short("1909 D Indian penny for her shoe ("+YEL+"Something Old"+NORM+")");
set_long(
  "How appropriate.  Wouldn't want to have bad luck.\n");

set_ac(1);
set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(50);
}
query_save_flag() { return 1; }
