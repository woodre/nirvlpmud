inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>
string person;
int a, play;

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("teacher");
	set_alt_name("evil teacher");
	set_race("human");
	set_alias("pre-k teacher");
	set_short("An angry Pre-K teacher");
	set_long("\
	This is a very tall teacher with long, flowing\n\
	brown hair that goes to her mid-back. She has a very\n\
	angry look on her face as if something has happened to her.\n\
	Maybe you can 'ask' about her problem.\n");
	set_level(1);
	set_hp(1 + random (1));
	set_ac(1 + random (1));
	set_wc(1 + random(1));
	set_al(-7000);
	set_chat_chance(2);
	load_chat(query_name()+" says, \"I can't wait for these little brats to leave!\"\n");
	load_chat(query_name()+" says, \"WHY did I have to be a teacher? This is the worst job EVER.\"\n");
}

init(){
  ::init();
	add_action("ask","ask");
  }
  
ask()
{
	person = this_player();
	play = 1;
 	call_out("talk",2,person);
 	return 1;
}

talk(person)
{
	say_it();
	a += 1;
  	if(a<19) call_out("talk",1,person);
  	else {
	play = 0;
	a = 0;
  	}
  	return 1;
}

say_it()
{
	string stuff;
	 switch(a){
		 case 0: stuff = " "; break;
		 case 1: stuff = "			The teacher looks at you with furious eyes."; break;
		 case 2: stuff = " "; break;
		 case 3: stuff = "			  This is the worst job I've ever had."; break;
		 case 4: stuff = "			     These brats ganged up on me."; break;
		 case 5: stuff = "			They grabbed my purse and ran around."; break;
		 case 6: stuff = "			   Now they are all over the place!"; break;
		 case 7: stuff = " "; break;
		 case 8: stuff = "			    The teacher pauses for a moment."; break;
		 case 9: stuff = "			  She takes a look around and whispers,"; break;
		 case 10: stuff = " "; break;
		 case 11: stuff = "			   If you get my stuff back from these..."; break;
		 case 12: stuff = " "; break;
		 case 13: stuff = "		  A vein in the teachers neck starts to protrude..."; break;
		 case 14: stuff = " "; break;
		 case 15: stuff = "		 		     T H I E V E S"; break;
		 case 16: stuff = "	  	       You can 'exchange' my items for money."; break;
		 case 17: stuff = "		      Get my stuff back by any means necessary!"; break;
		 case 18: stuff = " "; break; }
		 tell_object(person,
     	 BOLD+stuff+NORM+"\n");
     	 return 1;}