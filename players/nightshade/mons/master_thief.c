inherit "obj/monster";
#include <ansi.h>


/******************************************************************************
 * Program: master_thief.c
 * Path: /players/nightshade/mons/
 * Type: Mob
 * Updated: October 2014 by Karash
 *
 * Purpose: An upgrade to the Guildmasters located in the Nightshade area.  This
 *          is one of four guildmasters, including a Cleric, Fighter, Mage and Thief.
 *          They are all located in the same room and coded to fight in pairs, meaning
 *          when one will attack, there is a progression that dictates one of the 
 *          other Masters will join the fight to help (depending on which Master is
 *          attacked and who is remaining in the room).  Two Masters will always fight
 *          at the same time, unless players directly attack more than two.
 *
 *           The Thief has a little less HPS, but can do more damage, especially if no
 *          attackers are directly attacking him.  If he is initially attacked, he will
 *          duck into the shadows and emerge with a Backstab on the attacker, doing heavy
 *          damage and poisoning his target for damage over time.  
 *           If thief is fighting, he will continue to Backstab and Poison if no attacker
 *          is directly attacking him (meaning if an attacker focuses on him, he cannot
 *          duck into the shadows to perform his backstab).
 *           However, if Thief is fighting and his target is not focused on him, he will
 *          perform extra damage to his target as a Sneak Attack (the Fighter's taunt
 *          helps the Thief greatly).
 *           Lastly, the Thief has Evasion, which gives him a 50% chance to take 50% less
 *          damage of any type.  
 *           Thief carries dual daggers that can do some poison damage.
 *
 *          The only loot on the Guildmasters will be what they use to fight.  All other
 *          loot for the combined Masters will be found in a chest in the room, so 
 *          players must kill all Masters to get the combined loot. 
 *
 * History:
 *          
 ******************************************************************************/
 

#define TO this_object() 
#define ENV environment
#define CLCN "master cleric"
#define FTRN "master fighter"
#define MAGEN "master mage"
#define THFN "master thief"
#define CLCA CLC->query_attack()
#define FTRA FTR->query_attack()
#define MAGEA MAGE->query_attack()
#define THFA THF->query_attack()


object CLC, FTR, MAGE, THF;
object ATTACKER;
object weap1, weap2;
int hbeat, dodmg;  /** counters used to determine new rounds or new attackers for evasion **/
object attack;     /** to keep track of attacker for evasion                              **/
string evade;      /** to keep track of evasion for given attacker each round             **/
object killthf;    /** to track player who initiates attack with "kill thief"             **/
object room, shadows; /** this room, shadows in this room                                 **/


reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("thief");
  SetMultipleIds( ({ "master", "master thief", "Master Thief" }) );
  set_short(GRY+"Master Thief"+NORM);
  set_long("As the guildmaster of the thieves guild, this guy has become\n\
very powerful.\n");

  set_level(25);
  set_hp(900+random(300));
  set_wc(52);
  set_ac(24);

  set_heal(2,1);
  
  /** HP bonus will also increase if NPC is healed by Cleric **/
  /** Thief has Evasion where 50% of attacks he will take 50% damage, so with **/
  /** 1000hp * 50% chance * %50% less damage = 250hp bonus                    **/
  set_hp_bonus(250);
  
  /** WC bonus for Dual Daggers = 15WC each = 30 bonus to WC **/
  /** Sneak Attack as another 40 dmg if target is attacking another object, which
      should be most of the time since the other NPC's will taunt target, so for this
      bonus, we'll use 50% of the time for an extra 40dmg = 20 bonus to WC	           **/ 
  /** Note: Since guildmasters will help each other, players will always have to fight at least 2 of them.
      Since each GM has a WC of 44 or 52, adding WC bonus of 40 to increase exp reward for taking damage
	  of second NPC = 40 bonus to WC **/
  /** 30 + 20 + 40 = 90 bonus to WC  **/
  set_wc_bonus(90);
  
    
  /** Move spell functions to add_spell and other functions **
   ****************************************************************************************  
   ** set_chance(20);
   ** set_spell_dam(15);
   ** set_spell_mess1("The thief disappears for a moment and appears behind his enemy, sticking\n\
   ** his blade in their back!");
   ** set_spell_mess2("The thief disappears for a moment, and you suddenly feel a blade in your back!");
   *****************************************************************************************/
  

  set_multi_cast(1);
  
  /** Sneak Attack is extra damage to target player if target player is attacking someone else        **/ 
  /** Sneak Attack checks every round (100%)                                                          **/
  add_spell("sneak",0,0,100,0,0,0,"sneak_attack");
  
  /** Backstab will do heavy damage if NO ONE is attacking Thief (as if he disappears in the shadows) **/
  /** Backstab checks only a percentage of the time                                                   **/  
  add_spell("back_stab",0,0,30,0,0,0,"backstab");  

   
   
  /* PATHS UPDATED */
  /** No coins - Loot for all guildmasters will be in treasure chest **/
  /*
  gold=clone_object("obj/money");
  gold->set_money(2000);
  move_object(gold, this_object());
  */

  weap1=clone_object("players/nightshade/weap/poison_dagger_new");
  move_object(weap1, this_object());
  command("wield");
  weap2=clone_object("players/nightshade/weap/poison_dagger_new");
  move_object(weap2, this_object());
  weap2->offwield( this_object() );  

  hbeat = 0;
  dodmg = 0;
  
}


