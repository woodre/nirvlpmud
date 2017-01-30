#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
object cloak;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("elf");
set_race("elf");
set_short("An elven maiden");
set_long(
  "  The lady before you is one of the most beautiful women\n"+
  "you have ever seen.  Her long golden locks reach down the\n"+
  "back of her neck.  Looking into her eyes you are enthralled\n"+
  "by her radiance.\n");
 
set_level(13);
set_hp(195);
set_al(500);
set_wc(17);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(3);
  load_chat("The elven maiden shines a beautiful smile your way.\n");
set_a_chat_chance(2);
  load_a_chat("The maiden asks you: Have you seen my love?\n");
  load_a_chat("The maiden looks lovingly at the creek passing by.\n");

cloak = clone_object("/players/catacomb/MF/items/cloak.c"); 
move_object(cloak, this_object());
command("wear cloak", this_object());
set_ac(10);
}
 
monster_died(){
  tell_object(attacked,
  );
    move_object(, this_object());
}   