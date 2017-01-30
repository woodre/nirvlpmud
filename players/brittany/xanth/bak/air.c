#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

status ring;

reset(arg) {
   if(arg) return;
   ring = 1;
   set_light(1);
   
   short_desc = RED+"Forbidden Region"+NORM;
   long_desc =
   "     Inside the border of the Region of Air, dust storms roil and tumble.\n"+
   "There is no vegetation, just sand in dunes and valleys, and stone cliffs.\n"+
   "Sand is driven against the cliffs by blowing winds.  There is a door\n"+
   "embedded into one of the cliffs.\n";
   
   items = ({
         "door","A wide stone door with a pull ring, bolted to it",
         "ring","A bronze ring bolted to the door, maybe you could 'pull' it",
          });

   dest_dir = ({
         "/players/brittany/xanth/fen.c","north",        
              });
}

init() {
   ::init();
   add_action("search","search");
   add_action("pull_ring","pull");
  }
 
pull_ring(str){
object dragon;
if (!str || str != "ring") {
notify_fail ("What do you want to pull?\n");
return 0; }
 
if(ring) {
write("You pull the ring and the room fills with a cyan cloud.\n\n"+
   "A small "+CYN+"CYAN"+NORM+" dragon appears.\n");
  dragon = clone_object("/players/brittany/xanth/NPC/airling.c");
  move_object(dragon,this_object());
  dragon->attack_object(this_player());
  ring = 0;
  }
  else write("You pull the ball.\n");
  return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
