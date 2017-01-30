#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
     set_name("apron");
     set_alias("apron");
     set_short(CYN+"Hand Beaded Tribal Apron"+NORM);
     set_long(
       "Beautiful turquiose beads decorate this traditional \n"+
       "indian apron.  Anasazi women and men took great pride \n"+
       "in its crafting.\n");

     set_ac(1);
     set_type("misc"); 
     set_weight(1);
     set_value(890);
}

