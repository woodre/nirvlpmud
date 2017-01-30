#include "../def.h"
inherit "room/room";
reset(arg) {
  if(!present("board")) {
    object board;
    board=clone_object("/players/feldegast/std/board");
    board->set_file("players/feldegast/log/townhall");
    move_object(board,this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Town Hall";
  long_desc=
"    Rows of benches fill the front room of Haven's town hall which\n"+
"is also a meeting room for the local citizenry.  A bulletin board is\n"+
"posted on the wall next to the front door.  A staircase in the corner\n"+
"leads upstairs.\n";
  items=({
    "benches","A dozen rows of hard oak benches face the podium at the\n"+
              "front of the room",
    "staircase","A lacquered oak staircase in the corner leads upstairs"
  });
  dest_dir=({
    PATH+"Haven/town_square","north",
    PATH+"Haven/townhall2","up"
  });
}
