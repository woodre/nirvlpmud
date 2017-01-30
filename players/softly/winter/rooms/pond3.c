#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Warming Fire";
long_desc ="  A large fire is ablaze in the center of a circle of logs.\n"+
           "They look worn, as if many have sat here to warm themselves.\n"+
           "The path ends.  Downed trees and debris make passage westward\n"+
           "impossible.  The frozen lake surface is north where one might\n"+
           "skate.  A small path to the east seems to pass a shack.\n";

items = ({
  "fire",  "The dancing red and gold of the blazing fire warms the logs\n"+
           "and dances across the surface of the lake",
  "lake",  "The ice is quite thick covering the surface of the solidly\n"+
           "frozen lake. Looking closely there are a few small holes on\n"+
           "the surface",
  "shack", "A small shack has smoke rising above it.  It bears investigating",
  "logs",  "Large logs lie on the ground in a circle around the fire\n"+
           "They appear worn, as if many have sat on them to get warm",
  "circle",  "Large logs lie on the ground in a circle around the fire\n"+
           "They appear worn, as if many have sat on them to get warm",
  "path",  "The narrow lakeside path is very icy",
  "debris","Broken branches and downed trees block further passage",
  "trees", "Remnants of once healthy trees block movement westward",
  "shack", "A small shack has smoke rising above it.  It bears investigating",
  });

dest_dir = ({
  "/players/softly/winter/rooms/pond4.c","north",
  "/players/softly/winter/rooms/pond2.c","east",
  });
}
