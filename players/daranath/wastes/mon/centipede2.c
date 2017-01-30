#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object("obj/money");
  ob->set_money(random(300) + 100);
/* Average coins of 250 per monster guide */
  move_object(ob, this_object());

set_name("Centipede");
set_alias("platmon");
set_alt_name("centipede");
set_race("insect");
set_gender("creature");

set_short("A "+CYN+"giant centipede"+NORM);
set_long("Similiar to its smaller cousins, the Giant Centipede has identical sets\n"+
         "of legs running the length of its segmented body. Huge mandibles\n"+
         "dripping with puss snap in your direction. It might have a couple of\n"+
         "coins or items from someone it killed.\n");

set_level(6);
set_ac(5);
set_wc(9 + random(3));
set_hp(75 + random(30));
set_al(-900);
set_aggressive(1);

set_chat_chance(8);
set_a_chat_chance(50);
load_chat("Giant centipede crawls all over the area.\n");
load_a_chat("Giant centipede tears at you with its mandibles.\n");
load_a_chat("Giant centipede hits you very hard.\n");
load_a_chat("Giant centipede lunges to defend its Queen!\n");

   }
}

heart_beat(){
 object ob;
 object att;
 object next;
 if(!environment()) return;
 if(ob = present("queen", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
 ::heart_beat();
}

