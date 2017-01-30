#include <ansi.h>
inherit "/obj/monster";
#define SAL HIR+"Salamander"+HIY+" Cleric"+NORM

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(SAL);
  set_alias("cleric");
  set_short("a "+SAL);
  set_long(
  "The "+SAL+" is a powerful force amongst the Salamanders.  The Cleric\n"+
  "can call down the wrath of Tukukoi, the Lava God to aid it's faithful\n"+
  "servants.  The Clerics of Tutukoi are also fiercesome warriors.\n");
  set_level(20);
  set_hp(500);
  set_wc(35);
  set_ac(19);
  set_al(-1000);
  set_aggressive(0);
  set_a_chat_chance(40);
  load_a_chat("The "+SAL+" chants in its guttural language.\n");
  load_a_chat(SAL+" calls down the wrath of the Lava God!\n");
  load_a_chat("The Cleric stomps around and hisses angrily.\n");
  load_a_chat(SAL+" "+HIM+"curses"+NORM+" you!\n");
  set_chance(40);
  set_spell_dam(50);
  set_spell_mess1("The "+SAL+" casts a spell of "+HIY+"agony"+NORM+" on its enemy!");
  set_spell_mess2("The "+SAL+" casts a spell of "+HIY+"agony"+NORM+" on you!\n"+
	"You fall to the ground and write in pain!");
  switch (random(5)) {
	case 0 :
	   move_object(clone_object("players/pavlik/ilstkarn/heals/lava_drink"), this_object());
	   money = 3000 + random(1000);
	   break;
	case 1 :
	   move_object(clone_object("players/pavlik/ilstkarn/armor/cleric_amulet"), this_object());
	   money = random(1000);
	   break;
	default :
	   money = 4000 + random(1000);
	   break;
  }
}

stop_fight() {
  if(!random(2)) {
	::stop_fight();
	return 1;
  }
  return;
}

