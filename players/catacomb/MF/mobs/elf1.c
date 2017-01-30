#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object tunic;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("elf");
set_race("elf");
set_short("A Shamot elf");
set_long(
  "  You stand before a tall figure standing seven feet tall.\n"+
  "His long blond hair hides his pointed ears.  He is waiting\n"+
  "for his love to meet him at the bench along the creek.\n");
 
set_level(14);
set_hp(220);
set_al(300);
set_wc(18);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(3);
  load_chat("The elf asks: Have you seen my love?\n");
set_a_chat_chance(2);
  load_a_chat("The elf looks off into the sky.\n");
  load_a_chat("The elf paces back and forth.\n");

tunic = clone_object("/players/catacomb/MF/items/tunic.c"); 
move_object(tunic, this_object());
command("wear tunic", this_object());
set_ac(11);
}   