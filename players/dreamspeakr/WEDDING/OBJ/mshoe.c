#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put them in there, they are rented!\n");
    return 1;
}


reset(arg) {
set_name("black_shoes");
set_alias("shoes");
set_short("Dress Shoes (Black)");
set_long(
  "Black leather dress shoes. \n");

set_ac(1);
set_type("boots");
set_weight(1);
set_value(50);
}

query_save_flag() { return 1; }