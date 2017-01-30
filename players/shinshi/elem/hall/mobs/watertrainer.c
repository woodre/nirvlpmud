inherit "/obj/monster";
#include "/sys/lib.h"
#include "../../defs.h"
#include <ansi.h>

int a, play;
string person;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("glyndwr");
  set_alt_name("water");
  set_race("element");
  set_alias("element water");
  set_short("Glyndwr, the "+HIW+"Ancient"+NORM+" "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"t"+NORM+" of"+CYN+" Water"+NORM);
  set_long("\
   An Ancient Elements that has been around since existance has come to be.\n\
  It is made of nothing but complete water and mist as it radiates massive \n\
  power and strength. It spins and whips around the room with ungodly strength.\n\
  and flows with graceful movements. This is The Ancient Elemental of water and \n\
  and the powers and knowledge have been and will always be forever.\n");
 
  set_level(19);
  set_hp(100000+ random(100000));
  set_ac(99+ random(1));
  set_wc(99+ random(2));
  set_al(0);
}

init()
{
	::init();
	
	add_action("complete", "complete");
	add_action("inquire", "inquire");
	add_action("port", "port");
}

port()
{
	int money, cost;
	object book;
	
	cost = 15000;
	money = (int)this_player()->query_money();
	
	book = present("temp_ele_obj", this_player());
	
	if(!book)
	{
		write("Glyndwr gives you a weird look.\n");
		return 1;
	}
	
	if(book->query_earth())
	{
		write("Glyndwr says, \"You have already gained the Mark of the Earth!\"\n");
		return 1;
	}
	
	if(money < cost)
	{
		write("Glyndwr says, \"You do not have the money for me to do this!\"\n");
		return 1;
	}
	
	else
	{
		write("Glyndwr nods and says, \"Very well. Travel safely, warrior.\"\n");
		this_player()->add_money(-cost);
		write("You are blinded by a bright flash and appears in a different area.\n");
		move_object(this_player(), "/players/snow/water/throne_room.c");
		return 1;
	}
	return 1;
}


inquire()
{
	object book;
	
	book = present("book", this_player());
	
	if(!book)
	{
		write(CYN+"Glyndwr"+NORM+" sings, \"You've already completed my task!\n");
		return 1;
	}
	
	person = this_player();
	say("The ocean waves slam against the coast.\n");
  	call_out("talk",2,person);
	return 1;
}


complete(str)
{
	object tsunami, book;
	
	tsunami = present("tsunami_elemental_obj", this_player());
	
	if(!present("temp_ele_gobj", this_player()))
	{
		write("Glyndwr gives you a weird look.\n");
		return 1;
	}
	
	book = present("temp_ele_gobj", this_player());
	
	if(book->query_water())
	{
		write("Glyndwr laughs and says, \"You have already completed my task.\"\n");
		return 1;
	}
	
	if(!tsunami)
	{
		write("A rush of water comes flowing through the area. It invades your lungs!\n");
		write("Glyndwr yells, "+HIR+"\"YOU HAVE FAILED ME, HUMAN!\"\n"+NORM);
		this_player()->hit_player(30, "other|water");
		return 1;
	}
	
	if(tsunami)
	{
		write("The water whirls around your feet.\n");
		write("Glyndwr smiles happily and grants you his mark.\n");
		destruct(tsunami);
		book->set_water(1);
		command("bsave", this_player());
		return 1;
	}
	return 1;
}


talk(person)
{
	say_it();
	a += 1;
	if(a<27) call_out("talk",1,person);
	else {
		play = 0;
		a = 0;
	}
	return 1;
}

say_it(){
  string stuff;
  
   switch(a){
		case 0: stuff = "The Waters rise and crash before your very feet!"; break;
		case 1: stuff = " "; break;
		case 2: stuff = "Glyndwr says, \"In the deep, dark depths of the cold water,"; break;
		case 3: stuff = "deep inside the currents of the sea lies a King. If he decides"; break;
		case 4: stuff = "to send his army after our very home, we will surely be"; break;
		case 5: stuff = "destroyed. He was once an Elementalist; but he lost his way."; break;
		case 6: stuff = "He began to form a deadly army to attack myself and my"; break;
		case 7: stuff = "brothers. Recently, I have sent a scout to keep an eye on"; break;
		case 8: stuff = "him. However, my scout never returned with word. I am"; break;
		case 9: stuff = "assuming that the Troglodye King discovered his presense"; break;
		case 10: stuff = "and killed him.\""; break;
		case 11: stuff = " "; break;
		case 12: stuff = "The Elemental sighs in great sorrow."; break;
		case 13: stuff = " "; break;
		case 14: stuff = "\"I have no choice but to send you to the Hall of the Troglodyte"; break;
		case 15: stuff = "King. Dive deep into the depths and make it past his guards"; break;
		case 16: stuff = "and come back with proof of his death. He holds a trident known"; break;
		case 17: stuff = "as the Tsunami. Bring me his weapon as proof that he and his"; break;
		case 18: stuff = "army have been dismantled. With the Tsunami, I can once again"; break;
		case 19: stuff = "take control of the waters.\""; break;
		case 20: stuff = " "; break;
		case 21: stuff = "\"Return to me once you have the Tsunami and I will grant you"; break;
		case 22: stuff = "my mark.\""; break;
		case 23: stuff = " "; break;
		case 24: stuff = "\"I can port you to him for a small fee of 15,000 coins. However, you are"; break;
		case 25: stuff = "responsible for finding your own way back. If you are still interested,"; break;
		case 26: stuff = "just type 'port'.\""; break; }
     tell_object(person,
     BLU+stuff+NORM+"\n");
     return 1; }
     
catch_tell(str)
{
	object player;
	string who;
	
	if(!str) return;
	
	if(sscanf(str, "%s arrives", who) != 1) return;
	
	player = find_living(lower_case(who));
	
	if(!player) return;

	if(!present("temp_ele_gobj", player))
	{
		call_out("say_shit1", 2, player);
		return 1;
	}
	
	if(present("temp_ele_gobj", player))
	{
		call_out("say_shit2", 2, player);
		return 1;
	}
	return 1;
}

say_shit1(player)
{
	tell_object(player, CYN+"Glyndwr"+BOLD+" sings, \"Hiya! If you have the proper amount of\n");
	tell_object(player, "experience, I can 'train' you in the Element of Water!\n"+NORM);
	return 1;
}

say_shit2(player)
{
	tell_object(player, CYN+"Glyndwr"+BOLD+" sings, \"Hiya! I can do the following:\n");
	tell_object(player, "'inquire', 'port', and 'complete'!\"\n"+NORM);
	return 1;
}