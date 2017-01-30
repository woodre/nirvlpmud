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
  gold->set_money(random(600) + 600);
  move_object(gold,this_object());

set_name("bartender");
set_race("human");
set_short(BOLD+""+HIG+"Bartender"+NORM);
set_long(
  "  This is a bartender for the inn. He seems happy you\n"+
  "are here, and greets you with a smile.\n");
 
set_level(15);
set_hp(350);
set_al(400);
set_ac(14);
set_wc(19);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(7);
  load_chat("The bartender says, \"You want a drink?\"\n");
  load_chat("The bartender says, \"Good group of customers today.\"\n");
}


monster_died(){
   tell_object(attacked,
   "\nThe bartender falls with a terrible cry of death.\n");

}



