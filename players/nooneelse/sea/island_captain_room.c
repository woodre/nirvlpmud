/*
 island_captain_room.c
*/

inherit "room/room";

object obj;

init() {
  ::init();

  add_action("read", "read");
}

read(str) {
  if (!str && str != "paper") return;
  command("look at paper", this_player());
  say (this_player()->query_name()+" examines the piece of paper.\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("Captain Nimo's room");
  long_desc=("This room is a combination bedroom/study.\n"+
             "You can see a bed, a chair and a desk with some paper on it.\n");
  no_castle_flag=1;
  items =
    ({
      "desk", "It is a beautiful old writing desk.  There is a "+
              "piece of paper on it.",
      "chair", "A nice comfortable chair pushed up next to the desk.",
      "paper", "The note looks like a page from a diary.  It says:\n"+
               "   .......................................................\n"+
               "   :                                                     :\n"+
               "   :      My divers have finally found it!               :\n"+
               "   :                                                     :\n"+
               "   :      Soon we plunder the Seaview!                   :\n"+
               "   :                                                     :\n"+
               "   :      Hah!  I knew that bugger Captain S'drawkcab    :\n"+
               "   :                                                     :\n"+
               "   :      couldn't hide his treasures from me forever!   :\n"+
               "   :                                                     :\n"+
               "   .......................................................",
  });
  dest_dir =
    ({
      "players/nooneelse/sea/island_hall", "north",
    });
  return;
}
