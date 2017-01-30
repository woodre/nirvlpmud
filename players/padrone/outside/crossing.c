#pragma strong_types

inherit "room/room";

object sign, obliterator;

void populate();

void reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("Crossing");
  set_long(
"You are at a crossing, where two small paths are\n"+
"crossing each other in the forest.\n");
  dest_dir = ({
    "players/padrone/outside/path2", "north",
    "players/padrone/outside/path3", "south",
    "players/padrone/outside/crosspath1", "west",
    "players/padrone/outside/crosspath2", "east"
  });
}

void populate() {
  if (!obliterator &&
      !find_object("/players/padrone/outside/npc/crossing_obliterator")) {
    obliterator = clone_object("/players/padrone/outside/npc/crossing_obliterator");
    move_object(obliterator, this_object());
  }
  if (!sign) {
    sign = clone_object("players/padrone/obj/thing");
    sign->set_name("sign");
    sign->set_short("A sign pointing south");
    sign->set_long("This is a small white wooden sign on a pole.\n"+
            "It is pointing south, and there is something written on it.\n");
    sign->set_read("It says:  This way to the Caslte of Padrone.\n");
    sign->set_can_get(0);
    move_object(sign, this_object());
  }
}
