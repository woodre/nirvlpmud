#include "/players/eurale/closed/ansi.h"
inherit "players/eurale/closed/emonster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("friar tuck");
set_alias("friar");
set_alt_name("tuck");
set_race("human");
set_short("Friar Tuck");
set_long(
	"  Tuck is a short, jovial man who dresses in the brown robe of\n"+
	"his order.  He is fond of the 'grape' and takes care of whatever\n"+
	"ministries the merry men might need.\n");

  set_hp(475);
  set_level(19);
  set_al(250);
  set_wc(28);
  set_ac(16);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Tuck says: Anyone have a little wine to spare? \n");
  load_chat("Tuck asks: Thinking of going into the forest?\n");
  load_chat("The forest is full of bandits. says Tuck\n");
set_a_chat_chance(10);
  load_a_chat("Tuck attacks with ferocious rage... \n");

set_chance(18);
set_spell_dam(25);

set_spell_mess1(
  "\n\n"+
  "Tuck "+YEL+"POINTS HEAVENWARD"+NORM+" and lightning strikes..\n\n");
set_spell_mess2(
  "\n\nTuck "+YEL+"POINTS SKYWARD"+NORM+" and lightning strikes you!\n\n");

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nTuck gasps: May God have mercy on your soul!\n\n");
return 0; }
