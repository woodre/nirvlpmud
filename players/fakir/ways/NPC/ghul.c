#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("ghul");
set_alias("demon");
set_race("demon");
set_short("Ghul");
set_long(
  "Nothing meets your eye but a black cloak, hanging as if by\n"+
  "magic in the air.  No face can be seen within the depths of\n"+
  "the hood, no hands at the end of the robe's sleeves, no legs\n"+
  "nor feet beneath.  A small coin purse, tied fast with stout\n"+
  "cord to the cloak's sash catches your eye.\n");

set_level(18);
set_hp(450);
set_al(-850);
set_wc(26);
set_ac(15);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("The air around you becomes foul to the smell and bitter on your tongue.\n");
  load_chat("A heavy weight presses down upon you.  It becomes difficult to breath.\n");
set_a_chat_chance(15);
  load_a_chat("The demon's eyes flash red momentarily within the cowel of the cloak.\n");
  load_a_chat("The cloak billows outward and a gust of acid air burns your skin and eyes.\n");
  load_a_chat("The cloak contracts and you feel the air sucked from your lungs.\n");

set_chance(15);
set_spell_dam(20);

set_spell_mess1(
  "The demon cloak flashes in blue flame for a moment.  Fire licks out from its folds.\n");
set_spell_mess2(
  "The demon cloak flashes in blue flame for a moment.  Fire burns in your lungs.\n");

}

monster_died() {
  move_object(clone_object("/players/fakir/ways/OBJ/dpurse.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
	"The demon shrieks a final time and dies, dropping the coinpurse from his cloak.\n");
return 0; }
