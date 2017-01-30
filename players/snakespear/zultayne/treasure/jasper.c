#include "/players/snakespear/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

set_id("jasper");
set_alias("qpiece3");
set_short("a hunk of "+HIR+"jasper"+NORM);
set_long(
   "  This hunk of jasper is a redish quartz type stone.  Rumor has it\n"+
   "jasper can be worn or held to promote mental processes and to restrain\n"+
   "dangerous desires or whims.\n"+
   "Perhaps selling it would be best..\n");
set_weight(2);
set_value(300);
}
