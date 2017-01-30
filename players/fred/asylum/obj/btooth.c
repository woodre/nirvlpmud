inherit "/obj/treasure";
#include <ansi.h>
#include "/players/fred/defines.h"

reset(arg) {
  if(arg) return;
  set_id("tooth");
  set_alias("poopy21");          
  set_short("A sharp tooth");
  set_long(
  "  A small white tooth that almost resembles a needle.\n");
  set_weight(1);
  set_value(425);
  set_dest_flag(1);
}

 
