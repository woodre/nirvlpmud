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
      x = random(3)+3;
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
      "mirrors","The mirror warps things so that the top and bottom look big and\n\
the middle thin",
   });
}

init(){
    ::init();
    add_action("moven","north");
    add_action("bump_nose","northeast");
    add_action("movee","east");
    add_action("mover","southeast");
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
moven(){
    if(!TP){ return; }
    if(TP->query_phys_at(3) < 120){
       write("The suction from the tube above draws you upward...\nYou have moved.\n\n");
       if(testtank()){
          TP->move_player("up#"+AREA+"tank.c");
          return 1;
       }
       TP->move_player("up#"+AREA+"intank.c");
       return 1;
    }
    write("You are so heavy you fall through a hidden trap door...\n\n");
    say(TPN + " falls through the trapdoor.\n");
    if(testtank()){
       TP->move_player("down#"+AREA+"tank.c");
       return 1;
    }
    TP->move_player("down#"+AREA+"intank.c");
    return 1;
}

movee(){
     this_player()->move_player("out#"+AREA+"mirror2.c");
     return 1;
}

bump_nose(){
     write("You bump your nose on the glass of a mirror.\n");
     say(TPN + " bumps "+TP->query_possesive()+" nose on a mirror.\n");
     return 1;
}
testtank(){
     if(!find_object(AREA+"intank.c")){ return 0; }
     if( find_object(AREA+"intank.c")->query_dunkee() ){ return 1; }
     return 0;
}
listen(){
     write("Echos bounce around aimlessly, you can't tell exactly where\n\
from but they must be from somewhere nearby.\n");
     say(TPN+" pauses a moment, listening intently.\n");
     return 1;
}


realm(){ return "NT"; }
