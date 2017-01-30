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
move_object(clone_object("/players/dreamspeakr/mesa/NPC/chief.c"), this_object());

if(arg)return;
     set_light(1);

     short_desc = HIG+"Cliff Palace"+NORM;
     long_desc =
         "\tThe third story of this palace is very empty except \n"+
         "for the large blanket laying on a tall mound of piled up \n"+
         "grass on the floor.  This room appears to be the only \n"+
         "private bedroom in the palace.  Sunbeams shine into the\n"+
         "room from the small window on the front wall.  There is\n"+
         "a ladder going through a hole in the floor.\n";

     items = ({
         "floor","Made from stringers of juniper, covered with mud, juniper \n"+
            "bark and more mud.  It seems to support your weight just fine",
         "blanket","Made of twined turkey feathers wrapped around yucca cordage,\n"+
            "many hours must have gone into making this colorful blanket",
         "grass","Chopped Cheatgrass placed in a large pile to form a makeshift \n"+
            "bed of sorts",
         "mud","A combination of water, sand and dirt was mixed together to \n"+
            "hold the juniper bark and stringers together",
         "sunbeams","Golden sunbeams billow into the room with a great brillance",
         "window","Looking out the window you notice the people of the mesa \n"+
            "moving about their daily chores and activities outside",
         "ladder","Strong looking branches twined together with yucca cordage\n"+
            "leads way to the first and third floors",
         "hole","A Small hole in the floor to access the second floor",
         "bedroom","This must be the head of the tribes bedroom",
});

dest_dir = ({
    PATH+"mv8.c","down",
});

}
