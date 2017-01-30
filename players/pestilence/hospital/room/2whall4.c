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
  "/players/pestilence/hospital/room/2whall3.c","east",
  "/players/pestilence/hospital/room/2whall5.c","west",
});
}
init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 207 or 208.\n"); return 1; }
        if(str == "207"){
        write("You leave into hospital room 207.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/207.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "208"){
        write("You leave into hospital rom 208.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/208.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 207"){
         write("You leave into hospital room 207.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/207.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 208"){
        write("You leave into hospital rom 208.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/208.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 207 or 208.\n");
        return 0;
      
}
}

