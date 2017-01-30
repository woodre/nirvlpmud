#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("clinton mask");
   set_short("A thick, rubbery mask of Bill Clinton");
   set_long(
      "A thick, rubbery, folded mask of Bill Clinton, the president\n"+
      "who 'guided' our country through the 1990s.\n");
   set_costume_title("is William Jefferson Clinton");
   set_my_wear_msg("You put the mask over your face and begin playing the sax...\n");
   set_room_wear_msg("puts a Clinton mask and grabs a saxophone.\n");
   set_my_remove_msg(
      "You remove the Clinton mask and reach for a cigar...\n");
   set_room_remove_msg(
      "removes the Clinton mask and reaches for a cigar...\n");
   name_str = "Bill Clinton";
}

id(str)
{
   return str == "clinton mask" || str == "mask" || str == "costume";
}
