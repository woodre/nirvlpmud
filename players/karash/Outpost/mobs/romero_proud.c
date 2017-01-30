
inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: romero_proud.c
 * Path: /players/karash/Outpost/mobs
 * Type: Mob
 * Created: July 2014 by Karash
 *
 * Purpose: A high-level mob in the Outpost introductory area used to enhance
 *			the initial theme of the id software group.
 *			This mob will replace romero.c with boosted stats when a player
 *			says specific keywords 
 * 
 * History:
 *          
 ******************************************************************************/

 /** mod is a counter for stopping combat and giving out book **/
 int mod;
 
 object ATTACKER;
  
reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("John Romero");
  SetMultipleIds( ({ "john", "romero", "john romero", "proud" }) );
  set_race("human");
  set_short("John Romero "+CYAN+"the Proud"+NORM);
  set_long("  John is proud to be the face of the 'id' group and he gladly\n\
accepts all of the accolades that come with it.  He is quite sure of\n\
himself and stands "+CYAN+"proudly"+NORM+" before you with a huge vainglorious smile\n\
cherishing the recent compliments given to him.\n");

  set_level(24);
  set_al(random(250)+250);
  set_ac(55);
  set_wc(46);
  set_hp(1250+(random(250)));
  set_gender("male");
  set_dead_ob(this_object());
  set_aggressive(0);
  set_chat_chance(5);
    load_chat("John says, 'I'm sorry, but I have little time for autographs.  Please\n\
  adulate from a distance if you must.'\n");
    load_chat("John boasts, 'I have traveled through space and time to track down\n\
  this most prized "+YEL+"possession"+NORM+".'\n");
    load_chat("John proudly displays his sword and says, 'I present to you...\n\
  the one and the only... "+GRY+"Daikatana"+NORM+".'\n");
  set_a_chat_chance(5);
    load_a_chat("John shouts:  'You must really want to see this sword!'\n");
    load_a_chat("John shouts:  'Go away!  I have work to do!'\n");
  
  set_heal(15,1);
    
  set_multi_cast(1);
  
  add_spell("daikatana_slash",
    "#MN# spins around $HR$slashing$N$ you with his $HK$daikatana$N$.\n",
    "#MN# spins around $HR$slashing$N$ #TN# with his $HK$daikatana$N$.\n",
    35,"40-60","physical",0);

  add_spell("daikatana_pierce",
    "#MN# lunges forward $HR$piercing$N$ you with his $HK$daikatana$N$.\n",
    "#MN# lunges toward #TN# $HR$piercing$N$ #TO# with his $HK$daikatana$N$.\n",
    35,"40-60","physical",0);
	
  add_money(random(5500)+5500);
  
  move_object(clone_object("/players/karash/Outpost/items/daikatana.c"), this_object());
  command("wield sword", this_object());
  move_object(clone_object("/players/karash/Outpost/items/ego.c"), this_object());
  /*
  There's a bug that will count AC twice if you command to wear armor since mob wears it automatically
  command("wear ego", this_object());
  */
}
    
init() {
  ::init();
}

monster_died()
{
  int i, size;
  object *mobs;

  object corpse;
  object item;
  
 /************************************************************
  * This is to destruct 'ego' armor used to increase stats of 
  * mob, but not intended to be a drop for players
  ************************************************************/ 
  corpse = present( "corpse", environment() );
  if( corpse ) 
  {
    item = present( "ego", corpse );
    if( item )
      destruct( item );
  }
  
     
 /*****************************************************************
  * When mob dies, this code will log the tank as the killer and
  * also log every other player in the room at time of mob's death
  *****************************************************************/
  write_file("/players/karash/Outpost/log/kill_log",
"\n"+ctime(time())+" - "+attacker_ob->query_name()+" [L "+
attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
 "] killed Romero the Proud.\n");

  mobs = all_inventory(environment(attacker_ob));
  for( i=0, size = sizeof(mobs); i < size; i++ )
  {
    if(living(mobs[i]) && mobs[i]->is_player() && mobs[i]!=attacker_ob)
	{
	  write_file("/players/karash/Outpost/log/kill_log",
ctime(time())+" - "+mobs[i]->query_name()+" [L "+
mobs[i]->query_level()+"+"+mobs[i]->query_extra_level()+
 "] was present for death of Romero the Proud.\n");
	}
  }
  return 1;
}


/***********************************************************************
 * To notify players that they cannot affect Romero after he has transitioned
 ***********************************************************************/
void catch_tell(string str)
{
  string who, what, junk;
  str = remove_color( str );

  if (sscanf(str, "%s says: %s\n", who, what) == 2 ||
    sscanf(str, "%s exclaims: %s\n", who, what) == 2 ||
    sscanf(str, "%s tells you: %s\n", who, what) == 2) 
  {
	what = lower_case(what);
	/* for testing */
    /* tell_room(environment(),"WHO = "+who+"\n");   */
    /* tell_room(environment(),"WHAT = "+what+"\n"); */
      
	if(sscanf(what, "%sdaikatana", junk ))
    {
      tell_room(environment(),"John Romero's "+CYAN+"inflated ego"+NORM+" prohibits him from listening to you.\n");	 
      return;		
	}
  }
  return;
}

heart_beat() {
  ::heart_beat();
  ATTACKER = attacker_ob;
  if((((hit_point - random(100)) * 10 / max_hp) < 7)  &&  (!mod) )
  {
    calm_room();
	tell_room(environment(), "\n\John Romero throws his hands up to STOP THE FIGHT and says, "+CYAN+"'Whoa! Whoa!\n\
Okay, I get it.  I have what you want.  Everyone is looking for a handout.'"+NORM+"\n\n");
    tell_room(environment(), "John gives "+CYAN+ATTACKER->query_name()+NORM+" a prepaid gift card for an audiobook titled '"+YEL+"Masters of Doom"+NORM+"'.\n\n");
    tell_room(environment(), "John gives you a "+CYAN+"vainglorious "+NORM+YEL+"smile"+NORM+" and steps back looking very "+CYAN+"proud"+NORM+" of himself.\n");
    move_object(clone_object("/players/karash/Outpost/items/modaudio"), ATTACKER);
	mod++;
  }
  
  if((((hit_point - random(200)) * 10 / max_hp) < 4)  &&  (mod < 2) )
  {
    calm_room();
	tell_room(environment(), "\n\John Romero throws his hands up to STOP THE FIGHT and says, "+CYAN+"'Alright! Alright!\n\
I'll give you something better. People just can't get enough of John Romero.'"+NORM+"\n\n");
    tell_room(environment(), "John gives "+CYAN+ATTACKER->query_name()+NORM+" an "+HIM+"autographed"+NORM+" copy of the book titled '"+YEL+"Masters of Doom"+NORM+"'.\n\n");
    tell_room(environment(), "John "+YEL+"smiles "+NORM+CYAN+"happily"+NORM+", again looking very "+CYAN+"proud"+NORM+" of himself.\n");
    move_object(clone_object("/players/karash/Outpost/items/modbook"), ATTACKER);
	mod++;
  }   
  
  if(hit_point == max_hp)
  {
    mod = 0;
  }
     
}
  
  
calm_room() {

 object att, *ob;
 int    h, s;
 s = sizeof(ob = all_inventory(environment(this_object())));
 
 while(h < s)
 {
  if(att = (object)ob[h]->query_attack())
  {
   ob[h]->stop_fight();
   att->stop_fight();
  }
  h++;
 }
 return 1;
}