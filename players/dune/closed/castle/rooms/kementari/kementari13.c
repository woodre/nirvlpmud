inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

if (!present("sithi"))
  for(i = 1; i<=5; i++)
  move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"),
  this_object());
if (!present("lord"))
  move_object(clone_object(CASTLEMONSTER+"/noiar_lord.c"),
  this_object());

   if(!arg) {
   set_light(1);
   short_desc=("The Ruins of Kementari");
   long_desc=
"     The path ends upon a very large stone\n"+
"platform.  Upon the stone, several strange\n"+
"symbols and pictures are carved.  It must be\n"+
"of ancient artwork.\n";

   dest_dir=({
   CASTLEROOM+"/kementari12.c","south"  ,
            });

   items=({
   "path","     The path leads into a crevice in a boulder",
   "platform","     The platform is the top of a fallen boulder",
   "stone","     The stone is white in color",
   "symbols","     The symbols must be some sort of language",
   "pictures","     The pictures are of wild animals",
   });
   }   }
