#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object treasure;
  ::reset(arg);
  if(arg) return;

set_name("cenn");
set_alias("thatcher");
set_alt_name("buie");
set_race("human");
set_short("Cenn Buie");
set_long(
  "As gnarled and dark as an old root, Cenn is the village thatcher.  He\n"+
  "has been busy this winter keeping up with the harsh weather and storms.\n"+
  "He wonders if winter will ever end here in the Two Rivers.  He is very\n"+
  "concerned about the weather, and waits to express his feelings to the\n"+
  "village council, of which he is a member. \n");

set_level(17);
set_hp(380 + random (50));
set_al(-100);
set_wc(20 + random (4));
set_ac(10 + random (5));
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Cenn says: There have been so many storms this year.  It is odd. \n");
  load_chat("Cenn shrugs and says: We are in for a late spring, I feel it in my bones. \n");
  load_chat("Cenn frowns and puffs on his briar pipe. \n");
  load_chat("Cenn mumbles: It is the work of the Dark One, I just know it... \n");
 
set_a_chat_chance(15);
  load_a_chat("Cenn says: Don't kill me, I am just a simple thatcher. \n");
  load_a_chat("Cenn pokes you in the eye with his pipe stem. \n");
  load_a_chat("Cenn sidesteps your blow and hits you in the jaw. \n");

set_chance(10);
set_spell_dam(8);

set_spell_mess1(
  "Cenn spits tabac juice in his attacker's face. \n");
set_spell_mess2(
  "Cenn spits tabac juice in your face and you have to blink. \n");

treasure=clone_object("/players/fakir/inn/OBJ/pipe.c");
move_object(treasure,this_object());
treasure=clone_object("/players/fakir/inn/OBJ/tabac.c");
move_object(treasure,this_object());
treasure=clone_object("/players/fakir/inn/OBJ/purse1.c");
move_object(treasure,this_object());


}

monster_died() {
  tell_room(environment(this_object()),
	"Cenn gasps a last raspy breath and falls dead at your feet.\n");
return 0; }
