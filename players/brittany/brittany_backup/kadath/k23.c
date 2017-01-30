#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
string listens;

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = WHT+"Ulthar village"+NORM;
   long_desc =
   "    This is a steep little street overlooking the lower town.  A\n"+
   "sweet bell peals in the town temple below.  The merchant bar is\n"+
   "east and a merchant shop is west of here.  To the south down a\n"+
   "steep slope is a path beside the river.\n";
   
   items = ({
         "street","The street is small and narrowed",
         "temple","The stone temple has a bell swinging inside of it",
         "bar","A merchant bar lies east of here",
         "shop","A merchant shop lies west of here",
         "path","The path is rocky and steep",
         "towers","Tall black stone towers",
         "bell","A hollow instrument of cast metal, cup-shaped\n"+
         "and suspended from the vertex",
         "slope","A steep slope leading to a path beside the river",
         "river","A natural stream of water flowing down a channel",
         "town","The small merchant town along the City of Ulhtar",
         });

   dest_dir = ({
          "/players/brittany/kadath/k22.c","north",
        "/players/brittany/kadath/k27.c","south",
          "/players/brittany/kadath/k24.c","west",
          "/players/brittany/kadath/k26.c","east",
          });
   
}

   init(){
  ::init();
   add_action("search","search");
  add_action("listen","listen");
}
 
listen() {
write("A bell peals in the town temple.\n");
return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
