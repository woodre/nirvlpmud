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
      x = random(3)+4;
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
      "mirrors","They make it look as if there are hundreds of you stretching back\n\
into infinity",
      "walls","Though it's impossible to be sure, it looks like there might be\n\
several openings in different directions",
   });
}

init(){
    ::init();
    add_action("mover","north");
    add_action("mover","northeast");
    add_action("mover","east");
    add_action("mover","southeast");
    add_action("mover","south");
    add_action("mover","southwest");
    add_action("mover","west");
    add_action("mover","northwest");
    add_action("listen","listen");
}

mover(){
     int xdir;
     xdir = random(12);
     if(xdir > 1) xdir = xdir/2;
     this_player()->move_player("leaves#"+AREA+"mirror"+xdir+".c");
     return 1;
}

listen(){
     write("You can hear distant footfalls and indestiguishable exclamations echo\n\
from somewhere nearby.\n");
     say(TPN+" pauses a moment, listening intently.\n");
     return 1;
}

realm(){ return "NT"; }
