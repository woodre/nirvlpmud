#include "defs.h"
#include "dir.h"
#include <ansi.h>

inherit CMDBASE;

#define BONUS ({ "feint","strike", })
#define COST 10
#define SPELL COST*2
#define MODIFIER 1
#define RAGE 1

reset(arg) {
  if(arg) 
    return;
    
  skill_type = "saber";
  skill_level = 2;
  rank_level = 1;
  atk_flag = 1;
  saber_flag = 1;
  sp_cost = COST;
}

main() {
  int Dam, SpellDam, PenaltyMod;
  status bonus;
  string OldType;

  if( !force_spell() )
    return 1;
  
  OldType = Saber->query_modtype(); /* Last attack used */
  if(member_array(OldType, BONUS) > -1) bonus = 1;
  Dam = 0;
  SpellDam = 0;
  
  if(PO->query_rage()) Dam += RAGE;
  
  if(Saber->query_modifier() && !bonus) {
    write("You are already doing an attack.\n");
    return 1;
  }
  
  else Dam += Saber->query_modifier();

  PenaltyMod = Saber->set_combo(query_verb());
  if(PenaltyMod) Dam -= SPELL*PenaltyMod;
  Saber->set_modtype(query_verb());
  if(bonus) Dam += MODIFIER + SKILL;
  if(!Dam) Dam = -1;
  Saber->set_modifier(Dam);
  if(Dam > 0) {
    SpellDam = SPELL;
	  this_player()->set_spell_dam(SPELL);
  }
  switch(Dam + SpellDam) {
  case 12..100:
    write("You swing at "+ATTN+" and land a quick strike.\n");
    break;
  case 1..11:
    write("You swing with a quick strike, but your timing is slightly off.\n");
    break;
  default:
    write("You swing with a quick strike, but "+ATTN+" blocks your attack.\n");
    break;
  }
   return 1;
}