#include "/players/snakespear/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIW+"The Teacher"+NORM);
set_alias("teacher");
set_alt_name("teach");
set_race("demon");
set_long(HIR+
  "  This is the Teacher.  Although he is very large and bulky, he looks\n"+
  "quite agile.  This is no teacher you have ever seen.  He has large\n"+
  "horns extending from his massive forehead and eyes that seem to pierce\n"+
  "through your soul.  His only purpose in life is to discipline those\n"+
  "who refuse to take time to read or look at their surroundings.  He\n"+
  "waits for you to make the slightest aggression towards him, so he can\n"+
  "unleash his facets of pain onto you.  You wonder if such a puny person\n"+
  "like yourself could defeat a demon of such magnitude... \n"+
  "\t\tBut do you have much choice??\n\n"+NORM);

set_level(25);
set_hp(3500);
set_al(1000+random(-2000));
set_wc(65);
set_ac(45);
set_heal(20,10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("Demonic laughter floods your already occupied mind. \n");
set_a_chat_chance(5);
  load_a_chat(HIW+"You are fully healed by Someone.\n"+NORM);

set_chance(25);
set_spell_dam(75);

set_spell_mess1(
  HIR+"\n\n\t\tS  M  A  C  K ! !\n\n"+NORM);
set_spell_mess2(
  HIG+"\n\n\n\t\tTeach says: YOUR ASS BELONGS TO ME!!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(5000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIW+"\n\n\tThe Teacher has been vanquished!!\n\n\n"+NORM);
      return 0;
      }
