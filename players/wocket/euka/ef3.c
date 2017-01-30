#include "/players/wocket/closed/ansi.h"
#include "Def.h"
inherit EROOM;

reset(arg){
  if(arg){ get_monsters(); return; }
  short_desc = GRN+"The Euka Forest"+OFF;
  long_desc = "  "+
  "That path leads through a sharp curve ahead.  Shade from the ferns\n"+
  "and tree leaves are cast upon the ground darkening the area.  Birds\n"+
  "flash there color as the light the does filter through glints off\n"+
  "their feathers.  The brush lining the path blocks travel in those\n"+
  "directions.\n";
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
  EPATH+"ef2.c","west",
  EPATH+"ef4.c","south",
  });
  set_light(1);
  get_monsters();
 }


get_monsters(){
int i;  
   if(random(3)==1){
    move_object(clone_object(EPATH+"NPC/snapper.c"),this_object());
   }
   i=0;
   while(random(3)==1 && i < 2){
    move_object(clone_object("/players/wocket/mushrooms/nonge.c"),this_object());
    i++;
   }
   i = 0;
   while(random(3)==1 && i < 2){
     move_object(clone_object("/players/wocket/graveyard/niblet.c"),this_object());
     i++;
   }
}