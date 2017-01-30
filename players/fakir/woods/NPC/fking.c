#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_name("king");
set_alias("fairy");
set_race("fairy");
set_short(CYAN+"Fairy King"+OFF);
set_long(
  "Agbernon, King of the united southern fairy folk, is rather rotund, no\n"+
  "doubt from the rich diet he enjoys due to his station in life as King.\n"+
  "He is as ancient as this woods, and has reigned as sovereign lord for\n"+
  "many turnings of the wheel.\n");

move_object(clone_object("/players/fakir/woods/WEP/scepter.c"),
(this_object()));
command("wield scepter",this_object());

set_level(15);
set_hp(170 +random(60));
set_al(500);
set_wc(15 +random(6));
set_ac(9 +random(5));
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("The King speaks: Have you seen the Queen? I must find her soon.\n");
set_a_chat_chance(5);
  load_a_chat("The King speaks: I do not wish to waste my magic in a simple finding spell...\n");
set_a_chat_chance(5);
  load_a_chat("The King searches the bushes and trees for his Queen.\n");

set_chance(10);
set_spell_dam(8);

set_spell_mess1(
  "The King waves his "+WHITE+"Scepter of Light"+OFF+" and your skin begins to wrinkle.\n");
set_spell_mess2(
  "The King waves his "+WHITE+"Scepter of Light"+OFF+" and some life essence is draw into the crystal shaft.\n");


}

monster_died() {
  
  tell_room(environment(this_object()),
	"The King transfers his spirit to the Scepter as his once immortal body falls.\n");
return 0; }
