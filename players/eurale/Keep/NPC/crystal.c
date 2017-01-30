#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object wep1,wep2,gold;
  ::reset(arg);
  if(arg) return;

set_name("centaur");
set_alias("crystalmir centaur");
set_alt_name("centaur 2");
set_race("creature");
set_short("Crystalmir Centaur");
set_long(
	"  This centaur is strong and sturdy.  He stands approximately\n"+
	"five and a half feet tall and weighs 700-800 pounds.  He has\n"+
	"a lean body, slim neck and a high-set tail and is extremely\n"+
	"quick.\n");

set_level(19);
  set_hp(475);
  set_al(150);
  set_wc(28);
  set_ac(18);
  set_aggressive(0);

set_chat_chance(9);
  load_chat("The centaur paws the ground.....\n");
  load_chat("You look very carefully at this man/beast...\n");
  load_chat("The centaur asks: Can I help you?\n");
set_a_chat_chance(10);
  load_a_chat("The centaur REARS up....\n");
  load_a_chat("\nThe centaur's hoof just misses your head..\n");
  load_a_chat("\nThe centaur gallops behind you to attack..\n");

gold = clone_object("obj/money");
gold->set_money(1500 +random(1000));
move_object(gold,this_object());
}
