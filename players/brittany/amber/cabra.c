#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {

if(!present("zoog", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/amber/joplin.c"),
      this_object());
    }
  }

   if(arg) return;
   set_light(0);
   
   short_desc = GRY+"Lighthouse of Cabra"+NORM;
   long_desc =
   "     A gray lighthouse with a stone stairway leading up to the door\n"+
   "on its western face.  It is high, wide, heavy, and watertight, made\n"+
   "of concrete.  The lighthouse being 83 feet above water and the top of the\n"+
   lantern 87 feet above ground. A 25,000-candlepower light flashes white\n"+
   "every 3 seconds and is visible 15 miles at sea.\n";
   
   items = ({
         "stairway","A stone stairway",
         "door","A door with three dark hinges",
         "lantern","A lantern 87 feet above ground",
         "light","A white light in the lantern",
         });

   dest_dir = ({
         "players/brittany/amber/k15.c","climb",
          });
   }

   
init(){
::init();
add_action("climb","climb");
add_action("search","search");
}

climb(str){
  tp->move_player("climb#/players/brittany/amber/k15.c");
  return 1; }

 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
