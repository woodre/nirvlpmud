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
  set_name("aeolos");
  set_alt_name("air");
  set_race("element");
  set_alias("element air");
  set_short("Aeolos, the "+HIW+"Ancient"+NORM+" "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"t"+NORM+" of"+YEL+" Air"+NORM);
  set_long("\
   An Ancient Element that has been around since existance has come to be.\n\
  It is made of nothing but complete air and whipping winds that have massive \n\
  power and strength. It spins and whips around the room with ungodly strength.\n\
  and flows with graceful movements. This is The Ancient Elemental of Air and \n\
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
	
	book = present("temp_ele_obj", this_player());
	cost = 15000;
	money = (int)this_player()->query_money();
	
	if(!book)
	{
		write("Aeolos gives you a weird look.\n");
		return 1;
	}
	
	if(book->query_air())
	{
		write("Aeolos says, \"You have already gained the Mark of the Air!\"\n");
		return 1;
	}
	
	if(money < cost)
	{
		write("Aeolos says, \"You do not have the money for me to do this!\"\n");
		return 1;
	}
	
	else
	{
		write("Aeolos nods and says, \"Very well. Travel safely, warrior.\"\n");
		this_player()->add_money(-cost);
		write("You are blinded by a bright flash and appears in a different area.\n");
		move_object(this_player(), "/players/saber/tower/tower20+11.c");
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
		write(YEL+"Aeolos"+NORM+" says, \"You've already completed my task!\n");
		return 1;
	}
	
	person = this_player();
	say("The winds whip about you!\n");
  	call_out("talk",2,person);
	return 1;
}


complete(str)
{
	object bolt, book;
	
	bolt = present("bolt of lightning", this_player());
	
	if(!present("temp_ele_gobj", this_player()))
	{
		write("Aeolos gives you a weird look.\n");
		return 1;
	}
	
	book = present("temp_ele_gobj", this_player());
	
	if(book->query_air())
	{
		write("Aeolos laughs and says, \"You have already completed my task.\"\n");
		return 1;
	}
	
	if(!bolt)
	{
		write("The Winds whirl around aggressively, suffocating you!\n");
		write("Aeolos yells, "+HIR+"\"YOU HAVE FAILED ME, HUMAN!\"\n"+NORM);
		this_player()->hit_player(30, "other|wind");
		return 1;
	}
	
	if(bolt)
	{
		write("The Winds whirl around you happily.\n");
		write("Aeolos smiles happily and grants you his mark.\n");
		destruct(bolt);
		book->set_air(1);
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
  object trap;

   switch(a){
		case 0: stuff = "The Winds nearly take you off of your feet."; break;
		case 1: stuff = " "; break;
		case 2: stuff = "Aeolos says, \"Amongst the clouds near the Guardian Who Waits"; break;
		case 3: stuff = "there is a Lightning Element that resides in the clouds. It"; break;
		case 4: stuff = "strikes down on the earth and ravages the innocent and hurts those very"; break;
		case 5: stuff = "people I have protected for generations. He was pushed aside and deemed"; break;
		case 6: stuff = "unworthy of becoming an Elementalist.\""; break;
		case 7: stuff = " "; break;
		case 8: stuff = "The Elemental sighs in great sorrow."; break;
		case 9: stuff = " "; break;
		case 10: stuff = "\"About a week ago, he tried attacking once again to take"; break;
		case 11: stuff = "control of us and the powers that we possess. He greatly"; break;
		case 12: stuff = "damaged me and took my bolt of lightning. Without my bolt,"; break;
		case 13: stuff = "I am unable to control the lightning and thunder.\""; break;
		case 14: stuff = " "; break;
		case 15: stuff = " "; break;
		case 16: stuff = "\"Unfortunately, this must be your task. I need you to go venture to this place"; break;
		case 17: stuff = "and find the clouds in which he resides, with this you will have power to grab"; break;
		case 18: stuff = "him from the clouds and come back to me with proof that his chaos and terror has"; break;
		case 19: stuff = "ended. Bring me my Bolt of lightning back so I may once again reign the skies."; break;
		case 20: stuff = " "; break;
		case 21: stuff = "\"Return to me once you have the Bolt of Lightning and I will grant you"; break;
		case 22: stuff = "my mark."; break;
		case 23: stuff = " "; break;
		case 24: stuff = "\"I can port you to him for a small fee of 15,000 coins. However, you are"; break;
		case 25: stuff = "responsible for finding your own way back. If you are still interested,"; break;
		case 26: stuff = "just type 'port'.\""; break; }
	 tell_object(person,
     WHT+stuff+NORM+"\n");
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
	tell_object(player, YEL+"Aeolos"+BOLD+" says, \"If you need 'train'ing, just\n");
	tell_object(player, "let me know!\n"+NORM);
	return 1;
}

say_shit2(player)
{
	tell_object(player, YEL+"Aeolos"+BOLD+" says, \"Hello! I can do the following:\n");
	tell_object(player, "'inquire', 'port', and 'complete'.\"\n"+NORM);
	return 1;
}