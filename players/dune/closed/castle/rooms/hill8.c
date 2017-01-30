inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

if (!present("ogre")) {
  for(i = 1; i<=2; i++) 
    move_object(clone_object(CASTLEMONSTER+"/ogre.c"),
    this_object());
   }

   if(!arg) {
   set_light(1);
   short_desc=("The Foothills");
   long_desc=
"     Tall foothills bump across the land irregularly.\n"+
"Various trees, but mainly pine, grow everywhere.\n"+
"To the south and west, the hills eventually become\n"+
"tall snow-capped mountains.\n";

   dest_dir=({
   CASTLEROOM+"/hill7.c","north"  ,
   CASTLEROOM+"/hill6.c","east"  ,
            });

   items=({
   "foothills","     Smooth steep foothills surround you",
   "mountains","     Tall snow-capped mountains tower over the hills",
   "trees","     Trees grow all over the hills and up the mountains",
   "land","     The hilly land is like large swells in a sea",
   });
   }   }
