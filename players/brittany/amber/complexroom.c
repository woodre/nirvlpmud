#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {   
   if(!present("ganelon", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/amber/ganelon.c"),
      this_object());
    }
  }
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A Room"+NORM;
   long_desc =
   "     A room on the second floor of the main complex.  A large bed\n"+
   "is in the corner of the room, with a woodburning fireplace in the\n"+
   "middle of the wall.  A heavy wooden table near a wide window over-\n"+
   "looking the courtyard.  The only obvious exit is back.\n";
   
   items = ({
         "bed","A large bed",
         "fireplace","A woodburning fireplace",
         "fireplace","A small crack on the wall, maybe you could 'touch' it",
         "wall","The wall has a fireplace in the middle of it",
         "table","A heavy wooden table",
         "window","An open window with wood trim around it's frame",
         });

   dest_dir = ({
         "players/brittany/amber/chamber.c","back",
	     });
}

init() {
   add_action("back","back");
   add_action("search","search");
   add_action("touch_crack","touch");
}
touch_crack(str){
if(!str || str != "crack") {
        notify_fail("What do you want to touch?\n");
        return 0; }
 
write("You  T O U C H the crack and is drawn into the fireplace.\n");
   say(tpn+"  T O U C H E S the crack and is drawn into the fireplace.\n");
tp->move_player("touch#/players/brittany/amber/shadow#.c");
return 1; }

back(str){
  tp->move_player("back#/players/brittany/amber/chamber.c");
  return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
