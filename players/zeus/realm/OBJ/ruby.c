inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_id("zeus_red_ruby");
  set_alias("ruby");
  set_short("A "+RED+"red"+NORM+" ruby");
  set_long(
"This is a red ruby of exquisite beauty.  Holding it in your hand, it\n"+
"feels slightly warm, as though it has magical properties to it.  It\n"+
"is flawless in it's beauty, however, strangely enough, there is a\n"+
"small round hole in it.  You are sure that it is a very valuble item\n"+
"that could be 'barter'ed for.\n");
  set_weight(0);
  set_value(1500);
}
