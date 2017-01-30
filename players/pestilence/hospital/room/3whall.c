#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long hallway extending to west.  To the east there is the  \n"+
  " nurse's station.  On the north side of the hallway there is a\n"+ 
  "door leading to the stairway.  There are two doors here, where\n"+
  "they keep the newborn babies, to be cared for while the mothers\n"+
  "rest.  And the other room is the viewing room, where visitors can\n"+
  "view the newborns.  Further down the hallway is the rest of the\n"+
  "maternity ward.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/3whall2.c","west",
  "/players/pestilence/hospital/room/wstairway3.c","north",
  "/players/pestilence/hospital/room/lobby3.c","east",
});
}

init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 301 or 302.\n"); return 1; }
        if(str == "301"){
        write("You leave into hospital room 301.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/301.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "302"){
        write("You leave into hospital rom 302.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/302.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 301"){
         write("You leave into hospital room 301.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/301.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 302"){
        write("You leave into hospital rom 302.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/302.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 301 or 302.\n");
        return 0;
      
}
}

