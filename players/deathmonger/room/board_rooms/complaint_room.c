/* Earwax 9/28/05
 * Switched from including std.h to inheriting room.c to pretty
 * up the room.  Added include of defs.h to standardize.
*/

#include "defs.h"
inherit "/room/room.c";

object board, assassin;

reset(arg)
{
  ::reset(arg);

  if(arg) return;

  if(!present("board"))
  {
    board = clone_object(OBJ+"board.c");
    board->set_datafile("complaint");
    board->set_name("Complaints");
    move_object(board, this_object());
  }
  set_light(1);

  short_desc = "Complaint Room";
  long_desc = "The basement of the adventurers' guild is a dark, undermaintained\n"+
              "room with walls covered with graffiti.  In order to prevent you\n"+
              "from scribbling on the walls, a bulletin board is here for your\n"+
              "convenience.\n"+
              "It is intended to be used for complaints, bitching, and whining.  Feel\n"+
              "free to complain about the mud, quests, wizards, other players, or the\n"+
              "Guatamalan gorillas who smuggle explosive papayas into Ohio.\n";
  dest_dir = ({
    BOARD_ROOMS+"change_room.c", "up",
    BOARD_ROOMS+"flameroom", "south" });
 /*
    if(!present("assassin")){
      assassin = clone_object("players/deathmonger/MONSTERS/recruiter");
      move_object(assassin, this_object());
    }
 */
}

north() { write("What?\n"); return 1; }
/*
_old_north(){
    if(present("license", this_player())){
       this_player()->move_player("north#players/pain/closed/ASSASSIN/cenguild");
      return 1;
      }
    else {
        write("Can't you tell when you're not wanted?\n");
     return 1;
      }
}
*/

init() {
  ::init();
  add_action("north", "north");
}
