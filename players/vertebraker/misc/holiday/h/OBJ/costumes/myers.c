#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("mask");
    set_alias("white mask");
   set_short("A white mask with some brown hair");
   set_long(
      "A short white mask with two eyeholes, and some scraggly brown hair.\n");
   set_costume_title("is Michael Myers [beware]");
   set_my_wear_msg("You slide the evil mask over your head and hear the \"Halloween\" theme song in your head.\n");
   set_room_wear_msg("puts a white mask and some scraggly brown hair on his head.\n");
   set_my_remove_msg(
      "You remove the Michael Myers mask and hear the \"Halloween\" theme song running around in your head.\n");
   set_room_remove_msg(
      "removes the Michael Myers mask and looks totally normal.\n");
   name_str = "Michael Myers";
}

id(str)
{
   return str == "white mask" || str == "mask" || str == "costume";
}
