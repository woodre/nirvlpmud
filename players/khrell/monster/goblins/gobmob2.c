#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("goblin");
  set_alt_name("goblin");
  set_alias("chaos goblin");
  set_short("A"+HIK+" Chaos"+NORM+GRN+ " Goblin"+NORM);
  set_long("This was at one time a night goblin, now warped and twisted by raw chaos\n\
it stares out with hateful eyes, though how many and what configuration\n\
or arrangement can not be charted.  It's limbs are twisted and grotesque\n\
his cruel impish face now a mask of insane torment.                    \n");  
  set_gender("male");
  set_race("goblin");
  set_level(random(2)+15);
move_object(clone_object("/players/khrell/weapons/goblins/gobsword.c"));
init_command("wield sword");   
  set_wc(random(2)+18);
move_object(clone_object("/players/khrell/armors/goblins/gobshield.c"));
move_object(clone_object("/players/khrell/armors/goblins/gobrobe.c"));
init_command("wear shield");
init_command("wear robe");
  set_ac(12);
  set_hp(250);
  set_al(-100);
set_aggressive(0);

set_chat_chance(10);
load_chat("The goblin glares at you with it's hate filled eyes.\n");

set_a_chat_chance(10);
load_a_chat("The goblin moans in anguish.\n");
  set_chance(10);
set_spell_dam(25);
set_spell_mess1( 
"The goblin spurts ichor about!\n");

set_spell_mess2(
"The goblin flails with a warped appendage!\n");

}
