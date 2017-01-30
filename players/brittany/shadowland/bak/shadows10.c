#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {   
   if(!present("demon", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/shadowland/demon.c"),
      this_object());
    }
  }
  
   if(arg) return;
   set_light(1);
   
   short_desc = GRY+"Shadows10"+NORM;
   long_desc =
   "	As you continue on the road you get closer to the\n"+
   "structure.  The Citadel of Amber. You've heard stories\n"+
   "of it...whispers, intimations...you are sure that this\n"+
   "is the place, perhaps two or three miles away. Continue\n"+
   "west and east.\n";
     	
       items = ({
         "road",".",
         "bleys","A Prince of Amber fighting for the regency.\n",
         });

   dest_dir = ({
         "players/brittany/shadowland/shadows9.c","west",
         "players/brittany/shadowland/shadows11.c","east",
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

