#include "/players/mythos/closed/ansi.h"
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!present("limo")) {
    move_object(clone_object("/players/mythos/mmon/taxi.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Narita Airport>> ";
    long_desc =
    RED+"              Narita Airport\n"+NORM+
        "\nYou are in a large airport where people are coming\n"+
        "and going, bustling to and fro.  You can go anywhere\n"+
        "from here.\n";
  items = ({
    "juliana","The hottest dance club around",
    "tokyo","The center of everyting",
    "ginza","The place where the shopping is done",
    "akihabara","The world of electronics",
    "BGC","The neotokyo of saber's",
    "portal","Back to the Chamber of realms",
  });

  dest_dir = ({
    "/players/mythos/mroom/juliana.c","juliana",
    "/players/mythos/mroom/tokyo.c","tokyo",
    "/players/mythos/mroom/ginza.c","ginza",
    "/players/mythos/mroom/akihabara.c","akihabara",
    "/players/saber/tower/bgc/bg8.c","BGC",
    "/players/mythos/entrance.c", "portal",
  });
} }

init() {
 ::init();
 if(random(50) == 0) {
 move_object(clone_object("/players/mythos/mmisc/snipe.c"),this_player()); }
}
