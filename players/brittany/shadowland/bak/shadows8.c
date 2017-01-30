#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {

if(!present("demon", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/shadowland/NPC/benedict.c"),
      this_object());
    }
  }

   if(arg) return;
   set_light(0);
   
   short_desc = GRY+"Shadows8"+NORM;
   long_desc =   
   		"On this road the clouds break apart and you are\n"+
   "walking along a seashore.  The waves splash high and\n"+
   "enormous gulls sweep low above them.  The exit are north\n"+
   "and east from here.\n";
    
   items = ({
         "clouds","Big yellow windmills.",
         "cloud","A big yellow windmill.",
         "horseman","A horseman dressed in gray races pass you--it is an illusion.",
         "waves","Hugh waves splash high from out of nowhere.",
         });

   dest_dir = ({
         "players/brittany/shadowland/shadows4.c","north",
         "players/brittany/shadowland/shadows9.c","east"
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

