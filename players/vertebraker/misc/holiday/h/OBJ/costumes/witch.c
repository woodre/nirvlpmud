#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("witch hat");
   set_short(BOLD+BLK+"black witch's hat"+NORM);
   set_long(
      "A thick silken black witch's hat.  Underneath you spy\n"+
      "a thick green nose.\n");
   set_costume_title("is an "+BOLD+BLK+"Ugly Witch"+NORM+"!");
   set_my_wear_msg("You put the hat over your head and apply a long nose.\n"+
      "You cackle evilly!\n");
   set_room_wear_msg("puts a witch's hat on their head, applies a\n"+
      "long green nose, and cackles evilly!\n");
   set_my_remove_msg(
      "You mutter under your breath and remove the hat...\n");
   set_room_remove_msg(
      "removes the witch's hat...\n");
   name_str = "An ugly witch";
}

id(str)
{
   return str == "hat" || str == "costume" || str == "witch hat" || str == "witch's hat";
}
