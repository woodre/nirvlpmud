#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM+" ("+HIK+"Warped Passage"+NORM+")");
   set_long(
"This passageway is dark and forboding.  An almost oppresive atmosphere\n"+
"assails you from every angle.  The air is thin and carries a bitter and\n"+
"coppery tang to it.  The stone here seems relatively solid, yet also\n"+
"seems to be coated in a sticky substance.  The 'timber' beams above\n"+
"appear to be unstable, then you note they are actually writhing like\n"+
"like they were alive.\n"); 
   set_light(1);
   add_listen("main", "You hear a constant chorus of scream and moans\n");
   add_listen("screams", "You hear screams that chill your soul\n");
   add_listen("moans", "You hear spine chilling moans\n");
   add_smell("main", "You smell a dank coppery scent\n");
   add_smell("scent", "You smell the descrete tang of blood in the air\n");
   items = ({
             "stone", "It appears to be solid",
             "substance", "This is nothing short of a mixture of blood and ichor",
             "timber", "They look stable at first then slowly begin to move as if alive",
             "beams", "Though resembling wood they move with a life of their own.",
             "passageway", "Light does not seem to carry far, in fact the dark feeds on it",
             });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm8.c", "out",
         "players/khrell/area/goblins/gobrm14.c", "in"
         });
}