/** Sneak Attack will double the damage of Thief daggers if target player is focused on someone other than Thief **/
/** Each Dagger is WC15 plus WC5 poison, so 2 daggers with Sneak Attack are additional hit_player 30phys & 10poison            **/
sneak_attack()
{
  if(attacker_ob && present(attacker_ob) && (attacker_ob->query_attack() != TO)) 
  {
    tell_room(ENV(TO), "While "+attacker_ob->query_name()+" focuses on another target, the "+GRY+"Thief"+NORM+" attacks "+attacker_ob->query_objective()+" for extra "+HIM+"SNEAK ATTACK"+NORM+" damage!\n");
	attacker_ob->hit_player(30);
	attacker_ob->hit_player(10, "other|poison");
  }
}


/** Backstab will check to see if anyone is focused on Thief; IF NOT, then Thief will disappear into the shadows  **/
/** and backstab target for Heavy Damage                                                                          **/
backstab()
{

  object psn_obj;
  object att, *ob;
  int h, s;
  s = sizeof(ob = all_inventory(environment(this_object())));
 
  while(h < s)
  {
    if(!ob[h]->is_npc())
    {
      att = ob[h]->query_attack(); 
      if(att && (att == TO))
      {
	    return 1;
      }
    }
  h++;
  }
  
  if(attacker_ob && present(attacker_ob))
  {
    tell_room(ENV(TO), "The "+GRY+"Thief"+NORM+" disappears into the "+GRY+"shadows"+NORM+" and reappears to "+HIM+"BACKSTAB"+NORM+" "+attacker_ob->query_name()+"!\n");
	attacker_ob->hit_player(75);
	attacker_ob->hit_player(25, "other|poison");

    /* PATH UPDATED */
    psn_obj = "/players/nightshade/misc/poison_obj_new.c";

    if(!present("poison_me", attacker_ob))
	{ 
    tell_room(ENV(TO), HIG+"\n"+upper_case(attacker_ob->query_name())+" HAS BEEN POISONED!!!"+NORM+"\n\n");
      move_object(clone_object(psn_obj), attacker_ob);
    }
  }
}


void init()
{
  ::init();
  
  add_action("backstab_open", "kill");
  
  set_heart_beat(1);
}


/***********************************************************************************************************/
/** If Thief is NOT fighting and player initiates "kill", then Thief will duck into the shadows and open  **/
/** combat with a backstab.  Note: If player chooses to "kill master" to attack Thief, then Thief will    **/
/**	not backstab, since all guildmasters have the ID of "master".                                         **/
/***********************************************************************************************************/	
backstab_open(str)
{
  
  killthf = this_player();
  
  if(str == "thief" || str == "master thief" ) 
  {
    if(present(this_object(),environment()))
    {
	  if(!this_object()->query_attack())
	  {
	    /** Temporarily move Thief out of the environment as if it ducks into the shadows - callout brings it back **/
		room = environment(this_object());
		tell_room(room, "As "+killthf->query_name()+" tries to kill the "+GRY+"Thief"+NORM+", but he "+HIM+" EVADES"+NORM+" the attack and\n\
disappears into the "+GRY+"shadows"+NORM+".\n");
  	    
		/* PATH UPDATED */
		shadows = clone_object("/players/nightshade/room/shadows_room_new");
		move_object(this_object(), shadows);
		
		call_out("backstab_att1",5);
		return 1;
	  }
	  else
	  {
	    return 0;
	  }
	}
  }
}


