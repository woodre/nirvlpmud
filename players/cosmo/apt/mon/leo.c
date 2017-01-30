#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Leo"+NORM);
set_alias("uncle");
set_alt_name("leo");
set_race("human");
set_short("Uncle Leo");
set_long(
  "This is Jerry's uncle Leo.  He is very tall and\n"+
  "has long unkempt hair, despite being bald on top.\n"+
  "Leo is a bit unpredictable and you're never really\n"+
  "sure what he will do or say next, but he's always\n"+
  "a crowd favorite and seems to get along well with\n"+
  "Jerry's friend Kramer.\n");

set_level(11);
  set_hp(200);
  set_al(0);
  set_wc(13);
  set_ac(9);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

gold = clone_object("obj/money");
gold->set_money(400+random(100));
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
	"Leo grabs his heart in agony. \n");
return 0; }

