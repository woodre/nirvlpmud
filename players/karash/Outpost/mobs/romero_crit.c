
inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: romero_crit.c
 * Path: /players/karash/Outpost/mobs
 * Type: Mob
 * Created: July 2014 by Karash
 *
 * Purpose: A very high-level mob in the Outpost introductory area used to enhance
 *			the initial theme of the id software group.
 *			This mob will replace romero.c with boosted stats and spells when a player
 *			says specific keywords .
 *          This mob is intended to be a party mob (meaning he likes to PAR-TAY!)
 * 
 * SPECIAL NOTE:  Many thanks to Dragnar for majority of coding for shield and shield meter
 *
 * History: 
 *          
 ******************************************************************************/

/** critenemy is player who said keywords to criticize Romero **/
/** critenemy object is passed from Romero (basic)            **/
object critenemy;

#define MAXSHIELD 1000
int shield;
int sh;

object fbpresent;
int fb;

 
  
reset(arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("John Romero");
  SetMultipleIds( ({ "john", "romero", "john romero", "criticized" }) );
  
  set_race("human");
  set_short("John Romero "+MAG+"the Criticized"+NORM);
  set_long("  John may be the face of the 'id' and he may take all of the "+CYAN+"accolades"+NORM+"\n\
and "+MAG+"criticism"+NORM+" that goes with that, but he has had enough.  The stress\n\
is affecting him and he is not willing to take any more "+MAG+"criticism"+NORM+",\n\
especially towards his "+YEL+"prized possession"+NORM+".  With his weapon unsheathed,\n\
he gives you a fierce look and says, 'Prepare to "+HIR+"Suck It Down!"+NORM+"'\n");

  set_level(29);
  set_al(-random(500)-500);
  set_ac(56);
  /** Bumping WC of mob **/
  set_wc(70);
  /**********************************************************************************
  /** HALF + Random(HALF) of damage blocked by shield is reverted back to attackers,
  /** meaning 500-1000 damage is reverted back to attackers for each shield (3 shields) 
  /** Damage shield accounts for about 60% of Mob's HPs, so calculating extra damage 
  /** to attackers as 60% of fight
  /** Avg Base HP of Mob (2250) + Shield HP (3000) = 5250 ==> Shield ~ 60% Total HP of Mob
  /** 
  /** Estimating 100 dmg/heartbeat using add_hit_point (with 1.5 modifier)
  /**              60% of fight -> 100 * 1.5 * .60 = 90 WC Bonus
  /** It is not indicated here, but there is also a threat of 350 Damage to all living objects
  /** in the room 5 times during the fight, which can be avoided through combat     
  /**********************************************************************************/
  set_wc_bonus(90);
  set_hp(2000+(random(500)));
  /** Damage Shield of 1000 will be cast 3 times (1000*3=3000) **/
  set_hp_bonus(3000);
  set_gender("male");
  set_dead_ob(this_object());
 
  /** Mob is aggressive and  also coded to be ultra-aggressive towards the  **/
  /** player saying the keywords that initiate John Romero the Criticized   **/  
  set_aggressive(1);
  set_chat_chance(5);
    load_chat("John looks around for his criticizer.\n");
    load_chat("John asks, 'Where is that little shit?'\n");
    load_chat("John says, 'Hello.  My name is John Romero.  You insulted my\n\
"+GRY+"Daikatana"+NORM+".  Prepare to die.'\n");
  set_a_chat_chance(5);
    load_a_chat("John shouts:  'Say 'ello to my little friend!'\n");
    load_a_chat("John shouts:  'How do you like my "+GRY+"Daikatana"+NORM+" now?'\n");
 
  /** Minor healing added so mob can heal while damage shield is on and **/
  /** to heal when players leave room to heal/detox                     **/
  set_heal(2,1); 
    
  set_multi_cast(1);
  
  add_spell("daikatana_slash",
    "#MN# spins around $HR$slashing$N$ you with his $HK$Daikatana$N$.\n",
    "#MN# spins around $HR$slashing$N$ #TN# with his $HK$Daikatana$N$.\n",
    25,"55-75","physical",0);

  add_spell("daikatana_pierce",
    "#MN# lunges forward $HR$piercing$N$ you with his $HK$Daikatana$N$.\n",
    "#MN# lunges toward #TN# $HR$piercing$N$ #TO# with his $HK$Daikatana$N$.\n",
    25,"55-75","physical",0);
	
  add_money(random(5000)+10000);
  
  move_object(clone_object("/players/karash/Outpost/items/daikatana_emp.c"), this_object());
  command("wield sword", this_object());
  
}
   
   
  
