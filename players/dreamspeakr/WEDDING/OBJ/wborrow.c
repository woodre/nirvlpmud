#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}


reset(arg) {
set_name("cameo");
set_alias("cameo");
set_short("Mothers cameo ("+RED+"Something Borrowed"+NORM+")");
set_long(
  "Passed from generation to generation.  Her mother would kill her \n"+
  "if she didnt return this.\n");

set_ac(1);
set_type("amulet");
set_weight(1);
set_value(50);
}

query_save_flag() { return 1; }