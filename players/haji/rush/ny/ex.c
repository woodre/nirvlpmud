inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="A street in New York";
long_desc="There is the putrid smell of liberals here....\n" +
          "You can barely hear yourself over the wimpering and the heaving.\n" +
          "To the south youu see sanctuary as the EIB building looms over you.\n" +
          "To the west you see a bookstore, and finally, to the northwest,\n" +
          "you see the headquarters for R.U.S.H..\n";

/* The dest_dir  is a list of directions out of this room. The format is
 * "room_to_move_to" , "command_to_move"  where the command is anything
 * from north, south, east, west to jump, asdf, scramble, wat_eber.
 */
  dest_dir=({
          "players/haji/rush/ny/wstreet3", "north",
          "players/haji/rush/ny/wstreet1", "south",
            });
set_light(1);

items = ({"bookstore",
"This is the bookstore that has that great book The way things ought to be.\n",
"headquarters",
"This is the headquarters for R.U.S.H.,it is the orgainization to be in.\n"
  });
}


monster() {
int count;
   object liberal;

   if(!present("liberal")) {
    while (i<6) {
      liberal = clone_object("players/haji/rush/char/lib");
      move_object(liberal, this_object());
     i++;
       }
    i = 0;
   }
}
