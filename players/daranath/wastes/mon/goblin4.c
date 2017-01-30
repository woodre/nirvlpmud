#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2, ob3;
 ob = clone_object("obj/money");
  ob->set_money(random(200) + 100);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/gob_plate.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/bastard.c");
  move_object(ob3, this_object());

set_name("goblin champion");
set_alias("cavemon");
set_alt_name("champion");
set_race("goblin");
set_gender("male");

set_short(GRN+"goblin "+WHT+"champion"+NORM);
set_long("Wearing a dirty suit of platemail, the goblin is trying to champion\n"+
         "his race, protecting his home from any invaders.\n");

set_level(13);
set_ac(10);
set_wc(15 + random(4));
set_hp(350 + random(100));
set_al(-900);
set_aggressive(0);

init_command("wield sword");
init_command("wear plate");

set_a_chat_chance(10);
load_a_chat("Goblin barks at you during the fight.\n");
load_a_chat("The goblin swings the sword poorly.\n");

   }
}
