#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return 1;

short_desc = HIG+"Turtleville"+NORM;
long_desc = "   The air is clean and fresh upon this beautiful day.  The streets\n"+
            "are clean with smooth rocks paving the way.  To the north lies the center\n"+
            "of the city with the great fountain while west is the post office.\n"+
            "The buildings line the streets with their nice roofs and cheery appearance.\n"+
            "There is a small trail that leads down to a pond to the southeast.\n";

items = ({
    "trail","A soft dirt path that leads down to a pond",
    "rocks","They make up the paved road.  They are grey and have been worn down by much use",
    "road","Made up of many rocks, it is very smooth and clean",
    "fountain","It is kind of hard to make out, but lies to the north",
    "post office","They building looks very similar to all the others with a sign hanging\n"+
                  "above the door with some letters painted upon it",
    "buildings","They are nice and cheery with their shutters open to the clean air",
    "roofs","They are green like the shells of the turtles",
    "street","Made up of many rocks, it is very smooth and clean",
    "sign","It reads 'Post Office'",
});


  dest_dir = ({
    PATH+"/tville_fount.c","north",
    PATH+"/tville_post.c","west",
    PATH+"/tvpond1.c","southeast", 
 });
set_light(1);
}
