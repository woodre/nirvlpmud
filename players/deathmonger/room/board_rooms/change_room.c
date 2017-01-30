/* Earwax 9/28/05
 * Switched from including std.h to inheriting room.c to pretty
 * up the room.  Added include of defs.h to standardize.
*/

#include "defs.h"
inherit "/room/room.c";

object board;

reset(arg)
{
  ::reset(arg);

  if(arg) return;

  if(!present("board"))
  {
    board = clone_object("players/vertebraker/obj/news_sign");
    move_object(board, this_object());
  }
  set_light(1);

  short_desc = "Change Room";
  long_desc = "The basement of the adventurers' guild is a dark, undermaintained\n"+
              "room with walls covered with graffiti.  In order to prevent you\n"+
              "from scribbling on the walls, a bulletin board is here for your\n"+
              "convenience.\n"+
              "It is intended to be used to post notes about changes that wizards\n"+
              "make that they feel players should be aware of.\n";
  dest_dir = ({ "/room/adv_guild", "up",
                 BOARD_ROOMS+"complaint_room.c", "down" });
}
