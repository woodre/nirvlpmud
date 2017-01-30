#include "/players/snakespear/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
set_id("kunzite");
set_alias("qpiece4");
set_short("a bit of "+HIY+"kunzite"+NORM);
set_long(
  "  This is a lilac-shaded bit of kunzite.  It's known for its usefullness\n"+
  "for attracting love or to induce relaxation.  The bit seems to emit a\n"+
  "peaceful vibration, which is overwhelming by just gazing at it.\n"+
  "It's worth just "+HIY+"GLOWS"+NORM+".\n");
set_weight(2);
set_light(2);
set_value(300);
}
