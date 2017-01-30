inherit "obj/weapon";
#include <ansi.h>

#define TO this_object() 
#define ENV environment

/******************************************************************************
 * Program: hammer.c
 * Path: /players/nightshade/weap/
 * Type: Weapon
 * Updated: October 2014 by Karash
 *
 * Purpose: An upgrade to the original Nightshade weapon used by Wulfgar.  This upgrade
 *          adds some special abilities to follow the theme of Wulfgar and Aegis-fang.
 *          Player must wield hammer and become attuned through combat.  Once attuned,
 *          player can swing hammer for 2 rounds, then throw hammer for 100dmg or 
 *          500dmg if target NPC is 0/10.  If hammer is not attuned when thrown, hammer
 *          will do normal damage and not return to owner automatically.
 *          Player must have 20STR to wield, swinging hammer will cost 5sps/round and
 *          40 sps to throw.  Once it is thrown, it will need to be attuned again.
 *
 * History:
 *          
 ******************************************************************************/

#define ATTUNEDMG 80
#define ATTUNEXDMG 500

  
string attuned;  /** to track weapon attunement for special abilities **/
int attunecnt;   /** to track number of weapon_hit bonuses - need 5 to attune **/
string swinging; /** to track if player is swinging weapon **/
int swingcnt;    /** to track number of rounds swinging hammer **/
object me, att;
int spell, atthp, attmhp;
string dying;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("hammer");
  SetMultipleIds( ({ "aegis-fang", "hammer", "fang" }) );

  set_class(16);
  set_value(10000);
  set_weight(3);

  set_short(GRY+"Aegis-fang"+NORM);
  set_long(
"A very large magical war hammer. Intricate carvings of dragons and\n"+
"dwarves line the handle while the head has the dwarven god Rerox \n"+
"on one side and a balanced scale on the other. The whole of the \n"+
"hammer is made of pure, shining mithril, with the head having a gold \n"+
"band around the middle of it.  You may have heard about this legendary \n"+
"hammer, so try to '"+CYAN+"recall rumors"+NORM+"' to remember what this weapon can do.\n");

  set_hit_func(this_object());
  
  attuned = "no";
  swinging = "no";
  attunecnt = 0;
  swingcnt = 0;

}


weapon_hit()
{

  int W;
  W = random(12);
  
  if(swinging == "yes") { return; }
  
  if(W > 8)  
  {
	if(attunecnt < 5)
	{
      attunecnt++;
      if(attunecnt >= 5)
	  {
	  attuned = "yes";
      set_short(GRY+"Aegis-fang"+NORM+" ("+HIG+"ATTUNED"+NORM+")");
	  tell_object(ENV(TO), HIC+"\n\n\Aegis-fang is now "+NORM+HIG+"ATTUNED"+NORM+HIC+" to you!\n\n"+NORM);
	  }
	}
  
    /* A say is seen by everybody in the room BUT the user. */
    say(GRY+"Aegis-fang"+NORM+CYAN+" connects with a solid hit "+NORM+MAG+"crushing"+NORM+CYAN+" its foe.\n"+NORM);
    /* A write is seen ONLY by the user. */
    write(GRY+"Aegis-fang"+NORM+CYAN+" connects with a solid hit "+NORM+MAG+"crushing"+NORM+CYAN+" its foe.\n"+NORM);
    /* This return is the additional damage called.  */
    return 6;
   }
   return;
}


init() {
  ::init();
  add_action("Recall","recall");
  add_action("Swing","swing");
  add_action("Throw","throw");
  add_action("Stop","stop");
  
  attuned = "no";
  swinging = "no";
  attunecnt = 0;
  swingcnt = 0;
  set_short(GRY+"Aegis-fang"+NORM);  
    
  /* for testing */
  /* tell_room(ENV(TO), "TESTING INIT\n"); */

  
 
}

Recall(str) {
if(!str) { write("What are you trying to recall?\n"); return 1; }
if(str == "rumors" || str == "rumours") 
{
  write("From what you can recall, this heavy magical hammer can become attuned to its\n\
wielder through combat, which may allow for it to return to its owner's\n\
hand when thrown.  Rumors state that if you are able to wield Aegis-fang\n\
in combat, you could expend some of your energy to '"+CYAN+"swing hammer"+NORM+"' a couple\n\
rounds once it is attuned, then you could '"+CYAN+"throw hammer"+NORM+"' with enough force\n\
to possibly finish a weakened enemy (or you could '"+CYAN+"stop swinging"+NORM+"').\n");
  write(GRY+"(Note: The hammer will attune during the fight, then swing hammer for at\n\
least two rounds before throwing hammer for heavy damage or even more\n\
damage if target is almost dead.  If hammer is not attuned when thrown,\n\
it will do normal damage and will not return to its owner.)\n"+NORM);
  return 1; }
}


