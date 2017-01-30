#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("gauze");
   set_short("50' of gauze");
   set_long(
      "A huge roll of gauze, that would wrap all around\n"+
      "your body if you were wearing it.\n");
   set_costume_title("is a "+HIW+"Mummy"+NORM+"!");
   set_my_wear_msg("You carefully wrap the gauze all around yourself..\n\n"+
      "You look just like in the movies!\n");
   set_room_wear_msg("carefully wraps the gauze all around their body....\n\n"+
      "They look pretty damn scary!\n");
   set_my_remove_msg(
      "You carefully unwrap all the gauze....\n");
   set_room_remove_msg(
      "unwraps all the gauze...\n");
   name_str = "Mummy";
}

id(str)
{
   return str == "gauze" || str == "costume";
}
