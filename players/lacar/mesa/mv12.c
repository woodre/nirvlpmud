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
      "\tThe third story in this section of the palace appears \n"+
         "to be the sleeping quarters for the teenage warriors.  \n"+
         "Arrowheads are scattered around the floor in various spots.\n"+
         "Small bows hang from the walls in an orderly fashion.  Large\n"+
         "blankets laying on tall mounds of piled up grass.  The mud \n"+
         "covered floor seems sturdy enough to handle most anything.  \n"+
         "Sunbeams shine into the room from the small window on the \n"+
         "front wall. There is a ladder going down through a hole in \n"+
         "the floor.\n";

    items = ({
         "bows","Made from a strong hardwood, curved to just the right angle.  \n"+
         "Beautiful feathers hang from the tips for decoration",
         "arrowheads","Chipped from the cliffside rocks, formed into points.  You \n"+
            "wouldnt want one of these piercing thru your heart",
         "walls","Dark black stains cover these walls made from almost perfect\n"+
             "square blocks",
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
         "hole","A small hole in the floor to access the second floor",
});

dest_dir = ({
    PATH+"mv11.c","down",
});

}
