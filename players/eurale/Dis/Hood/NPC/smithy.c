#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

id(str) { return (::id(str) || str == "smith"); }

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("blacksmith");
set_alias("weaponsmith");
set_alt_name("smithy");
set_race("human");
set_short("Blacksmith");
set_long(
	"  This burly man has arms the size of small trees from the many\n"+
	"years of working with his heavy hammer.  He is dressed in work\n"+
	"clothes and wears a heavy leather apron to protect himself from\n"+
	"cuts and burns from the hot metal.  His black hair and dark eyes\n"+
	"give him a sinister appearance.\n");

  set_hp(500);
  set_level(20);
  set_al(-50);
  set_wc(30);
  set_ac(17);
  set_heal(5,5);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The smithy looks you over.....\n");
  load_chat("The smithy wipes his sweaty brow...\n");
  load_chat("The blacksmith says: You're new around here?\n");
  load_chat("I'm busy, come back later! barks the smithy\n");
set_a_chat_chance(15);
  load_a_chat("The smithy SPITS in your face....\n");
  load_a_chat("The blacksmith growls: I'll kill you now!\n");
  load_a_chat("The weaponsmith ducks your attack...\n");

set_chance(12);
set_spell_dam(30);

set_spell_mess1(
 "\n\nThe smithy "+BOLD+"P U N C H E S"+NORM+" his target in the face.\n\n");
set_spell_mess2(
 "\n\nThe smithy "+BOLD+"P U N C H E S"+NORM+" you in the face!\n\n");

gold = clone_object("obj/money");
gold->set_money(5000);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nThe blacksmith clutches his heart... and falls to the floor.\n\n");
return 0; }
