#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("samphire")) {
    move_object(clone_object("/players/brittany/xanth/NPC/samphire.c"),this_object());
   }
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A candy garden"+NORM;
   long_desc =
   "     The ground begins to get marshy and many trees surrounds the\n"+
   "the terrain.  You see a big nest in a low_branching trunk and some\n"+
   "huge tracks are on the terrain.  The tracks comes to an end in front\n"+
   "of the low-branched trunk.\n";
   
   items = ({
         "marshmallow","A soft fully marshmallow cushions your fall",
          });

   dest_dir = ({
         "/players/brittany/xanth/garden.c","south",
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
