#include "defs.h"
#include "dir.h"
#include <ansi.h>

inherit CMDBASE;

#define STAT this_player()->query_attrib("ste")
#define BONUS ({ "feint","parry", })
#define COST 22
#define SPELL COST/2
#define MODIFIER 14
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
  if(skill_check(9)) return 1;
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
  if(bonus && SKILL && ATTHP < 2 && attack->query_hp() < (SKILL*(STAT/4))) {
    write("\t\t\tHPS: "+attack->query_hp()+".\n");
    tell_object(USER,
      "You sidestep around "+ATTN+" and strike a deadly blow with your Lightsaber.\n");
    attack->heal_self(-attack->query_hp());
    USER->set_spell_dam(56);
    USER->add_spell_point(-COST);
    PO->adj_cp(-COST/SKILL);
    return 1;
  }
  USER->add_spell_point(-COST);
  PO->adj_cp(-COST/SKILL);
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
  case 37..100:
    write("You counter your "+OldType+" by sidestepping "+ATTN+" and delivering a devestating strike.\n");
    break;
  case 21..36:
    write("You sidestep around "+ATTN+" and strike a blow at their exposed flank.\n");
    break;
  case 12..20:
    write("You sidestep around "+ATTN+" and deliver a weakened blow at their exposed flank.\n");
    break;
  case 1..11:
    write("You attempt to sidestep, but "+ATTN+" recovers and partially blocks your attack.\n");
    break;
  default:
    write("You sidestep to the "+dir()+" but "+ATTN+" moves evasively out of your range.\n");
    break;
  }
   return 1;
}
