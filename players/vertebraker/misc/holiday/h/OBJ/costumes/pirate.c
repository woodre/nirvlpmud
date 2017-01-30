#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("pirate's costume");
   set_short("A pirate's bandanna.\n"+
      "A gold earring");
   set_long(
      "A purple bandanna and a golden earring that you can wear.\n"+
      "It looks just like a Pirate's costume!\n");
   set_costume_title("is a Swashbucklin' Pirate!");
   set_my_wear_msg("You don the bandanna and slide the earring into your\n"+
      "ear... You look just like a pirate!\n");
   set_room_wear_msg("wears a bandanna and a golden earring.\n");
   set_my_remove_msg(
      "You remove the earring and toss the bandanna off.\n"+
      "You smile.\n");
   set_room_remove_msg(
      "removes the earring and bandanna.\n");
   name_str = "A Swashbucklin' Pirate";
}

short()
{
   if(worn) return ("A pirate's bandanna (worn).\n"+
         "A gold earring (worn)");
   else return short_desc;
}

id(str)
{
   return str == "bandanna" || str == "earring" || str == "costume";
}
