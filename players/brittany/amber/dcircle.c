#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {
	if(!present("strgalldwir", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/amber/strgalldwir.c"),
      this_object());
    }
  }
   
   short_desc = GRY+"A Black Road"+NORM;
   long_desc =   
   "	There was movement along the black road, a dark column heading out\n"+
   "toward the citadel. There are a few sparks at the far end.  Overhead,\n"+
   "the sky has completely reversed itself, with you beneath the darkened\n"+
   "half. Again, you feel the strange feeling of having been here long, long\n"+
   "ago, to see that this, rather than Amber, was the True center of Creation.\n"+
   "The road continues east and west from here.\n";
   
   items = ({
         "road","The road is black and darkness looms by.",
         "sky","The sky seems to be going the wrong direction.\n"+
          });

   dest_dir = ({
         "players/brittany/amber/.c","west",
         "players/brittany/amber/.c","east",
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
