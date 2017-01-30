/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   12/18/00          */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"     /*area header */

inherit "room/room";
int x;

reset(arg) {
  x = 1;
  if(!arg) {

object monster;

set_light(-1);

short_desc = "The Back Room";
long_desc =
  "  The Back Room\n\
This is a small, featureless "+BLK+"black"+NORM+" room with no windows or \
doors. \nThe walls and floor are pitch "+BLK+"black"+NORM+" and hidden in \
"+BLK+"darkness"+NORM+". \nHow do you get \'out\'? \nWhy are you here? \nWhat \
is this room used for? \nThis room creates more questions than it answers.\n";

items = ({
  "room",
  "All you see is "+BLK+"darkness"+NORM,
  "walls",
  "All you see is "+BLK+"darkness"+NORM,
  "darkness",
  "All you see is "+BLK+"darkness"+NORM,
  "window",
  "You cannot see any openings to the outside world",
  "windows",
  "You cannot see any openings to the outside world",
  "floor",
  "All you see is "+BLK+"darkness"+NORM,
  "grate",
  "You have found a small "+HIR+"rusted"+NORM+" grate",
  "door",
  "You cannot see any openings to the outside world",
  "doors",
  "You cannot see any openings to the outside world"
});

dest_dir = ({
  });

  }
}

init() {
  ::init();
  add_action("search_me","search");
  add_action("move_out","out");
  add_action("open_grate","open");
  add_action("move_down","descend");
}

move_out() {
  write("You find a way out....\n \n");
  TP->move_player("out#"+SPROOM+"mdmshop.c");
  return 1;
}

open_grate() {
    write("You pry up the little grate and discover that you can \'descend\' a ladder there.\n");
    x = 1;
    return 1;
}

move_down() {
    if(x) {
    TP->move_player("descends into the darkness#"+SPROOM+"shaft1.c");
    write("The grate slides back into place.\n");
    say("The grate slides back into place.\n");
    x = 0;
    return 1;
    }
    write("There seems to be a grate between you and the ladder.\n");
    return 1;
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else switch(str) {
    case "room": write("You find yourself.\n"); break;
    case "walls": write("Your fingers find a way \'out\' of the bleak \
darkness.\n"); break;
    case "floor": write("You find a small grate that is "+HIR+"rusted"+NORM+" \
shut.\n"); break;
    case "grate": write("Perhaps you could \'open\' the grate.\n"); break;
    default: write("You have no idea how to search the "+str+".\n"); break;
  }
  return 1;
}
