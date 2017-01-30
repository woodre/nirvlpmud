#include "/players/mythos/closed/guild/def.h"
#include "/sys/ansi.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
    set_light(0);
    short_desc = HIK+"Cave Entrance "+NORM;
    long_desc = "You are at the entrance to a small cave.  From the cave\n"+
      "you sense a dark forbodeing.  Deep in your soul you feel\n"+
      "that to even attempt to enter is a "+BOLD+"very"+NORM+" bad idea.\n";
    items = ({
      "north","You can return to the forest",
      "enter",HIK+"Darkness"+NORM+"....",
    });
    dest_dir = ({
      "/players/mythos/closed/guild/forest/rooms/hunter2.c", "north",
  /*  "/players/mythos/closed/guild/forest/rooms/cave2.c","enter", */
    });
  } 
}

realm() { return "NT";}

