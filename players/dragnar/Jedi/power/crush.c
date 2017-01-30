#include "defs.h"

#define COST 100

inherit CMDBASE;

reset(arg) {
  if(arg) 
    return;
    
  skill_type = "telekinesis";
  skill_level = 7;
  rank_level = 10;
  atk_flag = 1;
  
}

status main(string str) {
  object spell;

  if( !force_spell( str ) )
    return 1;

  this_player()->spell_object(target, "crush", SKILL+random(18), 0, "");
  write("You tighten the living force that surrounds "+NAME(target)+"'s throat.\n");
  say(NAME(this_player())+" points toward "+NAME(target)+".\n");
  spell = clone_object( "/players/dragnar/Jedi/obj/crush" );
  move_object(spell, this_player());
  spell->set_enemy( target );
  this_player()->add_spell_point( -COST );
  PO->set_force_delay(10);
  return 1;
}
