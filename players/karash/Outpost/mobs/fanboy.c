
inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: fanboy.c
 * Path: /players/karash/Outpost/mobs
 * Type: Mob
 * Created: July 2014 by Karash
 *
 * Purpose: A minion mob in the Outpost introductory area called by the Daikatana;
 *			Fanboy does nothing when called by Player, but is activated by the
 *			presence of John Romero.  If Romero is in combat, Fanboy activates a
 *			timer that will do heavy "unrestricted" (laser) damage to entire room.
 * 
 * History:
 *          
 ******************************************************************************/

#define FANBOYDAMAGE 350
 
int x; /* For the detonator timer */
object jromero, jrattacker;  /* For checking if Romero is present & being attacked */

 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("fanboy");
  SetMultipleIds( ({ "fanboy", "boy", "fanboy" }) );
  set_race("human");
  set_short("Fanboy");
  setlongdescr();  /* calls function to set various descriptions */
  set_level(2);
  set_al(-random(100));
  set_ac(3);
  set_wc(5);
  set_hp(15);
  set_res(0);
  set_dead_ob(this_object());

  set_aggressive(0);
  set_chat_chance(3);
    load_chat("Fanboy looks around dazed and confused.\n");
    load_chat("Fanboy says, 'John Romero is like a god.'\n");
 
  }
 


heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  
  if(!present("john romero",environment()) && x==0) 
  {
    if(!random(25))
	{
      tell_room(environment(),  "Fanboy says, 'Where is John Romero?  I was wanting to see John Romero.'\n");
    } 
	return;
  }
  
  /***********************************************************************************
  /** John Romero must be present and attacked for fanboy to activate the timer,
  /** but once the timer is activated, it does not matter if John Romero is present
  /** or not - the timer will continue as long as someone is in the room to keep
  /** the heartbeat active
  /***********************************************************************************/
  jromero = present("john romero",environment());
  if(jromero || x>0)
  {
    jrattacker = jromero->query_attack();
    if(jrattacker || x>0)
	{    
      
	  x++;
	 
      /* for testing */
	  /* tell_room(environment(), "x = "+x+"\n"); */
	
	/*CheckPoint for Testing
	/*tell_room(environment(),  "ROMERO IS BEING ATTACKED BY "+jrattacker->query_name()+"\n");
    /**/
	
	/***********************************************
	 * If Romero is present and being attacked
	 * Start the countdown to detonation, which CANNOT be stopped with calm spell
	 * Once countdown starts, players must KILL fanboy to stop detonation
	 ***********************************************/
	 
      if(x==1) 
      {
	    tell_room(environment(), "\n\At the sight of John Romero being attacked by "+HIR+jrattacker->query_name()+NORM+",\n\
fanboy pulls out a "+CYAN+"futuristic device"+NORM+" from his pocket and walks\n\
toward those who threaten his hero.\n");
	  	  
		/* FANBOY ACTIVATED */
		tell_room(environment(), "\n\n");
		tell_room(environment(), YEL+"----------------------------------------------------"+NORM+"\n");
		tell_room(environment(), YEL+"FFFFFFF"+BLK+"...."+YEL+"AAA"+BLK+"...."+YEL+"NN"+BLK+"..."+YEL+"NN"+BLK+".."+YEL+"BBBBBB"+BLK+"...."+YEL+"OOOOO"+BLK+"..."+YEL+"YY"+BLK+"..."+YEL+"YY"+NORM+"\n");
		tell_room(environment(), ""+YEL+"FF"+BLK+"........"+YEL+"AA"+BLK+"."+YEL+"AA"+BLK+"..."+YEL+"NNN"+BLK+".."+YEL+"NN"+BLK+".."+YEL+"BB"+BLK+"..."+YEL+"BB"+BLK+".."+YEL+"OO"+BLK+"..."+YEL+"OO"+BLK+".."+YEL+"YY"+BLK+"..."+YEL+"YY\n");
		tell_room(environment(), ""+YEL+"FF"+BLK+"......."+YEL+"AA"+BLK+"..."+YEL+"AA"+BLK+".."+YEL+"NNNN"+BLK+"."+YEL+"NN"+BLK+".."+YEL+"BB"+BLK+"..."+YEL+"BB"+BLK+".."+YEL+"OO"+BLK+"..."+YEL+"OO"+BLK+".."+YEL+"YY"+BLK+"..."+YEL+"YY\n");
		tell_room(environment(), ""+YEL+"FFFFFFF"+BLK+".."+YEL+"AAAAAAA"+BLK+".."+YEL+"NN"+BLK+"."+YEL+"N"+BLK+"."+YEL+"NN"+BLK+".."+YEL+"BBBBBB"+BLK+"..."+YEL+"OO"+BLK+"..."+YEL+"OO"+BLK+"..."+YEL+"YY"+BLK+"."+YEL+"YY\n");
		tell_room(environment(), ""+YEL+"FF"+BLK+"......."+YEL+"AA"+BLK+"..."+YEL+"AA"+BLK+".."+YEL+"NN"+BLK+".."+YEL+"NNN"+BLK+".."+YEL+"BB"+BLK+"..."+YEL+"BB"+BLK+".."+YEL+"OO"+BLK+"..."+YEL+"OO"+BLK+"...."+YEL+"YYY\n");
		tell_room(environment(), ""+YEL+"FF"+BLK+"......."+YEL+"AA"+BLK+"..."+YEL+"AA"+BLK+".."+YEL+"NN"+BLK+".."+YEL+"NNN"+BLK+".."+YEL+"BB"+BLK+"..."+YEL+"BB"+BLK+".."+YEL+"OO"+BLK+"..."+YEL+"OO"+BLK+"...."+YEL+"YYY\n");
		tell_room(environment(), ""+YEL+"FF"+BLK+"......."+YEL+"AA"+BLK+"..."+YEL+"AA"+BLK+".."+YEL+"NN"+BLK+"..."+YEL+"NN"+BLK+".."+YEL+"BBBBBB"+BLK+"...."+YEL+"OOOOO"+BLK+"....."+YEL+"YYY\n");
		tell_room(environment(), "\n");
		tell_room(environment(), BLK+"............"+YEL+"A"+BLK+".."+YEL+"C"+BLK+".."+YEL+"T"+BLK+".."+YEL+"I"+BLK+".."+YEL+"V"+BLK+".."+YEL+"A"+BLK+".."+YEL+"T"+BLK+".."+YEL+"E"+BLK+".."+YEL+"D"+BLK+"............"+NORM+"\n");
		tell_room(environment(), YEL+"----------------------------------------------------"+NORM+"\n");
		tell_room(environment(), "\n\n");
		return;
      }
      else if (x==2)
      {
	    tell_room(environment(), "\n\Fanboy shouts, 'I will not let you hurt John Romero!'\n");
		/* Commencing Countdown THREE */
		tell_room(environment(), "\n\n");
		tell_room(environment(), YEL+"---------------------------------------------------------"+NORM+"\n");
		tell_room(environment(), YEL+"C"+BLK+".."+YEL+"O"+BLK+".."+YEL+"M"+BLK+".."+YEL+"M"+BLK+".."+YEL+"E"+BLK+".."+YEL+"N"+BLK+".."+YEL+"C"+BLK+".."+YEL+"I"+BLK+".."+YEL+"N"+BLK+".."+YEL+"G"+BLK+"...."+YEL+"C"+BLK+".."+YEL+"O"+BLK+".."+YEL+"U"+BLK+".."+YEL+"N"+BLK+".."+YEL+"T"+BLK+".."+YEL+"D"+BLK+".."+YEL+"O"+BLK+".."+YEL+"W"+BLK+".."+YEL+"N"+NORM+"\n\n");
		tell_room(environment(), BLK+".........................."+YEL+"33333"+NORM+"\n");
		tell_room(environment(), BLK+"........................."+YEL+"33"+BLK+"..."+YEL+"33"+NORM+"\n");
		tell_room(environment(), BLK+".............................."+YEL+"33"+NORM+"\n");
		tell_room(environment(), BLK+"............................"+YEL+"33"+NORM+"\n");
		tell_room(environment(), BLK+".............................."+YEL+"33"+NORM+"\n");
		tell_room(environment(), BLK+"........................."+YEL+"33"+BLK+"..."+YEL+"33"+NORM+"\n");
		tell_room(environment(), BLK+".........................."+YEL+"33333"+NORM+"\n");
		tell_room(environment(), YEL+"---------------------------------------------------------"+NORM+"\n");
		tell_room(environment(), "\n\n");
		return;
      }
      else if (x==3)
      {
   	    tell_room(environment(), "\n\Fanboy shouts, 'You asked for it!'\n");
		/* Commencing Countdown TWO */	  
		tell_room(environment(), "\n\n");
		tell_room(environment(), YEL+"---------------------------------------------------------"+NORM+"\n");
		tell_room(environment(), YEL+"C"+BLK+".."+YEL+"O"+BLK+".."+YEL+"M"+BLK+".."+YEL+"M"+BLK+".."+YEL+"E"+BLK+".."+YEL+"N"+BLK+".."+YEL+"C"+BLK+".."+YEL+"I"+BLK+".."+YEL+"N"+BLK+".."+YEL+"G"+BLK+"...."+YEL+"C"+BLK+".."+YEL+"O"+BLK+".."+YEL+"U"+BLK+".."+YEL+"N"+BLK+".."+YEL+"T"+BLK+".."+YEL+"D"+BLK+".."+YEL+"O"+BLK+".."+YEL+"W"+BLK+".."+YEL+"N"+NORM+"\n\n");
		tell_room(environment(), BLK+".........................."+YEL+"22222"+NORM+"\n");
		tell_room(environment(), BLK+"........................."+YEL+"22"+BLK+"..."+YEL+"22"+NORM+"\n");
		tell_room(environment(), BLK+".............................."+YEL+"22"+NORM+"\n");
		tell_room(environment(), BLK+"............................"+YEL+"22"+NORM+"\n");
		tell_room(environment(), BLK+"..........................."+YEL+"22"+NORM+"\n");
		tell_room(environment(), BLK+".........................."+YEL+"22"+NORM+"\n");
		tell_room(environment(), BLK+"........................."+YEL+"2222222"+NORM+"\n");
		tell_room(environment(), YEL+"---------------------------------------------------------"+NORM+"\n");
		tell_room(environment(), "\n\n");
		return;
      }
      else if (x==4)
      {
  	    tell_room(environment(), "\n\Fanboy shouts, 'There is no stopping this now!'\n");
		/* Commencing Countdown ONE */
		tell_room(environment(), "\n\n");
		tell_room(environment(), YEL+"---------------------------------------------------------"+NORM+"\n");
		tell_room(environment(), YEL+"C"+BLK+".."+YEL+"O"+BLK+".."+YEL+"M"+BLK+".."+YEL+"M"+BLK+".."+YEL+"E"+BLK+".."+YEL+"N"+BLK+".."+YEL+"C"+BLK+".."+YEL+"I"+BLK+".."+YEL+"N"+BLK+".."+YEL+"G"+BLK+"...."+YEL+"C"+BLK+".."+YEL+"O"+BLK+".."+YEL+"U"+BLK+".."+YEL+"N"+BLK+".."+YEL+"T"+BLK+".."+YEL+"D"+BLK+".."+YEL+"O"+BLK+".."+YEL+"W"+BLK+".."+YEL+"N"+NORM+"\n\n");
		tell_room(environment(), BLK+"............................"+YEL+"11"+NORM+"\n");
		tell_room(environment(), BLK+"..........................."+YEL+"111"+NORM+"\n");
		tell_room(environment(), BLK+"............................"+YEL+"11"+NORM+"\n");
		tell_room(environment(), BLK+"............................"+YEL+"11"+NORM+"\n");
		tell_room(environment(), BLK+"............................"+YEL+"11"+NORM+"\n");
		tell_room(environment(), BLK+"............................"+YEL+"11"+NORM+"\n");
		tell_room(environment(), BLK+".........................."+YEL+"111111"+NORM+"\n");
		tell_room(environment(), YEL+"---------------------------------------------------------"+NORM+"\n");
		tell_room(environment(), "\n\n");
		return;
      }
      else if (x==5)
      {
      tell_room(environment(), "\n\Fanboy detonates the device causing a huge explosion throughout the room.'\n");
      /* DETONATION - !BOOM! */
      tell_room(environment(), "\n\n");
      tell_room(environment(), HIR+"---------------------------------------------------------"+NORM+"\n");
      tell_room(environment(), BLK+"..."+HIR+"!!"+NORM+BLK+".."+HIR+"BBBBBB"+NORM+BLK+"...."+HIR+"OOOOO"+NORM+BLK+"...."+HIR+"OOOOO"+NORM+BLK+"..."+HIR+"MM"+NORM+BLK+"......."+HIR+"MM"+NORM+BLK+".."+HIR+"!!"+NORM+"\n");
      tell_room(environment(), BLK+"..."+HIR+"!!"+NORM+BLK+".."+HIR+"BB"+NORM+BLK+"..."+HIR+"BB"+NORM+BLK+".."+HIR+"OO"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+".."+HIR+"OO"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+".."+HIR+"MMM"+NORM+BLK+"....."+HIR+"MMM"+NORM+BLK+".."+HIR+"!!"+NORM+"\n");
      tell_room(environment(), BLK+"..."+HIR+"!!"+NORM+BLK+".."+HIR+"BB"+NORM+BLK+"..."+HIR+"BB"+NORM+BLK+".."+HIR+"OO"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+".."+HIR+"OO"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+".."+HIR+"MMMM"+NORM+BLK+"..."+HIR+"MMMM"+NORM+BLK+".."+HIR+"!!"+NORM+"\n");
      tell_room(environment(), BLK+"..."+HIR+"!!"+NORM+BLK+".."+HIR+"BBBBBB"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+".."+HIR+"OO"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+".."+HIR+"MM"+NORM+BLK+".."+HIR+"MMM"+NORM+BLK+".."+HIR+"MM"+NORM+BLK+".."+HIR+"!!"+NORM+"\n");
      tell_room(environment(), BLK+"..."+HIR+"!!"+NORM+BLK+".."+HIR+"BB"+NORM+BLK+"..."+HIR+"BB"+NORM+BLK+".."+HIR+"OO"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+".."+HIR+"OO"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+".."+HIR+"MM"+NORM+BLK+"..."+HIR+"M"+NORM+BLK+"..."+HIR+"MM"+NORM+BLK+".."+HIR+"!!"+NORM+"\n");
      tell_room(environment(), BLK+"......."+HIR+"BB"+NORM+BLK+"..."+HIR+"BB"+NORM+BLK+".."+HIR+"OO"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+".."+HIR+"OO"+NORM+BLK+"..."+HIR+"OO"+NORM+BLK+".."+HIR+"MM"+NORM+BLK+"......."+HIR+"MM"+NORM+BLK+"...."+NORM+"\n");
      tell_room(environment(), BLK+"..."+HIR+"!!"+NORM+BLK+".."+HIR+"BBBBBB"+NORM+BLK+"...."+HIR+"OOOOO"+NORM+BLK+"...."+HIR+"OOOOO"+NORM+BLK+"..."+HIR+"MM"+NORM+BLK+"......."+HIR+"MM"+NORM+BLK+".."+HIR+"!!"+NORM+"\n");
      tell_room(environment(), HIR+"---------------------------------------------------------"+NORM+"\n");
      tell_room(environment(), "\n\n");

      tell_room(environment(), "A massive wave of "+CYAN+"energy"+NORM+" disseminates from the device "+RED+"obliterating"+NORM+" fanboy\n\
and causing "+HIR+"MASSIVE DAMAGE"+NORM+" to everyone in the room.\n\n");	  
	  
      detonate();
      destroy_inventory();
      destruct(this_object());
	  return;
	  }

	}
  }
}


