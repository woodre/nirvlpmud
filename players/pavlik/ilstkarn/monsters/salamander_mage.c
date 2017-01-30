#include <ansi.h>
inherit "/obj/monster";
#define SAL HIR+"Salamander"+HIW+" Mage"+NORM

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(SAL);
  set_alias("mage");
  set_short("a "+SAL);
  set_long(
  "This Salamander dabbles in the art of "+HIR+"Fire-Magic"+NORM+".  The Mage wields\n"+
  "a dangerous array of spells to vanquish its foe.\n");
  set_race("salamander");
  set_level(20);
  set_hp(360);
  set_wc(50);
  set_ac(17);
  set_al(-random(1000));
  set_aggressive(0);
  set_chat_chance(20);
  set_a_chat_chance(30);
  load_chat("The "+SAL+" dips its head into the lava.\n");
  load_chat(SAL+" chants in its guttural language.\n");
  load_chat("The "+SAL+" traces magical runes in the lava.\n");
  load_a_chat("The "+SAL+" traces magical runes in the lava.\n");
  load_a_chat("Fire gouts from the "+SAL+"'s fintertips!\n");
  load_a_chat("The "+SAL+" casts a spell of burning on you!\n");
  load_a_chat(SAL+" summons an "+HIR+"Inferno"+NORM+" to roast its enemy!\n");
  load_a_chat(SAL+" chants a spell and "+HIR+"flames erupt!"+NORM+"\n");
  set_chance(40);
  set_spell_dam(50);
  set_spell_mess1("The "+SAL+" "+HIR+"scorches"+NORM+" his enemy with a powerful spell!");
  set_spell_mess2("The "+SAL+" "+HIR+"scorches"+NORM+" you with a powerful spell!");
  switch (random(5)) {
	case 0 :
	   move_object(clone_object("players/pavlik/ilstkarn/treasure/red_potion"), this_object());
	   money = 3000 + random(1000);
	   break;
	case 1 :
	   move_object(clone_object("players/pavlik/ilstkarn/weapons/lava_staff"), this_object());
	   money = 1000 + random(1000);
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