init() {
  ::init();
  
  /* for testing */
  /* tell_room(environment(), "INIT CHECK 1\n"); */

/** Use tell_object instead of tell_room to avoid picture showing in room for every other player **/
  
tell_object(this_player(), "                                                                           \n");
tell_object(this_player(), "                                          "+HIR+"   `    "+NORM+"                         \n");
tell_object(this_player(), "                                          "+HIR+"   +.   "+NORM+"                         \n");
tell_object(this_player(), "                                          "+HIR+"  .+.   "+NORM+"                         \n");
tell_object(this_player(), "                                          "+HIR+"  .+/`  "+NORM+"                         \n");
tell_object(this_player(), "                                          "+HIR+"  .yh.  "+NORM+"                         \n");
tell_object(this_player(), "                                          "+HIR+"  :+s`  "+NORM+"                         \n");
tell_object(this_player(), "                      `.--.               "+HIR+"  /mo   "+NORM+"                         \n");
tell_object(this_player(), "                    .:+/+syhy+.           "+HIR+"  +o/   "+NORM+"                         \n");
tell_object(this_player(), "                  `sy+:/o/+o+oyo:         "+HIR+"  ++/   "+NORM+"                         \n");
tell_object(this_player(), "                  /hmd/o//+ssyo/:         "+HIR+" `:-.   "+NORM+"                         \n");
tell_object(this_player(), "                 `hmNdysssyysoyh`         "+HIR+" .//.   "+NORM+"                         \n");
tell_object(this_player(), "                 dNmmmhhddhdydMMh`        "+HIR+" .//`   "+NORM+"                         \n");
tell_object(this_player(), "               `+MMMNNNNNmmdhmmmd         "+HIR+" ::/    "+NORM+"                         \n");
tell_object(this_player(), "             `+mNNMMMMMMMNNmdNNN-         "+HIR+" +-:    "+NORM+"                         \n");
tell_object(this_player(), "            :yhhhhmmmMMMMMMNNNNy`         "+HIR+" +::    "+NORM+"                         \n");
tell_object(this_player(), "           -hdo/+hdhdNNMMMMMMNNMm-      .."+HIR+":oo-    "+NORM+"                         \n");
tell_object(this_player(), "          .hmho/+yhysohMNMMMMMMMMy`    :mhsso/:`                           \n");
tell_object(this_player(), "          `:yysshhhddhNmmmdhhyydhyyo:://sdmhhs-`                           \n");
tell_object(this_player(), "            omNmhhdhhNhsoyoo+y+y:+oo+//:/ssssh`                            \n");
tell_object(this_player(), "            smNNNNNNmmdhmNmddhydhsyhyysssssooo                             \n");
tell_object(this_player(), "            /mNNNNmmNNNmddddhsNNNMMMMMMNNmmhs.                             \n");
tell_object(this_player(), "            -hNNNMNNNmmNNdhds `:.-oNMMMmdhyhd:                             \n");
tell_object(this_player(), "             `NNNNNMMMMMNmmNs      `+smmhsshhs                             \n");
tell_object(this_player(), "             oNNNNNNNNMMMNMMMs        `yysho`                              \n");
tell_object(this_player(), "            /NMMMMMNNMMNMMMMMNh-        `                                  \n");
tell_object(this_player(), "           +mNNdmNNNNmNNNNmmNmNmo`                                         \n");
tell_object(this_player(), "          -mmddNmdhdddddmNNNNmdsdm+`                                       \n");
tell_object(this_player(), "        `sdmmhyyhmmNNNNNNNddddmdhhmd:                                      \n");
tell_object(this_player(), "        .ydhsyhdNMMMMMMMMMMMNmNdhdhdms-                                    \n");
tell_object(this_player(), "       `ydh//sshmMMMNyooohNMMNMNmmo+ddso-                                  \n");
tell_object(this_player(), "      .hdhy//soNNNMd`     `sMMMMMmy+o/omNh/                                \n");
tell_object(this_player(), "      .yhdy+/dhdNNy.        :mMMMNmho++hdNm.                               \n");
tell_object(this_player(), "      -dddyyydmdmN-           oMMMMMNNmmmss/`                              \n");
tell_object(this_player(), "      :NmhymmydNMm`            +NMMMMMmdhmNhd+                             \n");
tell_object(this_player(), "       `+hmmNhhNMMN/            `:/+ohMMMMMNNNh`                           \n");
tell_object(this_player(), "         /sssmMMMMMM`                 -smMMMMNms-                          \n");
tell_object(this_player(), "            -NMMMMMh                     -yMMMNNN+                         \n");
tell_object(this_player(), "         `/yNMMMMMMo                       yMMMNmdy+:.                     \n");
tell_object(this_player(), "        `yMMMMMMMMM-````....-------------...dMMMNhdNdds```                 \n");
tell_object(this_player(), "  -+ssyhddmNNMMMMMMNNNmmmmmmmmmmmNNNNNNNNNNNMMMMMMNmNNmmhddhys+/:-`        \n");
tell_object(this_player(), " .hNmmmmNNmdhhhhsssos+osoosyyyhyyyyooooooossosyhhdhhhyysssyyshdmdd.        \n");
tell_object(this_player(), "  omdhmNNNNNmmNNmdymmmNMNNmmNNNmmdmmdsosohhdddNmmNMMMNMNNNNNNNNNsy         \n");
tell_object(this_player(), "   -+++++//++/+++::o+/+o+++++/++//+/////:-/++/++++++++++--:::///--         \n");
tell_object(this_player(), "\n");  


  /*****************************************************************/
  /** If mob is not being attacked and critenemy enters the room, **/
  /** mob will attack critenemy                                   **/
  /*****************************************************************/
  if(!this_object()->query_attack() && critenemy)
  {
  tell_room(environment(), "\n\John Romero shouts, '"+HIY+upper_case(critenemy->query_name())+"!  You should bite your tongue!"+NORM+"\n\n");
  attack_object(critenemy); 
  /* for testing */
  /* tell_room(environment(), "INIT CHECK 2\n"); */
  }  

}

