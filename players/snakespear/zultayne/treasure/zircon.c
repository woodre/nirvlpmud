#include "/players/snakespear/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
set_id("zircon");
set_alias("qpiece9");
set_short("a scrap of zircon");
set_long(
  "  A small scrap of white zircon.  This has been known to increase\n"+
  "sexual energy or to attract love.  You could carry it to drive away\n"+
  "depression, to increase alertness and for business success.....\n"+
  "Or maybe just sell the scrap for some cash!\n");
set_weight(3);
set_light(1);
set_value(300);
}
