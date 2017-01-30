/*
 * Doorknob
 * Cloud 2009
 * Not meant to be killed. Used as a way out of fayring.c!
 */
 
 
#include "/obj/ansi.h"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
  gold = clone_object("obj/money");
  gold->set_money(1);
  move_object(gold,this_object());

     set_name("doorknob");
     set_alt_name("knob");
     set_short(""+HIY+"A brass doorknob"+NORM+"");
     set_race( "Knob");
     set_gender("knob");
     set_alias("doorknob");
     set_long("This bright brass doorknob floats around the area freely.\n" +
     		  "On the end of a knob a face of brass moves as if alive.\n" +
     		  "It looks as if it wants you to turn it.\n");       
     set_level(18);
     set_ac(5000);
     set_wc(14);
     set_hp(3000);
     set_al(999);
     set_aggressive(0);
     set_chat_chance(5);
     load_chat(""+HIY+"The Doorknob says:"+NORM+" You know you want to turn me.\n");
   }
}


heart_beat()
{
  ::heart_beat();
  heal_self(1000);
  if(!environment()) return;
  if(attacker_ob && present(attacker_ob, environment(this_object())))
  {
    if(random(100) > 80) why_fight();
    if(random(100) > 90) turn_me();

  }
}


turn_me()
{
	tell_room(environment(),
	"\n"+HIY+"The Doorknob Exclaims, If you want to leave you will have to "+HIC+"turn"+HIY+" me!"+NORM+"\n");
}

why_fight()
{
    
  tell_room(environment(),
   "\n"+HIY+"The Doorknob Exclaims, More turning less fighting!"+NORM+"\n");    
}

init()
{
	::init();
	add_action("turn","turn");
}

turn(string str)
{		
	if(str == "knob")
  	{				
		tell_object(this_player(),
	  			"\n"+HIW+"As you turn the knob you are sucked back upwards into the platform."+NORM+"\n\n");
		tell_room(environment(this_player()),
				"\n"+HIW+this_player()->query_name()+" turns the knob and is sucked upwards into the platform."+NORM+"\n\n", ({ this_player() }));
		move_object(this_player(), "/players/cloud/Fayawyn/rooms/fay6.c");
		command("look", this_player());			
		return 1; 
 	}
 		
 	if(str == "doorknob")
  	{				
		tell_object(this_player(),
	  			"\n"+HIW+"As you turn the knob it screams and you are sucked back upwards into the platform."+NORM+"\n\n");
		tell_room(environment(this_player()),
				"\n"+HIW+this_player()->query_name()+" turns the knob and is sucked upwards into the platform."+NORM+"\n\n", ({ this_player() }));
		move_object(this_player(), "/players/cloud/Fayawyn/rooms/fay6.c");	
		command("look", this_player());					
		return 1;
 	}
 		 
  	else
  	{
	  	write("Turn what?\n");
	  	return 1;
  	}
}
