inherit "obj/monster";
#include "players/bastion/closed/color.h"

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("yerkle");
  set_race("tree");
  set_short(GREEN"Yerkle the "+BOLD+YELLOW+"happy"+OFF+GREEN+"tree"+OFF);
  set_long("Yerkle is just a sapling, but it is a happy tree. Normally trees\n"+
	"grow in one spot and stay there for their entire lives. Yeah. Well too bad.\n"+
	"Welcome to the Plane of Etheriel.\n\n"+
	"You can buy a panic button from Yerkel for 35 coins. Type 'pluck button'.\n");
  set_level(11);
  set_hp(165);
  set_al(920);
  set_ac(15);
  set_wc(11);
  set_chance(20);
  set_chat_chance(14);
  load_chat("Yerkle says: Want to buy a "+BLINK+"Portable Panic Button?"+OFF);
  load_chat("Yerkle says: It's only "+BOLD+"35"+OFF+" coins!\n");
  load_chat("Yerkle says: It works just like the REAL panic button!\n");
  set_spell_dam(25);
  set_spell_mess1("Yerkle screams: hey HEY!!! You dickhead!");
  set_spell_mess2("Yerkle goes: AAAaaaaaauuuuugh!");
weapon=clone_object("players/mizan/etheriel/heals/zokball");
move_object(weapon, this_object());
move_object(clone_object("players/mizan/etheriel/items/spuckballs"), this_object());
	}

pluck(str) {
  if(!str || str != "tree") return 0;
  if(this_player()->query_money() < 35) {
    write("Yerkle the happy tree says: You don't have enough money!\n");
    return 1;
  }
  if(present("Mi361007", this_player())) {
    write("Yerkle the happy tree says: But you already have a panic button!\n");
    return 1;
  }
  write("Yerkle bobbles happily and takes your money as you get a button.\n");
  move_object(clone_object("players/mizan/etheriel/items/portable-panic-btn"), this_player());
  this_player()->add_money(-35);
  return 1;
}

