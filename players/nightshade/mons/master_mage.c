inherit "obj/monster";
#include <ansi.h>

/******************************************************************************
 * Program: master_mage.c
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
 *           The Mage has a little less HPs than the other Masters.  The Mage's
 *          role is to stand in the back and blast attackers with lightning (electric
 *          damage).  When Mage enters combat, he will conjure a lightning elemental
 *          to assist in the fight, which also causes electric damage and will taunt
 *          attackers off the Mage and Thief if the Fighter is not present and fighting.
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
object weap, spbk, elem;
int ltngele;   /** If ltngele = 0, mage can cast elemental; if ltngele = 1, mage has already cast elemental **/


reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mage");
  SetMultipleIds( ({ "master", "master mage", "Master Mage" }) );
  set_short(HIC+"Master Mage"+NORM);
  set_long("The supreme mage in all of Ledsville. He has perfected\n"+
"the art of conjuring so beware. He is tough.\n");
  
  set_level(25);
  set_hp(900+random(300));
  set_wc(44);
  set_ac(23);

  set_heal(2,1);
  
  /** Note: Since guildmasters will help each other, players will always have to fight at least 2 of them. **/
  /** Since each GM has a WC of 44 or 52, adding WC bonus of 40 to increase exp reward for taking damage of second NPC **/
  set_wc_bonus(40);  
  
  /** HP bonus will increase if NPC is healed by Cleric **/
  set_hp_bonus(0);
  
  set_dead_ob(this_object());

  /** Move this to add_spell **
   ***********************************************************************
  **  set_chance(70);
  **  set_spell_mess1("The Master Mage blasts lightning!\n");
  **  set_spell_mess2("The Master Mage blasts you with lightning!\n");
  **  set_spell_dam(25);
  ************************************************************************/
  
  
  /** Basic Lightning spell **/	
  add_spell("call_lightning",
  "The $HC$Mage$N$ raises his hand and calls a $HY$BOLT of LIGHTNING$N$ down on you!\n",
  "The $HC$Mage$N$ raises his hand and calls a $HY$BOLT of LIGHTNING$N$ down on #TN#!\n",
  30,"40-60","other|electric",0); 
  
  /** Chain Lighting Hits ALL Attackers **/	
  add_spell("chain_lightning",
  "The $HC$Mage$N$ waves his hand and you are caught in a $HY$CHAIN of LIGHTNING$N$!\n",
  "The $HC$Mage$N$ waves his hand and calls forth a $HY$CHAIN of LIGHTNING$N$ hitting all attackers!\n",
  20,"25-50","other|electric",1); 
  
  
  
  /* PATHS UPDATED */
  /** No coins - Loot for all guildmasters are in treasure chest **/
  /*
  gold=clone_object("obj/money");
  gold->set_money(2000);
  move_object(gold, this_object());
  */
  
  weap=clone_object("players/nightshade/weap/invis_sword");
  move_object(weap, this_object());
  init_command("wield razor");
  
  spbk=clone_object("players/nightshade/misc/spell_book");
  move_object(spbk, this_object());

  
  ltngele = 0;
  
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
  
  /** If MAGE is fighting and can cast Elemental, then cast Elemental **/
  if(MAGEA)
    {
	  if(ltngele == 0)
	  {
	    /* PATH UPDATED */
	    elem = clone_object("players/nightshade/mons/ltng_elemental_new");
		move_object(elem, ENV(TO));
		tell_room(ENV(TO), "\n\The "+HIC+"Mage"+NORM+" conjures a "+YEL+"Lightning Elemental"+NORM+" for "+HIM+"protection"+NORM+"!\n\n");
		
		ltngele = 1;
	  }
	}
  
  
  /** If MAGE is NOT fighting, look for designated partner to help in the following order: **/
  /** THF,CLC,FTR but only 2 NPCs should attack together unless players attack a 3rd NPC **/

  /** Attack if THF is attacked where ALL present and CLC,FTR not fighting **/
  if(MAGE && THF && CLC && FTR)
  {
    if(!MAGEA && THFA && !CLCA && !FTRA)
	{
  	  ATTACKER = THFA;
	  tell_room(ENV(TO), "\n\The "+HIC+"Mage"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+GRY+"Thief"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	 
  
  /** Attack if THF is attacked where FTR not present and CLC not fighting **/
  if(MAGE && THF && CLC && !FTR)
  {
    if(!MAGEA && THFA && !CLCA)
	{
  	  ATTACKER = THFA;
	  tell_room(ENV(TO), "\n\The "+HIC+"Mage"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+GRY+"Thief"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	 

  /** Attack if THF is attacked where CLC not present and FTR not fighting **/
  if(MAGE && THF && !CLC && FTR)
  {
    if(!MAGEA && THFA && !FTRA)
	{
  	  ATTACKER = THFA;
	  tell_room(ENV(TO), "\n\The "+HIC+"Mage"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+GRY+"Thief"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	 
  
  /** Attack if CLC is attacked where THF not present and FTR not fighting **/
  if(MAGE && !THF && CLC && FTR)
  {
    if(!MAGEA && CLCA && !FTRA)
	{
  	  ATTACKER = CLCA;
	  tell_room(ENV(TO), "\n\The "+HIC+"Mage"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+HIW+"Cleric"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	

  /** Attack if THF is attacked where CLC,FTR not present **/
  if(MAGE && THF && !CLC && !FTR)
  {
    if(!MAGEA && THFA )
	{
  	  ATTACKER = THFA;
	  tell_room(ENV(TO), "\n\The "+HIC+"Mage"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+GRY+"Thief"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	

  /** Attack if CLC is attacked where THF,FTR not present **/
  if(MAGE && !THF && CLC && !FTR)
  {
    if(!MAGEA && CLCA )
	{
  	  ATTACKER = CLCA;
	  tell_room(ENV(TO), "\n\The "+HIC+"Mage"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+HIW+"Cleric"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	
  
  /** Attack if FTR is attacked where THF,CLC not present **/
  if(MAGE && !THF && !CLC && FTR)
  {
    if(!MAGEA && FTRA )
	{
  	  ATTACKER = FTRA;
	  tell_room(ENV(TO), "\n\The "+HIC+"Mage"+NORM+" joins the fight in "+HIM+"SUPPORT"+NORM+" of the "+HIR+"Fighter"+NORM+"!\n\n");
      attack_object(ATTACKER);
    }
  }	

}


monster_died()
{
  object corpse;
  object item;
  
 /************************************************************
  * This is to destruct 'invis sword' used to imitate spells of 
  * mob, but not intended to be a drop for players
  ************************************************************/ 
  corpse = present( "corpse", environment() );
  if( corpse ) 
  {
    item = present( "razor", corpse );
    if( item )
      destruct( item );
  }
  return 1;
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


