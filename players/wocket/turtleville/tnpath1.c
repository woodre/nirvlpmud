#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
#define PED "/players/wocket/turtleville/NPC/ped.c"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
if(random(2)==1){
if(!present("ped",this_object()))
  move_object(clone_object(PED),this_object());
 if(random(2)==1){
  move_object(clone_object(PED),this_object());
 }
} 
if(arg) return;

short_desc = HIG+"Turtleville"+NORM;
long_desc = "   The roads are nicely paved while the sky is a bright blue.  Shops\n"+
            "line the road.  To the west is the store while the advance hall\n"+
            "is to the east.  The green rooftops seem bright and cheery with\n"+
            "the day being so bright.\n";

items = ({
    "roads","They are nicely paved with smooth stones",
    "sky","It is a bright sky blue.  Small clouds fill the empty spaces",
    "rooftops","They look like green turtle shells",
    "day","It is bright with the sun beaming down and the breeze blowing",
    "advance hall","A small sign with a sword and some armor paintings hangs above the building",
    "hall","A small sign with a sword and some armor paintings hang above the building",
    "store","A sign reading \"le Turtleville Shoppe\" hangs above it",
    "shops","They line the road with their signs hanging above the entrances",
    "signs","They are wooden with painting on them",
});

  dest_dir = ({
    PATH+"/tnpath2.c","north",
    PATH+"/tville_shoppe.c","west",
    PATH+"/tville_fount.c","south",
    PATH+"/tville_adv.c","east",
  });
set_light(1);
}
