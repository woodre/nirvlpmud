/*
File: townhall.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  A town hall where players can post notes.
*/

#include "defs.h"

inherit ROOM;

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
"  Rows of benches fill the front room of Calador's town hall which\n"+
"is also a meeting room for the local citizenry.  A bulletin board is\n"+
"posted on the wall next to the front door.\n";
  items=({
    "benches","A dozen rows of hard oak benches face the podium at the\n"+
              "front of the room",
  });
  dest_dir=({
    PATH+"marble3","north",
  });
}