/** To swing hammer, it needs to be wielded and player needs necessary SPs **/

Swing(str)
{

  if(!str) { write("What are you trying to swing?\n"); return 1; }
  if(str == "hammer" || str == "aegis-fang") 
  {
    if(!wielded)  /** what about offwield? **/
    {
      write("You must wield "+GRY+"Aegis-fang"+NORM+" to do that.\n");
      return 1;
    }
    me = wielded_by;
    if(!me) me = this_player();
	
	if(!me->query_attack())
	{
	  write("You must be fighting to do that.\n");
	  return 1;
	}
		
    spell = me->query_sp();
	if(spell < 5)
	{
      write("You lack the necessary energy to swing "+GRY+"Aegis-fang"+NORM+".\n");
      return 1;
    }
	
	swinging = "yes";
	swing_hammer();
	set_heart_beat(1);
	
	/* for testing */
    /* tell_object(ENV(TO), "SWING TEST\n"); */
  }
  return 1;
}



swing_hammer()
{
  spell = me->query_sp();
  if(spell < 5)
  {
    write("You lack the necessary energy to swing "+GRY+"Aegis-fang"+NORM+".\n");
    stop_swinging();
	return 1;
  }

  if(swingcnt == 0 && attuned == "no")
  {
  tell_object(ENV(TO), "You muscle up enough "+YEL+"energy"+NORM+" to begin "+MAG+"SWINGING"+NORM+" your "+MAG+"UNATTUNED"+NORM+" weapon.\n");
	say(me->query_name()+" begins to swing "+me->query_possessive()+" hammer.\n");
  }
  if(swingcnt == 0 && attuned == "yes")
  {
  tell_object(ENV(TO), "You muscle up enough "+YEL+"energy"+NORM+" to begin "+MAG+"SWINGING "+NORM+GRY+"Aegis-fang"+NORM+" ("+HIG+"ATTUNED"+NORM+").\n");
	say(me->query_name()+" begins to swing "+me->query_possessive()+" hammer.\n");
  }  
  
  if(swingcnt >= 1 && attuned == "no")
  {
  tell_object(ENV(TO), "You continue to "+MAG+"SWING"+NORM+" your "+MAG+"UNATTUNED "+NORM+GRY+"HAMMER"+NORM+".\n");
  }
  if(swingcnt >= 1 && attuned == "yes")
  {
  tell_object(ENV(TO), "You continue to "+MAG+"SWING "+NORM+GRY+"Aegis-fang"+NORM+" ("+HIG+"ATTUNED"+NORM+").\n");
  }  
  
  swingcnt++;
  me->add_spell_point(-5);

}


/** To throw hammer, it needs to be wielded, player needs necessary SPs,
    player must be swinging hammer, and player needs to be in combat **/
	
Throw(str)
{

  if(!str) { write("What are you trying to throw?\n"); return 1; }
  if(str == "hammer" || str == "aegis-fang") 
  {
    if(!wielded)  /** what about offwield? **/
    {
      write("You must wield "+GRY+"Aegis-fang"+NORM+" to do that.\n");
      return 1;
    }
    me = wielded_by;
    if(!me) me = this_player();
	
	if(!me->query_attack())
	{
	  write("You must be fighting to do that.\n");
	  return 1;
	}
		
    spell = me->query_sp();
	if(spell < 40)
	{
      write("You lack the necessary energy to throw "+GRY+"Aegis-fang"+NORM+".\n");
      return 1;
    }
	
	if((swinging == "no") || ((swinging == "yes") && (swingcnt < 2)))
	{
	  write("You lack the swinging momentum to throw "+GRY+"Aegis-fang"+NORM+".\n");
	  return 1;
	}
	
	throw_hammer();

  }
  return 1;
}


/** If hammer is attuned, do heavy damage - even more if target is 0/10 **/
/** If hammer is not attuned, do normal damage - a little more if target is 0/10 **/

