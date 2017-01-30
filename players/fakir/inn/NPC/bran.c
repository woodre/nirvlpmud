#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object treasure, armor;
  ::reset(arg);
  if(arg) return;

set_name("bran");
set_alias("mayor");
set_alt_name("bran");
set_race("creature");
set_short("Bran al'Vere");
set_long(
  "Although nearly as wide as he is tall, Bran is quick of step and\n"+
  "fast with his hands.  A sparse fringe of greyish hair rings his\n"+
  "otherwise bald head.  He wears his shirt with sleeves rolled up\n"+
  "and has a spotless white apron wrapped around him.  A silver scales\n"+
  "in the form of a medallion hangs on his chest, the symybol of his\n"+
  "position in the village as mayor and head of the town council.  He\n"+
  "is not at all pleased to see you behind his bar and this close to\n"+
  "his cashbox.\n");

set_level(20);
set_hp(550);
set_al(0);
set_wc(30);
set_ac(17);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Bran says: You really should not have jumped my bar. \n");
  load_chat("Bran says: Get back I say. Stay away from my cashbox! \n");
  load_chat("Bran says: I am the mayor of this village, and I will have your head! \n");
  load_chat("Bran says: I thought you might be a thief. Now you will die...\n");
set_a_chat_chance(15);
  load_a_chat("Bran says: Your puny weapon cannot hurt me. I have fought tougher than you. \n");
  load_a_chat("Bran slaps you twice in the blink of an eye. \n");
  load_a_chat("Bran sidesteps your weapon and hits you in the ribs. \n");

set_chance(10);
set_spell_dam(25);

treasure=clone_object("/players/fakir/inn/OBJ/bartowel.c");
move_object(treasure,this_object());
armor=clone_object("/players/fakir/inn/ARM/medallion.c");
move_object(armor,this_object());
}
heart_beat() {
  if (attacker_ob) { 
  set_spell_mess1(
    "Bran bearhugs "+attacker_ob->query_name()+" and squeezes the lifebreath from his body. \n");
  set_spell_mess2(
    "Bran wraps his massive arms around your chest and squeezes the breath from your lungs. \n");
}
::heart_beat();
}

init(){
::init();
add_action("cmd_take","take");
add_action("cmd_take","get");
add_action("cmd_take","grab");
}
cmd_take(arg) {
if(arg=="cashbox") {
write("Bran slaps your hand and you cannot take the cashbox.\n");
return 1;
}}

monster_died() {
   tell_room(environment(this_object()),
	"Bran puts his bloody hands to his heart and falls.\n");
return 0; }
