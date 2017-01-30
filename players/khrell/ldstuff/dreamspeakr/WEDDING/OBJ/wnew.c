#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}


reset(arg) {
set_name("attitude");
set_alias("attitude");
set_short("A new attitude on life ("+HIG+"Something New)"+NORM);
set_long(
  "She has a new way of looking at life thru these eyes.  \n"+
  "She appears to be in love.\n");

set_ac(1);
set_type("shield");  /* boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(50);
}

query_save_flag() { return 1; }