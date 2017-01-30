inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int t;
int i;
reset(arg) {
 if(!present("pirate")) {
  for(t=0;t<2;t++){
   move_object(clone_object("players/persephone/monster/pscoutb"), TOB);
  }
 }
 if(!present("guard")) {
  for(i=0;i<2;i++){
   move_object(clone_object("players/persephone/monster/pscoutc"), TOB);
  }
 }
    if(!arg) {
    short_desc = ("An alley");
    long_desc = ("You are stuck in a maze of alleys, twisting all around you. You are hopelessly\n"+
      "lost, and feeling rather hopeless. Water drips off the walls here, and you\n"+
      "hear the skittering of rats around you.\n");
    items = ({
      "maze","One of those places that wizards set up just to piss off mortals",
"alleys","A narrow place between two walls",
      "walls","Nothing terribly interesting about them...other than the slime, the damp, the\n"+
      "graffiti..",
      "graffiti","`Jeny's tops' `Vvlad rules' `Crime Pays' and such",
      "water","H2O, my friend",
      "skittering","The pitter-pat of little feet...yuck",
    });
    dest_dir = ({
"/players/persephone/rooms/maze4","north",
"/players/persephone/rooms/maze2","west",
"/players/persephone/rooms/maze5","south",
"/players/persephone/rooms/maze9","east",
    });
 }
}
realm(){ return "NT";}
