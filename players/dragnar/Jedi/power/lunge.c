#include "defs.h"
#include "dir.h"
#include <ansi.h>

inherit CMDBASE;

#define STAT this_player()->query_attrib("str")
#define BONUS ({ "parry","feint", })
#define COST 35
#define SPELL COST/2
#define MODIFIER 28
#define RAGE 7

main() {
  int Dam, SpellDam, PenaltyMod;
  object Saber;
  status bonus;
  string OldType;

  if(!USER->query_attack()) return 0;
  Saber = present("jedi_saber", USER);
  if(!Saber || !Saber->query_ignited()) return 0;
  skill_type = "saber";
  if(skill_check(10)) return 1;
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
      "You lunge at "+ATTN+" and impale them on your Lightsaber.\n");
    attack->heal_self(-attack->query_hp());
    USER->set_spell_dam(56);
    USER->add_spell_point(-COST);
    PO->adj_cp(-COST/SKILL);
    return 1;
  }
  USER->add_spell_point(-COST);
  PO->adj_cp(-COST/SKILL);
  if(ATTHP > 3) {
    Dam = -56;
    bonus = 0;
  }
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
    write("You counter your "+OldType+" by lunging at "+ATTN+" with massive force.\n");
    break;
  case 34..51:
    write("You pull your Lightsaber back and lunge toward "+ATTN+" delivering a vicious blow.\n");
    break;
  case 17..33:
    write("You lunge nimbly at "+ATTN+".\n");
    break;
  case 1..16:
    write("You lunge forward, but "+ATTN+" moves slightly and weakens your blow.\n");
    break;
  default:
    write("You lunge at "+ATTN+" but miscalculate your timing.\n");
    if(!random(5)) {
      write(ATTN+" counters your move and delivers a blow to your exposed midsection.\n");
      this_player()->hit_player(random(40));
    }
    break;
  }
   return 1;
}