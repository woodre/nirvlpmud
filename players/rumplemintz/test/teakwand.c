/*
 * Teakwood wand
 */

inherit "/players/rumplemintz/basic/item";

void
configure()
{
  ::configure();
  set_encumbrance(1);
  set_id(({ "wand", "teakwood wand" }));
  set_short("A Teakwood Wand");
  set_long("A Teakwood Wand.  Probably belonged to a wizard of some sort.\n");
  set_value(-1);
}

void
init()
{
  add_action("wand_damage", "tzap");
}

status
wand_damage()
{
  object target;
  target = (object)this_player()->query_attack();
  if (!target || !present(target, environment(this_player())))
  {
    write("That is not here.\n");
    return 1;
  }

  write("You raise the wand and point it at "+target->query_name()+"!\n");
  say("A lightning bolt shoots down from the sky to smite "+target->query_name()+"!\n");
  target->hit_player(10000);
  return 1;
}
