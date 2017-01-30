#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("dragon")) {   
    move_object(clone_object("/players/brittany/xanth/NPC/dragonlady.c"),this_object());
   }
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Dragonland"+NORM;
   long_desc =
   "     A large passage leads you through the mountains.  Halfway\n"+
   "through the passage, you notice a huge net starting to form in the\n"+
   "middle.  A large throne sits inside of it.\n";
   
   items = ({
         "throne","The throne is in the shape of a huge diamond",
         "net","The net is made of scales from a huge fish",
          });

   dest_dir = ({
         "/players/brittany/xanth/dragonland.c","south",        
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
