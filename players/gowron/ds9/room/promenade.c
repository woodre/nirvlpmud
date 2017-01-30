inherit "room/room";

get_odo() {
  move_object(clone_object("players/gowron/ds9/monster/odo", this_object());
}

reset(arg) {
  if (arg) {
     if (!present("odo"))
        get_odo();
  return;
  }
  set_light(1);
  short_desc = "Promenade";
  long_desc = "You have stepped onto the promenade. It appears to be "+
              "a sprawling business area. There are people walking around "+
              "of all races and backgrounds. As you look back to the south "+
              "you see the turbolift. Further down the promenade you see "+
              "Garak's tailor shop. Directly to your left is Quark's bar. ";
  long_desc = format(long_desc, 75);
  dest_dir = ({ "players/gowron/ds9/room/turbolift", "south",
                "players/gowron/ds9/room/quarks", "west",
                "players/gowron/ds9/room/tailor", "north", });
  get_odo();
}
