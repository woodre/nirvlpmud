#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
#define PED "/players/wocket/turtleville/NPC/ped.c"
inherit "/players/wocket/std/tvroom.c";


reset(arg) {

if(!present("board")){
    move_object(clone_object(PATH+"/OBJ/postboard.c"),this_object());
}
if(!present("fred",this_object()))
  move_object(clone_object(PATH+"/NPC/postmaster.c"),this_object());  
if(random(2)==1){
if(!present("ped",this_object()))
  move_object(clone_object(PED),this_object());
 if(random(2)==1){
  move_object(clone_object(PED),this_object());
 }
}
    if(arg) return;
    set_light(1);
    short_desc = HIG+"The Turtleville Post Office"+OFF;
    dest_dir =({
    PATH+"/tspath1.c","east",
    });
   
    long_desc = ""+
                "   The turtleville post office.  Small holes line the right\n"+
                "side of the room, many filled with slips of paper and envelopes.\n"+
                "Each hole has a name engraved underneath it.  There is a note\n"+
                "board along the far wall where people can leave messages.\n";
    items = ({
      "holes","They are small holes with well rounded edges in the right wall",
      "paper","They fill the holes",
      "name","One even says \""+this_player()->query_name()+"\"",
      "envelopes","They fill the holes",
     });
    smells = ({
      "default","The air smells fresh and cheery",
      });
    listens = ({
       "default","You hear the bustle of the workers in the back",
      });
        
}
    


