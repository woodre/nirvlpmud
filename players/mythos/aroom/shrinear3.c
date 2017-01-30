#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/prac/mess.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Shrine Garden (east)";
    long_desc = GRN+
  "\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"+
    "\t^  ^^^    ^^^    ^     ^^^   ^^^   ^\n"+
    "\t^  ^  ^   ^     ^ ^    ^     ^     ^\n"+NORM+GRN+
    "\t^  ^^^    ^^^  ^^^^^   ^     ^^^   ^\n"+
    "\t^  ^      ^    ^   ^   ^     ^     ^\n"+
    "\t^  ^      ^^^  ^   ^   ^^^   ^^^   ^\n"+
    "\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n"+NORM+
    "\tYou have entered the east garden of \n"+
    "\tthe shrine.  Rest and be welcome\n";
  items = ({
    "west","You can see the center of the Shrine",
  });

  dest_dir = ({
    "/players/mythos/aroom/shrinear5.c", "west",
    "/players/vertebraker/guilds/samurai/room/1","east",
  });
} }

init() { 
  ::init();
  if(pp) {
    add_action("chamber","chamber");
    add_action("infuse","infuse");
  }
}

chamber() {
  tp->move_player("chamber#players/mythos/enterance.c");
return 1; }

infuse() {
  if(pp->query_sacrifice() < 1000) { write("You can not infuse.\n"); return 1;}
  tp->add_spell_point(1000);
  write("You infuse yourself with fae.\n"+
        "You feel the darkness is hungry for more sacrifice.\n");
  pp->add_sacrifice(-500-random(10000));
return 1; }

query_no_fight() { return 1; }

