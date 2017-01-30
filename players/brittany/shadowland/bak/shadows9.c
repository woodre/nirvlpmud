#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(0);
   
   short_desc = GRY+"Shadows9"+NORM;
   long_desc =
   "	You continue your trek through the shadows it grow\n"+
   "bleaker and bleaker, turning basically into a desert of\n"+
   "some kind. A huge sprawling tagled structure is seen in\n"+
   "the distance. Black as onyx, and seemingly itself alive,\n"+
   "it sits on the edge of a sea whose salt you can smell even\n"+
   "from here.  The trek continues west and est from here.\n";        	
    
   items = ({
         "desert",".",
         "structure","A structure that is black as onyx, you can\n"+
         "not make out what it is.",
         });

   dest_dir = ({
         "players/brittany/shadowland/shadows8.c","west",
         "players/brittany/shadowland/shadows10.c","east",
          });
   }
   
init() {
   ::init();
   add_action("search","search");
   }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
