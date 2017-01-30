#include "defs.h"
#include "dir.h"
#include <ansi.h>

inherit CMDBASE;

#define COST 10
#define Penalty COST*2

reset(arg) {
  if(arg) 
    return;
    
  skill_type = "saber";
  skill_level = 1;
  rank_level = 1;
  atk_flag = 1;
  saber_flag = 1;
  sp_cost = COST;
}

main() {
  int Dam, PenaltyMod;
  status bonus;
  string OldType;

  if( !force_spell() )
    return 1;

  OldType = Saber->query_modtype(); /* Last attack used */
  Dam = COST*2;
  if(Saber->query_modifier()) {
    write("You are already doing an attack.\n");
    return 1;
  }

  if(OldType == query_verb()) 
    Dam -= Penalty;
  
  Saber->set_modtype(query_verb());
  
  if(!Dam) Dam = -1;
  
  Saber->set_modifier(Dam);
  
  switch(Dam) {
  case 1..100:
    write("You feint to the "+dir()+", misleading "+target->query_name()+" into your attack.\n");
    break;
  default:
    write("You feint to the "+dir()+" but "+ATTN+" doesn't waver.\n");
    if(!random(10)) {
      USER->hit_player(random(SKILL*2));
    }
    break;
  }
   return 1;
}
