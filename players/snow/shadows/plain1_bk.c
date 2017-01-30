#include "shaddefs.h"

realm() { return "NT"; }
 
inherit "/players/snow/shadows/base.c";
 
reset(arg){
  
 if(!arg){
 
 set_light(0);
  short_desc="ShadowPlane";
 long_desc=
 "Shadows flit around the corners of your vision. What seems clear one moment\n"+
 "disappears the next. Vague shadow bushes appear here and there- sometimes\n"+
 "you think you might even see a tree. Shapes of animals suddenly appear... \n"+
 "and as suddenly leave. The landscape appears to somehow flow around your\n"+
 "solidity here. To move from place to place, you must make a huge effort. \n"+
 "\n";
 
items=({
 "bushes", "Bushes of shadowstuff. When you touch them, your hand meets little\n"+
           "resistance and passes through without noticable effect",
 "tree","You think you see a shadow tree but it fades away as you draw near",
 "animals","Vague animal shapes seem to peer at you, then fade away..",
 "landscape","Features of the land pass before your eyes",
});
 
   }   }
 
query_srealm() { return "shad"; }
