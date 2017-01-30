
inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: romero.c
 * Path: /players/karash/Outpost/mobs
 * Type: Mob
 * Created: July 2014 by Karash
 *
 * Purpose: A high-level mob in the Outpost introductory area used to enhance
 *			the initial theme of the id software group.   
 * 
 * History:
 *          
 ******************************************************************************/

void destroy_inventory();
  
reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("John Romero");
  SetMultipleIds( ({ "john", "romero", "john romero" }) );
  set_race("human");
  set_short("John Romero");
  set_long("  John Romero is one of the founding members of the thinktank group\n\
calling themselves the 'id'.  They are credited with creating and\n\
developing the slipgate technology.  Romero has always been the\n\
face of the group and gladly accepts all of the accolades, as well as\n\
being the target of many criticisms.  He appears to be in his late 20s\n\
with a medium build, long flowing black hair, and an unshaven, yet\n\
trimmed, face.  He looks presentable in his black silk shirt tucked\n\
into his black slacks as he gives you a dismissive look through his\n\
narrow-framed glasses momentarily before turning his attention back\n\
to the keyboard in front on him.\n");
  set_level(22);
  set_al(0);
  set_ac(20);
  set_wc(45);
  set_hp(800+(random(250)));
  set_gender("male");
  set_dead_ob(this_object());
  set_aggressive(0);
  set_heal(2,1);
  /* Listing the sword reference twice to increase the chance the reference will be said */
  set_chat_chance(5);
    load_chat("John says, 'The slipgate is my creation and I deserve the accolades.'\n");
    load_chat("John brags, 'I have used the slipgate to travel through space and time.'\n");
    load_chat("John says, 'I have found wonderful "+YEL+"treasures"+NORM+" within the slipgate.\n\
I carry one now, but only I know its true power.  "+BBLK+HIW+"What do you think?"+NORM+"'\n");
    load_chat("John says, 'I have found wonderful "+YEL+"treasures"+NORM+" within the slipgate.\n\
I carry one now, but only I know its true power.  "+BBLK+HIW+"What do you think?"+NORM+"'\n");
  set_a_chat_chance(5);
    load_a_chat("John shouts:  'You must really want to see this sword!'\n");
    load_a_chat("John shouts:  'Go away!  I have work to do!'\n");
  
  add_spell("daikatana_slash",
    "#MN# spins around $HR$slashing$N$ you with his $HK$daikatana$N$.\n",
    "#MN# spins around $HR$slashing$N$ #TN# with his $HK$daikatana$N$.\n",
    40,"20-30","physical",0);

  add_spell("daikatana_pierce",
    "#MN# lunges forward $HR$piercing$N$ you with his $HK$daikatana$N$.\n",
    "#MN# lunges toward #TN# $HR$piercing$N$ #TO# with his $HK$daikatana$N$.\n",
    40,"20-30","physical",0);
	
  add_money(random(2500)+2500);
  
  move_object(clone_object("/players/karash/Outpost/items/daikatana.c"), this_object());
  command("wield sword", this_object());
  
}
    
init() {
  ::init();

  if( this_player() && this_player()->is_player())
    call_out( "tellroom", 2 );
}

tellroom()
{
  switch( random(3) ) {
    case 2:
      tell_room(environment(),"John Romero acknowledges you and says, 'I have work to do.\n\
  Speak your mind, then let me be.'\n");
      break;
    case 1:
      tell_room(environment(),"John Romero motions towards the door and says, 'If you need assistance,\n\
  Carmack can help you.'\n");
      break;
    default:
      tell_room(environment(),"John Romero looks up with a sly grin and says, 'Are you lost... or\n\
  have you come to give praise?'\n");
      break;
  }
}


 /*****************************************************************
 * When mob dies, this code will log the tank as the killer and
 * also log every other player in the room at time of mob's death
 *****************************************************************/
 monster_died()
{
  int i, size;
  object *mobs;

  write_file("/players/karash/Outpost/log/kill_log",
"\n"+ctime(time())+" - "+attacker_ob->query_name()+" [L "+
attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
 "] killed Romero (basic).\n");

  mobs = all_inventory(environment(attacker_ob));
  for( i=0, size = sizeof(mobs); i < size; i++ )
  {
    if(living(mobs[i]) && mobs[i]->is_player() && mobs[i]!=attacker_ob)
	{
	  write_file("/players/karash/Outpost/log/kill_log",
ctime(time())+" - "+mobs[i]->query_name()+" [L "+
mobs[i]->query_level()+"+"+mobs[i]->query_extra_level()+
 "] was present for death of Romero (basic).\n");
	}
  }
  return 1;
}


