inherit "/obj/treasure.c";
#include "/players/softly/closed/ansi.h"

reset(arg){   
  if (arg) return;

  set_id("coldfire");
  set_short("Cold"+HIY+"fire"+NORM);
  set_long("A cool light from a firefly.\n");
  set_weight(1);
  set_value(100);
  set_light(1);
  call_out ("light_out",1200);
}

status light_out () {
  set_light(0);
  write("The light flickers and dies.\n");
  say ("The light fades...\n");
  return 1;
}
