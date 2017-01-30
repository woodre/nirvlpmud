#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"George"+NORM);
set_alias("george");
set_alt_name("castanza");
set_race("human");
set_short("George Castanza");
set_long(
  "George Castanza -- short, fat, and bald with glasses;\n"+
  "lives with his parents; works for George Steinbrenner;\n"+
  "hangs out with Jerry most of the time.  George dreams of\n"+
  "someday being an architect, and his claim to fame is once\n"+
  "saving the life of a beached whale while pretending to be\n"+
  "a marine biologist.\n");

set_level(11);
  set_hp(200);
  set_al(0);
  set_wc(13);
  set_ac(9);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chance(10);
set_spell_dam(20);
set_spell_mess1(
  "\n"+GRN+"George morphs into a roly-poly"+NORM+".\n");
set_spell_mess2(
  "\n"+GRN+"You are suddenly steam-rolled by George"+NORM+".\n");

gold = clone_object("obj/money");
gold->set_money(400+random(100));
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(),
	"George swaggers theatrically around the room as he\n"+
        "breathes his last gasp and then collapses to the ground.\n");
return 0; }

