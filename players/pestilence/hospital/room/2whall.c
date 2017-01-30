#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long hallway extending to the west.  To the \n"+
  "far east is the wall where the future wing could be added\n"+
  "On the north side of the hallway you can see a door leading\n"+
  "to the stairway.  There are two other doors, numbered 201\n"+
  "and 202 which appear as if they may be entered. Farther to the\n"+
  "west there is the beginning of the west wing of the hospital.\n"+
  "The west wing contains the patient rooms.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/2whall2.c","west",
  "/players/pestilence/hospital/room/wstairway2.c","north",
});
}

init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 201 or 202.\n"); return 1; }
        if(str == "201"){
        write("You leave into hospital room 201.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/201.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "202"){
        write("You leave into hospital rom 202.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/202.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 201"){
         write("You leave into hospital room 201.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/201.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 202"){
        write("You leave into hospital rom 202.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/202.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 201 or 202.\n");
        return 0;
      
}
}

