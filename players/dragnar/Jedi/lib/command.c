#include "../defs.h"
/******************************************************************************
 * Program: command.c
 * Path: /players/dragnar/Jedi/lib
 * Type: Inherit
 * Created: May 20th, 1999 by Dragnar
 *
 * Purpose: Inherited object for all of the Jedi spells. Keeps track of
 *          required variables and does all the checks for doing an
 *          attack. Some ideas borrowed from Pavliks Mage guild.
 *          Jedi spells are in the /bin directory.
 * History:
 *          05/20/1999 - Dragnar
 *            Created
 *          02/22/2014 - Dragnar
 *            Updated to include more variables and made calls more flexible.
 ******************************************************************************/

int skill_level;
int atk_flag;
int delay_flag;
int rank_level;
int saber_flag;
int sp_cost;
string skill_type;
string description;
object target;
object Saber;

int force_spell( string who );
int start_attack( string str );
status sp_check();
status rank_check();
status skill_check();
status saber_check();
delay_check();

int force_spell( string who ) {

  if(this_player()->query_ghost()) {
    notify_fail("You cannot reach the force while you are dead.\n");
    return 0;
  }
  if( !sp_check() ) {
    return 0;
  }
  
  if( rank_level && !rank_check() ) {
     return 0;
   }

  if( saber_flag && !saber_check() )
    return 0;
   
  if( atk_flag && !start_attack( who ) )
    return 0;
    
  if( delay_flag && !delay_check() )
    return 0;
    
  return 1;
}

int start_attack( string str ) {

  if(str) {
    target = present(str, environment(this_player()));
      if(!target) {
        write("You are unable to locate the force essence of "+capitalize(str)+".\n");
        return 0;
      }
      if(!living(target)) {
        write("The force essence of "+capitalize(str)+" indicates they are not a living being.\n");
        return 0;
      }
  }
  else
    target = (object) this_player()->query_attack();
  if(!target) {
    if( saber_flag ) {
      write("You must be attacking in order to use "+query_verb()+".\n");
        return 0;
    }        
      write("Who do you want to use "+query_verb()+" on?\n");
      return 0;
   }
   if( target == this_player()) {
      write("You can't attack yourself.\n");
      return 0;
   }
   if( target->query_ghost() ) {
      write("The force has no impact on the dead.\n");
      return 0;
   }
   if( target->is_player() && !present("jedi_object", target) ) {
      write("You can't use "+query_verb()+" on "+str+".\n");
      return 0;
   }

   return 1;
}

status rank_check() {
   if(this_player()->query_guild_rank() < rank_level ) {
      write("You have not mastered that ability.\n");
      return 0;
   }
   return 1;
}

status skill_check() {

  if(!skill_type) skill_type = query_verb();
  if(previous_object()->query_skill( skill_type ) < skill_level ) {
    write("You have not mastered that ability.\n");
    return 0;
  }
  return 1;
}

status saber_check() {
  
  Saber = present("jedi_saber", environment(previous_object()) );
  if(!Saber || !Saber->query_ignited()) {
    write("You try to "+query_verb()+" but fail.\n");
    return 0;
  }
    
  return 1;
}

status cp_check(int needed) {
   if(previous_object()->query_cp() < needed || this_player()->query_ghost()) {
    write("Your concentration fails you.\n");
    return 0;
  }
  return 1;
}

status sp_check() {
  if(this_player()->query_sp() < MIN_SP ) {
    write("You are too drained to call on the force.\n");
    return 0;
  }
  if( sp_cost > 0 )
    this_player()->add_spell_point(-sp_cost);
  
  return 1;
}

delay_check() {
  if(previous_object()->query_force_delay()) {
    write("You are too weary to concentrate.\n");
    return 0;
  }
  return 1;
}

level_to_class(int x ) {
  switch( x ) {
  case 1..4:
    return "Apprentice";
    break;
  case 5..8:
    return "Jedi Knight";
    break;
  case 9..12:
    return "Jedi";
    break;
  case 13:
    return "Jedi Master";
    break;
  default:
    return "Error";
    break;
  }
}
