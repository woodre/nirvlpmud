#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long highway extending from east to west.  There \n"+
  "are doors on the north and south side of the hallway.  This\n"+
  "part of the hospital where they keep the mentally insane along\n"+
  "with a few criminally insane patients.  The walls are dirty,\n"+
  "as are the floors.  It seems that the janitorial staff like to\n"+
  "avoid this part of the hospital.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/4whall2.c","east",
  "/players/pestilence/hospital/room/4whall4.c","west",
});
}
init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 405 or 406.\n"); return 1; }
        if(str == "405"){
        write("You leave into hospital room 405.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/405.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "406"){
        write("You leave into hospital rom 406.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/406.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 405"){
         write("You leave into hospital room 405.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/405.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 406"){
        write("You leave into hospital rom 406.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/406.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 405 or 406.\n");
        return 0;
      
}
}

