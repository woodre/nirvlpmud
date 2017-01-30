#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
      if(arg) return;
   set_light(1);

   short_desc = "Hall of Mirrors";
   long_desc =
"   Mirrors line the walls, all at odd angles so that it's hard to tell\n\
what's where.  Every direction looks the same.  The chute that drops\n\
in from high up on the wall and cannot be reached. The shouts of children\n\
echo through the maze like hall.\n";

   items = ({
      "mirrors","They make it look as if there are hundreds of you stretching back\n\
into infinity",
      "chute","That's how you got in, but there's no way to get back up to it\n\
You'll have to find another way out",
      "maze","The reflections within reflections are everywhere",
      "wall","above the mirror is the chute you dropped out of",
      "walls","Though it's impossible to be sure, it looks like there might be an\n\
opening to the west",
   });
}

init(){
    ::init();
    add_action("bump_nose","north");
    add_action("bump_nose","northeast");
    add_action("bump_nose","east");
    add_action("bump_nose","southeast");
    add_action("bump_nose","south");
    add_action("bump_nose","southwest");
    add_action("mover","west");
    add_action("bump_nose","northwest");
    add_action("listening","listen");
}

mover(){
     this_player()->move_player("west#"+AREA+"mirrorbase.c");
     return 1;
}

bump_nose(){
     write("You bump your nose on the glass of a mirror.\n");
     say(TPN + " bumps "+TP->query_possesive()+" nose on a mirror.\n");
     return 1;
}

listening(){
     write("The laughter of many playing children echo from everywhere.\n");
     return 1;
}

realm(){ return "NT"; }
