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
  set_name("aatami");
  set_alt_name("earth");
  set_race("element");
  set_alias("element earth");
  set_short("Aatami, the "+HIW+"Ancient"+NORM+" "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"t"+NORM+" of"+GRN+" Earth"+NORM);
  set_long("\
   An Ancient Element that has been around since existance has come to be.\n\
  It is made of nothing but complete earth and stone as it radiates massive \n\
  power and strength. It had diamonds and gemstones embedded in its body that\n\
  glow and glisten. This is the Ancient Elemental of Earth and and the powers \n\
  and knowledge have been and will always be forever.\n");
 
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
		write("Aatami gives you a weird look.\n");
		return 1;
	}
	
	if(book->query_earth())
	{
		write("Aatami says, \"You have already gained the Mark of the Earth!\"\n");
		return 1;
	}
	
	if(money < cost)
	{
		write("Aatami says, \"You do not have the money for me to do this!\"\n");
		return 1;
	}
	
	else
	{
		write("Aatami nods and says, \"Very well. Travel safely, warrior.\"\n");
		this_player()->add_money(-cost);
		write("You are blinded by a bright flash and appears in a different area.\n");
		move_object(this_player(), "/players/daranath/clearing/geo1.c");
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
		write(GRN+"Aatami"+NORM+" says, \"You've already completed my task!\n");
		return 1;
	}
	
	person = this_player();
	say("The Earthen Master groans loudly.\n");
  	call_out("talk",2,person);
	return 1;
}

complete(str)
{
	object robes, book;
	
	robes = present("geomancer robes", this_player());
	
	if(!present("temp_ele_gobj", this_player()))
	{
		write("Aatami gives you a weird look.\n");
		return 1;
	}
	
	book = present("temp_ele_gobj", this_player());
	
	if(book->query_earth())
	{
		write("Aatami laughs and says, \"You have already completed my task.\"\n");
		return 1;
	}
	
	if(!robes)
	{
		write("The earth beneath you begins to shake. Rock shards pierce your skin!\n");
		write("Aatami yells, "+HIR+"\"YOU HAVE FAILED ME, HUMAN!\"\n"+NORM);
		this_player()->hit_player(30, "other|earth");
		return 1;
	}
	
	if(robes)
	{
		write("The ground tremors softly.\n");
		write("Aatami smiles happily and grants you his mark.\n");
		destruct(robes);
		book->set_earth(1);
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
	   case 0: stuff = "The Earth tremors beneath you."; break;
	   case 1: stuff = " "; break;
	   case 2: stuff = "Aatami says, \"Deep within the heart of Storm Mountain lies"; break;
	   case 3: stuff = "Ragnok the Geomancer. We had many power struggles back when we were"; break;
	   case 4: stuff = "training to become Elementalists. The great power eventually overcame"; break;
	   case 5: stuff = "him and I was forced to have him banished from the Elementalists.\""; break;
	   case 6: stuff = " "; break;
	   case 7: stuff = "The Elemental sighs in great sorrow."; break;
	   case 8: stuff = " "; break;
	   case 9: stuff = "He continues, \"About a month ago, he tried attacking us once again with"; break;
	   case 10: stuff = "a gigantic army that nearly crushed our sacred halls. Luckily, Adroushan"; break;
	   case 11: stuff = "was able to force him away from us just before he was about to destroy our"; break;
	   case 12: stuff = "doors.\""; break;
	   case 13: stuff = " "; break;
	   case 14: stuff = " "; break;
	   case 15: stuff = "\"Unfortunately, this must be your task. I need you to go into Storm Mountain"; break;
	   case 16: stuff = "and destroy my childhood friend, Ragnok. However, don't think that you can just"; break;
	   case 17: stuff = "keep to yourself for a couple of days and come back to me without proof of his"; break;
	   case 18: stuff = "death. Bring me his Robes of the Earth. They were specially crafted for him by"; break;
	   case 19: stuff = "the Ancient Earthen Djinn that granted us our gift of the Earth.\""; break;
	   case 20: stuff = " "; break;
	   case 21: stuff = "\"Return to me once you have the Robes of the Earth and I will grant you"; break;
	   case 22: stuff = "my mark."; break;
	   case 23: stuff = " "; break;
	   case 24: stuff = "\"I can port you to him for a small fee of 15,000 coins. However, you are"; break;
	   case 25: stuff = "responsible for finding your own way back. If you are still interested,"; break;
	   case 26: stuff = "just type 'port'.\""; break; }
     tell_object(person,
     GRN+stuff+NORM+"\n");
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
	tell_object(player, GRN+"Aatami"+BOLD+" says, \"Greetings. If you need 'train'ing, just\n");
	tell_object(player, "let me know.\n"+NORM);
	return 1;
}

say_shit2(player)
{
	tell_object(player, GRN+"Aatami"+BOLD+" says, \"Greetings. I can do the following:\n");
	tell_object(player, "'inquire', 'port', and 'complete'.\"\n"+NORM);
	return 1;
}