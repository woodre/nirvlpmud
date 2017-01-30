#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object ;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("lady");
set_alt_name("elf");
set_race("elf");
set_short("A beautiful Elven lady");
set_long(
  "  The lady looks fairly young for an elf, possibly still living in\n"+
  "her first century.  Her sapphire blue, almond shaped eyes seem to \n"+
  "entrap you in her gaze.  Her long strawberry blond hair ripples in\n"+
  "the wind, giving her an aura of beauty.  Her years of martial art\n"+
  "training make her appear to be carved out of stone.\n");
 
set_level(16);
set_hp(300);
set_al(750);
set_aggressive(0);
set_chat_chance(2);
  load_chat("The lady smiles at you.\n");
set_a_chat_chance(1);
  load_a_chat("The lady asks: I wonder where Chelaris went off to?\n");
  load_a_chat("The lady hums an ancient tune.\n");
  load_a_chat("The elven lady takes a seat on a bench.\n");

staff = clone_object("/players/catacomb/MF/items/staff.c"); 
move_object(staff, this_object());
command("wield staff", this_object());
set_wc(22);

boot = clone_object("/players/catacomb/MF/items/boots.c");
move_object(boot, this_object());
command("wear boots", this_object());
set ac(13);
}
 
