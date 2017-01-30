#include "../defs.h"
inherit CMDBASE;
#include <ansi.h>
/******************************************************************************
 * Program: thrust.c - Jedi guild
 * Path: /players/guilds/Jedi/spells
 * Type: Spell Daemon for Thrust
 * Created: May 20th, 1999 by Dragnar/Maledicta
 * Description: Thrust is a Lightsaber attack that adds to the wc bonus in the
 *              guild object. Jedi must do attacks and get combinations to get
 *              the guild wc bonus. 
 *    NOTE: Much of the functionality is in the inherited object.
 * History:
 *          05/20/1999 - Dragnar
 *            Created
 *          08/12/2015 - Dragnar
 *            Moved code to /players/guilds and fixed includes etc. Moved much
 *            of the code to the command.c object so it can be reused.
 ******************************************************************************/

reset(arg) {
  if(arg) 
    return;
    
  skill_type = SABER;
  skill_level = 5;
  rank_level = 2;
  atk_flag = 1;
  saber_flag = 1;
  sp_cost = 16;
  BonusAttacks = ({ "parry","feint","spin","underhand", });

}

main( string str, object jedi, object gob ) {
  int Dam, Penalty;

  /* This is where most of the work is done in the superclass */
  if( !force_spell( str, jedi, gob ) )
    return 1;

  Dam = sp_cost*2;

#if DEBUG
  tell_object( jedi, "DAM1: "+Dam+" old_attack :"+old_attack+"\n" );
#endif
  
  Penalty = gob->set_combo( query_verb() );

#if !PENALTY_DEBUG
  if(Penalty) {
    Dam -= sp_cost * Penalty;
#if DEBUG
    tell_object( jedi, "\t\tPenalty: "+ sp_cost * Penalty+"\n" );
#endif
  }
#endif

  gob->set_saber_attack( query_verb() );
  if(combo_bonus) 
    Dam += gob->query_skill(skill_type);
#if DEBUG
  tell_object( jedi, "DAM3: "+Dam+"\n" );
#endif
  gob->set_saber_bonus(Dam);
  
  switch(Dam) {
  case 33..100:
    write("You counter your "+( old_attack ? old_attack : "attack")+" by pulling back your Saber and thrusting it at "+target->query_name()+".\n");
    break;
  case 18..32:
    write("You pull your Lightsaber back and thrust it toward "+target->query_name()+" delivering a brutal blow.\n");
    break;
  case 1..17:
    write("You pull back your Lightsaber and thrust, but "+target->query_name()+" partially blocks your attack.\n");
    break;
  default:
    write("You thrust your Lightsaber at "+target->query_name()+" but miscalculate your timing.\n");
    break;
  }
   return 1;
}
