#include "/players/vertebraker/define.h"
inherit ITEM;
reset(arg) {
  if(arg) return;
  set_id("skull scepter");
  set_alias("scepter");
  set_short("A skull-headed scepter");
  set_long(
"The ugly, deformed shrunken head on this scepter seems to resemble the head\n"+
"of an ancient Sumerian warrior- their heads were shrunk after death as a result\n"+
"of the ancient pagan religion and funerary rites they endured.\n");
  set_weight(2);
  set_value(850);
  }
