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
   
   short_desc = GRY+"Shadows3"+NORM;
   long_desc =
   "     You face the woods once more, but now the way leads\n"+
   "uphill through it.  The trees are tropical giants, scattered\n"+
   "with fern.  The ground seem to vibrate from the loud rumbling\n"+
   "in the air.  There are big flowers and puddles where the\n"+
   "moisture dripped from overhead.  The temperature begans to\n"+
   "rise in this room, you began to perspire.  The exits are west\n"+
   "and south.\n";
   
   items = ({
         "woods","A trail leading uphill.",
         "trees","Tropical giant branches.",
         "flowers","Big, flat, pale flowers.",
         "puddles","Small puddles of water.",
         });

   dest_dir = ({
         "players/brittany/shadowland/shadows1.c","west",
         "players/brittany/shadowland/shadows6.c","south",
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

