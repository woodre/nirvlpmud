#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("dragonskin");
   set_short(RED+"dragonskin"+NORM);
   set_long(
      "A red, scaly, shardak costume.  A dragon-like mask folds over\n"+
      "the wearer's head, with two eyeholes.  Finally, a thick red\n"+
      "pointed tail finishes off the costume.\n");
   set_costume_title("is a "+RED+"Servant of Shardak"+NORM+"!");
   set_my_wear_msg("You wrap the costume around your body, \n"+
      "and peer at the world through the eyes of a Shardak.\n");
   set_room_wear_msg("wraps a costume around their body and becomes a Shardak.\n");
   set_my_remove_msg("You peel back the dragonskin costume and smile.\n");
   set_room_remove_msg(
      "removes the dragonskin and smiles.\n");
   name_str = "Servant of Shardak";
}
