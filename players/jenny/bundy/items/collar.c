#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
    if(arg) return;
    set_name("collar");
set_id("collar");
set_ac(1);
set_weight(1);
set_value(800);
    set_type("amulet");
    set_short(""+YEL+"Buck Bundy's collar"+NORM+"");

    set_long(
      "This is the collar that the Bundy's dog Buck wears.\n"+
      "If it's good enough for the Bundy's dog to wear, you\n"+
     "could wear it too.\n");
}
