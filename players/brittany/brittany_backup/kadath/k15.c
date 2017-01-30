#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {


   if(arg) return;
   set_light(0);
   
   short_desc = GRN+"A dark tunnel"+NORM;
   long_desc =
   "     The walls are covered with a glowing fungi.  A trail of\n"+
   "honeycombs are scattered throughout the tunnel.  The trail\n"+
   "suddenly stops in a certain spot on the ground.  This appears\n"+
   "to be a DEAD end.  Maybe you can crawl out?\n";
   
   items = ({
         "honeycombs","Honey formed inside an hexagonal cell, half-eaten all over the place",
         "fungi","A phosphorescent spongy abnormal growth",
         "trail","A trail of honeycombs throughout the tunnel",
         "walls","The walls are covered with glowing fungi",
         "ground","The honeycombs suddenly stop at this spot",
         "opening","The opening is not accessible from this room",
         "tunnel","A trail of honeycombs are scattered on the ground, maybe you should 'search' it",
          });

   }
   
init(){
::init();
add_action("search","search");
add_action("crawl","crawl");
}

crawl(str){
   write("You crawl out of the tunnel and end back in the woods.\n\n");
   say(tpn+" CRAWLS out of the tunnel.\n");
  tp->move_player("crawl#/players/brittany/kadath/k13.c");
  return 1; }

search(str){
if(!str || str !="ground"){
  notify_fail("Search what?\n");
  return 0; }
 
   write("You search the ground, SUDDENLY the ground caves in and\n"+
        "you fall into a hidden burrow.\n\n");
    say(tpn+"  F A L L S  into the unknown.\n");
    tp->move_player("into the unknown#/players/brittany/kadath/k16.c");
   return 1;
}

