#include "/players/snakespear/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

set_id("ruby");
set_alias("qpiece7");
set_short("a portion of "+HIR+"ruby"+NORM);
set_long(
  "  This portion of ruby is indeed a very valueable treasure.\n"+
  "The ruby is a perfect specimen of a deep, blood-red hue stone\n"+
  "that is known for it's indication of coming success in business\n"+
  "or harvest for the owner.\n");
set_light(1);
set_weight(2);
set_value(300);
}
