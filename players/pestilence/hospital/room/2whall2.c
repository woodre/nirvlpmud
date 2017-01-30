#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long highway extending from east to west.  To the \n"+
  "far east one can see the lobby. To the north and south sides\n"+
  "you can see a doors leading to normal patient rooms.  This\n"+
  "hallway appears to be well worn and in need of replacing.\n"+
  "One can tell many patients and visitors have walked through\n"+
  "these hallways.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/2whall.c","east",
  "/players/pestilence/hospital/room/2whall3.c","west",
});
}
init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 203 or 204.\n"); return 1; }
        if(str == "203"){
        write("You leave into hospital room 203.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/203.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "204"){
        write("You leave into hospital rom 204.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/204.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 203"){
         write("You leave into hospital room 203.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/203.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 204"){
        write("You leave into hospital rom 204.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/204.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 203 or 204.\n");
        return 0;
      
}
}

