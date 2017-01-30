#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2, ob3;
 ob = clone_object("obj/money");
  ob->set_money(random(75) + 50);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/tabbard.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/spik_club.c");
  move_object(ob3, this_object());

set_name("goblin savage");
set_alias("cavemon");
set_alt_name("savage");
set_race("goblin");
set_gender("male");

set_short(GRN+"goblin "+YEL+"savage"+NORM);
set_long("A small goblin stands before you, his body covered in bright red and\n"+
     "orange tattoos that stand out against the green skin of the creature.\n");

set_level(9);
set_ac(7);
set_wc(11 + random(5));
set_hp(125 + random(50));
set_al(-800);
set_aggressive(1);

init_command("wield club");
init_command("wear tabbard");

set_a_chat_chance(10);
load_a_chat("Goblin barks at you during the fight.\n");
load_a_chat("Goblin Savage barks wildly during the fighting.\n");
load_a_chat("Goblin Savage swings the club for your head.\n");

   }
}
