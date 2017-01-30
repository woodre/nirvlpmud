#include "defs.h"
#include "dir.h"
#include <ansi.h>

#define SKILL previous_object()->query_skill("saber")

main() {
  object Saber;
  int Base, Cost;
  status bonus;

  if(!USER->query_attack()) return 0;
  Saber = present("jedi_saber", USER);
  if(!Saber || !Saber->query_ignited()) return 0;
  if(Saber->query_modifier()) return 0;
  Base = 10+SKILL;
  Cost = Base/2;
  if(SP < Cost) {
    tell_object(USER, "You are too drained to do that.\n");
    return 1;
  }
  USER->add_spell_point(-Cost);
  Saber->set_modtype(query_verb());
  Saber->set_modifier(1);
  tell_object(USER,
    "You feint to the "+dir()+", misleading "+ATTN+" into your attack.\n");
  return 1;
}
