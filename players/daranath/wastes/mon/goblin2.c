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
 ob2 = clone_object(ROOT +"obj/leathers.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/shortbow.c");
  move_object(ob3, this_object());

set_name("goblin scout");
set_alias("cavemon");
set_alt_name("scout");
set_race("goblin");
set_gender("male");

set_short(GRN+"goblin "+WHT+"scout"+NORM);
set_long("A small goblin is crouched down looking at the tracks running all about\n"+
    "the area. He is carrying a shortbow and wearing a set of supple leather\n"+
    "armor, ready for battle.\n");

set_level(7);
set_ac(6);
set_wc(9 + random(4));
set_hp(95 + random(30));
set_al(-750);
set_aggressive(0);

init_command("wield bow");
init_command("wear leather");

set_a_chat_chance(10);
load_a_chat("Goblin barks at you during the fight.\n");
load_a_chat("The goblin shoots an arrow into your arm.\n");

   }
}
