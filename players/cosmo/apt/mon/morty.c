#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Morty"+NORM);
set_alias("morty");
set_alt_name("seinfeld");
set_race("human");
set_short("Mr. Morty Seinfeld");
set_long(
  "  Morty is Jerry's father.  He's a fairly laid-back man for\n"+
  "the most part, except when Frank Castanza is around; they\n"+
  "despise each other.  Morty and his wife Helen have done pretty\n"+
  "well over the years.  They are now retired comfortably down in\n"+
  "Florida, and are on a short vacation to visit Jerry.\n");

set_level(12);
  set_hp(180);
  set_al(0);
  set_wc(16);
  set_ac(9);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chance(10);
set_spell_dam(30);
set_spell_mess1(
  "A cold wind blows through the room.\n");
set_spell_mess2(
  "You shiver as an eerie wind blows down your spine.\n");

gold = clone_object("obj/money");
gold->set_money(500+random(100));
move_object(gold,this_object());
}

