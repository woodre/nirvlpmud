#include "/players/wocket/closed/ansi.h"
#include "Def.h"
inherit EROOM;

reset(arg){
 object tree;
  if(arg){ get_monsters(); return; }
  if(!present("tree",this_object())){
     tree = clone_object(EPATH+"OBJ/e_tree.c");
     tree->set_dir(EPATH+"e_tree10.c");
     move_object(tree,this_object());
  }
  short_desc = GRN+"The Euka Forest"+OFF;
  long_desc = "   "+
  "Euka trees surround the partial clearing.  Bushes and vines cover\n"+
  "the ground around the tree.  The leaves rustle high in the wind\n"+
  "as they dapple the light across the ground.  Birds high in the trees\n"+
  "chirp loudly.\n";
  dest_dir = ({
  EPATH+"ef9.c","southeast",
  });
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