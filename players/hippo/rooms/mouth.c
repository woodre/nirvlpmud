#include "room.h"
#include "/players/hippo/bs.h"
int i;
object tooth;
object molar;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("tooth")){
   for (i=0;i<2;i++){
   move_object(clone_object("players/hippo/c/tooth.c"),this_object());
}
}
if(!present("molar")){
   for (i=0;i<3;i++){
    move_object(clone_object("/players/hippo/c/molar.c"),this_object());
}
}
}
THREE_EXIT("/room/jetty2","push_tongue",
   "/players/hippo/rooms/nose","nose",
   "/players/hippo/rooms/throat","down",
   "An enormous mouth!?",
/*
   "You wonder what happened to you. You were lifted up by this"+BS+
   "enormous hand, and now you are in a dark place. However"+BS+
    "you are still alive, and that is what matters, right?"+BS+
   "as soon as your eyes start to see a bit in the dark, you"+BS+
   "see teeth all over and a hugh tongue, trying to pull you to"+BS+
   "a dark hole. As you realise you are in a mouth, you suppose"+BS+
   "the hole must be the throat. And you think it might be"+BS+
   "interesting to go down, and look at this body's organs"+BS,
*/
format("\
A cold breeze from the one side is \
alternated by a warmer wind, comming from \
the opposite way. \
Judging from the smell, the warmer wind \
originates from the deep inside of the body. \
Just above the dark hole where it enters is another \
large gap, bringing fresh air from the nose every now and then. \
\nThe large, red, moving and twisting thing on the ground \
is Hippo's tongue. Pushing this might make \
him puke out the mouth's contents. \
"),
         1)

/* added by wocket (puzzles were removed in nose) */
init(){
  ::init();
    add_action("newnose","nose");
}

newnose(){
    write("You try to enter the nose but are blocked by a wall of mucus.\n\
The nose is currently stuffed up.\n");
    return 1; 
}
