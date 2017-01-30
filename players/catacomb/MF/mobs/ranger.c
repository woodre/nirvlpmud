#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object sword;
object shield;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("ranger");
set_alt_name("elf");
set_race("elf");
set_short("An elven ranger");
set_long(
  "  The elf looks very upset, almost to the point of crying.  The\n"+
  "ranger had told his son to never venture across the bridge, but\n"+
  "he didn't listen.  Now the man must venture through the cursed\n"+
  "forest in search of his child.\n");
 
set_level(17);
set_hp(350);
set_al(300);

set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(2);
  load_chat("The ranger asks: Why did I ever enter this cursed forest?\n");
set_a_chat_chance(1);
  load_a_chat("The elf looks around nervously.\n");
  load_a_chat("The ranger frowns.\n");
  load_a_chat("The ranger says: I have to find my son.\n");

sword = clone_object("/players/catacomb/MF/items/katana.c"); 
move_object(sword, this_object());
command("wield katana", this_object());
set_wc(24);

shield = clone_object("/players/catacomb/MF/items/shield.c");
move_object(shield, this_object());
command("wear shield", this_object());
set ac(14);
}
 
   