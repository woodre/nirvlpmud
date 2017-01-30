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

if(arg)return;
     set_light(1);

     short_desc = HIG+"Cliff Palace"+NORM;
     long_desc =
         "\n"+
         "\tSunshine floods into the room from the door and small \n"+
         "window.  Natural floors with small hand woven blankets lay neatly \n"+
         "in a circle around what appears to be a fire pit.  Small baskets \n"+
         "and bowls are neatly arranged on the ground alongside the wall.\n"+
         "There is a small ladder going up into a hole in the ceiling.\n"+
         "\n"
;

     items = ({
         "room","Neat and tidy, the women here must toll hard at keeping it\n"+
            "so nice and clean",
         "sunshine","It blinds you as you gaze at it.  It takes a few moments \n"+
            "for your eyes to adjust back",
         "door","Careful work must have gone into the construction of the \n"+
            "door as it is almost perfectly square",
         "window","Like the door it is almost a perfect square",
         "floors","Natural sandstone floors from the alcove in which this \n"+
            "home was built",
         "blankets","Made of twined turkey feathers wrapped around yucca cordage,\n"+
            "many hours must have gone into making these colorful blankets",
         "bowls","Almost perfect in shape and design, hand painted bowls with \n"+
            "expressions of animals, birds, and human forms compliment any \n"+
            "dinner",
         "ground","A thin layer of sand covers it beneath your feet",
         "wall","Dark black stains cover these walls made from almost perfect\n"+
             "square blocks",
         "ladder","Strong looking branches twined together with yucca cordage\n"+
            "leads way to the second floor",
         "hole","A small hole in the ceiling above you cut out to access the \n"+
            "second floor",
         "pit","Small bricks lay in a circle on the floor to keep the fire \n"+
            "from spreading",
         "fire","Still smoldering from the fire that recently went out",
         "baskets","Hand woven these beautiful baskets prove useful for holding\n"+
             "a variety of dry goods",
         "ceiling","Stringers of juniper jut out from the mud covered ceiling. \n"+
             "You hope its strong enough to hold those who might be above you",
});

dest_dir = ({
    PATH+"mv8.c","up",
    PATH+"mv6.c","leave",
});

}
