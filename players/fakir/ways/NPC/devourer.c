#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_name("devourer");
set_alias("demon");
add_money(3000+random(1000));
set_race("ancient");
set_short(BOLD+GREEN+"A Devourer"+OFF);
set_long(
  "Rotting flesh hangs in strips from a jumbled collection of disjointed\n"+
  "bones, animated by pure evil.  A gaping maw opens and closes in anticipation\n"+
  "of a warm meal.  In some former age, this regrettable pile of refuse was a\n"+
  "great warrior, who entered the Ways to do battle with evil.  He lost, as do\n"+
  "all who enter the Ways...eventually.\n");

move_object(clone_object("/players/fakir/ways/WEP/blade.c"),
(this_object()));
init_command("wield blade");

set_level(20);
set_hp(550);
set_al(-1000);
set_wc(30);
set_ac(17);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("The Devourer growls: "+BOLD+RED+"I hunger..."+OFF+"\n");
set_a_chat_chance(15);
  load_a_chat("The Devourer shifts slightly to the left...you miss your attack.\n");
  load_a_chat("A chunk of rotting flesh falls to the ground with a loud 'plop'...\n");
  load_a_chat("There is a rattle of bone against bone...you hear a loud *S N A P*...\n");
set_chance(15);
set_spell_dam(25);

set_spell_mess1(
  "The Devourer "+BLUE+"swings his blade in a wide arc and it"+OFF+" "+RED+"S L A S H E S"+OFF+" "+BLUE+"flesh and bone."+OFF+"\n");
set_spell_mess2(
"The Devourer "+BLUE+"swings his blade in a wide arc and it"+OFF+" "+RED+"S L A S H E S"+OFF+" "+BLUE+"flesh and bone."+OFF+"\n");
}

monster_died() {
  
  tell_room(environment(this_object()),
	"The flesh dissolves from the Devourer's bones and they fall in a heap.\n");
return 0; }
