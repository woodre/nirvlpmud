#pragma strong_types

inherit "room/room";

object guard;

void populate();

void reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("North shore");
  set_long(
"You are at the northern shore of a small lake in the forest.\n"+
"The trees are impressingly beautiful, high and green,\n"+
"and in the clear water you can see a reflection of the blue sky.\n");
  dest_dir = ({
    "players/padrone/outside/crosspath1", "east",
  });
}

void populate() {
  if (!guard || !living(guard)) {
    move_object(clone_object("/players/padrone/outside/npc/ns_guard"),
                this_object());
  }
}
