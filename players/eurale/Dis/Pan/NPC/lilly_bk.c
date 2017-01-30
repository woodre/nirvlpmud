#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("lily");
set_alias("tiger");
set_alt_name("tiger lily");
set_race("human");
set_short("Tiger Lily");
set_long(
	"  Tiger Lily is the beautiful Indian princess that lives on\n"+
	"Never Island.  Her silky black hair is braided and hangs almost\n"+
	"to her knees.  Her leather tunic is adorned with intricate and\n"+
	"colorful beadwork.\n");

  set_hp(450);
  set_level(18);
set_gender("female");
  set_al(50);
  set_wc(26);
  set_ac(15);
set_heal(3,9,);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(20);
  load_chat("Tiger Lily chants softly....\n");
set_a_chat_chance(20);
  load_a_chat("Tiger Lily lets loose a war cry........\n");

set_chance(10);
set_spell_dam(50);

set_spell_mess1(
  "\n\nTiger Lily "+BOLD+"TOMAHAWK CHOPS"+NORM+" her target.\n\n");
set_spell_mess2(
  "\n\nTiger Lily "+BOLD+"TOMAHAWK CHOPS"+NORM+" you!\n\n");

gold = clone_object("obj/money");
gold->set_money(1000);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nA A I I E E E E O O O..crys Tiger Lily as she falls.\n\n");
return 0; }
