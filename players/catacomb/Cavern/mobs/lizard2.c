#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object blood;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("lizard");
set_race("creature");
set_short("A lizard");
set_long(
  "  The lizard is the means of transportation for the Durkor.  This \n"+
  "lizard has been untamed.  Poison drips from the lizard's sharp fangs\n"+
  "in anticipation of it's next kill.\n");
 
set_level(17);
set_hp(350);
set_al(-250);
set_ac(14);
set_wc(24);
set_aggressive(0);
set_chat_chance(2);
  load_chat("The lizard lets out a loud hiss releasing a volley of venomous ooze.\n");
if(!present("blood"))
 {
    blood = clone_object("/players/catacomb/Cavern/items/blood.c");
    move_object(blood, this_object());
 }
}
heart_beat()
{
   int chance;
   chance = random(30);
   
  ::heart_beat();
   
   if(!environment())
    return;
   if(!ATTACKED)
    return;
   
   if (chance >= 20)
   {
    tell_room(environment(),
      "\n           The lizard rips through your arm with its fangs leaving a\n"+
      "               gash "+HIG+"oozing with its deadly poison"+NORM+".\n");
    ATTACKED->hit_player(random(30)+10);
    return 1;
   }
   else
     return 1;
}
   