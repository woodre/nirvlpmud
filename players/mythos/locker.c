#include <ansi.h>
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc = "Newbie Lockers";
    long_desc =
    "You have entered the Newbie Locker System <a Mythos Product>\n"+
    "This locker system is only for those of level 5 or below.\n"+
    "Please "+BOLD+"read sign"+NORM+" to learn how to utilize this system.\n"+
    "Thank you\n";
  items = ({
  });

  dest_dir = ({
    "/players/softly/nhall/rooms/n4", "west",
  });
} }

init() {
 ::init();
 if(this_player()->query_level() > 7 && this_player()->is_player() &&
  this_player()->query_real_name() != "mythos" &&
    this_player()->query_level() < 100) {
      write("You may not enter this room!\n");
      this_player()->move_player("out#players/mythos/enterance");
      return 1; }
/*
  if(this_player()->query_exp() > 26662 && this_player()->query_level() < 21) {
   write("Go level up! You have at least enough xp for level 7!\n");
   this_player()->move_player("out#players/mythos/enterance.c");
  return 1; }
*/
   if(this_player()->query_real_name() == "guest") {
     this_player()->move_player("out#room/church.c");
  return 1; }
 if(!present("locker_ob",this_player()) && this_player()->is_player()) {
   move_object(clone_object("/players/mythos/locker_ob.c"),
               this_player());
 }
 add_action("read","read");
}

read(str) {
  if(str && str == "sign") {
    write("The Newbie Locker System:\n"+
          "  Contains: 5 lockers per person \n\n");
    write("  Explanation:\n"+
          "    Lockers: any saveable item may be stored in each\n"+
          "             locker.  COST per item stored: ZERO xp\n\n");
    write("   Cmds:   store <name> - stores an item in a locker\n"+
          "           retrieve <name> - retrieves a stored item\n"+
          "           clear - clears out all lockers\n"+
          "           list - lists all items\n\n"+
          "                                      - Thank you <Mythos>\n");
  return 1; }
}

exit() {
object lo;
  if(this_player()) /* heh.  added 6.11.01 by verte */
  if(lo = present("locker_ob",this_player())) destruct(lo);
}

