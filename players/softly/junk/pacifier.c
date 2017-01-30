#include "/players/softly/closed/ansi.h"
inherit "/obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("pacifier");
   set_short(HIM+"Maggie's Pacifier"+NORM);
   set_alias("pacifier");
   set_long("A special pacifier, just for Maggie.\n");
   set_weight(0);
   set_value(0);
   save_flag=0;
}
