#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

status ball;

reset(arg) {
ball = 1;
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Fire Region"+NORM;
   long_desc =
   "     A ring of fire rages along the border of this region.  The\n"+
   "land beyond it is burned and full of ashes.  On one side\n"+
   "an eternal forest fire rages.  On the other side, a lake of fire\n"+
   "occasionally belches up mushroom clouds of flame.  A huge ball is\n"+
   "suspended in mid-air.\n";
   
   items = ({
         "land","The surface is burnt and full of ashes",
         "fire","A raging flame shaped into a ring",
         "lake","A mushroom cloud of flames",
         "ball","A blackened heart-shaped ball is suspended in mid-air, maybe\n"+
         "you could 'pull' it",
          });

   dest_dir = ({
         "/players/brittany/xanth/fen.c","south",
              });
}

init() {
   ::init();
   add_action("search","search");
   add_action("pull_ball","pull");
  }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

pull_ball(str){
object dragon;
if (!str || str != "ball") {
notify_fail ("What do you want to pull?\n");
return 0; }

if(ball) {
write("You pull the ball and the room fills with a black cloud.\n\n"+
   "A small "+HIR+"RED"+NORM+" dragon appears.\n");
  dragon = clone_object("/players/brittany/xanth/NPC/fireling.c");
  move_object(dragon,this_object());
  dragon->attack_object(this_player());
  ball = 0;
  }
  else write("You pull the ball.\n");
  return 1; }
