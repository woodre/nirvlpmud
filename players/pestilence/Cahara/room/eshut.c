#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;


if (!present("cannibal")) {
  move_object(clone_object("/players/pestilence/Cahara/mob/cannibal.c"),
        this_object()); }

short_desc = ""+YEL+"Cahara Island Hut"+NORM+"";
long_desc =
  "    A small room in the southern part of the hut.  This room is used for storing\n"+
  "excess food.  There are a few slaughtered animals carcasses leaning against the \n"+
  "east wall.  There is a small bowl near the west wall contain a large amount of\n"+
  "liquid substance.  There are several unrecongizable animal skeletons lying in the.\n"+
  "middle of the room\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/ehut.c","north",
});

}
