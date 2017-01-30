#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";

reset(arg) {
  if(arg) return;
set_short("An arrow sign") ;
set_long ("The sign points to north:  Fantasy / Ceres  wedding.\n");
}

id(str) { return str =="sign" || str =="arrow" || str=="arrow sign" ;}

get(stri) {
    if(stri == "sign" ) {
        notify_fail("Please, dont remove this sign from this room. \n");
        return 0;
    }
    return 0;
}

