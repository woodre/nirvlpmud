inherit	"room/room";
#include "/players/cosmo/closed/ansi.h"

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = HIB+"Thunderdome"+NORM;
  long_desc = 
   "You have entered "+HIB+"Thunderdome"+NORM+", a half-sphere of iron bars that rise up\n"+
   "nearly twenty feet in the air.  The bars are crossed such that there is\n"+
   "no chance for escape.  To be in this cage means you have a 50/50 chance\n"+
   "of life or death.  Spectators crowd in all around you, continuously\n"+
   "chanting:   "+RED+"Two men enter, one man leaves."+NORM+"\n";
  no_exits = 1;
  property = ({"NT", "NC", "PK"});
  items = ({"spectators",
          "Filthy, knarly men and women scream profanity, spit on you\n"+
          "and cry out for blood.  Their chant is never-ending:\n"+
          RED+"   Two men enter, one man leaves."+NORM+"\n"+
          "These people have climbed all over the outside of the cage,\n"+
          "blocking out all sunlight and forming a human dome around you\n"+
          "and the iron bars"});
  dest_dir = ({"players/cosmo/apt/pkarea/entrance.c", "out"});
  }
}
