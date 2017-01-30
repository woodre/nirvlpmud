#include "defs.h"
#include "dir.h"
#include <ansi.h>

inherit CMDBASE;

#define STAT this_player()->query_attrib("ste")
#define BONUS ({ "parry","feint","side","lunge", })
#define COST 30
#define SPELL COST/2
#define MODIFIER 22
#define RAGE 6

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
  SpellDam;
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
      "You spin to your "+dir()+" and cut down "+ATTN+" with your Lightsaber.\n");
    attack->heal_self(-attack->query_hp());
    USER->set_spell_dam(56);
    USER->add_spell_point(-COST);
    PO->adj_cp(-COST/SKILL);
    return 1;
  }
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
  case 52..100:
    write("You counter your "+OldType+" with a spin to the "+dir()+".\n");
    break;
  case 34..51:
    write("You spin to your "+dir()+" and use the momentum to deliver your blow.\n");
    break;
  case 17..33:
    write("You spin to your "+dir()+" but "+ATTN+" partially blocks your attack.\n");
    break;
  case 1..16:
    write("You spin to your "+dir()+" but "+ATTN+" moves slightly and weakens your blow.\n");
    break;
  default:
    write("You spin to your "+dir()+" but "+ATTN+" moves just out of your range.\n");
    break;
  }
   return 1;
}
