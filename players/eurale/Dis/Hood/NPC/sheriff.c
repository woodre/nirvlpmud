#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("sheriff");
set_alias("sheriff of nottingham");
set_race("human");
set_short("Sheriff of Nottingham");
set_long(
	"  This evil fellow is always dressed in black from head to toe.\n"+
	"His wide-brimmed, plummed hat and ruffled shirt gives him the\n"+
	"look of a 'dandy' but don't be fooled.  He is an excellent \n"+
	"swordsman and he always fights to win.  His smile is distracting\n"+
	"because of the bright gold tooth he has..\n");

  set_hp(500);
  set_level(20);
  set_al(-100);
if(!present("broadsword")) {
move_object(clone_object("players/eurale/Dis/Hood/OBJ/bsword"),
	this_object()); }
init_command("wield broadsword");
  set_wc(35);
  set_ac(15);
  set_heal(4,8);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The Sheriff squints in your direction...\n");
  load_chat("Here to pay your taxes? asks the Sheriff\n");
  load_chat("The Sheriff smiles, showing his gold tooth..\n");
set_a_chat_chance(15);
  load_a_chat("The Sheriff parried your attack..\n");
  load_a_chat("\nSWISH... the blade just misses your neck..\n\n");
  load_a_chat("The Sheriff laughs maniacially....\n");

set_chance(10);
set_spell_dam(40);

set_spell_mess1(
  "\n\n"+
  "The "+RED+"B L O O D "+NORM+" spurts from the wound..\n\n");
set_spell_mess2(
  "\n\nYou taste "+RED+"B L O O D"+NORM+" from the wound...\n\n");

gold = clone_object("obj/money");
gold->set_money(4000);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nI NEVER thought I'd be bested....whines the Sheriff\n\n");
return 0; }
