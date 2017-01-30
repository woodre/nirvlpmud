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
  set_name("adroushan");
  set_alt_name("fire");
  set_race("element");
  set_alias("element fire");
  set_short("Adroushan, the "+HIW+"Ancient"+NORM+" "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"t"+NORM+" of"+RED+" Fire"+NORM);
  set_long("\
   An Ancient Element that has been around since existance has come to be.\n\
  It is made of nothing but complete fire and blazes with intense heat and \n\
  power. Flames pop and crack as they roar around this massive ball of fire.\n\
  Element of Fire is the exsistance of power and knowledge form which it is\n\
  and always will be the Elemental power of Fire.\n");
 
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
		write("Adroushan gives you a weird look.\n");
		return 1;
	}
	
	if(book->query_fire())
	{
		write("Adroushan says, \"You have already gained the Mark of the Fire!\"\n");
		return 1;
	}
	
	if(money < cost)
	{
		write("Adroushan says, \"You do not have the money for me to do this!\"\n");
		return 1;
	}
	
	else
	{
		write("Adroushan nods and says, \"Very well. Travel safely, warrior.\"\n");
		this_player()->add_money(-cost);
		write("You are blinded by a bright flash and appears in a different area.\n");
		move_object(this_player(), "/players/dune/room/fire9.c");
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
		write(RED+"Adroushan"+NORM+" growls, \"You've already completed my task!\n");
		return 1;
	}
	
	person = this_player();
	say("A large fire sparks up from Adroushan's body!\n");
  	call_out("talk",2,person);
	return 1;
}


complete(str)
{
	object eyes, book;
	
	eyes = present("fire_eyes_elemental", this_player());
	
	if(!present("temp_ele_gobj", this_player()))
	{
		write("Adroushan gives you a weird look.\n");
		return 1;
	}
	
	book = present("temp_ele_gobj", this_player());
	
	if(book->query_fire())
	{
		write("Adroushan laughs and says, \"You have already completed my task.\"\n");
		return 1;
	}
	
	if(!eyes)
	{
		write("A Fire consumes the area. The fire jumps on you and sears your skin!\n");
		write("Adroushan yells, "+HIR+"\"YOU HAVE FAILED ME, HUMAN!\"\n"+NORM);
		this_player()->hit_player(30, "other|fire");
		return 1;
	}
	
	if(eyes)
	{
		write("The fire glows brightly.\n");
		write("Adroushan smiles happily and grants you his mark.\n");
		destruct(eyes);
		book->set_fire(1);
		command("bsave", this_player());
		return 1;
	}
	return 1;
}

talk(person)
{
	say_it();
	a += 1;
	if(a<30) call_out("talk",1,person);
	else {
		play = 0;
		a = 0;
	}
	return 1;
}

say_it(){
  string stuff;
  
   switch(a){
	   case 0: stuff = "The fire around Adroushan's body sparks brightly!"; break;
	   case 1: stuff = " "; break;
	   case 2: stuff = "Adroushan growls, \"Many years ago, I lost my way as an Elementalist."; break;
	   case 3: stuff = "I took my anger and frustrations out on the people of the World that"; break;
	   case 4: stuff = "I was bound to protect. The world has since forgiven me. Except for"; break;
	   case 5: stuff = "one. Saal, the \"Lord of Fire\"."; break;
	   case 6: stuff = " "; break;
	   case 7: stuff = "The Elemental growls in disgust."; break;
	   case 8: stuff = " "; break;
	   case 9: stuff = "He continues, \"He has been the only one to pull the wool over my eyes."; break;
	   case 10: stuff = "A couple of months ago, he begged me to visit him. Being foolish, I"; break;
	   case 11: stuff = "obliged. When I arrived at his lair, he had his minions throw some of"; break;
	   case 12: stuff = "Glyndwr's magical waters on me that greatly weakened me. Saal walked"; break;
	   case 13: stuff = "over to me and ripped out my Eyes of Fire."; break;
	   case 14: stuff = " "; break;
	   case 15: stuff = "\"Since then, I have lost my control over the fires and the ability to"; break;
	   case 16: stuff = "dampen the Fires that Saal has running rampant all over the world.\""; break;
	   case 17: stuff = " "; break;
	   case 18: stuff = "\"This is where you come in.\""; break;
	   case 19: stuff = " "; break;
	   case 20: stuff = "\"Venture into the old Elemental Tower and hunt down Saal. When you find"; break;
	   case 21: stuff = "find him, kill him and rip out the eyes. Bring back the eyes to me so I"; break;
	   case 22: stuff = "may once again control the Fires of the world."; break;
	   case 23: stuff = " "; break;
	   case 24: stuff = "\"Bring me back the Eyes of Fire and I will grant you my mark. When\""; break;
	   case 25: stuff = "you return, tell me that the mission is 'complete'.\""; break;
	   case 26: stuff = " "; break;
	   case 27: stuff = "\"I can port you to him for a small fee of 15,000 coins. However, you are"; break;
	   case 28: stuff = "responsible for finding your own way back. If you are still interested,"; break;
	   case 29: stuff = "just type 'port'.\""; break; }
     tell_object(person,
     RED+stuff+NORM+"\n");
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
	tell_object(player, RED+"Adroushan"+BOLD+" snarls. \"If you need me to 'train' you,\n");
	tell_object(player, "then just tell me.\"\n"+NORM);
	return 1;
}

say_shit2(player)
{
	tell_object(player, RED+"Adroushan"+BOLD+" snarls. \"I can only do the following:\n");
	tell_object(player, "'inquire', 'port', and 'complete'.\n"+NORM);
	return 1;
}