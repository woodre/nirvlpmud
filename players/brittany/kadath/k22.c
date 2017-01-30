#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = WHT+"Ulthar village"+NORM;
   long_desc =
   "     A blur of smoke rises on the horizon as you enter the village.\n"+
   "Beyond the smoke are some tall black towers in the distance.  The\n"+
   "streets are made of basalt and many sea-taverns are lined along\n"+
   "a river.  Merchant shops on a busy street can be seen not far away.\n"+
   "South of here is a steep street.\n";
   
   items = ({
         "sea-taverns","Small sea-taverns made of stone",
         "towers","Tall black stone towers",
         "river","A natural stream of water flowing down a channel",
         "shops","Small merchant shops selling goods",
         "streets","The streets are small and narrow",
         "street","The street is small and narrowed",
         "smoke","A visible black vapor",
         });

   dest_dir = ({
        "/players/brittany/kadath/k21.c","north",
          "/players/brittany/kadath/k23.c","south",

         });
   
}

   init(){
  ::init();
   add_action("search","search");
}
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
