#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())
object belt;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("spirit");
set_race("undead");
set_short("A wandering spirit);
set_long(
  "  Before you stands the lifeless body of a fallen Shamot.  In her\n"+
  "prime she was one of the elders of the tribe.  After going on a hunt\n"+
  "to find the nomad Yeroc, she met an untimely end by the claws of one\n"+
  "of the many creatures stalking the forest.  Now she only wishes to \n"+
  "extract her revenge on the living.\n");
 
set_level(19);
set_hp(500);
set_al(0);
set_ac(16);
set_wc(28);
add_money(random(2000)+2000)
set_dead_ob(this_object());
set_aggressive(1);
set_chance(6);
set_spell_dam(10);
set_spell_mess1(
  "The wraith draws in close to "+attacked+" and sucks the living essence from them.\n");
set_spell_mess2(
  "The wraith draws near, then sucks the life from your body.\n");

}
 
heart_beat()
{
   int chance;
   chance = random(20);
 ::heart_beat();

   if (!environment())
      return;
   if (!attacked)
      return;
   if (chance >= 15)
   {
     write("\n      The spirit takes a swipe at you \n"+
             "   Slowly you feel your life force leave.\n");
     say("The spirit swipes at "+attacked+" they appear drained and weak.\n");
     attacked->hit_player(random(15) + 10, "other|dark");
     return 1;
   }
}