heart_beat() {
    ::heart_beat();

  /***********************************************************************/
  /** If heartbeat is on, but mob is calmed or not attacked, mob will   **/
  /** attack critenemy if present, thus ignoring calm. If critenemy is  **/
  /** not present, then the next "if statement" will turn off heartbeat **/
  /***********************************************************************/
  if(!this_object()->query_attack() && critenemy)
  {
  attack_object(critenemy);
  /* for testing */
  /* tell_room(environment(), "HEARTBEAT CHECK 3\n"); */
  }

  /**********************************************************************************/
  /** This turns off heartbeat if mob is not attacked and critenemy is not present **/
  /** If critenemy enters the room, then init function will begin attack again     **/
  /**********************************************************************************/
  if(!this_object()->query_attack() && !critenemy) 
  {
  set_heart_beat(0);
  /* for testing */
  /* tell_room(environment(), "HEARTBEAT CHECK 2\n"); */
  }
  
  
  /******************************************************************
   * DDS - Daikatana Damage Shield
   * This code activates the shield at certain points in combat
   * The shield is activated 3 times - 9/10, 6/10, 2/10
   * 
   * The first if(!shield) is to bypass the other checks if there is a shield active.
   * Each individual check also has an if(!shield) check in case a party somehow 
   * creates massive damage on mob that may qualify it for a subsequent shield
   * and advance the counter.  This second if(!shield) statement ensures that the mob will
   * always activate the shield 3 times before mob dies.
   ******************************************************************/
    
  if(!shield)
  {  
    /* for testing */
	/* tell_room(environment(), "HEARTBEAT CHECK 34 - shield = "+shield+"\n\n"); */
    if((hit_point < max_hp)  &&  (!sh)  &&  (!shield) ) 
    {
      shield = MAXSHIELD;
	  sh++;
  	  tell_room(environment(), "John Romero raises the "+GRY+"Daikatana"+NORM+" horizontally above his head and says\n\
something indecipherable as a "+CYAN+"blue translucent energy"+NORM+" engulfs his body.\n\n");
	  tell_room(environment(), CYAN+"<<<<    SHIELD IS ACTIVATED    >>>>"+NORM+"\n\n");
	}
    if(((hit_point * 10 / max_hp) < 7)  &&  (sh < 2)  &&  (!shield))
	{
	  shield = MAXSHIELD;
      sh++;
  	  tell_room(environment(), "John Romero raises the "+GRY+"Daikatana"+NORM+" horizontally above his head and says\n\
something indecipherable as a "+CYAN+"blue translucent energy"+NORM+" engulfs his body.\n\n");
	  tell_room(environment(), CYAN+"<<<<    SHIELD IS ACTIVATED    >>>>"+NORM+"\n\n");
    }
    if(((hit_point * 10 / max_hp) < 3)  &&  (sh < 3)  && (!shield))
	{
	  shield = MAXSHIELD;
      sh++;
  	  tell_room(environment(), "John Romero raises the "+GRY+"Daikatana"+NORM+" horizontally above his head and says\n\
something indecipherable as a "+CYAN+"blue translucent energy"+NORM+" engulfs his body.\n\n");
	  tell_room(environment(), CYAN+"<<<<    SHIELD IS ACTIVATED    >>>>"+NORM+"\n\n");
    }
		
    /* for testing */
	/* tell_room(environment(), "HIT POINT CHECK 1a : s = "+sh+"\n\n"); */

  }

    /******************************************************************
   * Calling the Fanboy
   * This code will call a "minion" called "fanboy" at certain points in combat
   * Fanboy will be called 5 times - around 9/10, 7/10, 5/10, 3/10, 1/10
   * 
   * At the sight of John Romero in combat, Fanboy will activate a timer that will
   * warn everyone in the room for 4 heartbeats.  If not killed by players, Fanboy
   * will detonate an explosion doing massive damage to all living objects in room.
   * Fanboy can be easily killed with very low HP, so damage can be avoided.
   * Fanboy cannot be calmed once the timer is activated - He must be killed!
   ******************************************************************/
  
  fbpresent = present("fanboy",environment());
  
  if(!fbpresent)
  {
    /* for testing */
	/* tell_room(environment(), "HEARTBEAT CHECK 44\n\n"); */
	
    /****************************************************************************/
	/** Adding a random(number) modifier to each activation so fanboy is not      
	/** called at exactly each interval every fight - meaning the 2nd fanboy 
	/** may spawn prior to mob showing 7/10 on the health monitor                                     **/
	/****************************************************************************/

    if(((hit_point + 100) < max_hp)  &&  (!fb)  &&  (!fbpresent) ) 
    {
      move_object(clone_object("/players/karash/Outpost/mobs/fanboy"), environment());
      tell_room(environment(), "\n\John Romero holds the "+GRY+"Daikatana"+NORM+" in front of him and "+CYAN+"recites an incantation"+NORM+".\n");
      tell_room(environment(), HIY+"A fanboy has instantly appeared."+NORM+"\n\n");
	  fb++;
	  /* for testing */
	  /* tell_room(environment(), "FANBOY 1 IS ACTIVATED\n\n"); */
	}
    if((((hit_point - random(100)) * 10 / max_hp) < 8)  &&  (fb < 2)  &&  (!fbpresent) ) 
    {
      move_object(clone_object("/players/karash/Outpost/mobs/fanboy"), environment());
      tell_room(environment(), "\n\John Romero holds the "+GRY+"Daikatana"+NORM+" in front of him and "+CYAN+"recites an incantation"+NORM+".\n");       
      tell_room(environment(), HIY+"A fanboy has instantly appeared."+NORM+"\n\n");      
	  fb++;
	  /* for testing */
	  /* tell_room(environment(), "FANBOY 2 IS ACTIVATED\n\n"); */
	}
	if((((hit_point - random(200)) * 10 / max_hp) < 6)  &&  (fb < 3)  &&  (!fbpresent) ) 
    {
      move_object(clone_object("/players/karash/Outpost/mobs/fanboy"), environment());
      tell_room(environment(), "\n\John Romero holds the "+GRY+"Daikatana"+NORM+" in front of him and "+CYAN+"recites an incantation"+NORM+".\n");       
      tell_room(environment(), HIY+"A fanboy has instantly appeared."+NORM+"\n\n");       
	  fb++;
	  /* for testing */
	  /* tell_room(environment(), "FANBOY 3 IS ACTIVATED\n\n"); */
	}
	if((((hit_point - random(200)) * 10 / max_hp) < 4)  &&  (fb < 4)  &&  (!fbpresent) ) 
    {
      move_object(clone_object("/players/karash/Outpost/mobs/fanboy"), environment());
      tell_room(environment(), "\n\John Romero holds the "+GRY+"Daikatana"+NORM+" in front of him and "+CYAN+"recites an incantation"+NORM+".\n");       
      tell_room(environment(), HIY+"A fanboy has instantly appeared."+NORM+"\n\n");       
	  fb++;
	  /* for testing */
	  /* tell_room(environment(), "FANBOY 4 IS ACTIVATED\n\n"); */
	}
	if((((hit_point - random(200)) * 10 / max_hp) < 2)  &&  (fb < 5)  &&  (!fbpresent) ) 
    {
      move_object(clone_object("/players/karash/Outpost/mobs/fanboy"), environment());
      tell_room(environment(), "\n\John Romero holds the "+GRY+"Daikatana"+NORM+" in front of him and "+CYAN+"recites an incantation"+NORM+".\n");       
      tell_room(environment(), HIY+"A fanboy has instantly appeared."+NORM+"\n\n");      
	  fb++;
	  /* for testing */
	  /* tell_room(environment(), "FANBOY 5 IS ACTIVATED\n\n"); */
	}
	
	/* for testing */
    /* tell_room(environment(), "HEARTBEAT CHECK 1a : sh = "+sh+" ; fb = "+fb+" \n\n"); */

  }

}

