#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {

if(!present("demon", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/shadowland/NPC/demon.c"),
      this_object());
    }
  }

   if(arg) return;
   set_light(0);
   
   short_desc = GRY+"Shadows7"+NORM;
   long_desc =
   	   "Purple clouds cover over the sun and it begins to rain.\n"+
   "Lightning stalked the heavens and the skies grumbled above\n"+
   "you.  You imagine a horseman racing pass you in the other\n"+
   "direction, collar turned high and head lowered against the\n"+
   "rain.  The exit is west from here.\n";
   		
    
   items = ({
         "clouds","Big yellow windmills.",
         "cloud","A big yellow windmill.",
         "horseman","A horseman dressed in gray racing pass you--it is an illusion.",
         "rain",".",         
         });

   dest_dir = ({
         "players/brittany/shadowland/shadows6.c","west",
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
