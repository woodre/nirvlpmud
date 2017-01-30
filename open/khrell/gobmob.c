#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/obj/monster2.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("goblin");
  set_alt_name("goblin");
  set_alias("night goblin");
  set_short("A"+HIK+" Night"+NORM+HIG+ " Goblin"+NORM);
  set_long("This is a night goblin, a sub-race of goblins that live almost\n\
exclusively underground and only venture out at night, thus the name.\n");
  set_gender("male");
  set_race("goblin");
  set_level(random(5)+10);
move_object(clone_object("/players/khrell/weapons/goblins/gobsword.c"), this_object());
init_command("wield sword");   
  set_wc(random(7)+10);
move_object(clone_object("/players/khrell/armors/goblins/gobshield.c"), this_object());
move_object(clone_object("/players/khrell/armors/goblins/gobrobe.c"), this_object());
init_command("wear shield");
init_command("wear robe");
  set_ac(10);
  set_hp(200);
  set_al(-100);
  set_aggressive(0);
move_object(clone_object("players/khrell/heals/goblins/fungibrew.c"), this_object());  
  set_wander(30, 0, ({ "opening" }));
  set_chat_chance(10);
load_chat("The goblin sneers at you with hate-filled eyes.\n");

set_a_chat_chance(10);
load_a_chat("The goblin bites at you with its sharp teeth!\n");
  set_chance(10);
set_spell_dam(15);
set_spell_mess1( 
"The goblin cuts deep with his blade!\n");

set_spell_mess2(
"The goblin kicks you in the shin!\n");


}
