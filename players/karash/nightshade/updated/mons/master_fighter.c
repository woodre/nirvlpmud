inherit "obj/monster";
#include <ansi.h>

/******************************************************************************
 * Program: master_fighter.c
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
 *          The Fighter has a few more HPS and carries a Resistance Shield that has some
 *          resistance to all natural damage types.  The Fighter also has the ability to
 *          Parry Attacks (prevent damage), Cleave (hit all attackers) and make Critical
 *          Hits for heavy damage.  Also, if the Fighter is in combat, he will taunt
 *          every attacker in the room to draw their attack, which may allow other 
 *          Masters to perform their special abilities if they are fighting and not 
 *          being directly attacked.
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
object weap, shld;


reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("fighter");
  SetMultipleIds( ({ "master", "master fighter", "Master Fighter" }) );
  set_short(HIR+"Master Fighter"+NORM);
  set_long(
"This guy stands seven feet tall and carries himself like he fears nothing.\n\
He didn't become the master of the fighters guild for nothing!\n");
   
  set_level(25);
  set_hp(1200+random(500));
  set_wc(52);
  set_ac(26);
  
  set_heal(2,1);
  
  /** Note: Since guildmasters will help each other, players will always have to fight at least 2 of them. **/
  /** Since each GM has a WC of 44 or 52, adding WC bonus of 40 to increase exp reward for taking damage of second NPC **/
  set_wc_bonus(40);  

  /** HP bonus will increase if NPC is healed by Cleric **/
  set_hp_bonus(0);
  
  /** Move this to add_spell **
   ****************************************************************************************
   ** set_chance(20);
   ** set_spell_dam(10);
   ** set_spell_mess1("You see the Master execute a blurring double attack!");
   ** set_spell_mess2("You cannot follow the blades as the Master executes a blurring double attack!");
   ****************************************************************************************/
   
  /** Parry will block the attackers weapon attack **/ 
  add_spell("parry",
  "The $HR$Fighter$N$ $HM$PARRIES$N$ your weapon attack!\n",
  "The $HR$Fighter$N$ $HM$PARRIES$N$ the weapon attack from #TN#!\n",
  30,0,0,0,"parry_attack");
  
  /** Cleave will slice ALL attackers **/	
  add_spell("cleave",
  "",
  "The $HR$Fighter$N$ lunges foward swinging his sword in a wide arc and $HR$CLEAVING$N$ all attackers.\n",
  30,"40-60",0,3); 
  
  /** Critical Damage will do heavier damage to attacker **/	
  add_spell("critdmg",
  "The $HR$Fighter$N$ connects with a $HR$CRITICAL HIT$N$ causing $HM$heavy damage$N$!\n",
  "The $HR$Fighter$N$ hits #TN# with a $HR$CRITICAL HIT$N$ causing $HM$heavy damage$N$!\n",
  20,"90-150",0,0); 
  
      
  /* PATHS UPDATED */
  /** No coins - Loot for all guildmasters will be in treasure chest **/
  /*
  gold=clone_object("obj/money");
  gold->set_money(2000);
  move_object(gold, this_object());
  */

  weap=clone_object("players/nightshade/weap/lswd");
  move_object(weap, this_object());

  shld=clone_object("players/nightshade/armor/shield_natresist_new");
  move_object(shld, this_object()); 

  
}

