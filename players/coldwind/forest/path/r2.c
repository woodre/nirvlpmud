#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);


long_desc =
"You are in part of a dimly lit forest.\n"+
"Trails lead northwest and southeast. \n";


dest_dir = ({
  "/room/south/sforst45.c","northwest",
  "/players/coldwind/forest/path/r1.c","southeast",  
});

}

short(){
 return "A dimly lit forest";
}	