#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("cannibal")) {
  move_object(clone_object("/players/pestilence/Cahara/mob/cannibal.c"),
        this_object()); }

short_desc = ""+YEL+"Cahara's Cave"+NORM+"";
long_desc =
  "    A small cavern that seems to end right here.  The way back\n"+
  "out seems to have closed almost shut with the rocks falling as\n"+
  "you entered.  The walls are close together, covered with\n"+
  "moisture.  The walls are solid rock, and are very dense which\n"+
  "makes them unbreakable.  The floor is covered with water that is\n"+
  "two feet deep in the deeper parts.\n";
set_light(1);

items = ({
"walls","The walls are solid rock, with a small crack you could 'enter'",
"water","Water covering parts of the floor",
"rock","Solid gray rock seems to be everywhere",
"floor","The floor is covered with water",
});

dest_dir = ({
  "/players/pestilence/Cahara/room/nepath.c","out",
  "/players/pestilence/Cahara/room/cave2.c","north",
});

}
init() {
  ::init();
add_action("enter","enter");
}
enter(arg) {
   if(arg) { notify_fail("Just enter will work.\n");
       return 0;}

  if (this_player()->query_guild_name() == "Dark Order") {
     write("You enter the hole.\n");
     TP->move_player("into the crack#/players/pestilence/closed/dark/room/hall.c");
     return 1;}
}
