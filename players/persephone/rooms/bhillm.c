inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int i;
int t;
reset(arg){
 if(!present("ant")) {
  for(t=0;t<4;t++){
   move_object(clone_object("players/persephone/monster/ant"), TOB);
  }
 }
 if(!present("woodpecker")){
  move_object(clone_object("players/persephone/monster/bird"), TOB);
 }
 if(!present("bee")){
  for(i=0;i<3;i++){
   move_object(clone_object("players/persephone/monster/bbee"), TOB);
  }
 }
 if(!arg){
  set_light(1);
  short_desc="Blueberry Hill";
  long_desc="You are on a path halfway up Blueberry Hill. On either side of the path\n" +
            "you see big luscious blueberries growing amongst the majestic looking\n" +
            "willows, also you notice that there seems to be a slight wind here. \n" +
            "The path continues both to the North and South and you think you can\n" +
           "see a small path leading to the west\n"; 
  dest_dir=({"players/persephone/rooms/bhillb","north",
             "players/persephone/rooms/bhillt","south",
  });
 }
}
realm(){ return "NT";}
