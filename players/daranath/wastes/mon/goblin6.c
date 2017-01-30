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
 ob2 = clone_object(ROOT +"obj/standard.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/2sword.c");
  move_object(ob3, this_object());

set_name("goblin warlord");
set_alias("cavemon");
set_alt_name("warlord");
set_race("goblin");
set_gender("male");

set_short(GRN+"goblin "+BOLD+BLK+"warlord"+NORM);
set_long("Perhaps the largest goblin you've seen yet, the goblin warlord carries\n"+
         "a wicked looking two-handed sword easily in one hand, and a goblin\n"+
         "standard in the other.\n");

set_level(14);
set_ac(11);
set_wc(18 + random(4));
set_hp(200 + random(40));
set_al(-700);
set_aggressive(0);

init_command("wield sword");

set_a_chat_chance(10);
load_a_chat("Goblin barks at you during the fight.\n");
load_a_chat("The goblin warlord tries to take your head off with his sword.\n");
load_a_chat("Goblin warlord hits you very hard.\n");
load_a_chat("Goblin warlord rallies the others around him with the standard.\n");

   }
}
