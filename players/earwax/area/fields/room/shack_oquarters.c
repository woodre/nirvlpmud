#include "../defs.h"

inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("Guard Officer Quarters");
  set_long("This is the "+ENG+" Special Beano Control Detachment officer quarters.  Aside from a couple of bunks and a dirty floor, the only remarkable thing about this room is the smell.  It's reminiscent of a month-old rat corpse stuffed inside a fermented sausage after being spritzed up with some skunk musk.  The C.O.'s office is to the north.");
  add_exit("north", RPATH + "shack_office");
  add_desc("bunks", "They look like they could be comforable for someone without nerve endings.");
  add_desc("floor", "So filthy a cockroach wouldn't walk across it.");
}

void
on_reset()
{
  object ob;

  if (!present("captain", this_object()))
  {
    ob = (object)MOB_SETUP->make_capt();
    move_object(ob, this_object());
    say((string)ob->query_name()+" arrives.\n");
  }
}
