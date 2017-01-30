#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("feather");
  set_alias("golden feather");
  set_short(HIY+"A golden feather"+OFF);
  set_long("    This is the golden feather of a Chicobo.  Its yellow shimer reflects\n"+
  "the light making beautiful rays of color.  It seems very valuable.\n");
  set_value(300);
  set_weight(1);
}
