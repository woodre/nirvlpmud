#include "/open/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

status pedestal;

reset(arg) {
   if(arg) return;
   pedestal = 1;
   
   short_desc = WHT+"The Great One's Lair"+NORM;
    long_desc =
    "     All at once the pageant of impressions begins to achieve a vague\n"+
    "kind of stabilization.  Great masses of towering stone are carved\n"+
    "into gigantic hieroglyphed pedestals.  The pedestals are hexagonal\n"+
    "and surmounted by cloaked, ill-defined shapes.  One pedestal looks to\n"+
    "be unoccupied.\n";


   items = ({
         "stone","Stone carved into gigantic hieroglyphed pedestals",
         "pedestals","Towering stone carved into structured bases",
         "pedestal","A stone pedestal belonging to the Great One, he sometimes appears\n"+
         "if you 'gaze' at it",
         "shapes","The cloaked shapes appear to be of human origin without faces",
         "impressions","The images form into great masses of towering stone",
         "pageant","Illusions of shapes and scenary",
          });

dest_dir = ({   
         "/players/brittany/kadath/k38.c","back",
         "/players/brittany/kadath/k1.c","out",
      });
}
   
init(){
  ::init();
  add_action("gaze","gaze");
add_action("search","search");
}

gaze(str){
   if(!str ||  str != "pedestal") {
   notify_fail("What?\n");
   return 0; }
 
   if(pedestal) {
 write("The pedestal glows and you feel a strangeness about.\n\n");
     move_object(clone_object("/players/brittany/kadath/NPC/one.c"),this_object());
     pedestal = 0;
   }
   else write("Nothing happens.\n");
   return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
