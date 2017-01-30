#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long highway extending from east to west.  To the \n"+
  "far east one can see the nurses station.  On the north side\n"+ 
  "there is the birthing room 307 and 308 is on the south side.\n"+
  "It's very noisey here, the room is filled with echoes of screaming.\n"+
  "women, in the middle of giving birth.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/3whall3.c","east",
  "/players/pestilence/hospital/room/3whall5.c","west",
});
}
init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 307 or 308.\n"); return 1; }
        if(str == "307"){
        write("You leave into hospital room 307.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/307.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "308"){
        write("You leave into hospital rom 308.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/308.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 307"){
         write("You leave into hospital room 307.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/307.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 308"){
        write("You leave into hospital rom 308.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/308.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 307 or 308.\n");
        return 0;
      
}
}

