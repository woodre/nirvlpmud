#include "/players/jareel/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("swimmer");
set_alias("down");
set_race("duck");
set_short("Down Swimmer - Duck of the Quacking order. (neutral)");
set_long(
  "Down Swimmer stands about four feet tall, she loks like\n"+
  "a very skilled swimmer.  She waddles as she walks.  The\n"+
  "quick glances over her shoulder, seems to show she is a\n"+
  "little worried about adventurers\n");

set_level(10);
set_hp(150);
set_al(0);
set_wc(14);
set_ac(8);
set_heal(1,1);
set_aggressive(0);
set_dead_ob(this_object());
gold = clone_object("obj/money");
gold->set_money(400+random(50));
move_object(gold,this_object());
}
