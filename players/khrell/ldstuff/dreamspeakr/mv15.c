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
         "\tThe third story of this palace is quite empty except \n"+
         "for the large pile of rubble.  This appears to be some type \n"+
         "of storage room. The mud covered floor seems sturdy enough \n"+
         "to handle most anything.  Sunbeams shine into the room \n"+
         "from the small window on the front wall. There is a ladder \n"+
         "going down through a hole in the floor.\n"+
         "\n"
;

     items = ({
         "floor","Made from stringers of juniper, covered with mud, juniper \n"+
            "bark and more mud.  It seems to support your weight just fine",
         "mud","A combination of water, sand and dirt was mixed together to \n"+
             "hold the juniper bark and stringers together",
         "sunbeams","Golden sunbeams billow into the room with a great brillance",
         "window","Looking out the window you notice the people of the mesa \n"+
            "moving about their daily chores and activities outside",
         "ladder","Strong looking branches twined together with yucca cordage\n"+
            "leads way to the first and third floors",
         "hole","A small hole in the floor to access the second floor",
         "rubble","A large pile of what appears to be trash.  You wonder why \n"+
            "they dont do something else with it",  
});

dest_dir = ({
    PATH+"mv14.c","down",
});

}
