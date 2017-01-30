#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object ;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("archer");
set_alt_name("elf");
set_race("elf");
set_short("An Elven Archer");
set_long(
  "  One of the former guards stands before you.  His face has a scar\n"+
  "down his left cheek, a memento of his former profession.  Now he\n"+
  "has chosen to lay down his blade in exchange for a bow so he may\n"+
  "live out his remaining days without the horror of the bloodshed of\n"+
  "mortals.\n");
 
set_level(15);
set_hp(250);
set_al(550);
set_ac(12);
add_money(250);

set_aggressive(0);
set_chat_chance(2);
  load_chat("The elf shoots an evil glare in your direction\n");
set_a_chat_chance(1);
  load_a_chat("The archer asks: Have you seen that traitor Yeroc?\n");
  load_a_chat("The elf sips some of Shamot's finest.\n");
  load_a_chat("The archer brags: My bow never misses the mark.\n");

bow = clone_object("/players/catacomb/MF/items/bow.c"); 
move_object(bow, this_object());
command("wield bow", this_object());
set_wc(20);
}
 