/** To show damage meter in long description.                                          **/
/** This allows players to look at NPC in case damage meter scrolls too fast in combat **/
long() {
  ::long();
  damage_meter();
}

/**********************************************************************************
 * The awesome do_damage code that will prevent damage taken by mob due to damage
 * shield and revert damage back to attacker.                                      
 * BIG THANKS TO DRAGNAR FOR THIS CODE!
 ***********************************************************************************/
do_damage(int *damage, string *method){
  int i, dam, dam2;
  object target;

  if( shield > 0 ) {
    tell_room( environment(), CYAN+"John Romero laughs as damage bounces off his shield."+NORM+"\n");
    for( i=0; i < sizeof(damage); i++) {
	/*******************************************************************************************************/ 
	/**  EACH attacker gets a separate call to do_damage - this code adds the damage for each damage type  */
    /**  per attacker and adds them together before calling hit_player to revert damage back                */
    /*******************************************************************************************************/	
	  dam += damage[i];  
     /* for testing damage and type hitting the mob */	 
	 /* tell_room(environment(),RED+"DAMAGE[i] = "+damage[i]+"  "+method[i]+NORM+"\n"); */
	}

    reduce_shield( dam );
    target = this_player();
    /******************************************************************
	 * This is the damage that will be reverted from the shield back to the attacker
	 * hit_player(dam) => FULL damage
	 * hit_player(dam / 2) = HALF damage
	 * 
     *******************************************************************/
	 if( target ) {
	  dam2 = ( (dam / 2) + random( dam / 2) );
      target->add_hit_point( -dam2 );
	  /* The hit_player function was causing issues with armor that also reflected damage          */
	  /* causing a loop with the deflected damage from the shield, so add_hit_point was used above */
	  /* target->hit_player( dam / 2 ); */
      tell_room( environment(), "The "+HIR+"damage"+NORM+" reflects off the shield back at "+HIR+target->query_name()+NORM+"!\n");
    }
    
  damage_meter();

  }
  else {
    return ::do_damage( damage, method);
  }
}

