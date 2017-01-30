#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put them in there, they are rented!\n");
    return 1;
}


reset(arg) {
set_name("satin_shoes");
set_alias("shoes");
set_short("White satin shoes");
set_long(
  "Pearl white with small roses on the tips. \n");

set_ac(1);
set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(50);
}
query_save_flag() { return 1; }
