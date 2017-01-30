inherit "room/room";
reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc = "Dwarf Lord castle lobby";
    long_desc = "You are in the small, grungy lobby of the Dwarf Lord's castle.\n"+
    "there is blood strewn all about the floor, and you get a qweezy feeling\n"+
    "about the castle in general.\n";
    dest_dir = ({
      "players/rumplemintz/room/dlords/castle/room1", "east",
      "players/rumplemintz/room/dlords/castle/outside", "out",
      });
    items = ({
      "blood", "It looks fresh, and plentiful."
      });
    }
}
