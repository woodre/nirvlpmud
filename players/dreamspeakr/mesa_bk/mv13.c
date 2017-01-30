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
         "\tSunshine floods into the room from the door and \n"+
         "small window.  A small table with chairs, holds baskets \n"+
         "and bowls neatly arranged awaiting to be filled with food. \n"+
         "There is a small ladder going up into a hole in the ceiling.\n"+
         "\n"
;

     items = ({
         "room","Neat and tidy, the women here must work hard at keeping it\n"+
             "so nice and clean",
         "sunshine","It blinds you as you gaze at it.  It takes a few moments \n"+
             "for your eyes to adjust back",
         "door","Careful work must have gone into the construction of the \n"+
             "door as it is almost perfectly square",
         "window","Like the door it is almost a perfect square",
         "bowls","Almost perfect in shape and design, hand painted bowls with \n"+
            "expressions of animals, birds, and human forms compliment any \n"+
            "dinner",
         "ladder","Strong looking branches twined together with yucca cordage\n"+
            "leads way to the second floor",
         "hole","A small hole in the ceiling above you cut out to access the \n"+
            "second floor",
         "baskets","Hand woven these beautiful baskets prove useful for holding\n"+
             "a variety of dry goods",
         "ceiling","Stringers of juniper jut out from the mud covered ceiling. \n"+
             "You hope its strong enough to hold those who might be above you",
         "table","Made from a hardwood, it has seen many a meal.  Stains from \n"+
             "burning pots charred into it form circlular patterns on it",
         "chairs","Made of hardwood, they look as though a skilled carver spent \n"+
             "many hours crafting them",
});

dest_dir = ({
    PATH+"mv14.c","up",
    PATH+"mv6.c","leave",
});

}
