#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;

short_desc = HIG+"Turtleville"+NORM;
long_desc = "    The sun shines down through white puffy clouds as birds chirps\n"+
            "upon green rooftops.  Smooth stones pave the gentle street that winds\n"+
            "through the city.  To the west lies the shell smith while a gentle and\n"+
            "inviting pub is to the east.  Everything is bright and cheery.\n";  
            
items = ({
  "sun","A bright star lighting up the day",
  "clouds","They are white puffy clouds set with a blue background",
  "rooftops","They look like green turtle shells",
  "pub","A small sign with a beer mug hangs above it",
  "shell smith","A sign with a turtle shell hangs above it",
  "smith","A sign with a turtle shell hangs above it",
  "birds","They have many bright markings and chirp a lot",
  "stones","They are many dull colors and are very smooth",
  "street","It has been paved with many smooth stones and winds through the city",
});

listens = ({
    "default","Birds sing there soft song, brightening the day",
    "birds","They line the roof tops singing",
});
smells = ({
     "default","You smell the fresh air of a new day",
});

  dest_dir = ({
    PATH+"/tnpath3.c","north",
    PATH+"/tville_shellsmith.c","west",
    PATH+"/tnpath1.c","south",
    PATH+"/tville_pub.c","east",
  });
set_light(1);
}
