#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("baker");
set_race("human");
set_short("Baker");
set_long(
	"  This is one of the local bakers.  He is a balding, thin fellow\n"+
	"with a drooping moustache.  He wears a full apron and is covered\n"+
	"with various types of flour from his breadmaking.\n");

  set_hp(450);
  set_level(18);
  set_al(0);
  set_wc(26);
  set_ac(15);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The baker wipes his hands on his apron...\n");
  load_chat("The baker peers into the oven to check his bread..\n");
  load_chat("Can I get you something?  asks the baker\n");
  load_chat("Doesn't it smell good? asks the baker\n");
set_a_chat_chance(15);
  load_a_chat("The baker hollars: I'll toast your buns now!\n");
  load_a_chat("The baker swings at you with a heavy wooden rolling pin.\n");
  load_a_chat("The baker throws flour in your face...\n");

gold = clone_object("obj/money");
gold->set_money(1000);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nA cloud of flour dust POOFS as he hits the floor for the last time.\n\n");
return 0; }
