#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long highway extending to east and ending here.  To the \n"+
  "far east one can see the lobby.  On the north side of the hallway\n"+
  "you can see a door leading to room 209.  And to the south is a room\n"+
  "numbered 210.  This hallway seems to contain rooms for surgeries and\n"+
  "other various medical procedures.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/hospital/room/2whall4.c","east",
});
}
init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 209 or 210.\n"); return 1; }
        if(str == "209"){
        write("You leave into hospital room 209.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/209.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "210"){
        write("You leave into hospital rom 210.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/210.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 209"){
         write("You leave into hospital room 209.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/209.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 210"){
        write("You leave into hospital rom 210.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/210.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 209 or 210.\n");
        return 0;
      
}
}

