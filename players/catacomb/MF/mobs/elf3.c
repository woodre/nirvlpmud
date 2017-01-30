#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object dagger;
object pole;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("elf");
set_race("elf");
set_short("A Shamot elf");
set_long(
  "  You look upon one of the Shamot, relaxing in front of the\n"+
  "creek.  He has a small fishing pole with the string already\n"+
  "in the water.  He sits lazily just enjoying the day.\n");
 
set_level(15);
set_hp(250);
set_al(500);
set_ac(12);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(3);
  load_chat("The elf whistles an old elven tune.\n");
set_a_chat_chance(2);
  load_a_chat("The elf grabs for the pole thinking he has a bite, but then finds it's just the waves.\n");
  load_a_chat("The elf says: Beautiful day for fishing, wouldn't you say?\n");

dagger = clone_object("/players/catacomb/MF/items/dagger.c"); 
move_object(dagger, this_object());
command("wield dagger", this_object());
set_wc(20);

pole = clone_object("/players/catacomb/Cavern/items/pole.c"); 
move_object(pole, this_object());

}   