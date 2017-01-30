#include "/players/softly/closed/define.h"
#include "/players/softly/point/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(!present("bird")) 
  move_object(clone_object("players/softly/point/mobs/bird.c"),this_object());
  if(arg) return;
  set_chance(3);
  add_msg("The waves crash against the rocks...");
  add_msg("The sound of the sea drowns out all other noise ...");
  add_msg("The mist encloses you, clinging to your flesh....");
  add_msg("The jagged rocks rise up before you....");
  add_listen("main","You hear the sound of the sea crashing on the rocks.");

set_light(1);
short_desc=(RED + "R" + NORM + "ocky " + RED + "P" + NORM + "oint");
long_desc ="  Footing is treacherous on the large slick boulders that\n"+
           "are stacked to create the jetty.  The enshrouding mist is\n"+
           "broken only by the crashing surf.\n";

items = ({
  "boulders", "The grey black boulders are covered with algae and very wet",
  "surf","The surf smashes against the rocks and hurls fingers\n"+
        "of foam and water toward you",
  "mist","The air is white with mist, which hangs heavily over\n"+
         "the jetty and the surface of the sea.  It is warm and\n"+
         "dense, surrounding everything like a cloak",
  "jetty","The broad jetty is composed entirely of huge boulders\n"+
          "stacked to create a barrier against the sea.  The top\n"+
          "is very broad, flat, and very wet",

  });
}

init()  {
 ::init();
add_action("west","west");
add_action("east","east");

}
west()  {
write("You slowly climb over the large slippery rocks.\n");
say(this_player()->query_name()+" moves west across the jetty.\n");
call_other(this_player(),"move_player","west#/players/softly/point/rooms/for16.c");
  return 1;
}

east() {
write("Careful of your footing, you make your way east across the jetty.\n");
say(this_player()->query_name()+" moves east across the jetty.\n");
call_other(this_player(),"move_player","east#/players/softly/point/rooms/pt2.c");
  return 1;
}
