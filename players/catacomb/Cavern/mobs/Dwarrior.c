#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())
object sword, boots;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("warrior");
set_race("creature");
set_short("A Durkor warrior");
set_long(
  "  A slim but muscular humanoid.  The warrior's dark scarred face shows\n"+
  "that he has seen many battles, but very few in the light of day.  Trained\n"+
  "in the arts of mortal combat since he was a small Durkor child, he is \n"+
  "unaffraid of anything or anyone.\n");
 
set_level(17);
set_hp(325 + random(50));
set_al(-500);
set_dead_ob(this_object());
set_aggressive(0);
add_money(500 + random(300));
set_chat_chance(3);
  load_chat("The warrior urges you to attack him.\n");
set_a_chat_chance(4);
  load_a_chat("The warrior grins evilly at you.\n");
  load_a_chat("The warrior eyes you over looking for weak points.\n");
set_chance(15);
set_spell_dam(28);
set_spell_mess1(
  "The warrior slices through his foes defenses scoring a strong hit.\n");
set_spell_mess2(
  "The warrior slices through your defense causing a vicious laceration.\n");

sword = clone_object("players/catacomb/Cavern/items/Dscimitar.c");
move_object(sword, this_object());
command("wield sword",this_object());
set_wc(22 + random(4));

boots = clone_object("/players/catacomb/Cavern/items/Dboots.c");
move_object(boots, this_object());
init_command("wear boots", this_object());
set_ac(15);

}
  