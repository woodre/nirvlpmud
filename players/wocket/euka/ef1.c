#include "/players/wocket/closed/ansi.h"
#include "Def.h"
inherit EROOM;

reset(arg){
  if(arg) return;
  short_desc = GRN+"The Euka Forest"+OFF;
  long_desc = "  "+
  "A small path has been worn through the thick forest.  Ferns\n"+
  "grow large upon it, filtering out a lot of the sun light.  Flashes\n"+
  "of birds can be seen up within the Euka trees.  Vines and brush\n"+
  "line the path blocking passage in those directions.\n";
  items = ({
    "ferns","Very large and green ferns that fan out over the path",
    "path","A worn path with soft dirt covering it",
    "light","Bright light that has filtered through the fern leaves",
    "sun light","Bright light that has filtered through the fern leaves",
    "birds","Bright and colorful with long tail feathers.  They sit up\nin the trees",
    "trees","Large Euka trees.  They have large green leaves that create\nshade everywhere.  There branches are smooth and thick",
    "vines","Green vines with sharp thorns",
    "brush","Scrubby bushes with sharp leaves and branches",
  });
  smells = ({
    "default","You smell the clean air and fresh sent of Euka trees",
  });
  listens = ({
    "default","You hear songs of birds and the rustle of leaves",
    "birds","You hear them chirping in the trees",
   });
  dest_dir = ({
  "/room/south/sforst45.c","north",
  EPATH+"ef2.c","southeast",
   });
  set_light(1);
 }

