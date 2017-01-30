#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
     set_name("headdress");
     set_alias("headdress");
     set_short(HIB+"Wocawanee's Headdress"+NORM);
     set_long(
       "This colorful headdress belonged to the chief of the Anasazi \n"+
       "tribe.  Passed down from generation to generation in the \n"+
       "tradition of the ancient ones.\n");

     set_ac(1);
     set_type("helmet");
     set_weight(1);
     set_value(500);
}

