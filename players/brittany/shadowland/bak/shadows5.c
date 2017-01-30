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
   
   short_desc = GRY+"Shadows5"+NORM;
   long_desc =
   		"You are on a road where the sky has grown a bit greenish,\n"+
   "then shaded over into pink.  The road continues under a bridge,\n"+
   "after passing underneath you emerge on the other side and the\n"+
   "sky returns to normal.  The exits are west and north.\n";
   
   items = ({
         "sky","The sky is greenish then shaded over to pink.",
         "bridge",".",
         "road","A road in shadow.",
         });

   dest_dir = ({
         "players/brittany/shadowland/shadows4.c","west",
         "players/brittany/shadowland/shadows2.c","north",
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

