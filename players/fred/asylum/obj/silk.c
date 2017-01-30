inherit "/obj/treasure";
#include <ansi.h>
#include "/players/fred/defines.h"

reset(arg) {
  if(arg) return;
  set_id("silk");
  set_alias("silkygoodness");          
  set_short("A "+CYN+"strand"+NORM+" of spider's "+CYN+"silk"+NORM);
  set_long(
  "  A thin strand of a spiders silk. It might prove to be useful.\n");
  set_weight(1);
  set_value(325);
  set_dest_flag(1);
}

 
