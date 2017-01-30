#include "../defs.h"

inherit ROOM;

status
query_property(string arg) {
  return (arg == "no_fight");
}

void
on_create() {
  set_short("NPC Storage Room");
  set_no_clean(1);
  add_exit("up", RPATH+"sanctuary");
  set_long("This is the room where NPCs go that are booted out of the sanctuary.  No fighting here, it's designed so they don't spam up the sanctuary or cause problems there.");
}

void
on_init()
{
  object mob;

  mob = this_player();

  if (creator(mob) == "earwax")
    mob->move_player("arrives#"+RPATH+"fields"+(random(10)+1));
}
