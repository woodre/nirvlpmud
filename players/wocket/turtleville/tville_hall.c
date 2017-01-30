#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
#define PED "/players/wocket/turtleville/NPC/ped.c"
inherit "/players/wocket/std/tvroom.c";


reset(arg) {
  move_object(clone_object(PATH+"/NPC/mayor.c"),this_object());  
if(random(2)==1){
if(!present("ped",this_object()))
  move_object(clone_object(PED),this_object());
 if(random(2)==1){
  move_object(clone_object(PED),this_object());
 }
}    if(arg) return;
    set_light(1);
    short_desc = HIG+"The Turtleville City Hall"+OFF;
    dest_dir =({
    PATH+"/tnpath5.c","south",
    });
   
    long_desc = ""+
                "    This grand hall is immense.  A domed ceiling encompasses everything\n"+
                "as huge windows let in rays of brilliant light.  The carpet is a lush\n"+
                "red that complements the chairs that rest in the corner.  Turtillian\n"+
                "banners hang from the ceiling are ruffled by the breeze from the open door.\n"+
                "The entire sight would make anyone stand in awe.\n";
      
items = ({
      "roof","It is domed and looks like it was crafted from turtle shells",
      "windows","They are huge as they let light shine through",
      "carpet","It is a very thick, lush, red carpet",
      "banners","They hang from the ceiling telling stories and history of the Turtleville past",
      "ceiling","It is domed and looks like it was crafted from turtle shells",
      "chairs","They are carved from a dark wood and look comfortable",
      "corners","They embraces comfortable chairs and are filled with light from the windows",
      "door","A large, white, double door that rests open"   
 });
    smells = ({
      "default","The air smells fresh and cheery",
      });
    listens = ({
       "default","All is quiet as you stand in awe",
      });
        
}
    


