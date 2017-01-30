/*
 * Test Heal - Useful for LD testing - do not use
 */

inherit "/players/rumplemintz/basic/item";

void
configure()
{
  ::configure();
  set_encumbrance(1);
  set_id(({ "heal", "heal_spell", "spell" }));
  set_short("A heal spell");
  set_long("A heal spell.  Cast heal, or Cast spell to use.\n");
  set_value(-1);
}

void
init()
{
  add_action("use_heal", "cast");
}

status
use_heal(string str)
{
  if (!str || !id(str))
    return 0;
  write(this_player()->query_name()+" casts a heal spell.\n");
  this_player()->heal_self(1000);
  return 1;
}
