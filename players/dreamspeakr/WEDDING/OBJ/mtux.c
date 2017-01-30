#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}


reset(arg) {
set_name("tuxedo");
set_alias("tuxedo");
set_short("White Tuxedo");
set_long(
  "A finely tailored double breasted white tuxedo with tails.  \n");

set_ac(1);
set_type("armor");
set_weight(1);
set_value(50);
}
query_save_flag() { return 1; }
