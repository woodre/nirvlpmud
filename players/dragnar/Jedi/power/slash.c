#include "defs.h"
#include "dir.h"
#include <ansi.h>

inherit CMDBASE;

#define BONUS ({ "feint","strike", })
#define COST 12
#define SPELL COST/2
#define MODIFIER 2
#define RAGE 2

main() {
  int Dam, SpellDam, PenaltyMod;
  object Saber;
  status bonus;
  string OldType;

  if(!USER->query_attack()) return 0;
  Saber = present("jedi_saber", USER);
  if(!Saber || !Saber->query_ignited()) return 0;
  skill_type = "saber";
  if(skill_check(3)) return 1;
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
  if(cp_check(COST/SKILL)) return 1;
  if(sp_check(COST)) return 1;

  USER->add_spell_point(-COST);
  PO->adj_cp(-COST/SKILL);
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
  case 17..100:
    write("You slash quickly from right to left with your Lightsaber and hit "+ATTN+".\n");
    break;
  case 1..16:
    write("You slash from left to right, but your timing is slightly off.\n");
    break;
  default:
    write("You slash from left to right, but "+ATTN+" blocks your attack.\n");
    break;
  }
   return 1;
}