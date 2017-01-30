#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("salt")) {
  move_object(clone_object("/players/pestilence/blue/mob/salt.c"),
        this_object()); }
if (!present("pepper")) {
  move_object(clone_object("/players/pestilence/blue/mob/pepper.c"),
        this_object()); }
if (!present("paprika")) {
  move_object(clone_object("/players/pestilence/blue/mob/paprika.c"),
        this_object()); }
short_desc = "kitchen";
long_desc =
  "    This is the kitchen.  Blue and Steve come here to talk to their friends\n"+
  "and make food.  There is a refrigerator against the west wall with a picture\n"+
  "hanging on it.  There is an island in the middle of the room and a table\n"+
"and chair near by.\n";
set_light(1);

items = ({
  "refrigerator","A big white refrigerator with a picture hanging on it, maybe you could open it",
  "island","A counter in the middle of the room",
  "counter","A counter that consists of a tan formica [tm]",
  "table","A small table where Blue and Steve eat their meals",
  "chair","A small wooden kitchen chair",
  "picture","This is a picture colored by Blue, its hard to tell what it is",
});

dest_dir = ({
  "/players/pestilence/blue/rooms/backyard.c","north",
  "/players/pestilence/blue/rooms/room1.c","south",
});

}
init () {
   ::init() ;
     add_action ("open_refrigerator","open");
     }

open_refrigerator(str) {
if(!id(str)) { notify_fail("Open what?\n");
 return 0; }
  
     write("You see a very empty refrigerator.\n");
     return 1;}
