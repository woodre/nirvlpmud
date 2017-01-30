#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/mesa/"
inherit "room/room";

reset(arg) {
int i;
  i = random(2);
    if(i == 1){
    for(i=0 ; i < random(2)+1 ; i++){
    move_object(clone_object("/players/dreamspeakr/mesa/NPC/anasazi.c"),this_object());
    }
}

if(arg)return;
     set_light(1);

     short_desc = HIG+"Cliff Palace"+NORM;
     long_desc =
         "\n"+
         "\tThe second story of this section of the palace \n"+
         "appears to be the sleeping quarters for the small children.  \n"+
         "Small blankets are piled upon stacks of grass.  There is a \n"+
         "small handmade doll laying on one of the beds.  The mud \n"+
         "covered floor seems sturdy enough to handle most anything.  \n"+
         "Sunbeams shine through the small window into the room on \n"+
         "the front wall. There is a ladder going up and down through\n"+
         "holes in the ceiling and floor.\n"+
         "\n"
;

items = ({
    "floor","Made from stringers of juniper, covered with mud, juniper \n"+
       "bark and more mud.  It seems to support your weight just fine",
    "blankets","Made of twined turkey feathers wrapped around yucca cordage,\n"+
       "many hours must have gone into making these colorful blankets",
    "grass","Chopped Cheatgrass placed in small piles to form a makeshift \n"+
        "bed of sorts",
    "mud","A combination of water, sand and dirt was mixed together to \n"+
        "hold the juniper bark and stringers together",
    "sunbeams","Golden sunbeams billow into the room with a great brillance",
    "window","Looking out the window you notice the people of the mesa \n"+
       "moving about their daily chores and activities outside",
    "ladder","Strong looking branches twined together with yucca cordage\n"+
       "leads way to the first and third floors",
    "ceiling","Like the floor you stand on, its appearance is quite strong",
    "holes","Small holes in the ceiling above you and the floor to access \n"+
       "the first and third floors",
    "doll","Laying on the makeshift pillow of grass, she smiles up at you \n"+
       "with a permanent hand painted smile\n",
});

dest_dir = ({
    PATH+"mv12.c","up",
    PATH+"mv10.c","down",
});

}
