inherit "/obj/monster.c";
#include <ansi.h>

/******************************************************************************
 * Program: ltng_elemental_new.c
 * Path: /players/nightshade/mons/
 * Type: Mob
 * Created: October 2014 by Karash
 *
 * Purpose: A conjured mob from the Master Mage used to fight for the mage and
 *          will taunt all attackers if the Fighter is not present and fighting.
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



 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("elemental");
  SetMultipleIds( ({ "elemental", "lightning elemental" }) );  
  set_race("elemental");
  set_short(YEL+"A lightning elemental"+NORM);
  set_long("A large, vaguely humanoid creature, but with no recognizable features and\n\
completely consisting of energy.  It is a mindless servant of the mage.\n");

  set_level(22);
  set_hp(700);

  set_wc(0);
  set_ac(20);
  set_res(10);
  
  set_heal(2,1);

  /* WC 40 Lightning Damage */
  set_weapon_params("other|electric",40,0);
  set_wc_bonus(40);
  
  /* Immune to Lighting/Electricity */
  set_armor_params("other|electric",0,100,0);
  

  /** Extra Lightning Damage to All Attacking Elemental **/	
  add_spell("ltngdmg",
  "You receive a $HY$SHOCK$N$ as you attack the $Y$Elemental$N$!\n",
  "Everyone attacking the $Y$Elemental$N$ receives a $HY$SHOCK$N$!\n",
  100,"10-20","other|electric",3); 
  
  
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

  
  /** If MAGE is present and fighting, Elemental will attack whatever MAGE is Fighting **/
  if(MAGE)
  {
    if(MAGEA && !this_object()->query_attack())
	{
      attack_object(MAGEA);
    }
  }	
  

  /** If MAGE is present and fighting, Elemental will taunt attackers if FTR is NOT present **/
  if(MAGE && !FTR)
  {
    if(MAGEA)
	{
    taunt();
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
	    if(att == CLC) {tell_object((ob[h]), "\n\The "+YEL+"Elemental"+NORM+" draws your attention to "+HIM+"PROTECT"+NORM+" the "+HIW+"Cleric"+NORM+"!\n\n"); }
        else if(att == MAGE) {tell_object((ob[h]), "\n\The "+YEL+"Elemental"+NORM+" draws your attention to "+HIM+"PROTECT"+NORM+" the "+HIC+"Mage"+NORM+"!\n\n"); }
        else if(att == THF) {tell_object((ob[h]), "\n\The "+YEL+"Elemental"+NORM+" draws your attention to "+HIM+"PROTECT"+NORM+" the "+GRY+"Thief"+NORM+"!\n\n"); }
		else {tell_room(ENV(TO), "\n\The "+YEL+"Elemental"+NORM+" draws the attention of "+ob[h]->query_name()+" to "+HIM+"PROTECT"+NORM+" the "+HIM+att->query_name()+NORM+"!\n\n"); }
        /* This attack_object function was not working properly with alt attackers, but the command function is working fine */
		/* ob[h]->attack_object(FTR); */
		command("kill lightning elemental", ob[h]);
      }
    }
  h++;
  }
  
  return 1;

}