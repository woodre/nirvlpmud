
#include "std.h"

object board;

reset(arg)
{
  if(!arg)
  {
    if(!present("board"))
    {
      board = clone_object("players/fred/closed/change_board");
      move_object(board, this_object());
    }
  }
  set_light(1);
}


init()
{
  add_action("up", "up");
  add_action("down","down");
}

down()
{
  this_player()->move_player("down#players/deathmonger/CASTLE/complaint_room");
  return 1;
}

up()
{
  this_player()->move_player("up#room/adv_guild");
  return 1;
}


short(){ return "Change room"; }

long()
{
  write("The basement of the adventurers' guild is a dark, undermaintained\n"+
        "room with walls covered with graffiti.  In order to prevent you\n"+
        "from scribbling on the walls, a bulletin board is here for your\n"+
        "convenience.\n");
  write("It is intended to be used to post notes about changes that wizards\n"+
        "make that they feel players should be aware of.\n");
 write("   There are two obvious exits: up and down.\n");
}

