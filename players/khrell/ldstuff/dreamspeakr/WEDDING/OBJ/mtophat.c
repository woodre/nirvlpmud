#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}


reset(arg) {
set_name("tophat");
set_alias("tophat");
set_short("White Tophat");
set_long(
  "My....you look so stylish and sexy in this white tophat! \n");

set_ac(1);
set_type("helmet");
set_weight(1);
set_value(50);
}

query_save_flag() { return 1; }