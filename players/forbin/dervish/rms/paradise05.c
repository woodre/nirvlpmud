/* 
 * Forbin
 * Created:   2003.08.29
 * Last edit: 2003.09.25 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

reset(arg) {
  if(arg) return;
  short_desc = GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM;
  long_desc = 
    "  A path runs from the west before forking, one trail heading\n"+
    "north, the other east.  The forest is thick and impenetrable, yet\n"+
    "has not overgrown to overpath the pathway.  Far to the northeast,\n"+
    "a mountain towers over the horizon.  A strange smell permeates
    "the area.\n";
  add_item(({"path","trail","pathway"}),
    "The path goes in three directions - north, east, and southwest");
  add_item("forest",
    "Tall trees thick with vines grow on each side of the path");
  add_item(({"vine","vines"}),
    "The trees are choked with thick vines");
  add_item("trees",
    "Several different species of trees grow here.  One near the path\n"+
    "bears some sort of engraving or carving");
  add_item("carving",
    "The carving shows a swirling whirlwind wraped around a snowflake,\n"+
    "While a crude arrow points to the northeast.  It strkes you as\n"+
    "odd.  Beneath the carving is notched a scribbled name");
  add_item("name",
    "The scribbled name is so weathered you are unable to make it out");
  add_item("mountain",
    "Snow capped and cloaked in fog, it towers high over the north-\n"+
    "western forest");
  add_smell("main",
    "A strange scent hangs in the air here.  A sickly sweet smell,\n"+
    "like the burning of wood, you could track its source.\n");
  add_smell("smell",
    "You take in a strange, sickly sweet smell like, almost like\n"+
    "the burning of wood.  It seems to be coming from the forest.\n"+
    "Perhaps you could track it to its source.\n");
  add_smell("scent",
    "You take in a strange, sickly sweet smell like, almost like\n"+
     "the burning of wood.  It seems to be coming from the forest.\n"+
      "Perhaps you could track it to its source.\n");
  set_chance(random(5));
    add_msg("A strange smell floats through the air.");
  set_light(1);
  add_exit(ROOT+"rms/paradise06.c","north");
  add_exit(ROOT+"rms/paradise07.c","east");
  add_exit(ROOT+"rms/paradise04.c","southwest");
  add_exit_msg("north", "You head off into the jungle.\n",
		                "heads off into the jungle.\n");
  add_exit_msg("east", "You head off into the jungle.\n",
		               "heads off into the jungle.\n");
  add_exit_msg("southwest", "You head off into the jungle.\n",
		                    "heads off into the jungle.\n");
}

short() { return GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM; }

init() {
  ::init();
  add_action("cmd_track","track");
}

cmd_track(string str) {
  if(!str || (str != "scent" && str != "smell")) { 
    notify_fail("Track what?\n"); 
      return 0; 
  }
  write("You smell carefully to judge its direction, then head off to find\n"+
        "the source of the strange smell.\n");
  say(this_player()->query_name()+" takes a sniff of air, then heads into the woods.\n");
  move_object(this_player(),ROOT+"rms/outsidehut.c");
  command("look",this_player());
  say(this_player()->query_name()+" arrives.\n");
    return 1; 
}
