inherit "obj/monster";
#include <ansi.h>

/******************************************************************************
 * Program: master_cleric.c
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
 *          The Cleric has the ability to cast spells on players consisting of Physical
 *          and Good (Holy) damage, plus a mace that does both damage types.
 *          If the Cleric is fighting, the Cleric will heal all Masters in combat three
 *          times (including himself), which will increase the hp_bonus of the target
 *          each time a heal is cast.
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


int clchl, ftrhl, maghl, thfhl; /* counters for number of times cleric heals each npc */
int healamt, hpb;
object CLC, FTR, MAGE, THF;
object ATTACKER;
object sym, weap;



reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cleric");
  SetMultipleIds( ({ "master", "master cleric", "Master Cleric" }) );
  set_short(HIW+"Master Cleric"+NORM);
  set_long(
"You are looking at one who has attained a perfect harmony with his god.\n\
This master can bestow upon his disciple great powers!\n");
  
  set_level(25);
  set_hp(1000+random(250));
  set_wc(44);
  set_ac(23);
  
  set_heal(5,1);
  
  /** WC bonus for smite evil => 30% chance for avg 40dmg divided           **/
  /** by 2 for evil vs. good multiplied by 1.25 for non-physical damage = 8 **/
  /** Note: Since guildmasters will help each other, players will always have to fight at least 2 of them. **/
  /** Since each GM has a WC of 44 or 52, adding WC bonus of 40 to increase exp reward for taking damage of second NPC **/
  set_wc_bonus(48);
  
  /** HP bonus will increase if NPC is healed by Cleric **/
  set_hp_bonus(0); 

  /** Move this to add_spell **
   ******************************************************
   **  set_chance(20);
   **  set_spell_dam(20);
   **  set_spell_mess1("The cleric waves his symbol out in front of him and prays as a fiery pillar\n\
   ** appears to consume his enemy!");
   **  set_spell_mess2("The cleric's eyes roll back in his head in prayer as a fiery pillar appears\n\
   ** to consume you!");
   ******************************************************/

   /** Flame Strike is a pillar of fire where half damage is fire and half damage is holy **/ 
  add_spell("flame_strike",
  "The $HW$Cleric's$N$ eyes roll back in his head in $HW$prayer$N$ as a $HR$FIERY PILLAR$N$ consumes you!\n",
  "The $HW$Cleric$N$ waves his symbol and $HW$prays$N$ as a $HR$FIERY PILLAR$N$ consumes #TN#!\n",
  30,({"20-30","20-30"}),({"other|fire","other|good"}),0);   

  /** Smite spell does double damage if target is aligned towards evil **/	
  add_spell("smite",
  "The $HW$Cleric$N$ grasps his $HY$symbol$N$ and attacks you with a blast of $HW$WHITE LIGHT$N$.\n",
  "The $HW$Cleric$N$ grasps his $HY$symbol$N$ and attacks #TN# with a blast of $HW$WHITE LIGHT$N$.\n",
  30,"30-50",0,0,"smite_evil"); 
   
  /* PATHS UPDATED */
  /** No coins - Loot for all guildmasters are in treasure chest **/
  /*
  gold=clone_object("obj/money");
  gold->set_money(2000);
  move_object(gold, this_object());
  */
  
 
  weap=clone_object("players/nightshade/weap/holy_mace_new");
  move_object(weap, this_object());
  
  sym=clone_object("players/nightshade/misc/holy_symbol_new");
  move_object(sym, this_object());
  
  
}

void smite_evil(object target, object room, int damage) 
{
  if(damage > 0)
    { 
      if(target->query_alignment() < -100)
	  {
	  target->hit_player(damage, "other|good");
	  write("You have been "+HIW+"SMITED"+NORM+" for your "+GRY+"EVIL"+NORM+" ways!\n");
	  say(target->query_name()+" has been "+HIW+"SMITED"+NORM+" for "+target->query_possessive()+" "+GRY+"EVIL"+NORM+" ways!\n");
      }
    }
}

void init()
{
  ::init();
  
  set_heart_beat(1);
  
}

