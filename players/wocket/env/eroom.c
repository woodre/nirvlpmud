#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/room.c";

reset(arg){
  if(!present("board",this_object()))
    move_object(clone_object("/players/wocket/env/eboard.c"),this_object());
  if(arg) return;
  short_desc = HIB+"Environmental Meeting Room"+OFF;
  long_desc = "   "+
  "A large room with a circular oak table resting in the middle.  Large\n"+
  "candles light the room.  Light shimmers off the fine table.  Soft cushy\n"+
  "chairs surround the table.  A cork board hangs against the far wall\n"+
  "with small notes posted upon it.\n";
  set_light(1);
  dest_dir = ({ "/room/church.c","church" });
}
