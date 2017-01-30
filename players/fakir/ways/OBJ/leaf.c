#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("leaf");
   set_short("An Avendesora Leaf");
   set_long(
   "     This is a symbolic leaf from the legendary 'tree of life'.\n"+
   "It will act as a 'key' to the waygate behind this rock wall.\n"+
   "Simply 'place leaf' in the small depression.  The waygate will\n"+
   "open and you will enter into the ways.  Beware, there are dangers\n"+
   "unknown within the ways, and dark passages of decay.  To escape\n"+
   "the passages of the ways, you must find another waygate.\n");
   set_weight(1);
   set_value(0);
}
