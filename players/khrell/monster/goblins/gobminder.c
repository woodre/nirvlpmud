#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("grubnob");
  set_alt_name("goblin");
  set_alias("taskmaster");
  set_short("Grubnob the"+HIK+" taskmaster"+NORM);
  set_long("This is the night goblin taskmaster, given the job of minding to the\n\
massive ammounts of snotlings that breed like rabbits.\n");
  set_gender("male");
  set_race("goblin");
  set_level(random(13)+5);
move_object(clone_object("/players/khrell/weapons/goblins/gobprod.c"));
init_command("wield prodder");
  set_wc(random (4)+12);
move_object(clone_object("/players/khrell/armors/goblins/gobrobe.c"));
init_command("wear robe");
  set_ac(10);
  set_hp(180);
  set_al(-200);
set_aggressive(0);
  add_money(125);  

set_chat_chance(10);
load_chat("Grubnob mutters about his thankless job.\n");

set_a_chat_chance(10);
load_a_chat("Grubnob bites at you with his sharp teeth!\n");
  set_chance(10);
set_spell_dam(15);
set_spell_mess1( 
"Grubnob screams a piercing battle cry!\n");

set_spell_mess2(
"The goblin kicks you in the shin!\n");

}