parry_attack()
{
  object pry_obj;
   
  if(attacker_ob && present(attacker_ob)) 
  { 
    /* PATH UPDATED */
    pry_obj = "/players/nightshade/misc/parry_obj_new.c";

    if(!present("parry_me", attacker_ob))
	{ 
      move_object(clone_object(pry_obj), attacker_ob);
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
  
  /** If FTR is fighting, check if partner is present and in combat; if so, TAUNT any attacker off partner **/
  if(FTRA && MAGE)
  {
    if(FTRA && MAGEA)
	{
	  taunt();
	}
  }
  
  if(FTRA && THF)
  {
    if(FTRA && THFA)
	{
	  taunt();
	}
  }
  
  if(FTRA && CLC)
  {
    if(FTRA && CLCA)
	{
	  taunt();
	}
  }
  
  /** If FTR is NOT fighting, look for designated partner to help in the following order: **/
  /** MAGE,THF,CLC but only 2 NPCs should attack together unless players attack a 3rd NPC **/

  /** Attack if MAGE is attacked where ALL present and THF,CLC not fighting - FTR takes Lead **/
  if(FTR && MAGE && THF && CLC)
  {
    if(!FTRA && MAGEA && !THFA && !CLCA)
	{
	  ATTACKER = MAGEA;
	  tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+" leaps in front of  "+ATTACKER->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIC+"Mage"+NORM+"!\n\n");
	  attack_object(ATTACKER);
	  ATTACKER->attack_object(TO);
      MAGE->attack_object(ATTACKER);
    }
  }	  

  /** Attack if MAGE is attacked where CLC not present and THF not fighting - FTR takes Lead **/
  if(FTR && MAGE && THF && !CLC)
  {
    if(!FTRA && MAGEA && !THFA)
	{
	  ATTACKER = MAGEA;
	  tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+" leaps in front of  "+ATTACKER->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIC+"Mage"+NORM+"!\n\n");
	  attack_object(ATTACKER);
	  ATTACKER->attack_object(TO);
      MAGE->attack_object(ATTACKER);
    }
  }	   

  /** Attack if MAGE is attacked where THF not present and CLC not fighting - FTR takes Lead **/
  if(FTR && MAGE && !THF && CLC)
  {
    if(!FTRA && MAGEA && !CLCA)
	{
	  ATTACKER = MAGEA;
	  tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+" leaps in front of  "+ATTACKER->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIC+"Mage"+NORM+"!\n\n");
	  attack_object(ATTACKER);
	  ATTACKER->attack_object(TO);
      MAGE->attack_object(ATTACKER);
    }
  }	  

  /** Attack if THF is attacked where MAGE not present and CLC not fighting - FTR takes Lead **/
    if(FTR && !MAGE && THF && CLC)
  {
    if(!FTRA && THFA && !CLCA)
	{
	  ATTACKER = THFA;
	  tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+" leaps in front of  "+ATTACKER->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+GRY+"Thief"+NORM+"!\n\n");
	  attack_object(ATTACKER);
	  ATTACKER->attack_object(TO);
      THF->attack_object(ATTACKER);
    }
  }	

  /** Attack if MAGE is attacked where THF,CLC not present - FTR takes Lead **/
  if(FTR && MAGE && !THF && !CLC)
  {
    if(!FTRA && MAGEA )
	{
	  ATTACKER = MAGEA;
	  tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+" leaps in front of  "+ATTACKER->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIC+"Mage"+NORM+"!\n\n");
	  attack_object(ATTACKER);
	  ATTACKER->attack_object(TO);
      MAGE->attack_object(ATTACKER);
    }
  }	  

  /** Attack if THF is attacked where MAGE,CLC not present - FTR takes Lead **/
  if(FTR && !MAGE && THF && !CLC)
  {
    if(!FTRA && THFA )
	{
	  ATTACKER = THFA;
	  tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+" leaps in front of  "+ATTACKER->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+GRY+"Thief"+NORM+"!\n\n");
	  attack_object(ATTACKER);
	  ATTACKER->attack_object(TO);
      THF->attack_object(ATTACKER);
    }
  }	

  /** Attack if CLC is attacked where MAGE,THF not present - FTR takes Lead **/
  if(FTR && !MAGE && !THF && CLC)
  {
    if(!FTRA && CLCA )
	{
	  ATTACKER = CLCA;
	  tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+" leaps in front of  "+ATTACKER->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIW+"Cleric"+NORM+"!\n\n");
	  attack_object(ATTACKER);
	  ATTACKER->attack_object(TO);
      CLC->attack_object(ATTACKER);
    }
  }	
  
    
}


taunt()
{

  object att, *ob;
  int h, s;
  s = sizeof(ob = all_inventory(environment(this_object())));
 
  while(h < s)
  {
    if(!ob[h]->is_npc())
    {
      att = ob[h]->query_attack(); 
      if(att && (att != TO))
      {
	    if(att == CLC) {tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+HIM+" TAUNTS "+NORM+ob[h]->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIW+"Cleric"+NORM+"!\n\n"); }
        else if(att == MAGE) {tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+HIM+" TAUNTS "+NORM+ob[h]->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIC+"Mage"+NORM+"!\n\n"); }
        else if(att == THF) {tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+HIM+" TAUNTS "+NORM+ob[h]->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+GRY+"Thief"+NORM+"!\n\n"); }
		else {tell_room(ENV(TO), "\n\The "+HIR+"Fighter"+NORM+HIM+" TAUNTS "+NORM+ob[h]->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIM+att->query_name()+NORM+"!\n\n"); }
        /* This attack_object function was not working properly with alt attackers, but the command function is working fine */
		/* ob[h]->attack_object(FTR); */
		command("kill master fighter", ob[h]);
      }
    }
  h++;
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


