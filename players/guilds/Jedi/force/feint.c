#include "../defs.h"
inherit CMDBASE;
#include <ansi.h>
/******************************************************************************
 * Program: feint.c - Jedi guild
 * Path: /players/guilds/Jedi/spells
 * Type: Spell Daemon for Feint
 * Created: May 20th, 1999 by Dragnar/Maledicta
 * Description: Feint is a Lightsaber attack that adds to the wc bonus in the
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
  skill_level = 1;
  rank_level = 1;
  atk_flag = 1;
  saber_flag = 1;
  sp_cost = 5;
  BonusAttacks = ({ "feint","strike", });

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
  }
#endif

#if DEBUG
  if(Penalty) 
    tell_object( jedi, "\t\tPenalty: "+ sp_cost * Penalty+"\n" );
#endif

  gob->set_saber_attack( query_verb() );
  if(combo_bonus) 
    Dam += gob->query_skill(skill_type);
#if DEBUG
  tell_object( jedi, "DAM3: "+Dam+"\n" );
#endif
  gob->set_saber_bonus(Dam);
  
  switch(Dam) {
  case 1..100:
    write("You feint to the "+RDIR+", misleading "+target->query_name()+" into your attack.\n");
    break;
  default:
    write("You feint to the "+RDIR+" but "+target->query_name()+" doesn't waver.\n");
    if(!random(10)) {
      jedi->hit_player(random(gob->query_skill(skill_type)));
    }
    break;
  }
   return 1;
}