/*******************************************************************************
 * This NPC acts as a normal NPC, but if certain key phrases are said, then    *
 * the NPC will gain strength and abilities.  If NPC hears good phrases about  *
 * his sword (metagame: Daikatana the video game), then NPC is armored by      *
 * an inflated ego.  If NPC hears criticism about his sword (AKA: video game), *
 * then NPC gains strength, aggressiveness and nasty abilities.                *
 * Basically, John Romero is touchy about his Daikatana!                       *
 *******************************************************************************/

void catch_tell(string str)
{
    string who, what;
	object jrcrit, jrproud;
	object jrcritenemy; 

	/** Scan player speech **/
	str = remove_color( str );
	
    if (sscanf(str, "%s says: %s\n", who, what) == 2 ||
	sscanf(str, "%s exclaims: %s\n", who, what) == 2 ||
	sscanf(str, "%s tells you: %s\n", who, what) == 2) 
	{
	  what = lower_case(what); 
	 /** FOR LD, Replace the line above with this line below with the Trim function **/
	 /** what = trim(lower_case(what)); **/
	 
	 /* for testing */
     /* tell_room(environment(),"WHO = "+who+"\n");   */
     /* tell_room(environment(),"WHAT = "+what+"\n"); */
      
	  /** Search for Daikatana Praise **/
	  if(what == "daikatana is great" || what == "daikatana was great" || what == "daikatana is awesome" || 
	     what == "daikatana was awesome" || what == "daikatana rocks" || what == "daikatana rocked" || 
		 what == "i like daikatana" || what == "i love daikatana" ||
		 what == "i liked daikatana" || what == "i loved daikatana" || what == "your daikatana is nice" )
      { 
	    /** No change if mob is being attacked or is not at full health **/
        if(this_object()->query_attack() || hit_point < max_hp)
		{
		  tell_room(environment(),"John says, 'You can't hit me and then expect I listen to your rubbish!'\n");
		}
		else
        {
		  /** Transition to Romero the Proud **/
		  tell_room(environment(),"\n\The kind words bring a "+YEL+"smile"+NORM+" to John Romero's face.  He absorbs the\n\
praise as it "+CYAN+"inflates his ego"+NORM+" even more.  He stands taller, poking out\n\
his chest, and he seems "+RED+"stronger"+NORM+" and more confident than before.\n\n");	 
        
		  jrproud = clone_object("players/karash/Outpost/mobs/romero_proud");
          move_object(jrproud, environment());
		  destroy_inventory();
		  destruct(this_object()); 		
				
		}
		return;		
	  }
	  /** Search for Daikatana Criticism **/
	  else if(what == "daikatana sucks" || what == "daikatana sucked" || what == "daikatana is bad" || 
	     what == "daikatana was bad" || what == "i don't like daikatana" || what == "i do not like daikatana" || 
		 what == "i hate daikatana" || what == "i hated daikatana" ||
		 what == "i did not like daikatana" )
      {
        /** No change if mob is being attacked or is not at full health **/
        if(this_object()->query_attack() || hit_point < max_hp)
		{
		  tell_room(environment(),"John says, 'You can't hit me and then expect I listen to your rubbish!'\n");
		} 
		else
        {
		  /** Transition to Romero the Criticized **/
		  tell_room(environment(),"\n\John Romero has heard enough "+MAG+"criticism"+NORM+" and has reached his "+HIR+"breaking point"+NORM+"!\n\
He becomes "+HIR+"enraged"+NORM+" and unsheathes his beloved "+GRY+"Daikatana"+NORM+".\n");

		  tell_room(environment(),"\n\Holding his magical sword with two hands out front, Romero whispers a short\n\
incantation and "+HIR+"empowers"+NORM+" his "+GRY+"weapon"+NORM+".\n\n");
          
		  /** Get name of person triggering transition and pass it to new Romero **/
          jrcritenemy = present(lower_case(who), environment());
		  jrcrit = clone_object("players/karash/Outpost/mobs/romero_crit");
		  jrcrit->set_jrcritenemy(jrcritenemy);
          move_object(jrcrit, environment());
		  destroy_inventory();
		  destruct(this_object()); 

		  /* for testing */
  		  /* tell_room(environment(), "WHO = "+lower_case(who)+"\n"); */
          /* tell_room(environment(), "JRCRITENEMY name is "+jrcritenemy->query_name()+"\n"); */

		}
		return;
	  }
	
    else return;
	
  }
}

/************************************************************
 * This is to destroy John Romero inventory when destruction is called
 ************************************************************/
void destroy_inventory() {
  int ri, rsize;
  object *rinv;
  rinv = all_inventory( this_object() );
  for( ri=0, rsize = sizeof(rinv); ri < rsize; ri++ )
  {
  destruct(rinv[ri]);
  }
}

