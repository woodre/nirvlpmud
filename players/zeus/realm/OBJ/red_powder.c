inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_short("A small bag of "+RED+"red powder"+NORM);
  set_long(
"This is a small brown bag filled with a dark red powder.  It is tied\n"+
"closed with a small piece of leather.\n");
  set_weight(1);
  set_value(1500);
}

id(str){ return str == "powder" || str == "bag of powder" ||
str == "zeus_red_powder"; }