/************************************************************
 * This is to destroy fanboy inventory when detonation occurs
 ************************************************************/
destroy_inventory() {
  int fi, fsize;
  object *finv;
  finv = all_inventory( this_object() );
  for( fi=0, fsize = sizeof(finv); fi < fsize; fi++ )
  {
  destruct(finv[fi]);
  }
}



/***********************************************
 * Detonation harms all living creatures in room except
 * fanboy and John Romero
 ***********************************************/
detonate() {
  int i, size;
  object *mobs;
  
  /*  Spot Check for Testing
  tell_room(environment(),
  "DETONATION WORKED\n");
  */
  
  mobs = all_inventory(environment());
  for( i=0, size = sizeof(mobs); i < size; i++ )
  {
    if(living(mobs[i]))
    {
	/*  Spot Check for Testing
	tell_room(environment(),mobs[i]->query_name()+i+"\n");
	tell_room(environment(),mobs[i]->id("fanboy")+"\n");
    */
	
    if( !mobs[i]->id("fanboy") && !mobs[i]->id("john romero") )
      {
      mobs[i]->hit_player(FANBOYDAMAGE,"other|laser");
	  }
	
	/* Spot Check for Testing
	tell_room(environment(),"spotcheck"+i+"\n");
	*/

	}
  }	  
	
  /* Spot Check for Testing
  tell_room(environment(),
  "DETONATION WORKED2\n");
  */
  
}

