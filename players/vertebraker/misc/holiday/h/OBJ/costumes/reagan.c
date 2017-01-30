#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("reagan mask");
   set_short("A thick, rubbery mask of Ronald Reagan");
   set_long(
      "A thick, rubbery, folded mask of Ronald Reagan, the president\n"+
      "who 'guided' our country through the 1980s.\n");
   set_costume_title("is President Ronald Reagan");
   set_my_wear_msg("You place the mask of Ronald Reagan over your face\n"+
      "and feel like winning one for the Gipper.\n");
   set_room_wear_msg("puts a Ronald Reagan mask on and immediately feels\n"+
      "like winning one for the Gipper.\n");
   set_my_remove_msg("You take off the Ronald Reagan mask and breathe clean air once again.\n");
   set_room_remove_msg(
      "removes the Ronald Reagan mask and coughs quietly.\n");
   name_str = "President Ronald Reagan";
}

id(str)
{
   return str == "ronald reagan" || str == "mask" || str == "costume";
}
