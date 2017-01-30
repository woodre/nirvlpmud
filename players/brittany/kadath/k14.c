#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {

if(!present("zoog", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/kadath/NPC/zoogs.c"),
      this_object());
    }
  }

   if(arg) return;
   set_light(0);
   
   short_desc = GRN+"A burrow"+NORM;
   long_desc =
   "     This is a dark room.  You have fallen into a hidden burrow.\n"+
   "The walls are covered with glowing fungi.  The fluttering noises\n"+
   "seem much closer.  Half-eaten honeycombs are all over the ground.\n"+
   "Something skitters into the corner.\n";
   
   items = ({
         "burrow","The burrow is a tunnel dug into the ground",
         "honeycombs","Honey formed inside an hexagonal cell, half-eaten all over the ground",
         "fungi","A phophorescent slimy glow, consisting of mildew and mold",
         "ground","The ground is covered with honeycombs scattered all around",
         "walls","The walls are covered with some fungi from the Enchanted Wood",
         "corner","There is a tunnel opening leading into more darkness, in the corner",
          });

   dest_dir = ({
         "/players/brittany/kadath/k13.c","climb",
         "/players/brittany/kadath/k15.c","tunnel",
          });
   }

init(){
::init();
add_action("climb","climb");
add_action("tunnel","tunnel");
add_action("search","search");
add_action("listen","listen");
}

listen() {
write("You hear some fluttering noises.\n");
return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

climb(str){
   write("You climb out and end up in another area of the woods.\n\n");
  tp->move_player("climb#/players/brittany/kadath/k13.c");
  return 1; }

tunnel(str){
   write("You enter the tunnel.  The tunnel is too tight to turn back.\n\n");
    say(tpn+"  E N T E R S  the tunnel.\n");
  tp->move_player("tunnel#/players/brittany/kadath/k15.c");
  return 1; }
