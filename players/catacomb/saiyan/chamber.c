#include "/players/catacomb/saiyan/def.h"
inherit "players/vertebraker/closed/std/room.c";

reset(arg)
{
  if(arg) return;
  set_light(1);

  set_short("Hyperbolic Time Chamber");
  set_long(
  " The room is devoid of everything.  You can see nothing but an\n"+
  "endless sea of white everywhere you look.  The temperature never\n"+
  "stays the same for more than a few minutes for some reason.  In\n"+
  "this chamber you can test your skills with other saiyans by sparring\n"+
  "with them.\n");

  add_exit("/players/catacomb/saiyan/lookout1.c","exit");
  add_property(string "SPAR");
}