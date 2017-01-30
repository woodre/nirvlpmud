#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {

if(!present("demon1", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/shadowland/NPC/demon1.c"),
      this_object());
    }
  }

   if(arg) return;
   set_light(0);
   
   short_desc = GRY+"Shadows4"+NORM;
   long_desc =
   "     You hear a rumble as you emerge from the woods again, it\n"+
   "sounds like steady thunder falling against you.  At the edge\n"+
   "of the overhang, you see it plunges a thousand feet over the\n"+
   "mighty cataract that smoke the gray river.  Across, from here\n"+
   "perhaps a mile distant, a partly screened rainbow and mist is\n"+
   "in the sky.  The only exit is east.\n";
   
   items = ({
         "cataract","Steep rapids in the river.",
         "river","A stream of water.",
         "rainbow","A multicolored array.",
         "sky","A misty sky.",
         });

   dest_dir = ({
         "players/brittany/amber/shadows5.c","east",
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

