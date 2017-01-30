inherit "room/room";

object rom;

reset(arg) {
  if (arg) {
     if (!present("rom")) {
        rom = clone_object("players/gowron/ds9/monster/rom");
        move_object(rom,this_object());
     }
     return;
  } 
  set_light(1);
  short_desc = "Corridor";
  long_desc = "As you walk down the corridor you realize that the "+
              "construction of this space station must have been "+
              "one great undertaking, most likely built by Bajoran "+
              "slave labor. To your south you see the docking bay, "+ 
              "and to your north you see the turbolift.\n";
  long_desc = format(long_desc,75);
  dest_dir = ({ "players/gowron/ds9/room/dockingbay", "south",
                "players/gowron/ds9/room/turbolift", "north", });
   rom = clone_object("players/gowron/ds9/monster/rom");
   move_object(rom, this_object());
}
