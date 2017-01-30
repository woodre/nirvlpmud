#include "defs.h"
#include <ansi.h>
#include "hp_mod.h"

#define SKILL previous_object()->query_skill("saber")
#define BONUS 7 /*Attackers hps where we get a bonus */

main() {
  object Saber;
  int base;
  status bonus;

  if(!USER->query_attack()) return 0;
  Saber = present("jedi_saber", USER);
  if(!Saber || !Saber->query_ignited()) return 0;
  if(Saber->query_modifier()) return 0;
  base = 1 * SKILL;
  if(SP < base) {
    tell_object(USER, "You are too drained to do that.\n");
    return 1;
  }
  USER->add_spell_point(-base);
  if(ATTHP == BONUS) bonus = 1;
  Saber->set_modtype("roll");
  if(!hp_mod(BONUS)){
    tell_object(USER,
    "You attempt to shoulder roll, but "+ATTN+" doesn't waver.\n");
    USER->hit_player(random(50));
    Saber->set_modifier(-56);
    return 1;
  }

  tell_object(USER,
    "You shoulder roll evasively, and lead into "+ATTN+" with a quick thrust.\n");
  if(bonus) base += Rank*2;
  Saber->set_modifier(base);
  return 1;
}
