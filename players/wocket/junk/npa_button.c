#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_weight(1);
  set_id("button");
  set_short("NPA Button");
  set_long("A button representing the Nirvana Players Association.\n");
}
