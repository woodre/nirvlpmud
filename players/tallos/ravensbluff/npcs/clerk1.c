#include "/players/tallos/ansi.h"
inherit "obj/monster.c";
object attacked;
#define attacked (this_object()->query_attack())
#define tpn this_player()->query_name()
#define tpo this_player()->query_objective()

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

  gold = clone_object("obj/money");
  gold->set_money(random(1000) + 600);
  move_object(gold,this_object());

set_name("clerk");
set_race("human");
set_short(BOLD+""+HIG+"Store Clerk"+NORM);
set_long(
  "   This is the shop clerk for the potions store\n"+
  "he is ready to sell you potions at your request.\n");
 
set_level(15);
set_hp(550);
set_al(1000);
set_ac(20);
set_wc(30);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(5);
  load_chat("The clerk says, \"Can I help you?\"\n");
  load_chat("The clerk says, \"We have the finest potions this side of Procamper.\"\n");
}


monster_died(){
   tell_object(attacked,
   "\nThe clerk falls over and clutches his chest. \"Why?\"\n");

}



