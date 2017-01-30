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
   
   short_desc = GRY+"Shadows2"+NORM;
   long_desc =
   "     The trail takes an upward turn, passes an outcropping\n"+
   "of flint and onto higher ground.  The sky is a different\n"+
   "blue, as the trail opens up.  A lizard is sunning itself\n"+
   "on a rock.  The exits are east and south.";
   
   items = ({
         "sky","A beautiful clear blue sky.",
         "trail","A passage through shadow.",
         "lizard","A long-bodied reptile.",
         "rock","A large stone.",
         "flint","Some type of corn crop.",
         });

    dest_dir = ({
         "players/brittany/shadowland/shadows1.c","east",
         "players/brittany/shadowland/shadows5.c","south",
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
