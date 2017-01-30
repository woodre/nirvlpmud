#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
     set_name("necklace");
     set_alias("necklace");
     set_short(YEL+"Arrowhead Necklace"+NORM);
     set_long(
       "Twined pieces of leather wrap around a sharp arrowhead.  \n"+
       "There appears to be bloodstains on it.\n");

     set_ac(1);
     set_type("necklace"); 
     set_weight(1);
     set_value(500);
}

