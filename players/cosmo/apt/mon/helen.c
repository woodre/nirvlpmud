#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Helen"+NORM);
set_alias("helen");
set_alt_name("seinfeld");
set_race("human");
set_short("Mrs. Helen Seinfeld");
set_long(
  "  Mrs. Seinfeld cares very deeply about her son Jerry. She\n"+
  "always asks him if he is eating the right foods, getting\n"+
  "enough sleep, hanging around with the right people.  Helen\n"+
  "often begs Jerry to move out of the city, or to return to\n"+
  "Florida with her and Morty.\n");

set_level(12);
  set_hp(180);
  set_al(0);
  set_wc(15);
  set_ac(10);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chance(10);
set_spell_dam(30);
set_spell_mess1(
  "You hear Jerry's voice in the distance.\n");
set_spell_mess2(
  "A shadow appears and briefly fights at Helen's side.\n");

gold = clone_object("obj/money");
gold->set_money(500+random(100));
move_object(gold,this_object());
}

