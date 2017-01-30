inherit "room/room";
#include "definitions.h"

int i;

reset(arg) {

if (!present("buffalo")) {
  for(i = 1; i<=2; i++) 
    move_object(clone_object(CASTLEMONSTER+"/buffalo.c"),
    this_object());
   }

   if(!arg) {
   set_light(1);
   short_desc=("Northern Flat Plains");
   long_desc=
"     Yellow flat grassy plains spread across the\n"+
"landscape in all directions.  The absence of trees\n"+
"and small shrubs gives you an amazingly far-seeing\n"+
"view.  From here you can see for miles.  Tall\n"+
"mountains line the southwestern horizon like a row\n"+
"of crooked teeth.  A vast ocean spans into infiniti\n"+
"to the east.  To your north, the plains slowly\n"+
"become greener.  Far the northwest, you can barely\n"+
"see what seems to be a forest.\n";

   dest_dir=({
   CASTLEROOM+"/hill1.c","west"  ,
   CASTLEROOM+"/brown6.c","south"  ,
   CASTLEROOM+"/brown4.c","north"  ,
   CASTLEROOM+"/brown2.c","east"  ,
            });

   items=({
   "grass","     The grass is a mottled brownish-yellow",
   "landscape","     The land is flat here",
   "forest","     You can barely make out the tree tops",
   "plains","     The plains here are completely flat",
   "mountains","     The mountains tower above the hills",
   "ocean","     The ocean meets a long beach to the southeast",
   });
   }   }
