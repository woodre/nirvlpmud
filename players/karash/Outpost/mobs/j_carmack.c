
inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: j_carmack.c
 * Path: /players/karash/Outpost/mobs
 * Type: Mob
 * Created: July 2014 by Karash
 *
 * Purpose: A non-killable mob in the Outpost introductory area used to enhance
 *			the initial theme of the id software group.   
 * 
 * History:
 *          
 ******************************************************************************/

object attacker;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("John Carmack");
  SetMultipleIds( ({ "john", "carmack", "john carmack" }) );
  set_race("human");
  set_short("John Carmack");
  set_long(
    "  John Carmack sits on a tall office stool behind the podium furiously\n\
typing on the laptop in front of him.  The glare from the screen\n\
reflects off his glasses as he pauses to acknowledge you.  He has\n\
short blonde hair and dressed in a business casual manner.  You have\n\
heard comments made by others around the complex that suggest this\n\
John is actually the brains behind this technology.  He is a highly\n\
technical individual and an innovative programmer.\n");
  set_level(18);
  set_al(0);
  set_ac(15);
  set_wc(26);
  set_hp(400);
  set_gender("male");
  /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(1);
   load_chat("John assures you, 'I am a programmer.  I can always make this better.'\n");
   load_chat("John says, 'Have you seen Romero's new "+YEL+"possession"+NORM+"? "+BBLK+HIW+"You should see his ego\n\
when you compliment it, it's unbearable."+NORM+"'\n");
   load_chat("John says, 'I could change the world if I could only get the source code.'\n");
  set_a_chat_chance(3);
   load_a_chat("John laughs: 'Poor foolish person.  Will you never learn?'\n");
   load_a_chat("John says, 'You should stop now because I can do this all day.'\n");
   load_a_chat("John Carmack yawns.\n");
   
   set_heal(400,1);
    
   }
  
void init()
{
  ::init();
    
	add_action("no_kill", "kill");

    if( this_player() && this_player()->is_player())
      call_out( "tellroom", 2 );	
}
  
/** Witty sayings by John Carmack when attacker tries to 'kill' him **/
no_kill(str)
{

	attacker = this_player();
	
    if(str == "john" || str == "carmack" || str == "john carmack") 
	{
      if(present("john carmack",environment()))
	  {
	    switch( random(10) ) 
		{
		case(9):
	  tell_object(this_player(),"\n\John Carmack is the only barrier between Nirvana and the evil that\n\
threatens its existence.  Let's not interrupt his work!\n\n");
	    break;
		case(8):
	  tell_object(this_player(),"\n\John Carmack laughs at your persistent failure.\n"
+CYAN+"while(!(succeed = try()));"+NORM+" is an endless loop for you.\n\n");
        break;
        case(7):
      tell_object(this_player(),"\n\Seriously...go bother Romero.  "+HIY+"TELL HIM HIS "+NORM+GRY+"SWORD"+NORM+HIY+" IS AWESOME"+NORM+" or something.\n\n");
	    break;
		case(6):
	  tell_object(this_player(),GRN+"\n\if(present(sad(),"+(this_player()->query_name())+"() {\n\
  destruct('sad');\n\
  move_object(clone_object(smile.c),"+(this_player()->query_name())+"();\n\
  command('wear smile', "+(this_player()->query_name())+"());\n\
  beHappy();\n\
  }"+NORM+"\n\n");
	    break;
		case(5):
	  tell_object(this_player(),"\n\*Error in killing object\n\n");
	  call_out("callout1", 2 );
	    break;
		case(4):
	  tell_object(this_player(),"\n\There is a scene in 'The Color of Money' where Tom Cruise shows up at\n\
a pool hall with a custom pool cue in a case. 'What do you have in\n\
there?' asks someone. 'Doom' replied Cruise with a cocky grin.  "+HIR+"Doom."+NORM+"\n\n");
        break;
		case(3):
   	  tell_object(this_player(),"\n\John says, '"+GRN+"Save your aggression for when I reopen the slipgate."+NORM+"'\n\n");
	    break;
		case(2):
  	  tell_object(this_player(),"\n\John sarcastically trembles waving his hands about, '"+CYAN+"Oh, look at big,\n\
bad, mean old "+NORM+HIC+(this_player()->query_name())+NORM+CYAN+" trying to attack everything in sight."+NORM+"'\n\n");
 	    break;
		case(1):
	  tell_object(this_player(),HIR+"\n\You attack John Carmack haphazardly and fall into the slipgate which\n\
instantaneously transports you to an unknown place."+NORM+"\n\n\
                    "+RED+"["+NORM+"House of Chthon"+RED+"]"+NORM+"\n\
You stand in an immense stone room with a massive lava pool in the\n\
center.  Emerging from the lava is a gigantic monster with a face\n\
consisting of only a vertical mouth full of jagged teeth, no eyes,\n\
and no nose.  It raises his long claws to hurl a lava ball at you.\n\
     There are no obvious exits:\n\
Chthon.\n\n");
      call_out("callout2",2);
	  break;
	  default:
	  tell_object(this_player(),"\n\John Carmack is the only barrier between Nirvana and the evil that\n\
threatens its existence.  Let's not interrupt his work!\n\n");
	  break;
	  }
	  return 1;
	  
	  }
    }
}


callout1()
{
  tell_object(attacker,"\n"+YEL+"John grins evilly!"+NORM+"\n\n");
  return 1;
}


callout2()
{

  tell_object(attacker,(attacker->query_name())+" missed Chthon.\n\
Chthon hits you for "+HIR+"MASSIVE DAMAGE"+NORM+".\n\
"+RED+"<<<< HP "+(attacker->query_mhp())/25+"/"+attacker->query_mhp()+" SP "+attacker->query_sp()+"/"+attacker->query_msp()+" I 0 F 0 S 0 T 0 AHP: 10/10 >>>>"+NORM+"\n\n");
  call_out("callout3",2);
  return 1;
}


callout3()
{
  tell_object(attacker,"HAHAHAHAHA!\n\John Carmack waves his index finger at you while laughing and says,\n\
"+CYAN+"'No, no, no.  Spoilers!'"+NORM+"\n");
  return 1;
}

/** Return 0 for do_damage to make John Carmack unkillable **/
do_damage()
{
  return 0;
}

/** These are sayings for John Carmack to say at init **/
tellroom()
{
  switch( random(5) ) {
    case 4:
      tell_room(environment(),"John says, 'Welcome to the slipgate mobile unit.'\n");
    break;
    case 3:
      tell_room(environment(),"John says, 'Hello, I'm glad to see you interested in joining our cause.'\n");
    break;
	case 2:
      tell_room(environment(),"John says, 'Feel free to check out the complex until we are ready to\n\
open the slipgate again.'\n");
    break;
	case 1:
      tell_room(environment(),"John says, 'Hi there.  I knew we would find some strong, willing\n\
volunteers to stop this threat.'\n");
    break;
    default:
      tell_room(environment(),"John exclaims, 'Excellent!  More firepower!  I will let you know when\n\
I get the slipgate reopened.'\n");
    break;
  }
}