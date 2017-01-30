#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
 if(arg) return;

  short_desc = HIG+"The Magus Tower"+NORM;
  long_desc = "   "+
              "  This is a circular room with stairs leading up.  The room itself is\n"+
              "fairly bare with no objects, but many of the walls have very ornate\n"+
              "carvings.  The stairs swirl from the center leading up a small hole in\n"+
              "the ceiling.  Little light enters but enough to see.\n";

  set_light(1);
items = ({
    "carvings","They are of many swirling designs, giving a sense of magic castings",
    "walls","They are bare but have many carvings in them",
    "stairs","They spiral from the center of the room up through the ceiling",
    "ceiling","It is bare expect for a small hole",
    "hole","It is a small hole in the ceiling that allows the stairs through",
     
});
listens = ({
    "You hear soft chanting in the background.\nYou can't find a source",
 
});
smells = ({
    "default","You smell dust and age",
});

   dest_dir = ({
    PATH+"/tville_tower2","up",
    PATH+"/tnpath5.c","out",  
});
}

init(){
  ::init();
  add_action("search","search");
  add_action("push","push");
  add_action("push","press");
}

search(str){
if(!str){
  notify_fail("What would you like to search?\n");
  return 0;
}
if(str != "walls" && str != "carvings"){
  notify_fail("You find nothing of intrest.\n");
  return 0;
}
write("You find a small button hidden amoung the carvings.\n");
return 1;
}

push(str){
if(!str){
  notify_fail("What would you like to push.\n");
  return 0;
}
if(str != "button"){
  notify_fail("That is not here to push.\n");
  return 0;
}
if(!present("mageguildob",this_player())){
  notify_fail("As of now this is closed to all none mages.\n");
  return 0;
}
write("You press the button and slide through a hidden passageway.\n");
this_player()->move_player("through a secret passageway#/players/wocket/mages/rooms/guildhall.c");
return 1;
}
