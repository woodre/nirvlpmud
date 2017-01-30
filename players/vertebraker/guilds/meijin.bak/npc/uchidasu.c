inherit "/obj/monster";
#include "/players/pavlik/guild/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
  set_name("Uchidasu");
  set_alias("uchidasu");
  set_alt_name("weaponsmith");
  set_short("Uchidasu, the Weaponsmith");
  set_long("Uchidasu, the Weaponsmith");
  set_level(50);
  set_ac(100);
  set_wc(500);
  set_hp(10000);
  set_al(0);
  set_aggressive(0);
  }
}

query_meijin_master() { return 1; }

init() {
  ::init();
  add_action("sit","sit");
  add_action("buy","buy");
}

long() {
  write(
    "Uchidasu is the Meijin's expert Weaponsmith.  He works all day\n"+
    "at the forge crafting weapons and armor.  Uchidasu sells these\n"+
    "finely crafted items.  Avaliable for sale are:\n"+
    "\n"+
/*
    "           Chainmail Armor  ............... 3000 gp\n"+
    "           Scalemail Armor ................ 2000 gp\n"+
    "           Leather Armor ..................  750 gp\n"+
    "           Helmet .........................  500 gp\n"+
    "           Pair of Boots ..................  400 gp\n"+
    "           Weapon ......................... 3000 gp\n"+
*/
    "           Boots of Dexterity ............. 5000 gp\n"+
    "           Sword of Vigor ................  8000 gp\n"+
    "\n");
  return;
}

buy(str) {
  if(!str) {
	write("Uchidasu says: Buy what?\n");
	return 1;
  }
  if(str == "boots") {
	if(TP->query_money() < 5000) {
		write("Uchidasu says: You can not afford them.\n");
		return 1;
	}
	if(!this_player()->add_weight(1)) {
		write("You cannot carry that much.\n");
		return 1;
	}
	TP->add_money(-5000);
	move_object(clone_object("players/pavlik/guild/obj/dex_boots"), TP);
	write("Uchidasu says: Ah, an wise decision young master!\n");
	write("The venerable weaponsmith gives you a pair of boots.\n");
	return 1;
  }
  if(str == "sword") {
	if(TP->query_money() < 8000) {
		write("Uchidasu says: You can not afford them.\n");
		return 1;
	}
	if(!this_player()->add_weight(2)) {
		write("You cannot carry that much.\n");
		return 1;
	}
	TP->add_money(-8000);
	move_object(clone_object("players/pavlik/guild/obj/vigor_sword"), TP);
	write("Uchidasu says: Ah, an wise decision young master!\n");
	write("The venerable weaponsmith gives you a finely crafted sword.\n");
	return 1;
  }
  write("Uchidasu says: I do not sell that!\n");
  return 1;
}

sit() {
  write("You decide that this is not a proper place to sit.\n");
  return 1;
}

