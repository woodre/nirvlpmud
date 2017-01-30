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
 
set_level(15);
set_hp(250);
set_al(-100);
set_ac(12);
set_wc(20);
set_aggressive(0);
set_chat_chance(2);
  load_chat("The lizard lets out a loud hiss releasing a volley of venomous ooze.\n");
if (!present("blood"))
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
   
   if (chance >= 25)
   {
     tell_room(environment(),
      "\n           The lizard bites down hard on "+ATTACKED->query_name()+"'s arm leaving a deep\n"+
      "               gash "+HIG+"oozing with its deadly poison"+NORM+".\n");
     ATTACKED->hit_player(random(20)+ 5);
     return 1;
   }
   else
     return 1;
}
