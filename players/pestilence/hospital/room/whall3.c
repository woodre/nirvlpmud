#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long highway extending from east to west.  To the \n"+
  "far east one can see the lobby.  On the north side of the hallway\n"+
  "you can see a door leading to the stairway.    Farther to the\n"+
  "west there is the beginning  of the west wing of the hospital.\n"+
  "The west wing contains the surgery,  and other rooms for\n"+
  "various medical procedures that are done here.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/whall2.c","east",
  "/players/pestilence/hospital/room/whall4.c","west",
});
}
init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 105 or 106.\n"); return 1; }
        if(str == "105"){
        write("You leave into hospital room 105.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/105.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "106"){
        write("You leave into hospital rom 106.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/106.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 105"){
         write("You leave into hospital room 105.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/105.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 106"){
        write("You leave into hospital rom 106.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/106.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 105 or 106.\n");
        return 0;
      
}
}

