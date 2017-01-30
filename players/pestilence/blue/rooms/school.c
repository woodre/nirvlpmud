#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("pig")) {
  move_object(clone_object("/players/pestilence/blue/mob/student1.c"),
        this_object()); }
if (!present("gopher")) {
  move_object(clone_object("/players/pestilence/blue/mob/student2.c"),
        this_object()); }
if (!present("porcupine")) {
  move_object(clone_object("/players/pestilence/blue/mob/student3.c"),
        this_object()); }
short_desc = "School";
long_desc =
  "    This is the school house.  There are desks all around the room and a \n"+
  "blackboard at the front.  The teacher's desk is stacked up high with\n"+
  "a basket full of papers.  There is a play area with lots of toys in the\n"+
 "back corner of the room.\n";
set_light(1);

items = ({
  "desks","Quite a few students desks made of wood and are very small",
  "desk","A student desk made of wood and is very small",
  "teacher's desk","A teacher's desk made of oak and is very large compared to the other desks",
  "blackboard","A long blackboard which one can write on with chalk, covers the west wall",
  "area","A small area in the northeast corner of the school, where there is a designated playing area",
  "play area","A small area in the northeast corner of the school, where there is a designated playing area",
 "corner","A small area in the northeast corner of the school, where there is a designated playing area",
  "basket","A brown wicker basket full of papers",
  "papers","White papers with words written on them",
  "words","You can't quite make out what they say but you see a large F at the top of the paper",
  "toys","Toy trucks, and toy cars all over the place",
});

dest_dir = ({
  "/players/pestilence/blue/rooms/bplace.c","back",
});

}