heart_beat()
{
  ::heart_beat();

  CLC = present(CLCN, ENV(TO));  
  FTR = present(FTRN, ENV(TO));
  MAGE = present(MAGEN, ENV(TO));
  THF = present(THFN, ENV(TO));
  
  /* for testing */
  /* tell_room(ENV(TO), "TEST HeartBeat 1\n"); */
  
  /** If CLC is fighting, check health and heal up to 3 times **/
  if(CLCA)
  {
    if((CLC->query_hit_point() * 10 / CLC->query_mhp()) <= 3) 
	{
	  heal_cleric();
	}
  }

  /* for testing */
  /* tell_room(ENV(TO), "TEST HeartBeat 2\n"); */
  
  /** If CLC is fighting with partner, heal partner up to 3 times **/
  if(CLC && FTR)
  {
  if(CLCA && FTRA)
  {
    if((FTR->query_hit_point() * 10 / FTR->query_mhp()) <= 3) 
	{
	  heal_fighter();
	}
  }
  }
  
  if(CLC && MAGE)
  {
  if(CLCA && MAGEA)
  {
    if((MAGE->query_hit_point() * 10 / MAGE->query_mhp()) <= 3) 
	{
	  heal_mage();
	}
  }
  }
  
  if(CLC && THF)
  {
  if(CLCA && THFA)
  {
    if((THF->query_hit_point() * 10 / THF->query_mhp()) <= 3) 
	{
	  heal_thief();
	}
  }
  }

  /* for testing */
  /* tell_room(ENV(TO), "TEST HeartBeat 3\n"); */
  
  /** If CLC is NOT fighting, look for designated partner to help in this order:         **/
  /** FTR,MAGE,THF but only 2 NPCs should attack together unless players attack a 3rd NPC **/
  
  /** Attack if FTR is attacked where ALL present and MAGE,THF not fighting **/
  if(CLC && FTR && MAGE && THF)
  {
    if(!CLCA && FTRA && !MAGEA && !THFA)
    {
      tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+HIR+"Fighter"+NORM+"!\n\n");
      attack_object(FTRA);
    }
  }
  
  /** Attack if FTR is attacked where THF not present and MAGE not fighting **/
  if(CLC && FTR && MAGE && !THF)
  {
    if(!CLCA && FTRA && !MAGEA )
    {
      tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+HIR+"Fighter"+NORM+"!\n\n");
      attack_object(FTRA);
    }
  }  
  
  /** Attack if FTR is attacked where MAGE not present and THF not fighting **/
  if(CLC && FTR && !MAGE && THF)
  {
    if(!CLCA && FTRA && !THFA)
    {
      tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+HIR+"Fighter"+NORM+"!\n\n");
      attack_object(FTRA);
    }
  }    
  
  /** Attack if MAGE is attacked where FTR not present and THF not fighting - CLC takes Lead **/
  if(CLC && !FTR && MAGE && THF)
    {
    if(!CLCA && MAGEA && !THFA)
    {
	  ATTACKER = MAGEA;
	  tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" leaps in front of  "+ATTACKER->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIC+"Mage"+NORM+"!\n\n");
	  attack_object(ATTACKER);
	  ATTACKER->attack_object(TO);
      MAGE->attack_object(ATTACKER);
    }
  }
  
  /** Attack if FTR is attacked where MAGE,THF not present **/
  if(CLC && FTR && !MAGE && !THF)
  {
    if(!CLCA && FTRA )
    {
      tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+HIR+"Fighter"+NORM+"!\n\n");
      attack_object(FTRA);
    }
  }  
  
  /** Attack if MAGE is attacked where FTR,THF not present - CLC takes Lead **/
  if(CLC && !FTR && MAGE && !THF)
    {
    if(!CLCA && MAGEA )
    {
      ATTACKER = MAGEA;
	  tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" leaps in front of  "+ATTACKER->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIC+"Mage"+NORM+"!\n\n");
      attack_object(ATTACKER);
	  ATTACKER->attack_object(TO);
      MAGE->attack_object(ATTACKER);
     }
  }  
  
  /** Attack if THF is attacked and MAGE,FTR not present - CLC takes Lead **/
  if(CLC && !FTR && !MAGE && THF)
  {
    if(!CLCA && THFA && !MAGE && !FTR)
    {
      ATTACKER = THFA;
	  tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" leaps in front of  "+ATTACKER->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+GRY+"Thief"+NORM+"!\n\n");
      attack_object(ATTACKER);
	  ATTACKER->attack_object(TO);
      THF->attack_object(ATTACKER);
    }
  }

  /* for testing */
  /* tell_room(ENV(TO), "TEST HEARTBEAT\n\n"); */
  
}

heal_cleric()
{
  if(clchl < 3)
  {
    healamt = ( 200 + random(100));
    CLC->add_hit_point(healamt);
	tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" grasps his symbol and "+HIG+"HEALS"+NORM+" himself!\n\n");
    hpb = CLC->query_hp_bonus();
    CLC->set_hp_bonus(hpb + healamt);
    clchl++;
	
	/* for testing */
    /*
	tell_room(ENV(TO), "\n\Old HPB = "+hpb+"\n\n");
	tell_room(ENV(TO), "\n\HealAmt = "+healamt+"\n\n");
	tell_room(ENV(TO), "\n\New HPB = "+CLC->query_hp_bonus()+"\n\n");
	tell_room(ENV(TO), "\n\HealCounter = "+clchl+"\n\n");
	*/
	
  }
}


heal_fighter()
{
  if(ftrhl < 3)
  {
    healamt = ( 200 + random(100));
    FTR = present(FTRN, ENV(TO));
	FTR->add_hit_point(healamt);
	tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" places a hand on his friend and "+HIG+"HEALS"+NORM+" the "+HIR+"Fighter"+NORM+"!\n\n");
    hpb = FTR->query_hp_bonus();
    FTR->set_hp_bonus(hpb + healamt);
    ftrhl++;
  }
}


heal_mage()
{
  if(maghl < 3)
  {
    healamt = ( 200 + random(100));
    MAGE = present(MAGEN, ENV(TO));
	MAGE->add_hit_point(healamt);
	tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" places a hand on his friend and "+HIG+"HEALS"+NORM+" the "+HIC+"Mage"+NORM+"!\n\n");
    hpb = MAGE->query_hp_bonus();
    MAGE->set_hp_bonus(hpb + healamt);
    maghl++;
  }
}

heal_thief()
{
  if(thfhl < 3)
  {
    healamt = ( 200 + random(100));
    THF = present(THFN, ENV(TO));
	THF->add_hit_point(healamt);
	tell_room(ENV(TO), "\n\The "+HIW+"Cleric"+NORM+" places a hand on his friend and "+HIG+"HEALS"+NORM+" the "+GRY+"Thief"+NORM+"!\n\n");
    hpb = THF->query_hp_bonus();
    THF->set_hp_bonus(hpb + healamt);
    thfhl++;
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

