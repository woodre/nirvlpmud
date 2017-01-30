inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

  short_desc="The Museum";
  long_desc =
"You are in an empty side room of the museum.  The walls are crystal\n"+
"clear and provide a magnificent view of space.  There is a single\n"+
"transporter which will take you back to the museum lounge.\n";
  items=({
  "walls", "The walls are perfectly clear",
  "space", "You can see lots of stars",
  "stars", "There are many bright stars visible through the walls",
  "transporter", "The small circle on the ground will take you back to\n"+
  "the lounge of the Museum.  Just type 'leave'",
  });
  set_light(1);
  dest_dir=({ "/players/zeus/museum/lounge.c", "leave"  }); 
}

