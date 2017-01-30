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
        "\tThe second story of this palace is quite empty except \n"+
         "for the large blankets laying on tall mounds of piled up \n"+
         "grass.  The mud covered floor seems sturdy enough to handle \n"+
         "most anything.  Sunbeams shine into the room from the small\n"+
         "window on the front wall.  There is a ladder going up and\n"+
         "down through holes in the ceiling and floor.\n";

     items = ({
         "floor","Made from stringers of juniper, covered with mud, juniper \n"+
            "bark and more mud.  It seems to support your weight just fine",
         "blankets","Made of twined turkey feathers wrapped around yucca cordage,\n"+
            "many hours must have gone into making these colorful blankets",
         "grass","Chopped Cheatgrass placed in large piles to form a makeshift \n"+
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
});

dest_dir = ({
    PATH+"mv9.c","up",
    PATH+"mv7.c","down",
});

}
