#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("hook");
set_alias("captain");
set_alt_name("captain hook");
set_race("human");
set_short("Captain Hook");
set_long(
	"  This is Captain Hook, leader of the pirates.  He is a brawny\n"+
	"and fearless man with a long scar across his cheek.  He wears\n"+
        "a bright red blazer with his matching plummed hat.  For all\n"+
	"his bad points, he is actually quite dashing.  His missing\n"+
	"right hand has been replaced by a shiney steel hook that he uses\n"+
	"as a weapon in battle.\n");

  set_hp(550);
  set_level(20);
  set_al(-500);

if(!present("hook")) {
move_object(clone_object("players/eurale/Dis/Pan/OBJ/hook"),
	this_object()); }

  set_wc(31);
  set_ac(17);
set_heal(3,7,);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("Hook taps his hook on the railing....\n");
  load_chat("Hook sneers......\n");
  load_chat("Hook laments: Sure do miss my hand..wish I had it back!\n");
set_a_chat_chance(20);
  load_a_chat("Hook tries to gouge you in the eye.....\n");
  load_a_chat("Hook takes a swing at your stomach.. to disembowel you!\n");

set_chance(12);
set_spell_dam(55);

set_spell_mess1(
  "\n\nThe hook finds it's mark and goes deep......\n\n");
set_spell_mess2(
  "\n\nThe hook gores then rips through your flesh.....\n\n");

gold = clone_object("obj/money");
gold->set_money(3500);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nYou'll walk the plank one day, matey!!!\n\n");
return 0; }
