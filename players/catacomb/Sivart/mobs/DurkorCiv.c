#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("durkor");
set_alt_name("civilian");
set_race("durkor");
set_short("A durkor civilian");
set_long(
  "  \n"+
  "\n"+
  "\n"+
  "\n");
 
set_level();
set_hp();
set_al();
set_dead_ob(this_object());
set_aggressive(0);
add_money();
set_chat_chance();
  load_chat("\n");
set_a_chat_chance();
  load_a_chat("\n");
  load_a_chat("\n");
set_chance();
set_spell_dam();
set_spell_mess1(			what they see
  "\n");
set_spell_mess2(			what you see
  "\n");

sword = clone_object("players/catacomb/Cavern/items/Dscimitar.c");
move_object(sword, this_object());
command("wield sword",this_object());
set_wc(22 + random(4));

boots = clone_object("/players/catacomb/Cavern/items/Dboots.c");
move_object(boots, this_object());
init_command("wear boots", this_object());
set_ac(15);

}
  