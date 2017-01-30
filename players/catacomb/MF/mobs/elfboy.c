#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
object disks;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("boy");
set_alt_name("elf");
set_race("elf");
set_short("A small boy");
set_long(
  "  The boy is the epitimy of youth.  Running around without a care\n"+
  "in the world, he seems so free.  He is happy to be living in a \n"+
  "world that he believes is safe.\n");
 
set_level(12);
set_hp(180);
set_al(1000);
set_ac(9);
set_wc(16);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(4);
  load_chat("The boy plays with the spindle disks.\n");
set_a_chat_chance(1);
  load_a_chat("The elven boy tells you: HI!\n");
  load_a_chat("The boy runs around aimlessly, enjoying his youth.\n");
  
disks = clone_object("/players/catacomb/MF/items/disks.c"); 
move_object(disks, this_object());
}   