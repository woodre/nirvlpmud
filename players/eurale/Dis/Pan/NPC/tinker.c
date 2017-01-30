#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("tinkerbell");
set_alias("tinker");
set_race("creature");
set_short("Tinkerbell");
set_long(
	"  Tinkerbell is a cute little blonde fairy.  Her opaque wings\n"+
	"allow her to fly at will.  She can also help others fly.  She\n"+
	"has magic fairy dust that she uses.  Tinkerbell says, 'Whenever\n"+
	"you want to visit Never Land from here, just sprinkle dust and\n"+
	"and you'll be on your way...  WARNING: I may be little but\n"+
	"I pack a powerful punch if I get lucky!\n");

  set_hp(100);
  set_level(5);
  set_al(800);
  set_wc(9);
  set_ac(5);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(20);
  load_chat("Tinkerbell flits about the room....\n");
  load_chat("Tinkerbell tinkles....\n");
set_a_chat_chance(10);
  load_a_chat("Tinkerbells tinkles: Why? \n");
  load_a_chat("Tinkerbell dodges your attack...\n");
  load_a_chat("Tinkerbell crys.....\n");

set_chance(7);
set_spell_dam(100);

set_spell_mess1(
  "\n\nTinkerbell "+YEL+"G L O W S  B R I G H T L Y! "+NORM+"\n\n");
set_spell_mess2(
  "\n\nTinkerbell "+YEL+" G L O W S  B R I G H T L Y! "+NORM+"\n\n"+
  "        and you feel PAIN in your heart!!\n\n");

gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nTinkerbell tinkles: Tell Peter and the Boys I love them!\n\n");
return 0; }
