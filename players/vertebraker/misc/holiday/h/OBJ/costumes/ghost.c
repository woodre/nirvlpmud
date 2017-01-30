#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("ghost costume");
   set_short(HIW+"A ghost costume"+NORM);
   set_long(
      "A ghost's costume.  Made of a cheap linen sheet\n"+
      "and a pillowcase with two holes poked in it for\n"+
      "where your eyes will go.\n");
   set_costume_title("is a "+HIW+"Ghost"+NORM+"!");
   set_my_wear_msg("You put the pillowcase over your head, and wrap the sheet\n"+
      "around your body like a cape.  You really look spooky!\n");
   set_room_wear_msg("puts a pillowcase over their head, and\n"+
      "wears a simple sheet around their body.\n");
   set_my_remove_msg(
      "You unhappily remove the ghost costume and everybody sees who you are.\n");
   set_room_remove_msg(
      "unhappily removes the ghost costume.\n");
   name_str = HIW+"A ghost"+NORM;
}
