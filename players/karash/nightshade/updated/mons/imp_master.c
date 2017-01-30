inherit "obj/monster.c";
#include <ansi.h>

#define TO this_object() 
#define ENV environment

/******************************************************************************
 * Program: imp_master.c
 * Path: /players/nightshade/mons/
 * Type: Mob
 * Updated: September 2014 by Karash
 *
 * Purpose: The master imp was originally a high-level mob with no abilities.
 *          Based on Forgotten Realms imp abilities, imps have damage reduction (20% resist to physical dmg);
 *          fast healing (set_heal(5,1); immunity to poison (100% resist to poison dmg);
 *          resist to fire (20% resist to fire dmg); and Poison Dmg (poison wc = 20). 
 * 
 * History:
 *          
 ******************************************************************************/

object gold, weap;


reset(arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("imp");
  set_alias("master");
  set_short("Imp Master");
  set_long("This huge guy is here to prevent those unworthy of killing imps\n"+
"from doing so. Don't attack him.\n");

  set_level(22);
  set_hp(1500);
  set_wc(20);
  set_ac(20);
  
  /** Physical WC = 20; Poison WC = 20; However, when using set_weapon_params, exp calculation
   ** is not including physical WC in exp total, so using set_wc_bonus to force exp calculation
   ** to include set_wc(20)
   **/
  set_wc_bonus(20);
  
  set_heal(5,1);
  set_res(20); 
  set_ac_bonus(20); /* AC bonus for 20% physical resistance */  
  
  gold=clone_object("obj/money");
  gold->set_money(4000+random(2000));
  move_object(gold, this_object());

  /* PATH UPDATED */
  weap=clone_object("players/nightshade/weap/axe_new");
  move_object(weap, this_object());
  
  set_chance(45);
  set_spell_dam(100);
  set_spell_mess1("Die scum!");
  set_spell_mess2("The masters axe screams over his head and nails you square in the jaw,\n\
ripping half your face off!");

  set_weapon_params("other|poison",20,0); 
  
  set_armor_params("other|poison",0,100,0);
  
  set_armor_params("other|fire",0,20,0);
  
   
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

  