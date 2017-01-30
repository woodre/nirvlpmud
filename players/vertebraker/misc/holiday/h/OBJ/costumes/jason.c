#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("hockey mask");
   set_short("A bloodstained hockey mask");
   set_long(
      "A white hockey mask, stained with blood.  It is quite\n"+
      "gruesome to behold.\n");
   set_costume_title("is Jason Voorhees");
   set_my_wear_msg("You place the hockey mask over your head, and feel\n"+
      "a strange need to let bloodshed reign.\n");
   set_room_wear_msg("puts a hockey mask on their head and stalks around the room.\n");
   set_my_remove_msg("You unstrap the hockey mask and everyone gets a good laugh.\n"); 
   set_room_remove_msg(
      "unstraps the hockey mask and you breathe a sigh of relief.\n");
   name_str = "Jason Voorhees";
}

id(str)
{
   return str == "hockey mask" || str == "mask" || str == "costume";
}
