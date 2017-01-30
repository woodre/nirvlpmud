#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long hallhway extending from east to west.  To the \n"+
  "far east one can see the nurses station.  On the north side\n"+
  "you can see a recovery room for a mother who has just given\n"+
  "birth, numbered 303.  The same can be seen to the south, with\n"+
  "this room numbered 304.  The walls are covered with a clinical\n"+
  "white paint, while the floors are a dull white tile.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/3whall.c","east",
  "/players/pestilence/hospital/room/3whall3.c","west",
});
}
init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 303 or 304.\n"); return 1; }
        if(str == "303"){
        write("You leave into hospital room 303.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/303.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "304"){
        write("You leave into hospital rom 304.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/304.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 303"){
         write("You leave into hospital room 303.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/303.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 304"){
        write("You leave into hospital rom 304.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/304.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 303 or 304.\n");
        return 0;
      
}
}

