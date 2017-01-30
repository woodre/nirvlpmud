#include "/players/feldegast/closed/ansi.h"
inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
   long_desc=
"  You are in front of a big neon sign made of glowing blinking letters\n"+
"forming the word "+HIG+BLINK+"EclYpsE"+NORM+".  A wide space in front of the entrance is\n"+
"full of a crowd of people waiting to enter.\n";
   short_desc = "An entrance to the darkness";
    dest_dir = ({ "/players/trix/castle/center.c","north",
                  "/players/trix/castle/disco/in4.c","south"});
}
