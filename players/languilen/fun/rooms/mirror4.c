#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
   int x;
      if(arg) return;
   set_light(1);
   if( !present("child") ){
      x = random(3)+random(3);
      while(x){
            move_object(clone_object(MON+"child.c"),this_object());
            --x;
      }
   }
   short_desc = "Hall of Mirrors";
   long_desc =
"   Mirrors line the walls, all at odd angles so that it's hard to tell\n\
what's where.  Every direction looks the same.  The shouts of children\n\
echo through the maze like hall.\n";

   items = ({
      "mirrors","It makes the top and bottom of everything look small and the\n\
middle huge",
      "walls","Though it's impossible to be sure, it looks like there might be an\n\
opening to the north",
   });
}

init(){
    ::init();
    add_action("bump_nose","north");
    add_action("mover","northeast");
    add_action("movee","east");
    add_action("bump_nose","southeast");
    add_action("bump_nose","south");
    add_action("bump_nose","southwest");
    add_action("bump_nose","west");
    add_action("bump_nose","northwest");
    add_action("listen","listen");
}

mover(){
     this_player()->move_player("out#"+AREA+"mirrorbase.c");
     return 1;
}

movee(){
     this_player()->move_player("out#"+AREA+"mirror5.c");
     return 1;
}

bump_nose(){
     write("You bump your nose on the glass of a mirror.\n");
     say(TPN + " bumps "+TP->query_possesive()+" nose on a mirror.\n");
     return 1;
}
listen(){
     write("You can hear distant footfalls and indestiguishable exclamations echo\n\
from somewhere to the north.\n");
     say(TPN+" pauses a moment, listening intently.\n");
     return 1;
}

realm(){ return "NT"; }
