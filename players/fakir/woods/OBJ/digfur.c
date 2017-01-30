#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("fur");
   set_short("Soft digger fur");
   set_long(
   "This is the soft fur of a Brown Digger found in some parts of the realm\n"+
   "of time.  It is highly valued in the shops and trading posts of the world.\n");
   set_weight(1);
   set_value(150);
}

