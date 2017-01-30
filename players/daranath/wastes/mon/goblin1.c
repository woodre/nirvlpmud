#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2, ob3;
 ob = clone_object("obj/money");
  ob->set_money(random(25) + 10);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/tabbard.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/sh_sword.c");
  move_object(ob3, this_object());

set_name("goblin");
set_alias("cavemon");
set_alt_name("goblin");
set_race("goblin");
set_gender("male");

set_short("A small "+GRN+"goblin"+NORM);
set_long("A small goblin stands before you, trying to look brave as it holds\n"+
         "a dirty short sword in your direction. As you examine the goblin you\n"+
         "notice the sword seems to be shaking slightly.\n");

set_level(3);
set_ac(4);
set_wc(6 + random(4));
set_hp(30 + random(30));
set_al(-700);
set_aggressive(0);

init_command("wield sword");
init_command("wear tabbard");

set_a_chat_chance(10);
load_a_chat("Goblin barks at you during the fight.\n");
load_a_chat("The goblin swings the sword poorly.\n");

   }
}
