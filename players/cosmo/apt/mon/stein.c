#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object bbat,fkey;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"George Steinbrenner"+NORM);
set_alias("george");
set_alt_name("steinbrenner");
set_race("human");
set_short("George Steinbrenner");
set_long(
  "\nMr. Steinbrenner is the long-time, much publicized owner\n"+
  "of the New York Yankees professional baseball team.  He is\n"+
  "considered by many to be fairly ruthless in the way he\n"+
  "handles his players, coaches, and all employees in general.\n"+
  "George Castanza works for Mr. Steinbrenner and often cowers\n"+
  "away from the bark of this long-winded owner.  He carries\n"+
  "one of his prized possessions -- a bat used and autographed\n"+
  "by the one and only Babe Ruth.\n");

set_level(12);
  set_hp(300);
  set_al(-60);
  set_wc(16);
  set_ac(8);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("Mr. Steinbrenner barks:  Where is Castanza?\n");
set_a_chat_chance(10);
  load_a_chat("Mr. Steinbrenner screams: You'll never get out of here now!\n");

set_chance(10);
set_spell_dam(30);
set_spell_mess1(
  "Steinbrenner takes a mighty cut through the air.\n");
set_spell_mess2(
  "Steinbrenner takes a mighty swing through the air.\n"+
  BLU+"W H O O S H !!"+NORM+"\n"+
  "The bat impacts on your skull.\n"+
  RED+"C R A C K !!"+NORM+"\n"+
  "Blood trickles down to the ground.\n\n");

bbat = clone_object("/players/cosmo/apt/weap/bat.c");
move_object(bbat, this_object());
fkey = clone_object("/players/cosmo/apt/obj/freedom.c");
move_object(fkey, this_object());
}

monster_died() {
  tell_room(environment(this_object()),
	"Mr. Steinbrenner collapses face-down on his desk.\n");
return 0; }

