#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2;
 ob = clone_object("obj/money");
  ob->set_money(random(300) + 100);
/* Average coins of 250 per monster guide */
  move_object(ob, this_object());
 ob2 = clone_object(ROOT+"obj/larva.c");
  move_object(ob2, this_object());

set_name("Centipede Queen");
set_alias("queen");
set_alt_name("centipede");
set_race("insect");
set_gender("creature");

set_short(CYN+"Queen centipede"+NORM);
set_long("Similiar to its smaller cousins, the Giant Centipede has identical sets\n"+
         "of legs running the length of its segmented body. Huge mandibles\n"+
         "dripping with puss snap in your direction. It might have a couple of\n"+
         "coins or items from someone it killed.\n");

set_level(16);
set_ac(13);
set_wc(19 + random(5));
set_hp(250 + random(100));
set_al(-1000);
set_aggressive(0);

set_chat_chance(8);
set_a_chat_chance(10);
load_chat("Giant centipede crawls all over the area.\n");
load_a_chat("Giant centipede tears at you with its mandibles.\n");
load_a_chat("Giant centipede hits you very hard.\n");

   }
}
