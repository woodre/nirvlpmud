#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
  object videotape;
  
  if (!present("videotape")) {
    videotape = clone_object("obj/treasure");
    call_other(videotape,"set_id","videotape");
    call_other(videotape,"set_short","videotape");
    call_other(videotape,"set_name","videotape");
    call_other(videotape,"set_long","The Lost Episodes of Star Trek\n");
    call_other(videotape,"set_alias","trekkie");
    call_other(videotape,"set_weight",1);
    call_other(videotape,"set_value",12);
    move_object(videotape,this_object());
  }
}

ONE_EXIT("players/rich/quest/tapedud.c", "west",
	 "Jetty",
	 "You are at a jetty. The waves rolls in from east.\n"+
	 "A small path leads back to west.\n", 1)
