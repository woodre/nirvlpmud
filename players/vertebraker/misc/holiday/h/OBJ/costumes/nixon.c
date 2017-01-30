#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("nixon mask");
   set_short("A thick, rubbery mask of Richard Nixon");
   set_long(
      "A thick, rubbery, folded mask of Richard Nixon, the president\n"+
      "who 'guided' our country through the 1980s.\n");
   set_costume_title("is Richard 'Tricky Dick' Nixon");
   set_my_wear_msg("You put the mask over your face and flash a V for\n"+
      "victory with your left hand.\n");
   set_room_wear_msg("puts a Nixon mask on and flashes a V for victory.\n");
   set_my_remove_msg(
      "You remove the Nixon mask and warble out a few words.\n");
   set_room_remove_msg(
      "removes the Nixon mask and leaves the office of the President of the United States.\n");
   name_str = "Richard Nixon";
}

id(str)
{
   return str == "nixon mask" || str == "mask" || str == "costume";
}
