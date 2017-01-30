#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("bin laden mask");
   set_short("A scraggly black beard.\nA huge turban.\nDemonic eyes");
   set_long(
      "This is the costume of Public Enemy #1: Osama Bin Laden\n");
   set_costume_title("is that psychopathic moron Osama bin Laden");
   set_my_wear_msg("You put on the mask and immediately feel like humping a camel's ass.\n");
   set_room_wear_msg("puts on an Osama bin Laden mask and humps a camel.\n");
   set_my_remove_msg(
     "You remove the Osama bin Laden mask and begin to see things like a civilized person once again.\n");
   set_room_remove_msg(
      "removes the Osama Bin Laden mask and doesn't look quite so evil.\n");
   name_str = "That idiot Osama Bin Laden";
}

id(str)
{
   return str == "beard" || str == "black beard" || str == "turban" || str == "costume" || str == "mask" || str == "eyes";
}

short() { if(worn) return "A scraggly black beard (worn).\nA huge turban (worn).\nDemonic eyes (worn)"; else return ::short(); }
