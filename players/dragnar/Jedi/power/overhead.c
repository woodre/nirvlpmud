#include "defs.h"
#include "dir.h"
#include <ansi.h>

inherit CMDBASE;

#define STAT this_player()->query_attrib("ste")
#define BONUS ({ "underhand","spin", })
#define COST 24
#define SPELL COST/2
#define MODIFIER 15
#define RAGE 5

main() {
  int Dam, SpellDam, PenaltyMod;
  object Saber;
  status bonus;
  string OldType;

  if(!USER->query_attack()) return 0;
  Saber = present("jedi_saber", USER);
  if(!Saber || !Saber->query_ignited()) return 0;
  skill_type = "saber";
  if(skill_check(7)) return 1;
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
  if(ATTHP > 5 && !bonus) Dam -= random(ATTHP*10);
  PenaltyMod = Saber->set_combo(query_verb());
  if(PenaltyMod) {
    Dam -= SPELL*PenaltyMod;
    bonus = 0;
  }
  Saber->set_modtype(query_verb());
  if(bonus) Dam += MODIFIER + SKILL;
  if(!Dam) Dam = -1;
  Saber->set_modifier(Dam);
  if(Dam > 0) {
    SpellDam = SPELL;
	this_player()->set_spell_dam(SPELL);
  }
  switch(Dam + SpellDam) {
  case 47..100:
    write("You counter your "+OldType+" with a fierce downward swing toward "+ATTN+".\n");
    break;
  case 30..46:
    write("You raise your Lightsaber above your head and cut straight down at "+ATTN+".\n");
    break;
  case 15..29:
    write("You bring your Lightsaber stright down, but "+ATTN+" partially blocks your attack.\n");
    break;
  case 1..14:
    write("You bring your Lightsaber straight down, but miscalculate your strike.\n");
    break;
  default:
    write("You raise your Lightsaber above your head but "+ATTN+" strikes you while you are vulnerable.\n");
    if(!random(7)) {
      this_player()->hit_player(random(30));
    }
    break;
  }
   return 1;
}
