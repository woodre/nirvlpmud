#define TO this_object()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster";

object gold;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("queen");
  set_alias("evil queen");
  set_race("human");
  set_short("Evil Queen");
set_long(
	"  The Queen is a sinister figure.  She is dressed in black from\n"+
	"head to toe except for her gold crown and the fire red amulet\n"+
	"that holds her cloak on.  Her gaunt appearance and milky white\n"+
	"skin add a look of death to her.\n");
  set_hp(550);
  set_level(20);
  set_al(-100);

if(!present("amulet")) {
move_object(clone_object("players/eurale/Dis/SnWht/OBJ/amulet"),TO); }
init_command("wear amulet");
if(!present("crown")) {
move_object(clone_object("players/eurale/Dis/SnWht/OBJ/crown"),TO); }
init_command("wear crown");
  set_wc(40);
  set_ac(15);
  set_heal(2,8);
  set_aggressive(0);
set_gender("female");
  set_chat_chance(20);
  set_a_chat_chance(10);
load_chat("The Queen glares at you......\n");
load_chat("The Queen looks in the mirror and says: \n"+
	"     Mirror mirror on the wall, who's the fairest of us all?\n");
load_a_chat("The Queen points at you and says: YOU WILL DIE FOR THIS!\n");

  set_chance(14);
  set_spell_dam(75);
set_spell_mess1(
	"\n                    The Queen points her finger..... \n\n"+
	"                    The tip begins to glow.....\n\n"+
	RED+"                    F L A M E S  "+NORM+"shoot from the end..\n\n"+
	"                    and ENGULF the target.....\n\n");
set_spell_mess2(
	"\n                    The Queen points at you......\n\n"+
	"                    The tip of her finger begins to glow.....\n\n"+
     RED+"                    F L A M E S  "+NORM+"shoot from the end..\n\n"+
	"                    and E N G U L F you!!\n\n");

gold = clone_object("obj/money");
gold->set_money(random(500)+2000);
move_object(gold,this_object());
}
