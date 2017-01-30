#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    The hallway ends here but continues back out to the east.  There\n"+
  "are two rooms off this part of the hallway.  On the north side\n"+
  "you can see a door leading to room 409.  And to the south is a room\n"+
  "numbered 410.  This hallway seems to contain rooms for rehabilitation\n"+
  "and other various medical procedures.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/hospital/room/4whall4.c","east",
});
}
init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 409 or 410.\n"); return 1; }
        if(str == "409"){
        write("You leave into hospital room 409.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/409.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "410"){
        write("You leave into hospital rom 410.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/410.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 409"){
         write("You leave into hospital room 409.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/409.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 410"){
        write("You leave into hospital rom 410.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/410.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 409 or 410.\n");
        return 0;
      
}
}