setlongdescr() {

  switch( random(5) ) {
    case 4:
      set_long("  A socially-awkward teenager with a nametag showing 'RiX'.  His\n\
medium-length blonde hair is feathered.  He wears big-lensed glasses,\n\
a white t-shirt showing an indistinguishable computer graphic, faded\n\
denim shorts, and white tennis shoes with white crew socks.  He\n\
mumbles something about a LAN party.\n");
	  set_gender("male");
      move_object(clone_object("/players/karash/Outpost/items/spaceorb"), this_object());
      break;
    case 3:
      set_long("  A cocky young man in his mid-20s with a nametag showing 'BullyBoy'.\n\
He sports a feathered mullet, some facial hair, a long-sleeve black\n\
t-shirt tucked into his blue jeans.  He mumbles something about a LAN\n\
party.\n");
	  set_gender("male");
      move_object(clone_object("/players/karash/Outpost/items/gamepad"), this_object());	  
      break;
    case 2:
      set_long("  A balding guy in his mid-30s with a nametag showing 'Makaveli'.  He\n\
appears to be extremely confident sporting a goatee, a black t-shirt\n\
with some form of gaming clan symbol and his faded jeans.  He shouts\n\
profanities and something about missing his LAN party.\n");
	  set_gender("male");
      move_object(clone_object("/players/karash/Outpost/items/floppy"), this_object());
      break;
    case 1:
      set_long("  This 'fanboy' is actually a girl with a nametag showing 'SwanSong'.\n\
Her shoulder-length hair could probably use a wash, but she seems to\n\
be working the brown, low-cut top with spaghetti straps to gain\n\
attention from any socially-awkward guys in the area.\n");
	  set_gender("female");
	  SetMultipleIds( ({ "fanboy", "boy", "fangirl", "girl" }) );
      move_object(clone_object("/players/karash/Outpost/items/presspass"), this_object());
	  break;
    default:
      set_long("  A young man in his early 20s with a nametag showing 'Remedy'.  His\n\
hair is cleanly-cut, but somewhat greasy, and he's cleanly shaven\n\
with long sideburns.  He wears a black collared shirt over a black\n\
t-shirt with the sleeves rolled up to the elbow.  He seems to be\n\
looking for something called a LAN party.\n");
	  set_gender("male");
      move_object(clone_object("/players/karash/Outpost/items/mouse"), this_object());
      break;
  }

}

monster_died()
{

  /****************************************************************************
   * This is to show message that detonation device is destroyed if fanboy is
   * killed after countdown begins
   ****************************************************************************/
   
  if(x > 0)
  {
  tell_room(environment(),
    "\n\The unknown device in fanboy's hand falls to the ground and shatters.\n");
  }
}
