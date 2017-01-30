#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}


reset(arg) {
set_name("cummerbund");
set_alias("cummerbund");
set_short("Silk Cummerbund (Black)");
set_long(
  "A cummerbund made from a high quality silk. \n");

set_ac(1);
set_type("shield");
set_weight(1);
set_value(50);
}

query_save_flag() { return 1; }