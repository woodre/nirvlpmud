#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {

if(!present("ganelon", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/amber/demon.c"),
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
   "of the woods.  The exits are west and east.n";
   
   items = ({
         "tree","The tree has a thick trunk.",
         "cloud","Puffy white cotton balls in the sky.",
         "sun","Luminous celestial body peeking from the cloud.",
         "birds","There are only voices of birds nearby.",
         "leaves","Long and broad leaves growing on the trees.",
         });

   dest_dir = ({
         "players/brittany/amber/shadows.c","west",
         "players/brittany/amber/shadows2.c","east",
          });
   }

   
init() {
   ::init();
   add_action("search","search");
   add_action("step_stones","step");
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

step_stones(str){
if(!str || str != "stones") {
        notify_fail("Where do you want to step?\n");
        return 0; }
 
write("You  S T E P  on the stones and walk across the moat.\n");
   say(tpn+"  S T E P  on the stones and walk across the moat.\n");
tp->move_player("step#/players/brittany/xanth/mag2.c");
return 1; }
