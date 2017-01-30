inherit "/obj/monster";
#include "/sys/lib.h"
#include "../../defs.h"
#include <ansi.h>

int a, play, b, run;
string person;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("khnum");
  set_alt_name("elements");
  set_race("element");
  set_alias("khnum");
  set_short(BOLD+"Khnum"+NORM+", "+HIW+"Ancient Master "+NORM+"of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM);
  set_long("\
   An ancient master of the Elements with eyes that shimmer the color of the.\n\
  four elements. His hair is silver and glistens and blows in the soft wind.\n\
  Power and strength radiate from his aura. As he stands meditating in a deep\n\
  focused state of high knowledge and power. He is the only Legendary \n\
  Elder that still lives today to pass knowledge to the new generation of uprising\n\
  Elementalists\n");
 
  set_level(19);
  set_hp(100000+ random(100000));
  set_ac(99+ random(1));
  set_wc(99+ random(2));
  set_al(0);
  set_chat_chance(10);
  /*load_chat(BOLD+"Khnum "+NORM+"says,\n \"If you have the marks of the Elementals, you can 'complete' the final task!\"\n");*/
  }

  
init()
{
	::init();
	
	add_action("recruit_process", "recruit_process");
	add_action("complete", "complete");
}

recruit_process()
{
	object trap;
	
		trap = clone_object("/players/wicket/guild/objs/earthtrap.c");
		move_object(trap, this_player());
		write("Khnum yells, "+HIR+"\"HALT!!!\"\n"+NORM);
		write("Khnum casts an "+HIY+"EARTHEN TRAP"+NORM+" around your legs!\n");
  		person = this_player();
  		play = 1;
  		call_out("talk",2,person);
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
  
  trap = present("no_escape_bitch", person);
   switch(a){
	   case 0: stuff = " "; break;
	   case 1: stuff = "Khnum examines you.\n"; break;
	   case 2: stuff = " "; break;
	   case 3: stuff = "Khnum says, \"Who are you and why are you here?\n"; break;
	   case 4: stuff = "Khnum continues, \"Nevermind. It's not like it matters.\"\n"; break;
	   case 5: stuff = "Khnum raises his staff and begins to cast a deadly spell!\n"; break;
	   case 6: stuff = " "; break;
	   case 7: stuff = "Suddenly, he lowers his staff staring in disbelief at the book that you hold.\n"; break;
	   case 8: stuff = " "; break;
	   case 9: stuff = "	   "+HIR+"\"HOW DID YOU OBTAIN THAT BOOK?\"\n"+NORM; break;
	   case 10: stuff = "\"Wait a minute... Are you a potential recruit???\"\n"; break;
	   case 11: stuff = " "; break;
	   case 12: stuff = " "; break;
	   case 13: stuff = "\"Oh my! I'm so sorry! I didn't mean to threaten you!\"\n"; break;
	   case 14: stuff = " "; break;
	   case 15: stuff = " "; break;
	   case 16: stuff = "Khnum flashes a wicked grin.\n"; break;
	   case 17: stuff = " "; break;
	   case 18: stuff = "Khnum says, \"So you're interested, huh?\n"; break;
	   case 19: stuff = "Khnum continues, \"Keep the book. Study it. Absorb its knowledge.\"\n"; break;
	   case 20: stuff = "Khnum pauses for a moment!\n"; break;
	   case 21: stuff = " "; break;
	   case 22: stuff = "\"You will need to talk with the masters of each Element to gain\n"; break;
	   case 23: stuff = "their blessing. They will most likely ask you to bring something\n"; break;
	   case 24: stuff = "of great importance to them. Do as they ask and then we will\n"; break;
	   case 25: stuff = "form you into a true Master of the Elements.\n"; break;
	   case 26: stuff = " "; destruct(trap); break; }
     tell_object(person,
     BOLD+stuff+NORM+"\n");
     return 1; }
     
complete()
{
	object book, GOBJ;
	int currentexp;
	string pre;
	
	book = present("temp_ele_gobj", this_player());
	GOBJ = clone_object("/players/wicket/guild/gob.c");
	
	if(!book)
	{
		write("Khnum gives you a weird look.\n");
		return 1;
	}
	

	
	if(!book->query_air() || !book->query_earth() || !book->query_fire() || !book->query_water())
	{
		write("Khnum laughs at you and exclaims, \"You haven't completed their tasks yet!\"\n");
		return 1;
	}
	
	if(this_player()->query_wc())
	{
		write("Khnum laughs at you and says, \"You must remove your weapon first!\"\n");
		return 1;
	}
	
	if(this_player()->query_ac())
	{
		write("Khnum laughs at you and says, \"You must remove your armor first!\"\n");
		return 1;
	}
	
	pre = "";
	pre += MAG+" <"+NORM+"-"+MAG+"> "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+MAG+" <"+NORM+"-"+MAG+"> "+NORM;
	pre += HIK+"Khnum"+NORM+" just introduced "+this_player()->query_name()+" to the guild!\n";
	
	if(book->query_air() && book->query_earth() && book->query_fire() && book->query_water())
	{
		write("Khnum cackles and says, \"Very well! You are now an Elementalist!\"\n");
		destruct(book);
		move_object(GOBJ, this_player());
		currentexp = (int)this_player()->query_exp();
		this_player()->add_exp(-currentexp);
		this_player()->add_exp(620026);
		this_player()->set_level(15);
		this_player()->set_extra_level(0);
		this_player()->set_guild_name("Elementalist");
		this_player()->set_home("/players/wicket/guild/hall/rooms/entrance.c");
		"/bin/channel_daemon.c"->add_channel(CHAN_NAME, this_player());
		"/bin/channel_daemon.c"->transmit_message(CHAN_NAME, pre);
		command("gsave", this_player());		
		return 1;
	}
	return 1;
}

catch_tell(str)
{
	object player;
	string who;
	
	if(!str) return;
	
	if(sscanf(str, "%s arrives.", who) != 1) return;
	
	player = find_player(lower_case(who));
	
	
	if(!player) return;
	
	if(present("temp_ele_gobj", player))
	{
		call_out("say_shit1", 2, player);
		return 1;
	}
	
	if(!present("temp_ele_gobj", player))
	{
		call_out("say_shit2", 2, player);
		return 1;
	}
	return 1;
}

say_shit1(player)
{
	tell_object(player, BOLD+"Khnum"+NORM+" says, \"Greetings. If you have the required Marks of the Elements,\n");
	tell_object(player, "you can 'complete' my task and become an Elementalist.\"\n"+NORM);
	return 1;
}

say_shit2(player)
{
	tell_object(player, BOLD+"Khnum"+NORM+" says, \"If your Magic Aptitude is at 30, I can\n");
	tell_object(player, "raise it up to a maximum of 50 for a cost of 50,000 experience each.\n");
	tell_object(player, "Just let me know if you would like to 'raise' your 'mag'ic aptitude.\"\n");
	return 1;
}