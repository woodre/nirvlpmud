#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("man");
set_alias("invisible man");
set_race("human");
set_short();
set_long(
	"  This mad scientist in the long white lab coat has discovered\n"+
	"a drug to make him invisible but the side effects drive him to\n"+
	"madness and murder.  This 1933 hit The Invisible Man starred\n"+
	"Claude Rains and was adapted from a story by H.G. Wells.\n");

set_level(20);
  set_hp(500);
  set_al(-100);
  set_wc(30);
  set_ac(17);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("You hear the faint sound of breathing...\n");
  load_chat("The Invisible Man says: Prepare to meet your maker..\n");
  load_chat("You hear the invisible man move behind you....\n");
set_a_chat_chance(15);
  load_a_chat("You sense a quick movement off to your right...\n");
  load_a_chat("From out of nowhere, a fist to the face..BASH!!\n");
  load_a_chat("Hands choke you from behind......\n");

set_chance(16);
set_spell_dam(20);

set_spell_mess1(
  "\n\nYou hear a "+BOLD+"T H U D"+NORM+" as something hits your head..\n\n");
set_spell_mess2(
  BOLD+"T H U D!.. "+NORM+" something hits you from behind..\n\n");

gold = clone_object("obj/money");
gold->set_money(4200);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nAs life's essence flows from his body.....\n\n"+
  "          the scientist becomes visible once again.....\n\n"+
  "                    and the eyes close in this once distorted face.\n\n");
return 0; }
