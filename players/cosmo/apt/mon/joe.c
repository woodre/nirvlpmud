#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Joe"+NORM);
set_alias("joe");
set_alt_name("davola");
set_race("human");
set_short("Crazy Joe Davola");
set_long(
  "  Crazy Joe is completely insane.  He and Kramer are great\n"+
  "friends and always seem to get along well, but everyone else\n"+
  "(especially George and Jerry) think he's off his rocker.  He\n"+
  "is a faithful friend to Kramer nonetheless.\n");

set_level(12);
  set_hp(160);
  set_al(0);
  set_wc(18);
  set_ac(8);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chance(10);
set_spell_dam(30);
set_spell_mess1(
  "\nCrazy Joe rants and raves.\n");
set_spell_mess2(
  "\nCrazy Joe goes "+GRN+"berzerk"+NORM+"!\n"+
  "He begins throwing every object in the room at you.\n");

gold = clone_object("obj/money");
gold->set_money(550+random(50));
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
	"The cigar store Indian suddenly topples to the ground.\n");
return 0; }

