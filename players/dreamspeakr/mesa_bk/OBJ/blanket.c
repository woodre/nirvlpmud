#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
     set_name("blanket");
     set_alias("blanket");
     set_short(RED+"Bearskin Blanket"+NORM);
     set_long(
       "A thick bearskin blanket.  Looks like it would \n"+
       "keep you quite warm in freezing weather.\n");

     set_ac(4);
     set_type("armor");
     set_weight(4);
     set_value(1000);
}

