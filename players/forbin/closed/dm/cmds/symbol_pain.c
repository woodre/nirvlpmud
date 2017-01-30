#include "../defs.h"

inherit SPELL;

void reset(int x)
{
  if(x) return;
  set_spell(
    "Symbol: Pain", /* spell name */
    0,              /* hp cost */
    0,              /* sp cost */
    0,              /* sac cost */
    0,              /* fae req */
    0,             /* glevel req */
  );
}

status main(string str, object gob, object player)
{
  object targ;
  if(!(targ = spell_ok(0,"attack:npc",str)))
    return 1;
    
  tell_object(player,
    "You attacked "+(string)targ->query_name()+" with "+SpellName+".\n");
  return 1;
}

