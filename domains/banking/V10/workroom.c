/*
 * This is the V10 workroom of the Banking domain.
 * Here wizards can register new banks and erase them if they are to be
 * closed. Therefore the castle moves itself into this room
 */

#pragma strong_types

#include <banking.h>

inherit "complex/room";

private void
make_exit(string s)
{
  add_exit("player/"+s+"/workroom",s);
}

void
configure()
{
  room::configure();
  set_short("Banking workroom");
  set_long("This is the Banking workroom. Here you can open a new bank and"
           " close an old one if you wish to dissolve your bank.\n");
  map(BANKING_MEMBERS,#'make_exit);
  add_exit(BANKING"doc/moonshine","west");
  add_exit(BANKING"doc/sunrise","east");
  add_exit(BANKING"doc/highnoon","south");
  add_exit(BANKING"doc/midnight","north");
}

void
populate()
{
  object board;
  room::populate();
  if (!present("board",this_object()))
  {
    board = clone_object("complex/board");
    board->set_topic("economy and banking");
    board->set_admins(BANKING_LORDS);
    board->set_database("/"BANKING"save/economy_board",0,0);
    move_object(board,this_object());
  }
}

void
board_room()
(         /* This is necessary to let a board stand here */
}
