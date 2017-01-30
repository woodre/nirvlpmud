#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object shield, dagger;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("guard");
set_race("creature");
set_short("A Durkor guard");
set_long(
  "  One of the sentinels of the Durkor city.  He stands before you \n"+
  "poised to attack anyone trying to enter the city.  A strange magical\n"+
  "aura surrounds him adding to his already great battle prowess.\n");
 
set_level(17);
set_hp(400);
set_al(-500);
set_ac(14);
set_wc(25);
set_dead_ob(this_object());
set_aggressive(0);
add_money(500 + random(1000));
set_chat_chance(5);
  load_chat("Guard says: No surface dwellers shall pass into our city.\n");
set_chance(20);
set_spell_dam(25);
set_spell_mess1(
  "The guard's enemy twitches violently as a lightning bolt strikes them.\n");
set_spell_mess2(
  "The guard points at you and utters an incantation.  "+HIW+"Lightning"+NORM+"\n"+
  "bursts from his hand.  You twitch violently from the electrical current.\n");
}
heart_beat()
{
  int HEAL, HEALAMT;
  HEALAMT = random(20);
  HEAL = random(100);
  ::heart_beat();
  if (!environment())
  {  return;  }
  if (!ATTACKED)
  {  return;  }
  if (HEAL >= 90)
  {
    tell_room(environment(),
      "\n\nThe durkor guard utters something in a strange language.\n\n");
    hit_point = hit_point + HEALAMT;
    return 1;
  }
  return 1;
}
     
monster_died(){
  object shield, dagger;
  tell_object(ATTACKED,
    "The Durkor guard drops his shield and dagger as he falls to the ground dead.");
  shield = clone_object("/players/catacomb/Cavern/items/Dgshield.c");  
  move_object(shield, this_object());
  dagger = clone_object("/players/catacomb/Cavern/items/Dgdagger.c");
  move_object(dagger, this_object());
}   