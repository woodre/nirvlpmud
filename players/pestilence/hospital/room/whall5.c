#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long highway extending to east and ending here.  To the \n"+
  "far east one can see the lobby.  On the north side of the hallway\n"+
  "you can see a door leading to room 109.  And to the south is a room\n"+
  "numbered 110.  This hallway seems to contain rooms for surgeries and\n"+
  "other various medical procedures.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/hospital/room/whall4.c","east",
});
}
init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 109 or 110.\n"); return 1; }
        if(str == "109"){
        write("You leave into hospital room 109.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/109.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "110"){
        write("You leave into hospital rom 110.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/110.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 109"){
         write("You leave into hospital room 109.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/109.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 110"){
        write("You leave into hospital rom 110.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/110.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 109 or 110.\n");
        return 0;
      
}
}

