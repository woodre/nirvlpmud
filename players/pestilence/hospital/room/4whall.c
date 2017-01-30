#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long highway extending to the west.  The hallway ends here\n"+
  "in the east direction.  On the north side of the hallway\n"+
  "you can see a door leading to the stairway.    Farther to the\n"+
  "west there is the beginning of the west wing of the hospital.\n"+
  "The west wing contains the insanity ward, and several rooms\n"+
  "for patient living, and for various rehabilitation purposes.\n";
set_light(4);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/4whall2.c","west",
  "/players/pestilence/hospital/room/wstairway4.c","north",
});
}

init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 401 or 402.\n"); return 1; }
        if(str == "401"){
        write("You leave into hospital room 401.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/401.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "402"){
        write("You leave into hospital rom 402.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/402.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 404"){
         write("You leave into hospital room 404.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/404.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 402"){
        write("You leave into hospital rom 402.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/402.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 404 or 402.\n");
        return 0;
      
}
}

