#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(6);
    short_desc = "River of Deacrom ";
    long_desc =
    "You see a raging river flowing past you.\n"+
    "Deep within its waters something lurks.\n"+
    "Upstream you notice something odd, and on\n"+
    "the other side you see something shining.\n";
  items = ({
    "cross","You may reach other bank",
    "back","Leads back to the hill",
    "up","Leads upstream",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/task/hills/hills3.c", "back",
    "/players/mythos/closed/guild/task/hills/river2.c","cross",
    "/players/mythos/closed/guild/task/hills/upstream.c","up",
  });
} }

realm() { return "NT"; }

init() {
 ::init();
 add_action("dive","dive");
}

dive() {
  write("You close your eyes for a brief moment\n"+
       "and dive into the raging river.\n");
  tp->move_player("into the river#players/mythos/closed/guild/task/hills/under.c");
return 1;}
       
       
