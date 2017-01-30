#include "/players/wocket/closed/ansi.h"
#include "Def.h"
inherit EROOM;

reset(arg){
object tree;
  if(arg){ get_monsters(); return; }
  if(!present("tree",this_object())){
     tree = clone_object(EPATH+"OBJ/e_tree.c");
     tree->set_dir(EPATH+"eftb.c");
     move_object(tree,this_object());
  }  
  short_desc = GRN+"The Euka Forest"+OFF;
  long_desc = "   "+
  "The worn path leads off in many directions.  A small clearing can be\n"+
  "seen to the east, while the path continues to twist and turn up to\n"+
  "the northeast and southeast.  Bushes and vines entangle against each\n"+
  "other making it seemingly impossible to travel in any other direction.\n"+
  "Birds can be heard chirping high in the Euka trees.\n";
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
  EPATH+"ef12.c","east",
  EPATH+"ef5.c","northeast",
  EPATH+"ef7.c","southeast",
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