throw_hammer()
{

  dying = "no";
  att = this_player()->query_attack();
  atthp = att->query_hit_point();
  attmhp = att->query_mhp();

  /** Monitor may show 0/10, but target query_hp may lag 1 heartbeat, so subtracting 50   **/
  /** from query_hp to determine dying status to help prevent an incorrect status at 0/10 **/  
  if((((atthp-50) * 10) / attmhp) < 1 ) { dying = "yes"; }
    
  if(attuned == "yes")
  {
	write("You "+MAG+"THROW "+NORM+GRY+"Aegis-fang"+NORM+"("+HIG+"ATTUNED"+NORM+") at "+att->query_name()+" causing "+HIR+"CRUSHING DAMAGE"+NORM+".\n");
	write(GRY+"Aegis-fang"+NORM+CYAN+" returns to your hand.\n"+NORM);
	/** do_damage caps at 50dmg and add_hit_point drops target to 0 (which may need another heartbeat to die) **/
	/** So, add_hit_point for big damage, then do_damage for 5 to kill target if target is at 0 hps           **/
    if(dying=="yes") { att->add_hit_point(-ATTUNEXDMG); }
	if(dying=="no" ) { att->add_hit_point(-ATTUNEDMG); }
    if(dying=="yes") { att->do_damage(({5}), ({"other|hammer"})); }
	if(dying=="no" ) { att->do_damage(({5}), ({"other|hammer"})); }
	
	/* for testing */
	/* write("DYING = "+dying+"\n"); */
  }

  if(attuned == "no")
  {
  	write("You "+MAG+"THROW "+NORM+" your "+MAG+"UNATTUNED"+NORM+GRY+" hammer"+NORM+" at "+att->query_name()+" causing "+HIW+"minimal damage.\n"+NORM);
	write(GRY+"Aegis-fang"+NORM+CYAN+" falls to the floor.\n"+NORM);
    if(dying=="yes") { att->hit_player(40); }
	else { att->hit_player(20); }
    command("drop aegis-fang",this_player());
  }  
      
  init();
  me->add_spell_point(-40);

}


/** This function is called to 'stop swinging' hammer **/

Stop(str)
{
  if(!str) { write("Stop what?\n"); return 1; }
  if(str == "swinging" ) 
  {
    if(swinging == "yes")
    {
      stop_swinging();
	  return 1;
	}
    else
    {
      tell_object(ENV(TO), "You are not swinging "+GRY+"Aegis-fang"+NORM+".\n");
	  return 1;
    }
  }
}


stop_swinging()
{
  tell_object(ENV(TO), "You stop swinging "+GRY+"Aegis-fang"+NORM+".\n");
  swingcnt = 0;
  swinging = "no";
  return 1;  
}


heart_beat()
{
  /* for testing */
  /*
  att = ENV(TO)->query_attack();
  atthp = att->query_hit_point();
  attmhp = att->query_mhp();
  */

  /* for testing */
  /* tell_object(ENV(TO), "TEST WEAPON HEARTBEAT\n"); */

  if(!me->query_attack())
  {
	if(swinging == "yes")
	{
	  stop_swinging();
	}
  set_heart_beat(0);
  }
  
  if(swinging == "yes")
  {
  swing_hammer();
  }
   
   
  /* for testing */
  /*
  write("SWINGING = "+swinging+"\n");
  write("SWINGCNT = "+swingcnt+"\n");  
  tell_object(ENV(TO), "SWINGING = "+swinging+"\n");
  tell_object(ENV(TO), "SWINGCNT = "+swingcnt+"\n"); 
  tell_object(ENV(TO), "ATTUNED = "+attuned+"\n");
  tell_object(ENV(TO), "ATTUNECNT = "+attunecnt+"\n");    
  */
  /*  
  tell_object(ENV(TO), "HPS at "+atthp+"  MHP = "+attmhp+"\n");
  tell_object(ENV(TO), "HPS at "+(atthp*10)/attmhp+"  / 10\n");
  */  
   
}


wield(string str)
{
  if(this_player()->is_npc())
  {
    ::wield(str);
    return 1;
  }
  if(id(str) && this_player()->query_attrib("str")<20 )
  {
    tell_object(this_player(), "You lack the strength to properly wield this weapon.\n");
    return 1;
  }
  else
  {
    ::wield(str);
    return 1;
  }
}


/** needed this to remove weapon attunement when placed into bag **/
drop()
{
  attuned = "no";
  swinging = "no";
  attunecnt = 0;
  swingcnt = 0;
  set_short(GRY+"Aegis-fang"+NORM);  
 
  ::drop();
}

/** To prevent hammer from wearing out in combat **/
query_wear() {
   int wear;
   wear = 0;
  return wear;
}

