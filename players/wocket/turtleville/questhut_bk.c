inherit "/players/wocket/std/tvroom.c";
#include "/players/wocket/closed/ansi.h"

reset(arg){
if(!present("felic"))
  move_object(clone_object("/players/wocket/turtleville/NPC/questhero.c"),this_object());
  if(arg) return;
short_desc = HIG+"A Turtillian Hut"+NORM;
long_desc = ""+
"   A shell roof covers this small hut buried deep with in the swamp.\n"+
"The wooden walls have been keep relitivly clean considering the\n"+
"environment they are in.  Many trophies of dragon heads and monster\n"+
"teeth adorn shelves.  A rocking chair rests in a corner while a small\n"+
"makeshift kitchen resides across the room.  Trunks and boxes line the\n"+
"floor with various items like books, swords, and clothing.  All and all\n"+
"it's a vary inviting and clean hut.\n";

items = ({
  "roof","It is green and look similar to a turtleshell",
  "walls","They are wooden and have many holes in them",
  "trophies","The trophies are of past victories.  Many are heads of dragons while\nothers are monster teeth",
  "heads","They are the heads of dragons.  Some have fins while otherh have spikes",
  "teeth","Giant teeth stained yellow.  They look very sharp",
  "shelves","They are old and very unstable",
  "chair","A well worn rocking chair.  Its red wood looks very comfortable",
  "kitchen","A small stove with pots and pans and a sink make up the kitchen",
  "trunks","They are old wooden trunks covered with dust",
  "corner","Dust and cobwebs fill it alongside a rocking chair",
  "boxes","Small wooden boxes filled with books, swords, and clothing",
  "books","Leather bound, they are covered in dust",
  "swords","They are plain and have been dulled by time",
  "clothing","The clothing is old and tattered",
  "floor","It is well packed dirt covered with boxes and trunks",
});
dest_dir = ({
  "/players/wocket/turtleville/tvmarsh7.c","out",
});
set_light(1);

smells = ({
  "default","A soft scent of snapdragons fills the air",
});
listens = ({
   "default","You can hear crickets outside of the hut chirping away",
});
}

clean_up(){
return 1;
}
