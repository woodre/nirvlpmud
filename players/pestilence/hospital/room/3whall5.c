#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    A long hallway extending to east and ending here.  To the \n"+
  "far east one can see the nurses station.  On the north side of the\n"+
  "hallway you can see a door leading to room 309.  And to the south is\n"+
  "a room numbered 310.  These rooms primary function is for bringing\n"+
  "new babies into the world.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/hospital/room/3whall4.c","east",
});
}
init() {
  ::init();
add_action("enter","enter");
}

enter(str){
        if(!str){ write("You can only enter rooms 309 or 310.\n"); return 1; }
        if(str == "309"){
        write("You leave into hospital room 309.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/309.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "310"){
        write("You leave into hospital rom 310.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/310.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "room 309"){
         write("You leave into hospital room 309.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/309.c"); 
        command("look",this_player());
        return 1;
          }
        else if(str == "room 310"){
        write("You leave into hospital rom 310.\n");
        move_object(this_player(), "/players/pestilence/hospital/room/310.c");
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter rooms 309 or 310.\n");
        return 0;
      
}
}

