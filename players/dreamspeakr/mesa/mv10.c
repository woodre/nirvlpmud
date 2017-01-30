inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/mesa/"

reset(arg) {
int i;
  i = random(2);
    if(i == 1){
    for(i=0 ; i < random(2)+1 ; i++){
    move_object(clone_object("/players/dreamspeakr/mesa/NPC/anasazi.c"),this_object());
    }
}

if(arg) return;

     set_light(1);

     short_desc = HIG+"Cliff Palace"+NORM;
     long_desc =
         "\n"+
         "\tSunshine floods into the room from the door and \n"+
         "small window.  The floors appear quite messy, bowls and \n"+
         "baskets lay all about.  It appears that a large feast \n"+
         "has just ended.  The floors are covered with small hand \n"+
         "woven blankets in a circle around what appears to be a \n"+
         "fire pit.  There is a small ladder going up into a hole \n"+
         "in the ceiling.\n"+
         "\n"
;

items = ({
    "sunshine","It blinds you as you gaze at it.  It takes a few moments \n"+
       "for your eyes to adjust back",
    "door","Careful work must have gone into the construction of the \n"+
       "door as it is almost perfectly square",
    "window","Gazing out the window you notice small children outside \n"+
       "playing some kind with small rocks",
    "floors","Natural sandstone floors from the alcove in which this \n"+
       "home was built",
    "blankets","Made of twined turkey feathers wrapped around yucca cordage,\n"+
       "many hours must have gone into making these colorful blankets",
    "bowls","Still filled with the remnents of the feast.  You feel a pang \n"+
       "of hunger as you look at all the leftover food",
    "ladder","Strong looking branches twined together with yucca cordage\n"+
       "leads way to the second floor",
    "hole","A small hole in the ceiling above you cut out to access the \n"+
       "second floor",
    "pit","Small bricks lay in a circle on the floor to keep the fire \n"+
       "from spreading",
    "fire","Still smoldering from the fire that recently went out",
    "baskets","Piled high with fresh fruits and nuts",
    "ceiling","Stringers of juniper jut out from the mud covered ceiling. \n"+
        "You hope its strong enough to hold those who might be above you",
});

dest_dir = ({
    PATH+"mv11.c","up",
    PATH+"mv6.c","leave",
});

}