/**********************************************/ 
/** To reduce the damage shield as it is hit **/
/**           Props to Dragnar!              **/
/**********************************************/
reduce_shield( int dam ) {
  if( shield > 0 ) {
    shield -= dam;
    if( shield < 0 )
      shield = 0;
  }
}


/***************************************************
 * To show visual of damage meter as shield is destroyed
 *              Props to Dragnar!
 ***************************************************/
damage_meter() {

  int cols;
  string color;

    if( shield > 0 ) {
    cols = shield * 100 / MAXSHIELD;
    switch( cols ) {
      case 0..30:
        tell_object(this_player(),HIR);
        break;
      case 31..70:
        tell_object(this_player(),HIY);
        break;
      default:
        tell_object(this_player(),HIG);
        break;
    }

    /** Adjust to a line limit of 80 **/
    cols = cols * 80 / 100;

    if( cols == 0 )
      cols = 1;

    if( cols > 80 )
      cols = 80;
	
    tell_object(this_player(), "\n\n\SHIELD STRENGTH\n"  );
	tell_object(this_player(), pad("", cols, '#')) ;
    tell_object(this_player(), "\n" +NORM );
    /* for testing */
	/* tell_object(this_player(), "The shield is at: "+shield+"\n"); */
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
 "] killed Romero the CRITICIZED.\n");

  mobs = all_inventory(environment(attacker_ob));
  for( i=0, size = sizeof(mobs); i < size; i++ )
  {
    if(living(mobs[i]) && mobs[i]->is_player() && mobs[i]!=attacker_ob)
	{
	  write_file("/players/karash/Outpost/log/kill_log",
ctime(time())+" - "+mobs[i]->query_name()+" [L "+
mobs[i]->query_level()+"+"+mobs[i]->query_extra_level()+
 "] was present for death of Romero the CRITICIZED.\n");
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
      tell_room(environment(),"John Romero is too "+MAG+"enraged by criticism"+NORM+" to listen to you.\n");	 
      return;		
	}
  }

  return;
 
}

/** Player who initiated Romero transition by saying keywords is set here **/
set_jrcritenemy(object ob) 
{
  critenemy = ob;
}

