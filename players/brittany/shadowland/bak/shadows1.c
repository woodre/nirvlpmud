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
   
   short_desc = GRY+"Shadows1"+NORM;
   long_desc =
   "     You are in the woods moving among the trees, a cloud\n"+
   "obscures the sun and the shadows deepened.  You hear voices\n"+
   "of birds growing louder and you feel a dampness in the air.\n"+
   "The leaves on the trees look longer and broader in this area\n"+
   "of the woods.  There are exits west and east of here.n";
   
   items = ({
         "tree","The tree has a thick trunk.",
         "cloud","Puffy white cotton balls in the sky.",
         "sun","Luminous celestial body peeking from the cloud.",
         "birds","There are only voices of birds nearby.",
         "leaves","Long and broad leaves growing on the trees.",
         });

   dest_dir = ({
         "players/brittany/shadowland/shadows2.c","west",
         "players/brittany/shadowland/shadows3.c","east",
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
