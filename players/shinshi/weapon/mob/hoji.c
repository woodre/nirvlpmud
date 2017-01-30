inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("swordsman");
	set_alt_name("teacher");
	set_race("human");
	set_alias("hoji");
	set_short("Hoji, Teacher of Ancient Swords");
	set_long("\
	Fix\n\
	This\n\
	Later\n\
	Maybe you can 'ask' about his problem.\n");
	set_level(1);
	set_hp(1 + random (1));
	set_ac(1 + random (1));
	set_wc(1 + random(1));
	set_al(-7000);
	set_chat_chance(2);
	load_chat("Hoji twirls his blades with swift precision around his body.\n");
}

init(){
  ::init();
	add_action("ask","inquire");
}

ask(str){
	object ob;
	
	if(!str){
		write("What would you like to inquire?\n");
		return 1;
	}
	
	if(str != "about weapon"){
		write("You can only inquire about the weapon.\n");
		return 1;
	}
	
	if(str == "about weapon"){
		write("Hoji says: Ahhh, so you wish to finally learn the ways of the weaponmaster.\n");
		write("VERY WELL! It shall cost you $500,000 coins! If you wish to continue,\n");
		write("an account will be created for you to deposit coins! Continue? (y/n)\n");
		input_to("answer");
		return 1;
		}
}

answer(str){
	
	if(!str){
		write("You decide to decline the offer.\n");
		return 1;
	}
	
	if(str != "y" && str != "Y"){
		write("You decide to decline the offer.\n");
		return 1;
	}
	
	if(str == "y" || str == "Y"){
		write("\nHoji smiles and says: You have taken your first step to great power!\n\n");
		write("Hoji continues: At any time you would like to make a payment, just\n");
		write("'make' a 'payment' for the amount you'd like to deposit. Also, please\n");
		write("tell me whether it will be coming from your bank account or you have the\n");
		write("cash on you. Good luck in your adventures!\n\n");
		save_object("players/shinshi/weapon/save/"+this_player()->query_real_name());
		return 1;
	}
}