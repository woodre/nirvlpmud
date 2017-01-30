#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold, gboy;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Jerry"+NORM);
set_alias("jerry");
set_alt_name("seinfeld");
set_race("human");
set_short("Jerry Seinfeld");
set_long(
  "Jerry Seinfeld -- medium build, long dark hair;\n"+
  "has his own apartment; established as one of the\n"+
  "funniest stand-up comedians of his generation;\n"+
  "always seems to go out with beautiful women, and\n"+
  "he used to date his good friend Elaine. Jerry often\n"+
  "wonders how difficult it must be for waiters to tell\n"+
  "the difference between 'salsa' and 'seltzer'.\n");

set_level(11);
  set_hp(200);
  set_al(0);
  set_wc(11);
  set_ac(11);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chance(10);
set_spell_dam(30);
set_spell_mess1(
  "\n"+GRN+"Jerry cracks a hilarious joke"+NORM+".\n");
set_spell_mess2(
  "\n"+GRN+"Jerry tells you one of the funniest jokes that "+
  "you've ever heard.\nYou fall on the floor laughing.\n"+
  "Jerry sucker-punches you while you're on the floor."+NORM+"\n\n");

gboy = clone_object("players/cosmo/apt/armor/goldenboy");
move_object(gboy,this_object());
gold = clone_object("obj/money");
gold->set_money(350+random(50));
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
	"Jerry starts to tell a joke, but you never get a chance\n"+
        "to hear the punchline.... \n");
return 0; }

