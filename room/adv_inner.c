inherit "/room/room";

void reset(status arg) {
  object board;
  if(!present("board")) {
   move_object(clone_object("obj/wiz_bull_board"), this_object());
/*
    move_object(clone_object("/object/news/wiz_board.c"),this_object());
*/
  }
  if(arg)
    return;
  set_light(1);
  short_desc="An inner room of the adventurer's guild";
  long_desc=
"This is a room for communications regarding the move to LDMUD.  If\n\
You are looking for the old wiz board, check the 'read news' command.\n";
  dest_dir =({
    "room/adv_guild", "north",
    "room/adv_inner2", "south",
    "room/adv_inner3", "west",
  });
}
