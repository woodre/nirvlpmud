#include "../../std.h"

inherit COSTUME;

reset(x)
{
   if(x) return;
   ::reset();
   set_id("rubbery costume");
   set_short("A rubbery costume");
   set_long(
      "A rubbery costume detailed with fake blood and gore.\n"+
      "Pus floats comes out of infested wounds, and it is\n"+
      "quite hideous looking.\n");
   set_costume_title("is a "+BOLD+BLK+"Corpse"+NORM+" (ick)");
   set_my_wear_msg("You apply the makeup and put on the corpse\n"+
      "suit.  You now look incredibly disgusting.\n");
   set_room_wear_msg("applies some fake blood and shadow, and wears a rubbery\n"+
      "mask.  They really look disgusting!\n");
   set_my_remove_msg(
      "You peel off the rubbery mask and laugh as everyone looks at you\n"+
      "in disgust.\n");
   set_room_remove_msg(
      "peels off the rubbery layer of skin and looks normal again.\n");
   name_str = "A corpse";
}

extra_look()
{
   return USER->QN+" looks just like a corpse!";
}
