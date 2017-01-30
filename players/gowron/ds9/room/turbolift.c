inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Turbolift";
  long_desc = "You have stepped onto a turbolift. This is an elevator that "+
              "can take you to various parts of the station. You may wish "+
              "to visit the promenade where many of the station "+
              "businesses, such as Quark's bar are located. Or you can "+
              "go to the habitat ring, where the crew quarters are "+
              "located. Ops is the nerve center of the station, where "+
              "all the important business is conducted.\n";
  long_desc = format(long_desc, 75);
  dest_dir = ({ "players/gowron/ds9/room/promenade", "promenade",
                "players/gowron/ds9/room/ops", "ops",
                "players/gowron/ds9/room/corridor", "south",
                "players/gowron/ds9/room/habitat", "habitat ring", });
}
