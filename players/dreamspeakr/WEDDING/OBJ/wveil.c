#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}

reset(arg) {
set_name("lace_veil");
set_alias("veil");
set_short("Lace veil");
set_long(
  "This long lace veil covers the face of a woman in love.  You \n"+
  "can barely make out the beautiful woman underneath it.  Small \n"+
  "patterns of roses compliment the fine lace in which it was made.\n");

set_ac(1);
set_type("helmet");
set_weight(1);
set_value(50);
}
query_save_flag() { return 1; }
