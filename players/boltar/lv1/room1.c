#include "std.h"


#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
extra_init() {
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
  }

extra_reset() {
   object oldtwn;
   call_other("room/pub2.c","blah",0);
   if (!present("paper", find_object("room/pub2.c"))) {
oldtwn = clone_object("obj/treasure");
call_other(oldtwn, "set_id", "paper");
call_other(oldtwn, "set_name", "the old town news");
call_other(oldtwn, "set_alias", "news");
call_other(oldtwn, "set_read", "  \n\n\n"+
":----------------------------------------------------------------------:" +
"\n" +
":                        Ye Olde Town News                             :" +
"\n" +
":                                                                      :" +
"\n" +
":                          { 11-10-0147 }                              :" +
"\n" +
":                          ---est 0099---                              :" +
"\n" +
":                                                                      :\n" +
":   The Olde Town News --- we get the story first!                     :\n" +
":                                                                      :\n" +
": Big House Opens Pawn shop              death from firebreather       :\n" +
":                                                                      :\n" +
": The big house now contains a old       Don't drink and fight.        :\n" +
":style pawn shop. A new place where      It might get you killed.      :\n" +
":anyone can exchange their items         Just think about it. A service:\n" +
":for cash--and get them back for         of The Olde Town News - We    :\n" +
":only a small charge. On the wildwest    get the story FIRST!          :\n" +
":street, south and east of the shop.                                   :\n" +
":                                                                      :\n" +
":______________________________________________________________________:\n" +
"\n");
call_other(oldtwn, "set_value",4);
       call_other(oldtwn, "set_short", "The Old Town News");
move_object(oldtwn, this_object());
transfer(oldtwn, "room/pub2.c");
   }
    }

look(str) {
   if (!str) {
   return 0;
  }
 if (str == "at gate") {
  write("The gate looks badly rusted.\n");
   return 1;
  }
return 0;
}
FOUR_EXIT("players/boltar/castle.c", "exit",
          "players/boltar/castle.c", "east",
   "players/boltar/sprooms/dead_office.c", "north",
	   "players/boltar/lv1/room2", "west",
	   "Entrance room of the big house",
   "Upon entering The Big House you find that it does not look like a \n" +
   "prison on the inside either.  You realize that the name must come from\n" +
 "the huge prison style iron gate that lies to your west.  The gate appears\n"+
   "to be frozen in the open position by many decades of rust.\n"+
   "There is a wood and glass door to the north with 'legion office' painted on\n"+
   "the glass.\n", 1)