backstab_att1()
{
  tell_room(room, "\n\You sense "+GRY+"something"+NORM+" lurking in the "+GRY+"shadows"+NORM+".\n\n");
  call_out("backstab_att2",5);
}


backstab_att2()
{

  object psn_obj;
  
  move_object(this_object(), room);

  if(killthf && present(killthf))
  {
    tell_room(ENV(TO), "\n\The "+GRY+"Thief"+NORM+" leaps from the "+GRY+"shadows"+NORM+" to "+HIM+"BACKSTAB"+NORM+" "+killthf->query_name()+"!\n\n");
	killthf->hit_player(75);
	killthf->hit_player(25, "other|poison");

	attack_object(killthf);	
	
    /* PATH UPDATED */
    psn_obj = "/players/nightshade/misc/poison_obj_new.c";

    if(!present("poison_me", killthf))
	{ 
    tell_room(ENV(TO), HIG+"\n"+upper_case(attacker_ob->query_name())+" HAS BEEN POISONED!!!"+NORM+"\n\n");
    move_object(clone_object(psn_obj), killthf);
    }
	
  }
  else
  {
    tell_room(room, "The "+GRY+"Thief"+NORM+" steps out of the "+GRY+"shadows"+NORM+".\n");
  }
  return 1;
}



heart_beat()
{
  ::heart_beat();

  hbeat++; 

  CLC = present(CLCN, ENV(TO));  
  FTR = present(FTRN, ENV(TO));
  MAGE = present(MAGEN, ENV(TO));
  THF = present(THFN, ENV(TO));
  
  
  /** If THF is NOT fighting, look for designated partner to help in the following order: **/
  /** CLC,FTR,MAGE but only 2 NPCs should attack together unless players attack a 3rd NPC **/

  /** Attack if CLC is attacked where ALL present and FTR,MAGE not fighting **/
  if(THF && CLC && FTR && MAGE)
  {
    if(!THFA && CLCA && !FTRA && !MAGEA)
	{
  	  ATTACKER = CLCA;
	  tell_room(ENV(TO), "\n\The "+GRY+"Thief"+NORM+" ducks behind "+ATTACKER->query_name()+" to help "+HIM+"SUPPORT"+NORM+" the "+HIW+"Cleric"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	 

  /** Attack if CLC is attacked where MAGE not present and FTR not fighting **/
  if(THF && CLC && FTR && !MAGE)
  {
    if(!THFA && CLCA && !FTRA )
	{
  	  ATTACKER = CLCA;
	  tell_room(ENV(TO), "\n\The "+GRY+"Thief"+NORM+" ducks behind "+ATTACKER->query_name()+" to help "+HIM+"SUPPORT"+NORM+" the "+HIW+"Cleric"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	 
  
  /** Attack if CLC is attacked where FTR not present and MAGE not fighting **/
  if(THF && CLC && !FTR && MAGE)
  {
    if(!THFA && CLCA && !MAGEA )
	{
  	  ATTACKER = CLCA;
	  tell_room(ENV(TO), "\n\The "+GRY+"Thief"+NORM+" ducks behind "+ATTACKER->query_name()+" to help "+HIM+"SUPPORT"+NORM+" the "+HIW+"Cleric"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	
  
  /** Attack if FTR is attacked where CLC not present and MAGE not fighting **/
  if(THF && !CLC && FTR && MAGE)
  {
    if(!THFA && FTRA && !MAGEA )
	{
  	  ATTACKER = FTRA;
	  tell_room(ENV(TO), "\n\The "+GRY+"Thief"+NORM+" ducks behind "+ATTACKER->query_name()+" to help "+HIM+"SUPPORT"+NORM+" the "+HIR+"Fighter"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	
  
  /** Attack if CLC is attacked where FTR,MAGE not present **/
  if(THF && CLC && !FTR && !MAGE)
  {
    if(!THFA && CLCA )
	{
  	  ATTACKER = CLCA;
	  tell_room(ENV(TO), "\n\The "+GRY+"Thief"+NORM+" ducks behind "+ATTACKER->query_name()+" to help "+HIM+"SUPPORT"+NORM+" the "+HIW+"Cleric"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	
  
  /** Attack if FTR is attacked where CLC,MAGE not present **/
  if(THF && !CLC && FTR && !MAGE)
  {
    if(!THFA && FTRA )
	{
  	  ATTACKER = FTRA;
	  tell_room(ENV(TO), "\n\The "+GRY+"Thief"+NORM+" ducks behind "+ATTACKER->query_name()+" to help "+HIM+"SUPPORT"+NORM+" the "+HIR+"Fighter"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	
  
  /** Attack if MAGE is attacked where CLC,FTR not present **/
  if(THF && !CLC && !FTR && MAGE)
  {
    if(!THFA && MAGEA )
	{
  	  ATTACKER = MAGEA;
	  tell_room(ENV(TO), "\n\The "+GRY+"Thief"+NORM+" ducks behind "+ATTACKER->query_name()+" to help "+HIM+"SUPPORT"+NORM+" the "+HIC+"Mage"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	   
  
    
}  


/******************************************************************************************
 *  Thief has Evasion where he has a 50% chance to take 50% damage of any type from each player
 *  NOTE: I wanted Thief to take 50% damage AFTER modifiers, but this do_damage function modifies
 *        base damage before modifiers (AC, Resist, Guild modifiers, etc), which may be causing too
 *        many misses when damage is cut in half, then modified with AC.  So, I may need to decrease
 *        base damage to give lower-level player a chance to hit the mob (monitor this)
 ******************************************************************************************/
do_damage(int *damage, string *method)
{
  int i;
  /** Note to self: Each time a variable is declared, it is reset to 0, so if you want a variable **/
  /**               to carry forward its value, declare the value globally                         **/
  /* string evade;  */
  /* object attack; */
  
  /* for testing
  tell_room(ENV(TO), "\n\dodmg counter = "+dodmg+"\n");
  tell_room(ENV(TO), "hbeat counter = "+hbeat+"\n");
   tell_room(ENV(TO), "this_player() = "+this_player()->query_name()+"\n");
  if(attack) {tell_room(ENV(TO), "attacker name = "+attack->query_name()+"\n"); } 
  */
  
  if(hbeat != dodmg)
  {
    dodmg = hbeat;
	attack = this_player();
    if(!random(2))
	{ 
	  evade = "yes";
      tell_object( this_player(), "The "+GRY+"Thief"+NORM+HIM+" EVADES"+NORM+" you and only takes "+MAG+"PARTIAL DAMAGE"+NORM+"!\n");
	}
	else
	{ evade = "no";  }
  }
  if(hbeat == dodmg)
  {
    if(attack != this_player())
	{
      attack = this_player();
      if(!random(2))
	  { 
	    evade = "yes";
        tell_object( this_player(), "The "+GRY+"Thief"+NORM+HIM+" EVADES"+NORM+" you and only takes "+MAG+"PARTIAL DAMAGE"+NORM+"!\n");
	  }
	  else
	  { evade = "no";  }
	}
  }
  if(evade == "yes")
  {
   /* for testing
   tell_room(ENV(TO), "\n\TEST TEST\n");
   */
   for( i=0; i < sizeof(damage); i++) 
    {
	  /* for testing 
	  tell_room(ENV(TO), "\n\Original Dmg = "+damage[i]+"\n");
      */
	  damage[i] /= 2; 
	  /* for testing
	  tell_room(ENV(TO), "Modified Dmg = "+damage[i]+"\n");
	  tell_room(ENV(TO), "Dmg Type = "+method[i]+"\n");
	  tell_room(ENV(TO), "HeartBeat = "+hbeat+"\n");
	  tell_room(ENV(TO), "DoDamageCount = "+dodmg+"\n");
	  tell_room(ENV(TO), "Attack Name = "+attack->query_name()+"\n");
	  tell_room(ENV(TO), "ThisPlayer Name = "+this_player()->query_name()+"\n");
	  tell_room(ENV(TO), "Evade = "+evade+"\n"); 
	  tell_room(ENV(TO), "Array Loop Counter [i] = "+i+"\n"); 
  	  */
	  return ::do_damage( damage, method );
	}  
  }
  if(evade == "no")
  {
    /* for testing 
    tell_room(ENV(TO), HIG+"\n\FULL DAMAGE\n\n"+NORM);
	tell_room(ENV(TO), "HeartBeat = "+hbeat+"\n");
 	tell_room(ENV(TO), "DoDamageCount = "+dodmg+"\n");
	tell_room(ENV(TO), "Attack Name = "+attack->query_name()+"\n");
	tell_room(ENV(TO), "ThisPlayer Name = "+this_player()->query_name()+"\n");
	tell_room(ENV(TO), "Evade = "+evade+"\n"); 
	*/
	return ::do_damage( damage, method );
  }
  
}


move_player(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

move_object(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

run_away(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to run but is compelled to stay...\n");}

movement(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

  
