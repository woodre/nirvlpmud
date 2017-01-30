#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}


reset(arg) {
set_name("tie");
set_alias("tie");
set_short("Bow Tie (Black)");
set_long(
  "A traditional black bow tie.\n");

set_ac(0);
set_type("misc");
set_weight(1);
set_value(50);
}

query_save_flag() { return 1; }