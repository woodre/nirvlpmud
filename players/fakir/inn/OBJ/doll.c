#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("doll");
   set_short("A Rag Doll");
   set_long(
   "Made from old scraps of worn out clothing, this doll is\n"+
   "none-the-less a work of art.  Her face is stiched with\n"+
   "silk thread, and the button eyes are made of ivory inset\n"+
   "with a sparkling jewel. \n");
   set_weight(1);
   set_value(200);
}

