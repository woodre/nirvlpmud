#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("Nozezap");
  set_alt_name("shaman");
  set_alias("goblin");
  set_short(HIK+"Chaos"+GRN+" Goblin"+NORM+GRN+" Shaman"+YEL+" Nozezap"+NORM);
  set_long("Unlike most of his kin, Nozezap posessess a modicum of actual smarts.\n\
He's suffered the ravages of the warp and now is totally insane and \n\
completely demented.  Though warped and twisted by forces beyond his\n\
control, his simple graps of shamanistic powers staved off the worst\n\
of the ravage of the warp.                                           \n");
  set_gender("male");
  set_race("goblin");
  set_level(random(13)+4);
move_object(clone_object("/players/khrell/weapons/goblins/gobstaff.c")); 
init_command("wield staff");
  set_wc(16);
move_object(clone_object("/players/khrell/armors/goblins/gobrobe.c"));
init_command("wear armor");
  set_ac(15);
  set_hp(200);
  set_al(-100);
set_aggressive(0);
  

set_chat_chance(5);
load_chat("Nozezap picks his teeth with a splintered bone fragment.\n");

set_a_chat_chance(10);
load_a_chat("Nozezap shreiks and curses.\n");
  set_chance(15);
set_spell_dam(30);
set_spell_mess1( 
"The shaman invokes a titanic "+HIG+ "ectoplasmic"+NORM+" foot.\n");

set_spell_mess2(
"A giant foot is summoned by the shaman to"+GRN+" stomp"+NORM+" on his foe.\n");

}
