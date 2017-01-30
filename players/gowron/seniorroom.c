inherit "room/room";

#include "players/balowski/guild/people.h"

object board;

reset(arg) {
   if (arg) return;
   set_light(1);
   short_desc = "Senior's Room";
   long_desc = "This is a room where the guild elite can meet to "+
 	       "disscuss guild policy or whatever they want. From "+
	       "here, you can either take the stairs to the throne "+
	       "room, or go west to the law room.\n";
   long_desc = format(long_desc,75);
   dest_dir = ({ "players/balowski/guild/room/throne", "up",
                 "players/balowski/guild/room/lawroom", "west" });
   if (!present("board")) {
      board = clone_object("players/balowski/std/board2");
      board->set_name("seniors");
      board->set_size(50);
      board->set_short("A bulletin board for senior discussions.\n");
      /* I'm not going to deal with security. I'm going to */ 
      /* filter out all non readers in init() 		   */
      move_object(board, this_object());
   }
}

init() {
   object mark;
   int class;

   mark = present("mark", this_player());
   class = mark->GuildClass();
   if (class < C_BESERKER) 
      this_player()->move_player("kicked out#players/balowski/guild/room/grotto");
}
