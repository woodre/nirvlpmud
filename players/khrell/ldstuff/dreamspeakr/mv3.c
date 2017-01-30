#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/mesa/"

inherit "room/room";

reset(arg) {
     move_object(clone_object("/players/dreamspeakr/mesa/NPC/scorpion.c"), this_object());
     if(arg) return;
     set_light(1);

     short_desc = HIG+"Mesa Verde Cliffside"+NORM;
     long_desc =
         "\n"+
         "\tSmall holes scale this wall in an orderly fashion.  \n"+
         "A firm handhold might be a little treacherous on this  \n"+
         "sandstone cliffside.  The flat surface of the wall makes it \n"+
         "a dangerous climb.  The shadow of a great eagle reflects on \n"+
         "the small rock ledges above. \n"+
         "\n"
;

     items = ({
         "holes","Dark and foreboding you feel a little leary as you\n"+
            "carefully place your hands and feet in each one to \n"+
            "scale the cliff. Above you a lizard scurries out of \n"+
            "one",
         "wall","A rocky sandstone wall that goes straight up, giving\n"+
            "you the impression that it almost reaches the clouds",
         "sandstone","Your fingers seem to slide on the gritty \n"+
            "surface of this sandstone wall.  You worry that the \n"+
            "stone will crumble under your grip",
         "cliffside","There appears to be nothing more then the holes to support\n"+
            "your weight as you work your way up this cliffside.  The gritty \n"+
            "soft rock surface makes it a difficult climb",
         "eagle","Its cry echos through the canyon as it gracefully \n"+
            "soars above you searching for a resting spot",
         "rock","Sandstone rocks clutter the small crevices and fall \n"+
            "to the ground as you climb this wall",
         "ledges","You notice a small nest of newborn birds awaiting \n"+
            "their mother to bring them their food on one of the many ledges",
         "shadow","A dark shadow soars across the face of the rock as \n"+
            "the eagle flys through the canyon",
});

dest_dir = ({
    PATH+"mv4.c","climb",
    PATH+"mv2.c","descend",
});

}

listen(){
  write("You close your eyes and listen.... you hear a soft babbling \n"+
        "river and the whisper of the wind rustles thru your hair.  Echos \n"+
        "of people singing seem to surround you. \n");
  return 1;
}
