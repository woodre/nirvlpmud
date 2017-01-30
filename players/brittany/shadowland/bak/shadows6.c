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
   
   short_desc = GRY+"Shadows6"+NORM;
   long_desc =
   		"There are windmills all over the place.  You notice\n"+
   "the people on the streets are dressed rather strangely,\n"+
   "and the roadway is of brick.  The exits are north and east.\n";
   
   items = ({
         "windmills","Big yellow windmills.",
         "windmill","A big yellow windmill.",
         "roadway",".",
         "road",".",
         });

   dest_dir = ({
         "players/brittany/shadowland/shadows3.c","north",
         "players/brittany/shadowland/shadows7.c","east",
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
