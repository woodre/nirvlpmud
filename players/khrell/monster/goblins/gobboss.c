#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("skrub");
  set_alt_name("goblin");
  set_alias("boss");
  set_short(HIG+"Big Boss Skrub"+NORM);
  set_long(
"Big Boss Skrug is large for his kind, both in height and girth.  Great\n"+
"rolls of fat spill out over his belted pants and his pudgy cheeks give\n"+
"his red eyes a squinty look.  He holds in his chubby fingers a gigantic\n"+
"and well used club, obivously used to keep order among his followers.\n");
  set_gender("male");
  set_race("goblin");
  set_level(random(5)+15);
move_object(clone_object("/players/khrell/weapons/goblins/gobclub.c"));
init_command("wield club");
  set_wc(random (4)+12);
move_object(clone_object("/players/khrell/armors/goblins/gobrobe.c"));
init_command("wear robe");
  set_ac(10);
  set_hp(325);
  set_al(-1200);
  set_aggressive(5);
  

  set_chat_chance(10);
load_chat("Skrub rolls his fat about his body.\n");

  set_a_chat_chance(10);
load_a_chat("Skrub bites at you with his chipped teeth!\n");
  set_chance(10);
  set_spell_dam(50);
  set_spell_mess1( 
"Skrub screams and bodyslams you!\n");

  set_spell_mess2(
"The goblin kicks you in the shin!\n");

}

init(){
::init();
add_action("stop_move", "enter", 1);
}


stop_move(){
if(this_player()->query_ghost()) return;
write("Skrub jumps in your way blocking the exit!\n");
return 1;
}
