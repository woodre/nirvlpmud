#include "/players/jaraxle/ansi.h"
inherit "obj/monster.c";
#define ALLY "players/boltar/templar/daemon/Ally.c"
#define TP this_player()

object gold,helmet,armor,weapon,shield;
int guarding;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("alexander");
set_alt_name("ambassador");
set_alias("templar_guard");
set_race("human");
set_short(HIW+"Alexander, "+HIB+"High Templar Ambassador to the Bards"+NORM);
set_long(
"  Before you stands Alexander, a powerful ambassador of the Templars.\n"+
"He is dressed in a full suit of plate armor, tinted blue with a white\n"+
"cross displayed on the breastplate and knee guards. A large shield\n"+
"is held at the ready, and an oversized broadsword is left sheathed\n"+
"at the hip. He seems ready for any combat. He is a representative of\n"+
"the Templars, and he is here to assist any Bard to join the Templar-\n"+
"Bard alliance.  Simply type, 'alliance' to join or, if you have lost\n"+
"your alliance object, type, 'renew'.\n");  
set_level(20);
set_hp(2000);
set_al(1000);
weapon = clone_object("players/jaraxle/templar/items/bsword");
move_object(weapon, this_object());
command("wield pike", this_object());
armor = clone_object("players/jaraxle/templar/items/fullplate2");
move_object(armor, this_object());
command("wear fullplate", this_object());
helmet = clone_object("players/jaraxle/templar/items/helmet");
move_object(helmet, this_object());
command("wear helmet", this_object());
shield = clone_object("players/jaraxle/templar/items/shield");
move_object(shield, this_object());
command("wear shield", this_object());
set_wc(50);
set_ac(30);
set_aggressive(0);
set_heart_beat(1);
set_chance(50);
set_spell_dam(60);
set_spell_mess1(
  "The High Templar charges his foe!\n");
set_spell_mess2(
  "You feel a biting pain as the High Templars Sword slices into your flesh!\n");
gold = clone_object("obj/money");
gold->set_money(800);
move_object(gold,this_object());
}


init(){
::init();
add_action("renew", "renew");
add_action("alliance", "alliance");
}

renew(){
	if(ALLY->Query(TP->query_real_name())){
		if(present("KnightInvite", TP)){
			destruct(present("KnightInvite", TP));
			move_object(clone_object("/players/boltar/templar/items/bracer.c"), TP);
			write("You renew your object.\n");
			return 1;
		}
		move_object(clone_object("/players/boltar/templar/items/bracer.c"), TP);
		write("You obtain your Alliance object. ally_info for more assistance.\n");
		return 1;
	}
	return 0;
}


alliance(){
	if(!present("bard_obj", TP)) return 0;
	if(ALLY->Query(TP->query_real_name())){
		write("Alexander says, 'You are already an Ally.'\n");
		return 1;
	}
	ALLY->Insert(TP->query_real_name());
	write("Alexander smiles at you and nods his approval.\n"+
		  "\"I welcome you to the Alliance,\" he says as he hands you\n"+
		  "something that glistens.  You look at it and see that it is\n"+
		  "a beautiful Coat of Arms.\n"+
		  "\"I am also skilled with Arms and would be happy to teach\n"+
		  " you to fight in a manner similar to the Knights,\" he continues.\n"+
		  "You train with several weapons and listen carefully to Alexander\n"+
		  "as he teaches you.\n"+
		  "Alexander then finishes, and bows low to you.\n\n"+
		  HIY+"Welcome to the Alliance!\n\n"+NORM);
	write("You obtain your Alliance object. ally_info for more assistance.\n");
	move_object(clone_object("/players/boltar/templar/items/bracer.c"), TP);
	return 1;
	}
