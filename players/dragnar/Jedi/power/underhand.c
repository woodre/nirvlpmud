#include "defs.h"
#include "dir.h"
#include <ansi.h>

inherit CMDBASE;

#define BONUS ({ "feint","parry","spin", })
#define COST 16
#define SPELL COST/2
#define MODIFIER 7
#define RAGE 3

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
  this_player()->set_spell_dam(SPELL);
  if(Dam > 0) {
    SpellDam = SPELL;
	this_player()->set_spell_dam(SPELL);
  }
  switch(Dam) {
  case 28..100:
    write("You counter your "+OldType+" with a quick underhand strike.\n");
    break;
  case 17..27:
    write("You rotate your Saber with your wrist and swing your saber in an arc with amazing force.\n");
    break;
  case 1..16:
    write("You do a quick underhand strike, but your timing is slightly off.\n");
    break;
  default:
    write("You do a quick underhand strike, but "+ATTN+" blocks your attack.\n");
    break;
  }
   return 1;
}
