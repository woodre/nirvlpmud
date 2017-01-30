#define TO this_object()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster";
reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("stromboli");
  set_alias("strom");
  set_alt_name("gypsy");
  set_race("human");
  set_short("Stromboli");
set_long(
	"  Stromboli is a brawny, robust gypsy.  He has a full, long \n"+
	"black beard, wears a brown leather vest and a bright red sash.\n"+
	"His left ear has a gold hoop earring.  This balding vagabond \n"+
	"loves to take truant kids to Pleasure Island.\n");
  set_hp(600);
  set_level(20);
  set_al(0);
  set_wc(30);
  set_ac(17);
  set_aggressive(0);
  set_dead_ob(this_object());

if(!present("candy")) {
  move_object(clone_object("players/eurale/Dis/Pino/OBJ/candy"),TO); }

  set_chat_chance(15);
  set_a_chat_chance(10);
load_chat("Stromboli hums quietly...\n");
load_chat("Stromboli checks his candy sack...\n");
load_a_chat("Stromboli bellows:  You'll pay now! \n");
load_a_chat("Stromboli squeezes your head in a headlock!\n");
  set_chance(15);
  set_spell_dam(45);
set_spell_mess1(
  "\n\nStromboli "+RED+">>S M A S H E S<< "+NORM+"the nose of his foe!\n\n");
set_spell_mess2(
  "\n\nStromboli "+RED+">>S M A S H E S<<"+NORM+" your nose!\n\n");

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nStromboli gives a huge... G R U N T   and dies!\n\n");
return 0; }
