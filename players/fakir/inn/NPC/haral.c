#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object armor, weapon, treasure;
  ::reset(arg);
  if(arg) return;

set_name("haral");
set_alias("blacksmith");
set_alt_name("luhhan");
set_race("human");
set_short("Haral Luhhan");
set_long(
  "With arms roped heavy with muscle and as large as most mens legs,\n"+
  "the village blacksmith would be a match for any man.  His heavy\n"+
  "leather apron has the burn marks of many hours at the forge, and\n"+
  "his hammer hangs at his side through a loop in the apron.  He is\n"+
  "a member of the village council, and is concerned about the number\n"+
  "of trolloc's seen of late, roaming the countryside. \n");

set_level(18);
set_hp(410 + random (50));
set_al(0);
set_wc(20 + random (6));
set_ac(11 + random (6));
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Haral says: There have been so many trolloc's this year.  Be very careful. \n");
  load_chat("Haral shrugs and says: This does not bode well for our village...not one bit. \n");
  load_chat("The blacksmith frowns and wipes his hands on his heavy apron. \n");
  load_chat("Haral mumbles: It is the work of the Dark One, I just know it... \n");
 
set_a_chat_chance(15);
  load_a_chat("Haral says: I will crush you with my mighty Forge Hammer. \n");
  load_a_chat("The blacksmith smashes you on the head with his hammer. \n");
  load_a_chat("Haral blocks your blow and knocks you flat. \n");

set_chance(10);
set_spell_dam(8);

set_spell_mess1(
  "The blacksmith crushes his attacker with his mighty forge hammer. \n");
set_spell_mess2(
  "Haral crushes you with his mighty forge hammer. \n");

armor=clone_object("/players/fakir/inn/ARM/apron.c");
move_object(armor,this_object());
weapon=clone_object("/players/fakir/inn/WEPS/fhammer.c");
move_object(weapon,this_object());
treasure=clone_object("/players/fakir/inn/OBJ/purse3.c");
move_object(treasure,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
   "Haral drops the mighty hammer and gasps his last breath.\n");
    return 0; }
